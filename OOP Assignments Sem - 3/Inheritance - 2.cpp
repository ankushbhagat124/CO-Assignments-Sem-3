
// Questions
// 1(A). (Hierarchical Inheritance) a program to calculate the salary of faculty, staff using inheritance of class employee with constructors
// 
// (B). (Multiple) a program to calculate the salary of FACULTY using inheritance of class EMPLOYEE , CLASS SALARY with constructors
//
// (C) Write a program using multilevel inheritance class A (member a1, get_a(), display_a() ) is inherited by Band B (member b1, get_b(), display_b ())is inherited by C.
// make object of C (member c1, get_c(), display_c()) only. Print members of A, B, C classes using object of C only.

#include <iostream>
using namespace std;
class  EMPLOYEE
{
    public:
        float base;
        float pf;
        float houseAll;

    public:
    EMPLOYEE()
    {
        base = 0;
        pf = 0;
        houseAll = 0;
    }
    void getdata()
    {
        cout << "Enter details: ";
        cout<<"\nBase : ";
        cin>>base;
        cout<<"PF : ";
        cin>>pf;
        cout<<"House Allowance : ";
        cin>>houseAll;
    }
};
class SALARY: public EMPLOYEE
{
    public:
    void sum()
    {
        cout << "Total Salary is: " << base+pf+houseAll;
    }
};
int main ()
{
    SALARY s;
    s.getdata();
    s.sum();
}
