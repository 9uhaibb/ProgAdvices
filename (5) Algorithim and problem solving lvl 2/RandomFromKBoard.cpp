#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

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

int main ()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::LowerCase) << endl;
    cout << GetRandomCharacter(enCharType::uppercase) << endl;
    cout << GetRandomCharacter(enCharType::SpecialChar) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;

}