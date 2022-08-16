# -*- coding: utf-8 -*-
"""
Text demo
Created on Tue Mar 24 16:53:44 2020

@author: hp2017
"""

import tkinter as tk
from tkinter import ttk

mainWd = tk.Tk()
mainWd.title('Text')
mainWd.geometry('500x300')

entry = ttk.Entry(mainWd)
entry.pack()

def insert():
    var = entry.get()
    text.insert('insert', var)

button = ttk.Button(mainWd, text='insert', width=10, command=insert)
button.pack()

text = tk.Text(mainWd, height=3)
text.pack()

mainWd.mainloop()