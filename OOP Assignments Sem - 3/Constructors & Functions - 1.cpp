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

class Bank
{
    private:
    int principle;
    float rate;
    int time;
    public:
    Bank()
    {
        principle = 5000;
        rate = 5.0;
        time = 18;
    }
    Bank(int a, float r, int t)
    {
        a = principle;
        r = rate;
        t = time;
    }
    void getSI()
    {
        float ans = (principle*rate*time)/100;
        cout << "Principle(Rs):       " << principle << "\n";
        cout << "Rate of Interest(%): " << rate << "\n";
        cout << "Time(months):        " << time << "\n";
        cout << "Simple Interest(Rs): " << ans << "\n";
    }
};
int main()
{
    Bank B;
    B.getSI();
}
