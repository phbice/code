# -*- coding: utf-8 -*-
'''
分解质因数
2020年8月3日14:39:43
彭寒冰
'''
class factoritem:
    def __init__(self, factor, exponent):
        self.factor = factor
        self.exponent = exponent

    def __str__(self):
        return f'{self.factor}^{self.exponent}' if self.exponent > 1 else f'{self.factor}'
    def __repr__(self):
        return f'({self.factor}, {self.exponent})'

class factorlist(list):
    def __str__(self):
        return ' * '.join(map(str,self))

def inputPosInt():
    while True:
        input_str = input("Input a integer ( >= 2 ): ")
        try:
            num = int(input_str)
            if num <= 1:
                raise ValueError
            return num
        except ValueError:
            print(f'{repr(input_str)} is not integer or <= 1.')

def factor(num):
    lastFactor = 0
    factors = factorlist()
    i = 2
    while i**2 <= num:
        if num % i == 0: # Find a prime factor
            if i != lastFactor: # A new factor arises
                lastFactor = i
                factors.append(factoritem(lastFactor, 1))
            else: # A repeating prime factor arises
                factors[-1].exponent += 1
            num //= i
        else:
            i += 1
    if num != lastFactor:
        factors.append(factoritem(num, 1))
    else:
        factors[-1].exponent += 1
    return factors


print(factor(inputPosInt()))
