'''
A combobox demo
2022-08-20
'''

import tkinter as tk
from tkinter import ttk
import ctypes

try:
    ctypes.windll.shcore.SetProcessDpiAwareness(1)
except AttributeError:
    pass

class MainGUI(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('Combobox Demo')
        
        mainframe = ttk.Frame(self, padding='1cm 3mm')
        mainframe.grid(row=1, column=1)

        # Combobox
        self.number = tk.StringVar()
        self.number_combobox = ttk.Combobox(mainframe, width=12,
            textvariable=self.number)
        self.number_combobox['values'] = (1, 5, 10, 20, 50, 100)
        self.number_combobox.grid(column=1, row=1)
        self.number_combobox.state(['readonly'])
        # self.number_combobox.bind('<<ComboboxSelected>>',
        #     lambda e: self.number_combobox.selection_clear())
        # self.number_combobox.current(0)

        # 确认按钮
        ttk.Button(mainframe, text='确定', command=
            lambda: self.event_generate('<<number_confirmed>>')
        ).grid(row=1, column=2)

        # 输出标签
        self.output_var = tk.StringVar(value='你还没有选择。')
        ttk.Label(mainframe, textvariable=self.output_var,
            anchor='center').grid(
            row=2, column=1, columnspan=2)

    def get_number(self):
        return self.number_combobox.current(), self.number.get()
    
    def output(self, text):
        self.output_var.set(text)


class Main:
    def __init__(self):
        self.gui = MainGUI()
        self.gui.bind('<<number_confirmed>>',
            self.number_confirmed)
    
    def mainloop(self):
        return self.gui.mainloop()
    
    def number_confirmed(self, event):
        index, number = self.gui.get_number()
        if number and index >=0:
            output = f'你选择了 {number}，它是第 {index+1} 个选项。'
        elif number:
            output = f'你选择了 {number}，它不在选项中。'
        else:
            output = '你还没有选择。'

        self.gui.output(output)

if __name__ == '__main__':
    main = Main()
    main.mainloop()