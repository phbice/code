'''在指定文件夹下的所有文件中寻找文字
'''
from pathlib import Path

##class TreeIter:
##    def __init__(self, root):
##        self.root = Path(root)
##        self.stack = [self.root.iterdir()]
##        
##    def __iter__(self):
##        return self
##
##    def __next__(self):
##        try:
##            path = next(self.stack[-1])
##            if path.is_file():
##                return path
##            else:
##                self.stack.append(path.iterdir())
##                return next(self)
##        except StopIteration:
##            self.stack.pop()
##            if self.stack:
##                return next(self)
##            else:
##                raise StopIteration

def treeiter(root):
    root = Path(root)
    stack = [root.iterdir()]

    while stack:
        try:
            path = next(stack[-1])
        except StopIteration:
            stack.pop()
        else:
            if path.is_file():
                yield path
            else:
                stack.append(path.iterdir())

root = r'C:\Users\hp2017\AppData\LocalLow\Nolla_Games_Noita'
# r'F:\Game\Noita'# input('输入路径：')
target_text = 'death_count' # input('输入要查找的文字：')

for path in treeiter(root):
    text = path.read_text(errors='replace')
    if target_text in text:
        print(path)
