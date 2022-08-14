'''
2021-03-28 12:23:43
数字转化为中文小写数字
'''

import csv
import re

def to_chinesenum(num):
    assert 0 < num < 10000 and isinstance(num, int)
    
    chinese_digits = '零一二三四五六七八九十'
    chinese_bases = ['']+list('十百千')

    digits = [int(d) for d in str(num)]
    length = len(digits)

    if 0 <= num <= 10:
        return chinese_digits[num]
    elif 11 <= num <= 19:
        return '十' + chinese_digits[digits[1]]
        
    result = []
    for i, digit in enumerate(digits):
        if digit != 0:
            result.append((digit, length - 1 - i))
        if digit == 0 and result and result[-1][0] != 0:
            result.append((digit, 0))
    if result[-1][0] == 0:
        result.pop()

    return ''.join(chinese_digits[x[0]] + chinese_bases[x[1]]
                   for x in result)

def from_chinesenum(text):
    chinese_digits = {x : i for i, x in enumerate('零一二三四五六七八九十')}
    chinese_bases = {x : 10**(i+1) for i, x in enumerate('十百千')}
    
    text = text.replace('零', '')
    c_digit_bases = re.split('(?<=[十百千])', text)
    while True:
        try:
            c_digit_bases.remove('')
        except ValueError:
            break

    result = 0
    for x in c_digit_bases:
        if len(x) == 1:
            result += chinese_digits[x]
        else:
            result += chinese_digits[x[0]] * chinese_bases[x[1]]
    return result

def check():
    with open('chinesenum.csv', encoding='utf-8', newline='') as file:
        csvreader = csv.reader(file)
        for row in csvreader:
            num = int(row[0])
            excel_convert = row[1]
            if num >= 10000:
                break
            my_convert1 = to_chinesenum(num)
            my_convert2 = from_chinesenum(excel_convert)

            if my_convert1 != excel_convert or my_convert2 != num:
                print(num, excel_convert, my_convert, sep='\t')


if __name__ == '__main__':
    check()
