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
    }while (number <= 0);
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

        return 'f';

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

void GenerateKeys (int number)
{
    for (int i = 1; i <= number;i++)
    {
        if (i <= 9)
        {
            cout << "Key  [" << i << "] : " << GenerateKey () << endl;
        }
        else 
        {
            cout << "Key [" << i << "] : " << GenerateKey () << endl;

        }
    }
}

int main ()
{
    GenerateKeys(ReadPositiveNumber ("Enter Number Of Keys To Generate?"));
}