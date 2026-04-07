#include <iostream>
using namespace std;

//swap two entered numbers

// swap prosedure
void Swap(int &A, int &B) // i need the reffrance of A,B so they be the same as they on the main
{
    int temp;

    temp = A;
    A = B;
    B = temp;

    cout << "Numbers after swap inside prosedure : A = " << A << " B = "<< B << endl;
}
int main ()
{
    int A,B;
    cout << "Eneter A value :\n";
    cin >> A;
    cout << "Enter B value :\n";
    cin >> B;
    
    cout << "Numbers before swap : A = " << A << " B = " << B << endl;

    swap(A,B);
    cout << "Numbers after swap inside main function : A = "<<A<<" B : "<<B<<endl;
}
/*output before add & to the value in prosedure:
Eneter A value :
90
Enter B value :
50
Number before swap : A = 90 B = 50
Numbers after swap inside prosedure : A = 50 B : 90
Numbers after swap inside main function : A = 90 B : 50    <-----

output after add & to the value in prosedure:
Eneter A value :
90
Enter B value :
50
Number before swap : A = 90 B = 50
Numbers after swap inside prosedure : A = 50 B : 90
Numbers after swap inside main function : A = 50 B : 90    <-----
*/
