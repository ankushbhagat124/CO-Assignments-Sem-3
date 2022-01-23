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
#define pi 3.14
using namespace std;
class Area
{
    static float SUMAREA;
    float r;
    float area;

    public:
    Area()
    {
        cout << "Enter radius for first circle: " << endl;
        cin >> r;
        area = pi * r * r;
        cout << "Area of first circle: " << area << endl;
        SUMAREA = SUMAREA + area;
    }
    Area(float r)
    {
        this->r = r;
        area = pi * this->r * this->r;
        cout << "Area of second circle: " << area << endl;
        SUMAREA = SUMAREA + area;
    }
    Area(Area &A)
    {
        int x = A.r;
        area = pi * x * x;
        cout << "Area of third circle: " << area << endl;
        SUMAREA = SUMAREA + area;
    }
    static void netarea()
    {
        cout << "Total area(sq m): " << SUMAREA << endl;
    }
    ~Area()
    {
    }
};
float Area ::SUMAREA;
int main()
{
    int b;
    Area a1;
    cout << "Enter radius of 2nd cirlce: " << endl;
    cin >> b;
    Area a2(b), a3(a2);
    Area ::netarea();
    return 0;
}
