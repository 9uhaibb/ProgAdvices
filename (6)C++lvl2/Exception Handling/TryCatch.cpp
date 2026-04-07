#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // if the prog crach, put the code inside the try scope
    // try catch slow down the prog, so just use it when needed.

    vector <int> Num {1, 3, 4, 2};

    try
    {
        cout << Num.at(5) << endl; // the prog should crach here but u use try catch
    }
    catch(...)
    {
        cout << "out of bound.\n";
    }
    
}
