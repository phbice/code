# -*- coding: utf-8 -*-
"""
Listbox demo
Created on Tue Mar 24 17:05:14 2020

@author: phb
"""

import tkinter as tk

mainWd = tk.Tk()
mainWd.title('Listbox')
mainWd.geometry('500x300')

strings = tk.StringVar()
strings.set((1,2,3,4))
listbox = tk.Listbox(mainWd, listvariable=strings)
listbox.pack()

select = tk.StringVar()
def printSelection():
    index = listbox.curselection()
    if index == ():
        select.set('No selection')
    else:
        select.set(listbox.get(index))

label = tk.Label(mainWd, textvariable=select, width=30, height=2,
                  bg='green', fg='white')

button = tk.Button(mainWd, text='Select', command=printSelection)
label.pack()
button.pack()

mainWd.mainloop()