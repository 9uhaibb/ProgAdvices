#include <iostream>
#include<string>
using namespace std;

string ReadText (string massege)
{
    string Text ="";
    cout << massege << endl;
    getline(cin,Text);
    return Text;
}

string EncryptText (string Text,const short EncryptKey)
{
    for (int i = 0; i <= Text.length (); i++)
    {
        Text[i] = char((int)Text[i] + EncryptKey);
        // حول النص لمصفوفة طولها بطول النص, وحوله لارقام عشان تجمعله 2 او اي رقم
    }
    return Text;
}

string DecryptText (string Text,const short EncryptKey)
{
        for (int i = 0; i <= Text.length (); i++)
    {
        Text[i] = char((int)Text[i] - EncryptKey);
        // حول النص لمصفوفة طولها بطول النص, وحوله لارقام عشان تطرحله 2 او اي رقم
    }
    return Text;
}

int main ()
{
    const short EncryptKey = 2;

    string Text = ReadText ("Enter a Text?");
    string TextAfterEncryption = EncryptText (Text,EncryptKey);
    string TextAfterDecryption = DecryptText (TextAfterEncryption,EncryptKey);

    cout << "Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption  : " << TextAfterEncryption << endl;
    cout << "Text After Decryption  : " << TextAfterDecryption << endl;

}