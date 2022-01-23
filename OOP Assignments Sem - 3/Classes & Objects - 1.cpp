// Problem 4(A)
// Write a program in C++ using static variable to get the sum of the salary of 10 employees
//
//
// Problem 4(B)
// Write a program to find the sum of the area of three circles using 3 objects and static variable SUMAREA/TOTALAREA . Use different constructors in the class.
// 1. Three constructors In 1st object use default constructor, in 2nd use parameterized , 3rd use copy
// 2. Find area of circle
// 3. Sum of the area TOTALAREA/SUMAREA of all three circles
// 4. Display area
// 5. Display SUMAREA/TOTALAREA

#include <iostream>
using namespace std;
class Employee
{
    static int salary;
    static int netSalary;

public:
    void setSalary(int i)
    {
        cout << "Enter the salary of " << i + 1 << " employee(in Rs): ";
        cin >> salary;
    }
    void totalSalary()
    {
        netSalary = netSalary + salary;
    }
    static void shownetSalary()
    {
        cout << "Net Salary :- Rs " << netSalary << endl;
    }
};
int Employee ::netSalary;
int Employee ::salary;
int main()
{
    Employee sal[10];
    for (int i = 0; i < 10; i++)
    {
        sal[i].setSalary(i);
        sal[i].totalSalary();
    }
    Employee ::shownetSalary();
    return 0;
}
