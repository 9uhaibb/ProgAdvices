#include <iostream>
#include <vector>

// iterator is accessing vector elemnt using pointer

using namespace std;

int main ()
{
    vector <int> vNum {1, 2, 3, 4, 5};

    //declear iterator
    vector <int>::iterator iter ; // this mean iter is a pointer for first element(by default) in this vector

    // use iterator using for loop
    for (vector <int>::iterator iter = vNum.begin(); iter != vNum.end() ; iter++ /*moving to next element*/ )
    {
        cout << *iter << " ";
    }

    


}