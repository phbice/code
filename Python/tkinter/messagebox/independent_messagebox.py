from tkinter import messagebox
import ctypes

try:
    ctypes.windll.shcore.SetProcessDpiAwareness(1)
except AttributeError:
    pass

messagebox.showinfo('消息框测试', 'Hello,\nworld!')