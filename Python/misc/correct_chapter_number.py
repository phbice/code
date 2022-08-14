import re
import chinesenum

filename = input('Input filename: ')

lines = []
chapter_number = 1
with open(filename, encoding='utf-16') as file:
    for line in file:
        match = re.match('^第(.+?)章(.+\n)', line)
        if match:
            print(line.strip().ljust(40), end='')
            if not match.group(1).isdigit():
                d = chapter_number - chinesenum.from_chinesenum(match.group(1))
                if d != 0:
                    print(chapter_number, d, end='')
            print()
            lines.append(f'第{chapter_number}章{match.group(2)}')
            chapter_number += 1
        else:
            lines.append(line)
with open('result.txt', 'w', encoding='utf-16') as file:
    file.write(''.join(lines))
            
            
