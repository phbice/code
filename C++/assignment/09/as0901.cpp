/*
 继承与多态
 
    彭寒冰
    2019-4-30 21:31
*/
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926535897932385;
//***************
// Point class
//***************
class Point
{
public:
    double x, y;
    
    Point(double ix = 0, double iy = 0):x(ix), y(iy) {}
    Point(double p[]):x(p[0]), y(p[1]) {}

    friend ostream & operator<<(ostream & os, Point p);
};

ostream & operator<<(ostream & os, Point p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}


//****************
// Shape class
//****************
class CX_Shape
{
public:
    virtual void Show(void) = 0;
    virtual float Area(void) = 0;
};

//****************
// Triangle class
//****************

class Triangle : public CX_Shape
{
private:
    Point points[3];
public:
    Triangle();
    Triangle(Point p[]);
    Triangle(double p[][2]);

    void Show();
    float Area();
};

Triangle::Triangle()
{
    points[0] = Point(0, 0);
    points[1] = Point(1, 0);
    points[2] = Point(0, 1);
}

Triangle::Triangle(Point p[])
{
    for (int i = 0; i < 3; i++)
        points[i] = p[i];
}

Triangle::Triangle(double p[][2])
{
    for (int i = 0; i < 3; i++)
        points[i] = Point(p[i]);
}

void Triangle::Show()
{
    cout << "Triangle(" << points[0] << ", " << points[1]
         << ", " << points[2] <<")";
}

float Triangle::Area()
{
    return fabs( (points[1].x - points[0].x)*(points[2].y - points[0].y) -
                 (points[1].y - points[0].y)*(points[2].x - points[0].x) ) / 2;
}


//*******************
// Rectangle class
//*******************
class Rectangle : public CX_Shape
{
private:
    Point point;
    double length, width;
public:
    Rectangle(Point p, double l, double w):point(p), length(l), width(w) {}
    void Show();
    float Area();
};

void Rectangle::Show()
{
    cout << "Rectangle(" << point << ", " << length << ", " << width << ")";
}

float Rectangle::Area()
{
    return length * width;
}


//*******************
// Square class
//*******************
class Square : public CX_Shape
{
private:
    Point point;
    double length;
public:
    Square(Point p, double l) : point(p), length(l) {}
    void Show();
    float Area();
};

void Square::Show()
{
    cout << "Square(" << point << ", " << length << ")";
}

float Square::Area()
{
    return length * length;
}

//********************
// Circle class
//********************
class Circle : public CX_Shape
{
private:
    Point point;
    double radius;
public:
    Circle(Point p, double r) : point(p), radius(r) {}
    void Show();
    float Area();
};

void Circle::Show()
{
    cout << "Circle(" << point << ", " << radius << ")";
}

float Circle::Area()
{
    return PI * radius * radius;
}

double CalcArea(CX_Shape &shape)
{
    return shape.Area();
}

int main()
{
    Point     points[3] = {Point(0, 0), Point(3, 1), Point(1, 3)};
    Triangle  triangle(points);
    Circle    circle(Point(1, 3), 3);
    Rectangle rectangle(Point(-1, 2), 3, 5);
    Square    square(Point(1, 5), 4);

    circle.Show();
    cout << endl;
    triangle.Show();
    cout << endl;
    rectangle.Show();
    cout << endl;
    square.Show();
    cout << endl;

    cout << "面积之和 = " << CalcArea(triangle) + CalcArea(circle) +
                             CalcArea(rectangle) + CalcArea(square) << endl;

    return 0;
}