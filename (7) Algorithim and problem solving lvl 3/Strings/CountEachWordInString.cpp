// Read string then count each word in that string

/*  1- find("xxx" || 'x' ) ===> find word or char in  string
    2- substr(from(int pos), to(int pos)) ===> select part of string
    3- erase(from(int pos), to(int pos))  ===>  delete part of string

*/

#include<iostream>
#include<string>
#include"StringCharLib.h"

using namespace std;

int CountEachWordInString (string String)
{
    string delim = " ";
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

int main ()
{
    string S1 = StringCharLib::ReadString();

    cout << "The number of words in your string is: " << CountEachWordInString(S1);

    system("pause>0");
}