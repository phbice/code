import tkinter as tk
from tkinter import ttk

class FeetToMeters:
    def __init__(self):
        self.root = tk.Tk()
        # 窗口标题
        self.root.title("Feet to Meters")

        mainframe = ttk.Frame(self.root, padding='3 3 12 12')
    
        mainframe.grid(column=0, row=0, sticky=(tk.N, tk.W, tk.E, tk.S))
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)

        # 输入框
        self.feet = tk.StringVar()
        feet_entry = ttk.Entry(mainframe, width=7, textvariable=self.feet)
        feet_entry.grid(column=2, row=1, sticky=(tk.W, tk.E))

        # 显示结果
        self.meters = tk.StringVar()
        ttk.Label(mainframe, textvariable=self.meters).grid(
            column=2, row=2, sticky=(tk.W, tk.E))

        ttk.Button(mainframe, text="Calculate", command=self.calculate).grid(
            column=3, row=3, sticky=tk.W)
        ttk.Label(mainframe, text='feet').grid(
            column=3, row=1, sticky=tk.W)
        ttk.Label(mainframe, text='is equivalent to').grid(
            column=1, row=2, sticky=tk.E)
        ttk.Label(mainframe, text='meters').grid(
            column=3, row=2, sticky=tk.W)

        for child in mainframe.winfo_children():
            child.grid_configure(padx=5, pady=5)

        feet_entry.focus()
        self.root.bind("<Return>", self.calculate)

    def calculate(self, *args):
        try:
            value = float(self.feet.get())
            self.meters.set(int(0.3048 * value * 10000.0 + 0.5) / 10000.0)
        except ValueError:
            pass
    
    def mainloop(self):
        return self.root.mainloop()

gui = FeetToMeters()
gui.mainloop()