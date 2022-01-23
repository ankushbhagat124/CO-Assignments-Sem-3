//Question: Find greatest of three numbers using classes

#include<iostream>
using namespace std;
class Largest
{
    private:
        int x,y,z,ans;
    public:
    void input()
    {
        cout << "Enter 3 numbers:\n";
        cin >> x;
        cin >> y;
        cin >> z;
    }

    void calc()
    {
        if (x >= y)
        {
            if (x >= z)
                ans = x;
            else
                ans = z;
        }
        else
        {
            if (y >= z)
                ans = y;
            else
                ans = z;
        }
    }
    void print()
    {
        cout<<"The Largest Number among ["<<x<<","<<y<<","<<z<<"] = "<<ans<<"\n";
    }
};

int main()
{
        Largest l;
        l.input();
        l.calc();
        l.print();
        return 0;
}
