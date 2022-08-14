# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 16:21:02 2020

@author: phb
"""

import tkinter as tk

mainWd = tk.Tk()
mainWd.title('Button')
mainWd.geometry('500x300')

# 设置标签
#var 用来从hitMe函数接收字符串变量
var = tk.StringVar()
var.set("I'm safe.")
# width height 以字符为单位，30表示三十个字符宽，2表示两个字符高
label = tk.Label(mainWd, textvariable=var, width=30, height=2,
                 bg='green', fg='white', font=('Arial',16))
label.pack()

onHit = False
def hitMe():
    global onHit
    if onHit == False:
        onHit = True
        var.set("I'm hit!")
    else:
        onHit = False
        var.set("I'm safe.")

# 设置并放置按钮
button = tk.Button(mainWd, command=hitMe,
                   text='hit me', width=10, height=1, font=('Arial', 16))
button.pack()

mainWd.mainloop()