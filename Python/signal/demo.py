'''
Python signal handling demo
phb
2022-01-22 11:37
'''

import signal
import time

class SigIntHandle:
    def __init__(self):
        self.suspend_flag = False
        self.int_flag = False
        self.original_handle = signal.signal(signal.SIGINT, self)
    
    def suspend(self):
        self.suspend_flag = True

    def release(self):
        if self.int_flag:
            self.int_flag = False
            self.suspend_flag = False
            raise KeyboardInterrupt
        self.suspend_flag = False

    def __call__(self, signalnum, frame):
        if self.suspend_flag:
            self.int_flag = True
            print("Unstoppable schema, Keyboard Interrupt Suspended")
        else:
            raise KeyboardInterrupt


i = 0
j = 0
sigIntHandle = SigIntHandle()
while True:
    sigIntHandle.suspend()
    i += 1
    print(f'i = {i}', end='\t')
    time.sleep(1)
    j += 1
    print(f'j = {j}')
    sigIntHandle.release()\


