#include<iostream>

using namespace std;

class clsCalculator 
{
private:
    float _PreviousResult = 0;
    float _LastNumber = 0;
    string _LastOperation = "";
    float _Result = 0;
public:
    void Add (float Number)
    {
        _PreviousResult = _Result;
        _LastNumber = Number;
        _LastOperation = "Adding ";
        _Result += Number;
    }
    void Subtract (float Number)
    {
        _PreviousResult = _Result;
        _LastNumber = Number;
        _LastOperation = "Subtracting ";
        _Result -= Number;
    }
    void Multiply (float Number)
    {
        _PreviousResult = _Result;
        _LastNumber = Number;
        _LastOperation = "Multiplying ";
        _Result *= Number;
    }
    void Divide (float Number)
    {
        if (Number == 0)
            Number = 1;

        _PreviousResult = _Result;
        _LastNumber = Number;
        _LastOperation = "Dividing ";
        _Result /= Number;
    }

    void Clear ()
    {
        _PreviousResult = _Result;
        _LastNumber = _PreviousResult;
        _LastOperation = "Clearing ";
        _Result = 0;
    }

    void PrintResults ()
    {
        cout << "Result After " << _LastOperation << _LastNumber << " is: " << _Result << endl;
    }

};

int main ()
{
    clsCalculator Calculator1;
    Calculator1.Add(10);
    Calculator1.PrintResults();

    Calculator1.Add(2);
    Calculator1.PrintResults();

    Calculator1.Divide(2);
    Calculator1.PrintResults();

    Calculator1.Divide(0);
    Calculator1.PrintResults();

    Calculator1.Subtract(2);
    Calculator1.PrintResults();

    Calculator1.Clear();
    Calculator1.PrintResults();

    Calculator1.Subtract(2);
    Calculator1.PrintResults();

}