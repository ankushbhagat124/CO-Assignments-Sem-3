// Questions
// 1. Write a class which creates an array and search a number in that array
//
//
// 2.Function Overloading- write a program to find the area of different shapes with one or two arguments
// -type int or long or float or double or short or unsigned .
// -write at least 5 overloading functions for 5-6 shapes
// -Each func should print input, shape, output
// -then - Also include a function with default value in function overloading
// - Call these functions with at least 10 different combinations of arguments

#include <iostream>
using namespace std;
void area(int a)
{
    cout << "Area of Square with Int data type: " << a*a;
}
void area(float a)
{
    cout << "Area of Square with float data type: " << a*a;
}
void area(double a)
{
    cout << "Area of Square with double data type: " << a*a;
}
void area(int a, int b)
{
    cout << "Area of Rectangle with Int data type: " << a*b;
}
void area(double a, double b)
{
    cout << "Area of Rectangle with double data type: " << a*b;
}
void area(float a, float b)
{
    cout << "Area of Rectangle with float data type: " << a*b;
}
void area(long a)
{
    cout << "Area of Circle with long data type: " << 3.14*a*a;
}
void area(short a)
{
    cout << "Area of Circle with short data type: " << 3.14*a*a;
}
void area(short a, short b)
{
    cout << "Area of Triangle with short data type: " << 0.5*a*b;
}
void area(long a, long b)
{
    cout << "Area of Triangle with short data type: " << 0.5*a*b;
}
int main()
{
    double a, b;
    cin >> a >> b;
    area(a,b);
    cout << "\n";
    area((float)a, (float)b);
    cout << "\n";
    area((long)a, (long)b);
    cout << "\n";
    area((float)12, (float)3);
    cout << "\n";
    area((long)a, (long)b);
    cout << "\n";
    area((short)a, (short)b);
    cout << "\n";
    area((int)12, (int)3);
    cout << "\n";
    area((int)a);
    cout << "\n";
    area(12);
}
