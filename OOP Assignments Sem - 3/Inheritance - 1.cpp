// Questions
// 1(A). (Hierarchical Inheritance) a program to calculate the salary of faculty, staff using inheritance of class employee with constructors
//
// (B). (Multiple) a program to calculate the salary of FACULTY using inheritance of class EMPLOYEE , CLASS SALARY with constructors
//
// (C) Write a program using multilevel inheritance class A (member a1, get_a(), display_a() ) is inherited by Band B (member b1, get_b(), display_b ())is inherited by C.
// make object of C (member c1, get_c(), display_c()) only. Print members of A, B, C classes using object of C only.

#include<iostream>
using namespace std;

class employee
{
    public:
        float base;
        float pf;
        float houseAll;

        employee()
        {
        }
};

class staff: public employee
{
    public:
        float travel;

        staff()
        {
            cout<<"Staff class !!"<<"\n";
        }

        float sum()
        {
            cout<<"Enter your input: "<<"\n";
            cout<<"\nBase : ";
            cin>>base;
            cout<<"PF : ";
            cin>>pf;
            cout<<"House Allowance : ";
            cin>>houseAll;
            cout<<"Travel : ";
            cin>>travel;

            return (base+pf+houseAll+travel);
        }

};

class faculty : public employee
{
    public:
        float med;

        faculty()
        {
            cout<<"\nFaculty class !! "<<"\n";
        }
        float sum()
        {
            cout<<"Enter your values: ";
            cout<<"\nBase: ";
            cin>>base;
            cout<<"PF : ";
            cin>>pf;
            cout<<"House Allowance : ";
            cin>>houseAll;
            cout<<"Medical Allowance : ";
            cin>>med;

            return (base+pf+houseAll+med);
        }
};

int main()
{
    staff s1;
    float ans1=s1.sum();
    cout<<"\nSum of salary of staff : "<<ans1 << "\n";

    faculty f1;
    float ans2=f1.sum();
    cout<<"\nSum of salary of faculty : "<<ans2 << "\n";
    return 0;
}
