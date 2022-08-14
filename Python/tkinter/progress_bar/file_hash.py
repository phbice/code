import hashlib, threading, io, os, ctypes
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox

# SetProcessDpiAwareness: 设置高 DPI 适配
# typedef enum PROCESS_DPI_AWARENESS {
#   PROCESS_DPI_UNAWARE = 0,
#   PROCESS_SYSTEM_DPI_AWARE = 1,
#   PROCESS_PER_MONITOR_DPI_AWARE = 2
# } ;
# 设为 PROCESS_SYSTEM_DPI_AWARE 使程序忽略系统的全局缩放设置，
# 而根据实际 DPI 设置各组件的大小，这样能使图形界面清晰锐利，
# 避免系统强制缩放造成的模糊。
ctypes.windll.shcore.SetProcessDpiAwareness(1)
# system_dpi = ctypes.windll.user32.GetDpiForSystem()
# base_dpi = 72
# scale_factor = system_dpi / base_dpi
# print(scale_factor)

class MainGUI(tk.Tk):
    def __init__(self):
        super().__init__()
        # 设置缩放因子，非必须，当设置了DPI Awareness 后，使用默认设置即可
        # print(self.tk.call('tk', 'scaling', scale_factor))
        # GUI 变量
        self._filename = tk.StringVar()
        self._output = tk.StringVar()
        self.progress_text = tk.StringVar()
        # self.file_hash = None

        self.title('计算文件的 SHA256')
        self.grid_columnconfigure(1, weight=1)

        mainframe = ttk.Frame(self, padding='3m')
        mainframe.grid(row=1, column=1, sticky=(tk.W, tk.E, tk.N, tk.S))
        mainframe.grid_columnconfigure(2, weight=1)

        # 选择文件
        ttk.Label(mainframe, text='文件路径：').grid(
            row=1, column=1, sticky=tk.E)
        ttk.Entry(mainframe, textvariable=self._filename).grid(
            row=1, column=2, sticky=(tk.W, tk.E))
        self.button = ttk.Button(mainframe, text='计算',
            command=lambda: self.event_generate('<<start_calculation>>'))
        self.button.grid(row=1, column=3, sticky=tk.W)

        # 进度
        ttk.Label(mainframe, text='进度：').grid(
            row=2, column=1, sticky=tk.E)

        progress_frame = ttk.Frame(mainframe)
        progress_frame.grid(row=2, column=2, columnspan=2, sticky=tk.W)

        self.progress_bar = ttk.Progressbar(progress_frame,
            orient='horizontal', mode='determinate')
        self.progress_bar.grid(row=1, column=1, sticky=tk.W)
        ttk.Label(progress_frame, textvariable=self.progress_text).grid(
            row=1, column=2, sticky=tk.W)

        # 显示结果
        ttk.Label(mainframe, text='SHA-256：').grid(
            row=3, column=1, sticky=tk.E)
        ttk.Label(mainframe, textvariable=self._output, width='65').grid(
            row=3, column=2, columnspan=2, sticky=tk.W)

    def set_button(self, calculate_cancel_flag: str):
        if calculate_cancel_flag == 'start':
            self.button['text'] = '计算'
            self.button['command'] = lambda: self.event_generate('<<start_calculation>>')
        else:
            self.button['text'] = '取消'
            self.button['command'] = lambda: self.event_generate('<<cancel_calculation>>')

    def set_progress(self, value:int=None, max:int=None):
        if value is not None:
            self.progress_bar['value'] = value
        if max is not None:
            self.progress_bar['maximum'] = max
        value = self.progress_bar['value']
        max = self.progress_bar['maximum']
        max_length = len(str(max))
        self.progress_text.set(f'{str(value).rjust(max_length)}/{max}')

    @property
    def filename(self):
        return self._filename.get()
    @filename.setter
    def filename(self, value):
        self._filename.set(value)
    
    @property
    def output(self):
        return self._output.get()
    @output.setter
    def output(self, value):
        self._output.set(value)

class Main:
    def __init__(self):
        self.gui = MainGUI()
        self.file_hash = None

        self.gui.bind('<<start_calculation>>', self.start_calculation)
        self.gui.bind('<<cancel_calculation>>', self.cancel_calculation)
        self.gui.bind('<<finish_calculation>>', self.finish_calculation)

        # s = ttk.Style()
        # print(s.theme_use())
    def run(self):
        return self.gui.mainloop()
    
    def start_calculation(self, *args):
        try:
            # print(self.gui.filename)
            self.file_hash = FileHash(self.gui.filename)
        except OSError:
            messagebox.showerror(title='读取文件错误',
                message='无法打开指定文件，请检查输入')
        else:
            thread = threading.Thread(target=self.file_hash.calculate,
                daemon=True)
            thread.start()

            self.gui.set_progress(max=self.file_hash.filesize)
            self.gui.set_button('cancel')
            self.gui.after(1, self.progress)

    def cancel_calculation(self, *args):
        self.file_hash.cancel.set()
        self.file_hash = None
        self.gui.set_button('start')
        self.gui.output = '计算已取消'

    def finish_calculation(self, *args):
        self.gui.set_progress(value=0)
        self.gui.set_button('start')
        self.gui.output = self.file_hash.hashvalue
        self.file_hash = None

    def progress(self, *args):
        if self.file_hash is not None: # 计算未被取消
            read_size = self.file_hash.read_size
            self.gui.set_progress(value=read_size)
            if read_size == self.file_hash.filesize: # 计算完成
                self.gui.event_generate('<<finish_calculation>>')
            else:
                self.gui.after(250, self.progress)

class FileHash:
    def __init__(self, filename):
        self.file_hash = hashlib.sha256()
        self.file = open(filename, 'rb')
        self.filesize = os.stat(filename).st_size
        # 进度，进程间共享的信息
        self._read_size = 0
        self._lock_read_size = threading.Lock()
        self.cancel = threading.Event()
        self.cancel.clear()

        self.hashvalue = None

    def calculate(self):
        with self.file:
            while not self.cancel.is_set():
                block = self.file.read(io.DEFAULT_BUFFER_SIZE)
                if not block:
                    break
                self.file_hash.update(block)
                self.read_size += len(block) 
        self.hashvalue = self.file_hash.hexdigest()
    
    @property
    def read_size(self):
        self._lock_read_size.acquire()
        _read_size = self._read_size
        self._lock_read_size.release()
        return _read_size

    @read_size.setter
    def read_size(self, value):
        self._lock_read_size.acquire()
        self._read_size = value
        self._lock_read_size.release()

# class MainThread(threading.Thread):
#     def __init__(self):
#         super().__init__(daemon=True)

#     def run(self):
#         main = Main()
#         main.run()

# main_thread = MainThread()
# main_thread.start()

main = Main()
main.run()