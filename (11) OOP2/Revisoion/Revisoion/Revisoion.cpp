
#include <iostream>

using namespace std;

void PrintNumbers(int from, int to)
{
    if (from <= to)
    {
        cout << from << endl;
        PrintNumbers(from + 1, to);
    }
}

void PrintNumbers2(int from, int to)
{
    if (from >= to)
    {
        cout << from << endl;
        PrintNumbers2(from - 1, to);
    }
}

int MyPower(int number, int power)
{
    
    if (power == 0)
        return 1;
    else
        return number * (MyPower(number, power - 1));
}
////////////////////////////////////////////////////////////

struct stEmplyee
{
    string Name;
    float Salary;
};
int main()
{
    //PrintNumbers2(10, 5);
    cout << MyPower(2, 3);
    
    stEmplyee Employee1, * ptr;

    Employee1.Name = "Mohammed Abu-Hadhoud";
    Employee1.Salary = 5000;

    cout << Employee1.Name << endl;
    cout << Employee1.Salary << endl;

    ptr = &Employee1;

    cout << "\nUsing Pointer:\n";
    cout << ptr->Name << endl;
    cout << ptr->Salary << endl;

    //cout << *ptr->Name << endl; wrong

    return 0;
}
