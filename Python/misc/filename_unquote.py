'''
unquote all filenames in a given directory
'''

import os
from urllib import parse

def listfile(target_dir):
    dirlist = os.listdir(target_dir)
    filelist = []
    for name in dirlist:
        if os.path.isfile(target_dir+'\\'+name):
            filelist.append(name)
    return filelist

target_dir = r'C:\Users\hp2017\Downloads\image'
trans_table = str.maketrans(r'\/:*?"<>|',r'_________')
filenames = listfile(target_dir)
for filename in filenames:
    newname = parse.unquote(filename)
    newname = newname.translate(trans_table)
    os.rename(target_dir+'\\'+filename, target_dir+'\\'+newname)
