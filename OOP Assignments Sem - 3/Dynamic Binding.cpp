// Question
// 1. Write a program to find square and cube of a number using
// (write functions for getdata, show data, show result)
// late/dynamic binding using base pointer. Create base class shape and inherit it in square and cube.

#include <iostream>
using namespace std;
class base
{
public:
    virtual void getdata() = 0;
    virtual void showdata() = 0;
    virtual void showresult() = 0;
};
class power : public base
{
    int n, res;

public:
    void getdata()
    {
        cout << "\nEnter a number : ";
        cin >> n;
    }
    void showdata()
    {
        cout << "The number for which the square and cube have to be found is: " << n << endl;
    }
    int getSquare()
    {
        res = n * n;
        return res;
    }
    int getCube()
    {
        res = n * n * n;
        return res;
    }
    void showresult()
    {
        cout << "\nSquare of " << n << " is equal to : " << getSquare() << endl;
        cout << "\nCube of " << n << " is equal to : " << getCube() << endl;
    }
};
int main()
{
    base *obj = new power;
    obj->getdata();
    cout<<endl;
    obj->showdata();
    cout<<endl;
    obj->showresult();
    return 0;
}
