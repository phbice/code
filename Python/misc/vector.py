# -*- coding: utf-8 -*-
"""
Created on Thu Oct 17 19:09:49 2019

@author: hp2017
"""
import math

class vector:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def add(self, other):
        return vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def sub(self, other):
        return vector(self.x - other.x, self.y - other.y, self.z - other.z)

    def times(self, other):
        return vector(self.x * other, self.y * other, self.z * other)

    def dot(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross(self, other):
        return vector(self.y * other.z - self.z * other.y,
                      self.z * other.x - self.x * other.z,
                      self.x * other.y - self.y * other.x)

    def norm(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def __add__(self, other):
        return self.add(other)

    def __sub__(self, other):
        return self.sub(other)

    def __mul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            return self.times(other)
        elif isinstance(other, vector):
            return self.dot(other)
        else:
            raise TypeError

    def __matmul__(self, other):
        if isinstance(other, vector):
            return self.cross(other)
        else:
            raise TypeError