'''
property
'''
from numbers import Number

class Point:
    __slots__ = ('_x', '_y')
    def __init__(self, x, y):
        if isinstance(x, Number) and isinstance(y, Number):
            self._x, self._y = x, y
        else:
            raise TypeError

    @property
    def x(self):
        return self._x
    @x.setter
    def x(self, value):
        raise TypeError
    @x.deleter
    def x(self):
        raise TypeError

    @property
    def y(self):
        return self._y
    @y.setter
    def y(self, value):
        raise TypeError
    @y.deleter
    def y(self):
        raise TypeError

    def __repr__(self):
        return f'Point({self.x}, {self.y})'
    def __str__(self):
        return f'({self.x}, {self.y})'

p1 = Point(1, 3)
print(p1)
print(repr(p1))
print(p1.x, p1.y)
p1.x = 2
