'''
flatten directory by one layer
'''

import os

def listfile(target_dir='.'):
    dirlist = os.listdir(target_dir)
    subdirlist = []
    for name in dirlist:
        dir_ = f'{target_dir}\\{name}'
        if os.path.isdir(dir_):
            subdirlist += ((dir_, subdir)
                         for subdir in os.listdir(f'{target_dir}\\{name}'))
    return subdirlist

target_dir = r'F:\BaiduNetdiskDownload\长图+pdf'
filelist=listfile(target_dir)
for dir_, subdir in filelist:
    os.renames(f'{dir_}\\{subdir}', f'{target_dir}\\{subdir}')
#print(*listfile(), sep='\n')
