#include <iostream>
#include<vector>

using namespace std;



int main()
{
    int ArrNumbers [5] = {1, 2, 3, 4 ,5};
    for (int n : ArrNumbers)
    {
        cout << n << endl;
    }
    for (int n : {1, 2, 3, 4 ,5})
    {
        cout << n << endl;
    }

    vector <string> vString = {"Ahmad", "Mohammad", "Ali", "Salamah" ,"Suhaib"};
    for (string n : vString)
    {
        cout << n << endl;
    }


}