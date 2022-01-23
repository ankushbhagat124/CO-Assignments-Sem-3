// Question
// write a program to accept values from users, find sum, product, difference division of two numbers
//  (a) using 3-5 inline functions
// (b) using reference variable
// (c) using macros


/*#include <iostream>
using namespace std;
class operation
{
    int a,b,add,sub,mul;
    float div;
    public:
    void get();
    void sum();
    void difference();
    void product();
    void division();
};
inline void operation :: get()
{
    cout << "Enter Two numbers:";
    cin >> a;
    cin >> b;
}

inline void operation :: sum()
{
    add = a+b;
    cout << "Sum: " << add << "\n";
}

inline void operation :: difference()
{
    sub = a-b;
    cout << "Difference: " << sub << "\n";
}

inline void operation :: product()
{
    mul = a*b;
    cout << "Product: " << mul << "\n";
}

inline void operation ::division()
{
    div=a/b;
    cout<<"Division: "<< div <<"\n" ;
}

int main()
{
    cout << "Program using inline function\n";
    operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();

    return 0;
}*/

#include <iostream>
using namespace std;
void add(float &a, float &b)
{
    cout << "Sum: " << a+b << "\n";
}
void sub(float &a, float &b)
{
    cout << "Difference: " << a-b << "\n";
}
void mul(float &a, float &b)
{
    cout << "Product: " << a*b << "\n";
}
void division(float &a, float &b)
{
    cout << "Division: " << a/b << "\n";
}

int main ()
{
    float a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    add(a,b);
    sub(a,b);
    mul(a,b);
    division(a,b);
}

/*#include <iostream>
#define ADD(a,b) a+b
#define SUB(a,b) a-b
#define MUL(a,b) a*b
#define DIV(a,b) a/b
using namespace std;
int main ()
{
    float a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum: " << ADD(a,b) << "\n";
    cout << "Difference: " << SUB(a,b) << "\n";
    cout << "Product: " << MUL(a,b) << "\n";
    cout << "Division: " << DIV(a,b) << "\n";
}
*/

/*#include <iostream>
using namespace std;
inline void add(float a, float b)
{
    cout << "Sum: " << a+b << "\n";
}
inline void sub(float a, float b)
{
    cout << "Difference: " << a-b << "\n";
}
inline void mul(float a, float b)
{
    cout << "Product: " << a*b << "\n";
}
inline void division(float a, float b)
{
    cout << "Division: " << a/b << "\n";
}

int main ()
{
    float a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    add(a,b);
    sub(a,b);
    mul(a,b);
    division(a,b);
}*/
