#include <iostream>
using namespace std;

class clsA 
{

public:

    static int Function1()
    {
        return 10;
    }

    int Function2()
    {
        return 20;
    }

};

int main()
{   
   
    //The following line calls static function directly via class no throught the object
    //At class level you can call only static methods and static members
    cout << clsA::Function1() <<endl;

    //static methods can also be called throught the object.
    clsA A1, A2;
    cout << A1.Function1() << endl;
    cout << A1.Function2() << endl;
    cout << A2.Function1() << endl;
   

}
/*
we can call static methods with and without object
static method can ONLY access static members
    because static methods can be calles without object,
    and non static members you cannot access them without  having an object*/