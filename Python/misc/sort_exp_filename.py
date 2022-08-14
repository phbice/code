import os

def listfile(target_dir = '.'):
    dirlist = os.listdir(target_dir)
    filelist = []
    for name in dirlist:
        if os.path.isfile(target_dir+'\\'+name):
            filelist.append(name)
    return filelist

target_dir='表情包'
filelist = listfile(target_dir)
i = 1
for file in filelist:
    ext = os.path.splitext(file)[1]
    file = os.path.join(target_dir, file)
    if ext == '':
        os.remove(file)
    else:
        os.rename(file, os.path.join(target_dir,'exp_%d%s' % (i, ext)))
        i += 1