//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
    clsMyString S1;

    cout << "\nS1 = " << S1.Value;

    S1.Value= "Suhaib";
    cout << "\nS1 = " << S1.Value;

    S1.Value = "Suhaib 2";
    cout << "\nS1 = " << S1.Value;

    S1.Value = "Suhaib 3";
    cout << "\nS1 = " << S1.Value;

    S1.Value = "Suhaib 4";
    cout << "\nS1 = " << S1.Value;


    cout << "\n\nUndo\n";
    cout << "_______________";

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value;

    cout << "\n\nRedo\n";
    cout << "_______________";

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value;





    system("pause>0");

}