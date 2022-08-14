# -*- coding: utf-8 -*-
"""
Radiobutton demo
Created on Tue Mar 24 17:33:56 2020

@author: phb
"""

import tkinter as tk

mainWd = tk.Tk()
mainWd.title('Radiobutton')
mainWd.geometry('500x300')

label = tk.Label(mainWd, bg='yellow', width=20, text='empty')
label.pack()

selectVar = tk.StringVar()
def printSelection():
    label.config(text=selectVar.get())

radiobutton1 = tk.Radiobutton(mainWd, text='Option A', value='A',
                              variable=selectVar, command=printSelection)
radiobutton2 = tk.Radiobutton(mainWd, text='Option B', value='B',
                              variable=selectVar, command=printSelection)
radiobutton3 = tk.Radiobutton(mainWd, text='Option C', value='C',
                              variable=selectVar, command=printSelection)
radiobutton1.pack()
radiobutton2.pack()
radiobutton3.pack()

mainWd.mainloop()