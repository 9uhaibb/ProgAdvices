#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int ReadPositiveNumber (string massege)
{
    int number;
    do 
    {
    cout << massege << endl;
    cin >> number;
    }while (number <= 0 || number > 26 );
    return number;
}

int RandomNumber (int From,int To)
{
    int randNumber = rand () % (To - From + 1) + From;
    return randNumber;
}

enum enCharType {LowerCase = 1, uppercase = 2, SpecialChar = 3, Digit = 4};

char GetRandomCharacter (enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::LowerCase:
        {
            return char (RandomNumber(97,122));
            break;
        }
        case enCharType::uppercase:
        {
            return char (RandomNumber(65,90));
            break;
        }
        case enCharType::SpecialChar:
        {
            return char (RandomNumber(33,47));
            break;
        }
        case enCharType::Digit:
        {
            return char (RandomNumber(48,57));
            break;
        }



    }
}

string GenerateWord (enCharType CharType , short Length)
{
    string word;
    for (int i = 1 ;i <= Length ; i++ )
    {
        word = word + GetRandomCharacter(CharType);
    } return word;
}
string GenerateKey ()
{
    string key;
    key = key + GenerateWord (enCharType::uppercase , 4) + "-";
    key = key + GenerateWord (enCharType::uppercase , 4) + "-";
    key = key + GenerateWord (enCharType::uppercase , 4) + "-";
    key = key + GenerateWord (enCharType::uppercase , 4);
    return key;
}

void FillArrayWithKeys (string array[100],int arrayLength)
{
    for (int i = 0; i <= arrayLength; i++)
    {
        array[i] = GenerateKey();
    }
}

void PrintStringArray(string arr[100], int arrayLength)
{
    cout << "\nArray Elements:\n";
    for (int i = 0; i <= arrayLength; i++)
    {
        if (i <= 9)
        {
        cout << "Array [" << i << "] : ";
        cout << arr[i] << endl;
        }
        else 
        {
        cout << "Array [" << i << "]: ";
        cout << arr[i] << endl;
        }
    }
    cout << endl;
}


int main ()
{
    string array[100]; int arrayLength = 0;
    arrayLength = ReadPositiveNumber("Enter Number Of Keys To Generate?");

    FillArrayWithKeys(array,arrayLength);

    PrintStringArray(array,arrayLength);
}