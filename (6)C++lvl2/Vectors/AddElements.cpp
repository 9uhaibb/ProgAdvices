#include<iostream> 
#include<vector> 
using namespace std; 

vector <int> ReadNumbers ()
{
    vector <int> vNumbers;
    int Number ;
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y')
    {
        cout << "Enter a number ? ";
        cin >> Number;

        vNumbers.push_back(Number);

        cout << "Do you want to add more? ";
        cin >> choice;
    }

    return vNumbers;
}

void PrintIntvNumbers (vector <int> & vNumbers)
{
    for (int& N : vNumbers)
    {
        cout << N << " ";
    }
}

int main ()
{
    vector <int> vNumbers = ReadNumbers();
    PrintIntvNumbers(vNumbers);
}
