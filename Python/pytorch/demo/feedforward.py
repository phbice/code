'''2021-11-04 09：49'''

import torch
import torch.nn as nn
import torchvision.datasets as dsets
import torchvision.transforms as transforms
import matplotlib.pyplot as plt

class Net(nn.Module):
    def __init__(self, input_size, hidden_size, num_classes):
        super(Net, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(hidden_size, num_classes)

    def forward(self, x):
        out = self.fc1(x)
        out - self.relu(out)
        out = self.fc2(out)
        return out

class Main:
    def __init__(self):
        # Constant Values
        self.input_size = 784
        self.hidden_size = 500
        self.num_classes = 10
        self.num_epochs = 20
        self.batch_size = 100
        self.learning_rate = 0.001

        # Data sets
        self.train_dataset = dsets.MNIST(root='./data', train=True,
            transform=transforms.ToTensor(), download=True)

        self.test_dataset = dsets.MNIST(root='./data',train=False,
            transform=transforms.ToTensor(), download=True)

        self.train_loader = torch.utils.data.DataLoader(dataset=self.train_dataset,
            batch_size=self.batch_size, shuffle=True)

        self.test_loader = torch.utils.data.DataLoader(dataset=self.test_dataset,
            batch_size=1, shuffle=True)

        self.test_y = self.test_dataset.targets

        # Net, loss, optimizer
        self.net = Net(self.input_size, self.hidden_size, self.num_classes).double().cuda()
        self.criterion = nn.CrossEntropyLoss().cuda()
        self.optimizer = torch.optim.Adam(self.net.parameters(), lr=self.learning_rate)

    def train(self):
        '''Train the Model'''
        self.losses = []
        for epoch in range(self.num_epochs):
            for images, labels in self.train_loader:
                images = images.reshape(-1, self.input_size).double().cuda()
                labels = labels.cuda()

                self.optimizer.zero_grad()
                outputs = self.net(images)
                loss = self.criterion(outputs, labels)
                loss.backward()
                self.optimizer.step()

                self.losses.append(float(loss))

    def test(self):
        '''Test the Model'''
        self.correct = 0
        self.total = 0
        self.correct_image = []
        self.wrong_image = []
        for image, label in self.test_loader:
            label = label.cuda()
            outputs = self.net(image.reshape(-1, self.input_size).double().cuda())
            _, predicted = torch.max(outputs.data, 1)

            self.total += 1
            if predicted == label:
                self.correct_image.append((image[0,0], label.item()))
                self.correct += 1
            else:
                self.wrong_image.append((image[0,0], label.item(), predicted.item()))
        return self.correct, self.total

    def save(self, file='model.pkl'):
        '''Save the Model'''
        torch.save({
            'model': self.net.state_dict(),
            'optimizer': self.optimizer.state_dict(),
            'losses': self.losses
            }, file)
    
    def load(self, file='model.pkl'):
        '''Load the Model'''
        checkpoint = torch.load(file)
        self.net.load_state_dict(checkpoint['model'])
        self.optimizer.load_state_dict(checkpoint['optimizer'])
        self.losses = checkpoint['losses']
    
    def save_test(self, file='test_result.pt'):
        '''Save test result'''
        torch.save({'correct': self.correct_image, 'wrong': self.wrong_image},
        file)

    def load_test(self, file='test_result.pt'):
        test_result = torch.load(file)
        self.correct_image = test_result['correct']
        self.wrong_image = test_result['wrong']
    
    def plot(self):
        # Losses vs. Train patches curve
        losses = self.losses[:200]
        fig, ax = plt.subplots()
        ax.plot(range(len(losses)), losses)
        ax.set_xlabel('训练批次')
        ax.set_ylabel('损失')
        plt.savefig('./losses.pdf')

        # Correct image
        fig, axs = plt.subplots(3, 3)
        for (image, label), ax in zip(self.correct_image, axs.flat):
            ax.imshow(image.numpy(), cmap='gray')
            ax.set_title(f'{label}')
            ax.get_xaxis().set_visible(False)
            ax.get_yaxis().set_visible(False)
        fig.tight_layout()
        fig.savefig('./test_correct.pdf')

        # Wrong image
        fig, axs = plt.subplots(3, 3)
        for (image, label, predicted), ax in zip(self.wrong_image, axs.flat):
            ax.imshow(image.numpy(), cmap='gray')
            ax.set_title(f'实际标签：{label}\n识别结果：{predicted}')
            ax.get_xaxis().set_visible(False)
            ax.get_yaxis().set_visible(False)
        fig.tight_layout()
        fig.savefig('./test_wrong.pdf')

# test_output = net(images[:20])
# pred_y = torch.max(test_output, 1)[1].data.cpu().numpy().squeeze()
# print('prediction number', pred_y)
# print('real number', test_y[:20].numpy())
if __name__ == '__main__':
    driver = Main()
    driver.load()
    print(driver.test())
    # driver.save_test()
    # driver.load_test()
    # driver.plot()