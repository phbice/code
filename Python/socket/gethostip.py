'''
2020年8月2日11:09:47
Windows 上获取本机IP地址
'''

import socket
import os

def gethostip():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(('8.8.8.8', 53))
        ip = s.getsockname()[0]
    finally:
        s.close()
    return ip

def gethostip2():
    hostname = socket.gethostname() # 获取本机计算机名称
    ipList = socket.gethostbyname_ex(hostname) # 获取所有网卡的IP地址
    return ipList[2]

def gethostip3():
    return [a for a in os.popen('route print').read().readlines()
            if ' 0.0.0.0 ' in a][0].split()[-2]
