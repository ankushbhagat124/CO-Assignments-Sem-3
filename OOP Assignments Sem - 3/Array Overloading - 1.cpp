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
class Search
{
    private:
    int n;
    int arr[100];
    public:
    void input()
    {
        cout << "Enter size of the array: ";
        cin >> n;
        cout << "Enter your array: ";
        for (int i = 0; i < n; i++)
        cin >> arr[i];
    }
    void search(int x)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                cout << "Number present at position: " << i+1;
                flag = true;
                break;
            }
        }
        if (flag == false)
        cout << "Number is absent!";
    }
};
int main ()
{
    Search s;
    s.input();
    int x;
    cout << "Enter no to be searched: ";
    cin >> x;
    s.search(x);
}
