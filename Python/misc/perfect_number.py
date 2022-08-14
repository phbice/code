# -*- coding: utf-8 -*-
'''
Perfect number 完全数
2020年8月3日13:55:52
彭寒冰
'''
import json

def factorsum(num):
    self = num
    result = 1
    factor = 2
    exponent = 0
    i = 2
    while i * i <= num:
        if num % i == 0:
            if i == factor:
                exponent += 1
            else:
                result *= (factor ** (exponent + 1) - 1) // (factor - 1)
                factor = i
                exponent = 1
            num //= i
        else:
            i += 1
    if num == factor:
        result *= (factor ** (exponent + 2) - 1) // (factor -1)
    else:
        result *= (factor ** (exponent + 1) - 1) // (factor -1) * (1 + num)
    return result - self

class perfect_number:
    number = 2
    perfects = []

    @classmethod
    def load(cls):
        try:
            with open('perfect_number.json', encoding='utf-8') as file:
                save = json.load(file)
        except FileNotFoundError:
            pass
        else:
            cls.number = save['progress']
            cls.perfects = save['perfect_numbers']
            if cls.number in cls.perfects:
                cls.number += 1

    @classmethod
    def save(cls):
        with open('perfect_number.json', 'w', encoding='utf-8') as file:
            json.dump({'progress': cls.number,
                       'perfect_numbers': cls.perfects}, file)

    @classmethod
    def search(cls):
        cls.load()
        try:
            while True:
                if cls.number == factorsum(cls.number):
                    cls.perfects.append(cls.number)
                cls.number += 1
        except KeyboardInterrupt:
            pass
        finally:
            cls.save()
            print(f'Searching reaches {cls.number}')
            print('Perfect numbers found:')
            print(*cls.perfects, sep=', ')

if __name__ == '__main__':
    perfect_number.search()
