# -*- coding: utf-8 -*-
"""
Created on Tue May 26 10:49:21 2020

@author: hp2017
"""

import tkinter as tk
from tkinter import ttk

mainWnd = tk.Tk()
mainWnd.title('Python GUI')

label = ttk.Label(mainWnd, text='Enter a name:')
label.grid(column=0, row=0)

name = tk.StringVar()
nameEntry = ttk.Entry(mainWnd, width=20, textvariable=name)
nameEntry.grid(column=0, row=1)
# set focuse
nameEntry.focus()

def click_me():
    # Disable the button
    button.configure(text=f'Hello {name.get()}', state='disabled')

button = ttk.Button(mainWnd, text='Click Me!', command=click_me)
button.grid(column=1, row=1)

mainWnd.mainloop()