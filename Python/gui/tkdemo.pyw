# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 15:53:17 2020

@author: phb
"""

import tkinter as tk

# 实例化对象，建立主窗口 mainWd
mainWd = tk.Tk()

# 设置窗口标题
mainWd.title('你好，世界！')

# 设置窗口大小（长×宽）
mainWd.geometry('500x400')

# 设置 Listbox
li = ['Hello world!', 'What ever you say', 'This is only a demo']
li2 = [1,2,231,415,565321,1454,2]
listbox = tk.Listbox(mainWd)
listbox2 = tk.Listbox(mainWd)
for item in li[::-1]:
    listbox.insert(0, item)
for item in li2[::-1]:
    listbox2.insert(0, item)

# 放置列表
listbox.pack()
listbox2.pack()

# 进入主窗口消息循环
mainWd.mainloop()