'''
2021-08-10 15:37
'''

import os
import pathlib

def rar2zip(rar_path, password):
    temp_path = '.\\_temp'

    rar_path = pathlib.Path(rar_path)
    zip_path = rar_path.parent / f'{rar_path.stem}.zip'
    app_path = pathlib.Path('C:\\Program Files\\7-Zip\\7z.exe')

    # extract from rar
    assert 0 == os.system(f'""{app_path}" x "{rar_path}" "-o{temp_path}"'
    f' "-p{password}""')

    # repack into zip
    assert 0 == os.system(f'""{app_path}" a "{zip_path}" "{temp_path}\*"'
    ' -sdel"')

def list_file(root)->list:
    root = pathlib.Path(root)
    file_list = []
    for path in root.iterdir():
        if path.is_file():
            file_list.append(path)
        elif path.is_dir():
            file_list.extend(list_file(path))
        else:
            raise Exception(f'Unknow Path {path}')
    return file_list

#rar2zip('D:\\迅雷下载\\赫斯提亚双马尾巨乳本+其他双马尾汉化本合集（105本，3.12G，附预览+目录）\\第一弹（32）\\(COMITIA107) [kuma-puro (Shouji Ayumu)] Houkago no Tsuzuki(Chinese)[oxt04389漢化].rar',
#'扶她奶茶')

#root = pathlib.Path('D:\\迅雷下载'
#'\\赫斯提亚双马尾巨乳本+其他双马尾汉化本合集（105本，3.12G，附预览+目录）')
root = pathlib.Path(input('Input root:'))
file_list = list_file(root)
for file_path in file_list:
    if file_path.suffix == '.rar':
        rar2zip(file_path, '扶她奶茶')
