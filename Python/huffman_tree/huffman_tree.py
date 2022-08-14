'''
Huffman Tree
2021-7-12 16:33:16
'''
import heapq


class HuffmanTree:
    def __init__(self, left=None, right=None, data=None, weight=None):
        self.left = left
        self.right = right

        self.data = data
        if weight:
            self.weight = weight
        else:
            self.weight = self.left.weight + self.right.weight

    def __bool__(self):
        return True

    def __lt__(self, other):
        return self.weight < other.weight
    def __le__(self, other):
        return self.weight <= other.weight
    def __eq__(self, other):
        return self.weight == other.weight


class Heap:
    def __init__(self):
        self.queue = []

    def push(self, item):
        heapq.heappush(self.queue, item)

    def pop(self):
        return heapq.heappop(self.queue)


with open('demo.txt', encoding='utf-16') as file:
    char = file.read(1)
    counter_dict = {}
    while char:
        try:
            counter_dict[char] += 1
        except KeyError:
            counter_dict[char] = 1
        char = file.read(1)

heap = Heap()
for char, count in counter_dict.items():
    heap.push(HuffmanTree(data=char))