// Question
// 1. Write a program to overload ! (not) operator (unary) AND %= (assignment) all data members of a class

#include <iostream>
using namespace std;
class simple
{
int a;
int b;
public:
void setNumber(int a, int b)
{
this->a = a;
this->b = b;
}
void display()
{
cout << "The value of a and b is :" << a << " " << b << endl;
}
void operator!()
{
this->a = !a;
this->b = !b;
}
void operator&()
{
this->a = this->a&a;
this->b = this->b&b;
}
simple operator%=(simple &obj)
{

this->a = ((obj.a) % (this->a));
this->b = ((obj.b) % (this->b));
return *this;
}
};
int main()
{
simple sim;
cout << "Enter the number a and b" << endl;
int a, b;
cin >> a >> b;
sim.setNumber(a, b);
cout << "The value before the !" << endl;
sim.display();
!sim;
cout << "The value after the !" << endl;
sim.display();
!sim;
simple sim2;
sim2.setNumber(a, b);
cout << "The value before the &" << endl;
sim2.display();
&sim;
cout << "The value after the &" << endl;
sim.display();
simple another;
int a2, b2;
cout << "Enter the values for another obj:" << endl;
cin >> a2 >> b2;
another.setNumber(a2, b2);
another %= sim;
cout << "After overloading another obj:" << endl;
another.display();
}
