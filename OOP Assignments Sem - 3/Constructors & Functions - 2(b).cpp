// Question
// 1. Calculate the interest of bank on principle , rate of interest can be 4% to 10%, time can be a few months to 5 years. Use constructor overloading, default values with 3 type of constructors where constructor will provide one or all values like principle, ROI, time and destructors.
//
//
// 2. Write a program using
// a. natural function as friend
// b. member function as friend
// to calculate the sum of two complex numbers by using a class complex

#include <iostream>
using namespace std;
class Complex;
class A
{
    public:
    void Sum(Complex);
};
class Complex
{
    private:
    int a1,a2;
    int b1,b2;
    public:
    void set(int x1, int x2, int y1, int y2)
    {
        a1 = x1;
        a2 = x2;
        b1 = y1;
        b2 = y2;
    }
    friend void A::Sum(Complex);
};
void A::Sum(Complex c)
{
    int ans1 = c.a1 + c.b1;
    int ans2 = c.a2 + c.b2;
    cout << "First Complex no:  " << c.a1 << " + i" << c.a2 << "\n";
    cout << "Second Complex no: " << c.b1 << " + i" << c.b2 << "\n";
    cout << "Sum: " << ans1 << " + i" << ans2;
}

int main ()
{
    int x1, y1, x2, y2;
    Complex c;
    A a;
    cout << "Enter real part of 1st complex number: ";
    cin >> x1;
    cout << "Enter imaginary part of 1st complex number: ";
    cin >> x2;
    cout << "Enter real part of 2nd complex number: ";
    cin >> y1;
    cout << "Enter imginary part of 2nd complex number: ";
    cin >> y2;
    c.set(x1,x2,y1,y2);
    a.Sum(c);
}
