#pragma once
#include <iostream>
#include<vector>
#include<string>

using namespace std;

class clsString
{
private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }
    clsString(string Value)
    {
        _Value = Value;
    }

    void setValue(string Value)
    {
        _Value = Value;
    }
    string getValue()
    {
        return _Value;
    }
    //__declspec(property(get = getValue, set = setValue)) string Value;
    ///

    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (int l = 0; l < S1.length(); l++)
        {
            if (isFirstLetter == true && S1[l] != ' ')
            {
                S1[l] = toupper(S1[l]);
            }
            isFirstLetter = (S1[l] == ' ' ? true : false);
        }
        return S1;
    }

    string UpperFirstLetterOfEachWord()
    {
        return UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord (string S1)
{
    bool isFirstLetter = true;
    for (int l = 0; l < S1.length(); l++)
    {
        if (isFirstLetter == true && S1[l] != ' ')
        {
            S1[l] = tolower(S1[l]);
        }
        isFirstLetter = (S1[l] == ' ' ? true : false);
    }
    return S1;
}

    string LowerFirstLetterOfEachWord ()
    {
        return LowerFirstLetterOfEachWord (_Value);
    }

    static string UpperAllString(string S1)
    {
        for (int i = 0; i <= S1.length(); i++)
        {
            if (islower(S1[i]))
            {
                S1[i] = toupper(S1[i]);
            }
        }
        return S1;
    }

    string UpperAllString()
    {
        return UpperAllString(_Value);
    }

    static string LowerAll(string S1)
    {
        for (int i = 0; i <= S1.length(); i++)
        {
            if (isupper(S1[i]))
            {
                S1[i] = tolower(S1[i]);
            }
        }
        return S1;
    }
    
    string LowerAll()
    {
        return LowerAll(_Value);
    }

    static string TrimLeft(string S1)
    {
        for (int i = 0; i <= S1.length(); i++) // start from the start of the string to the last position
        {
            if (S1[i] != ' ') // if i is char
            {
                return S1.substr(i, S1.length() - i); // cut from i to total string length - i
            }
            // if not char, repeat go to the next position
        }
        return "";
    }

    static string TrimRight(string S1)
    {
        for (int i = S1.length() - 1; i >= 0; i--) // strart from the last position to the start of the string
        {                                          //                      - 1 cuz the length() start from 1 not 0,
                                                   //                       we need it with 0 to use it in the loop
            if (S1[i] != ' ')                      // if i is char
            {
                return S1.substr(0, i + 1); // cut from the start of the string to i position
                //                 + 1 cuz i position itself will be deleted
                //                  thats how substr() works, so we add 1 to include i position
            }
        }
        return "";
    }

    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    string TrimLeft()
    {
        return TrimLeft(_Value);
    }
    
    string TrimRight()
    {
        return TrimRight(_Value);
    }
    
    string Trim()
    {
        return Trim(_Value);
    }

    static vector <string>  Split (string String, string Delim)
{
    vector <string> vString;

    short Position = 0;
    string sWord;

    while((Position = String.find(Delim)) != std::string::npos)
    {
        sWord = String.substr(0, Position);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        String.erase(0, Position + Delim.length());
    }

    // now there still the last word and the loop can't reach it.
    if (String != "")
    {
        vString.push_back(String); // added it to the vector
    }
    return vString;
}

    vector <string> Split (string Delim)
    {
        return Split(_Value, Delim);
    }

    static string Reverse (string StringToReverse, string Delim)
{
    vector <string> vString ;
    string ReversedString = "";

    vString = Split(StringToReverse, Delim);

    // loop on the vector(from the last element) using iterator
    // Remmember: iterator is accessing vector elemnt using pointer

    vector <string> ::iterator iter = vString.end()/*يؤشر على نقطة ما بعد العنصر الاخير*/;

    while (iter != vString.begin())
    {
        --iter;
        ReversedString += *iter + Delim;
    }

    // at the end will be additional Delim,
    // we will delete it;

    ReversedString = ReversedString.substr(0, ReversedString.length() - 1); /* 1 is the delim */

    return ReversedString;
}

    string Reverse (string Delim)
    {
        return Reverse(_Value, Delim);
    }

    static string ReplaceWords (string String, string StringToReplace, string ReplaceTo)
{
    short pos = String.find(StringToReplace);

    while (pos != std::string::npos)
    {
        String = String.replace(pos, StringToReplace.length(),ReplaceTo);

        pos = String.find(StringToReplace); // search again
    }
    return String;
}

    string ReplaceWords (string StringToReplace, string ReplaceTo)
    {
        return ReplaceWords(_Value, StringToReplace, ReplaceTo);
    }

static string RemovePunctuations (string S1)
{
    string S2 = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

string RemovePunctuations()
{
    return RemovePunctuations(_Value);
}

static bool IsVowel(char Char)
{
    Char = tolower(Char);
    return ((Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u'));
}

static void PrintVowels(string String)
{
    for (int i = 0; i < String.length(); i++)
    {
        if (IsVowel(String[i])) // tolower() inside IsVowel does not affect here in PrintVowels()
                                // cuz it's sent by value, so just effect on IsVowel()
        {
            cout << String[i] << "    ";
        }
    }
}

void PrintVowels ()
{
    return PrintVowels(_Value);
}

static void PrintEachWord (string S1)
{   
    short position = 0;
    string Delim = " ";
    string sWord;

    while ((position = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, position);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, position + Delim.length());
    }
    // the last word
    if (!S1.empty())
    {
        cout << S1 << endl;
    }
}

void PrintEachWord ()
{
    return PrintEachWord(_Value);
}

static string JoinString (vector <string> vString, string Delim)
{
    string FinalString = "" ;
    for (string &s : vString)
    {
        FinalString += s + Delim;
    }

    return FinalString.substr(0, FinalString.length()- Delim.length()) + ".";
     // return the string without the last delim
}

static string JoinString (string ArrString[],short ArrLegth, string Delim)
{
    string FinalString = "";
    for (int i = 0; i < ArrLegth /*0 to 2 inside the array*/; i++)
    {
        FinalString += ArrString[i] + Delim;
    }
    return FinalString.substr(0, FinalString.length() - Delim.length()) + ".";
}

static string InvertLetters (string S1)
{
    for (int i = 0; i <= S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            S1[i] = toupper(S1[i]);
        }
        else 
        {
            S1[i] = tolower(S1[i]);
        }
    }
    return S1;
}

string InvertLetters ()
{
    return InvertLetters(_Value);
}

static void PrintFirstLetterOfEachWord (string S1)
{
    bool isFirstLetter = true; /* true = First letter, false = Not a first letter (' ')*/

    cout << "\n First Letters of this string: \n";

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter/*true*/)
        {
            cout << S1[i] << endl;
        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
        /*if (S1[i] == ' ')
            isFirstLetter = true;
        else 
            isFirstLetter = false;*/
    }
}

void PrintFirstLetterOfEachWord()
{
    PrintFirstLetterOfEachWord(_Value);
}

private:
enum enLetterCount {SmallLetter = 0, CapitalLetter = 1, All = 2};

public:
static int CountLetters (string String, enLetterCount LetterCount)
{
    short Counter = 0;
    for (int i = 0; i < String.length(); i++)
    {
        if (LetterCount == enLetterCount::CapitalLetter && isupper(String[i]))
            ;
        {
            Counter++;
        }
        if (LetterCount == enLetterCount::SmallLetter && islower(String[i]))
        {
            Counter++;
        }
        else 
        {
            Counter++;
        }
    }
    return Counter;
}

int CountLetters (enLetterCount LetterCount)
{
    return CountLetters(_Value, LetterCount);
}

static int CountEachWord (string String, string delim)
{
    string sWord;
    int Position = 0;
    int WordCount = 0;

    while ((Position = String.find(delim)) != std::string::npos) // الموقع = اول مسافه
    {
        sWord = String.substr(0, Position); // من الصفر لحد اول مسافه
        if (sWord != "")
        {
        WordCount++;
        String.erase(0, Position + delim.length());
        }
    }
    // الكلمة الأخيرة لا تُعالج داخل الحلقة
    // لأن الحلقة تعتمد على المسافة كفاصل بين الكلمات.
    // فلا يوجد مسافه بعد اخر كلمة, فلذلك
    // يتم احتساب الكلمة الأخيرة خارج الحلقة 

    return WordCount + 1; // plus the last word

}

int CountEachWord (string delim)
{
    return CountEachWord(_Value, delim);
}



};