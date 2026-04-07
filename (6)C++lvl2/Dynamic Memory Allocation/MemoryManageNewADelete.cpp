#include<iostream>
using namespace std;

int main ()
{
    // declear int & float pointers
    int *iPtrX;
    float *fPtrY;

    // dynamicly allocate memory 
    iPtrX = new int;
    fPtrY = new float;

    // adding values to these addresses
    *iPtrX = 50;
    *fPtrY = 84.9;

    cout << *iPtrX << endl;
    cout << *fPtrY << endl;

    // deallocate the memory

    delete iPtrX;
    delete fPtrY;
    // or : delete iPtrX, fPtry;



}