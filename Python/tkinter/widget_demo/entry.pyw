# -*- coding: utf-8 -*-
"""
Entry demo
Entry: 单行文本输入域
Created on Tue Mar 24 16:47:05 2020

@author: phb
"""

import tkinter as tk

mainWd = tk.Tk()
mainWd.title('Entry')
mainWd.geometry('500x300')

# show='*': 显示为密文 *
# show=None: 显示为明文
entry1 = tk.Entry(mainWd, show='*', font=('Arial',16))
entry2 = tk.Entry(mainWd, show=None, font=('Arial',16))
entry3 = tk.Entry(mainWd, font=('System', 32, 'bold'))
entry4 = tk.Entry(mainWd, font=('Arial', 32, 'bold'))
entry5 = tk.Entry(mainWd, font=('宋体', 32, 'bold'))
entry1.pack()
entry2.pack()
entry3.pack()
entry4.pack()
entry5.pack()
mainWd.mainloop()