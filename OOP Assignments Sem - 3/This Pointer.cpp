// Question
// 1.
// Write a C++ program to create three
// objects for a class named pntr_obj with data members such as roll_no & name
// . Create a member function set_data() for setting the data values and print()
// member function to print which object has invoked it using ‘this’ pointer.

#include <iostream>
using namespace std;
class thispointer
{
    string name;
    int roll_no;
    int age;
    public:
    static int call;
    thispointer()
    {
        cout << "\nOBJECT " << call << " CONSTRUCTOR CALLED ";
        call++;
    }
    thispointer( string name, int roll_no, int age)
    {
        cout << "OBJECT " << call << " CONSTRUCTOR CALLED " << "\n";
        call++;
        this->name = name;
        this->roll_no = roll_no;
        this->age = age;
    }
    void set_data()
    {
        cout << "\nInput Your Details\n";
        cout << "Enter Name : ";
        cin >> this->name;
        cout << "Enter Age : ";
        cin >> this->age;
        cout << "Enter Roll Number : ";
        cin >> this->roll_no;
    }
    void print()
    {
        cout << "\nOUTPUT\n";
        cout << "Name : " << this->name << "\n";
        cout << "Age : " << this->age << "\n";
        cout << "Roll Number : " << this->roll_no << "\n";
    }
};
int thispointer::call=1;
int main()
{
    cout << "OBJECT 1 \n";
    thispointer tp1;
    tp1.set_data();
    tp1.print();
    cout << "\nOBJECT 2\n";
    thispointer tp2("ANKUSH BHAGAT", 78, 17);
    tp2.print();
    cout << "\nOBJECT 3";
    thispointer tp3;
    tp3.set_data();
    tp3.print();

    return 0;
}
