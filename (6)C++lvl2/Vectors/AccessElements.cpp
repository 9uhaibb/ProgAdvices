#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector <int> Num {1, 2, 3, 4, 5};

    cout << "\n usnig .at(x) \n";
    cout << "Element at index 0 : " << Num.at(0) << endl;
    cout << "Element at index 2 : " << Num.at(2) << endl;
    cout << "Element at index 4 : " << Num.at(4) << endl;

    cout << "\n\n using [x] \n";
    cout << "Element at index 0 : " << Num[0] << endl;
    cout << "Element at index 2 : " << Num[2] << endl;
    cout << "Element at index 4 : " << Num[4] << endl;

}