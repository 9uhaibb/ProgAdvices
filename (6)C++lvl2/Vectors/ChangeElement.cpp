#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector <int> Num {1, 2, 3, 4, 5};
    
    cout << "initial Vector : " ;
    for (const int & i : Num) // const = u can't change it
    {
        cout << i << " ";
    }

    cout << "\n\nupdated vector 1 : " ;
    for (int & i : Num)
    {
        i = 20;
        cout << i << " ";
    }

    cout << "\n\nupdated vector 2 : ";
    Num[0] = 19;
    Num.at(1) = 90;
    for (const int &i : Num)
    {
        cout << i << " ";
    }

    return 0 ;

}