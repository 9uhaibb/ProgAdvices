#include <iostream>
#include<vector>
#include<fstream>

using namespace std;

void SaveVectorToFile (string FileName, vector <string> vFileName)
{
    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out);

    if (MyFile.is_open())
    {
        for (string &Line : vFileName)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }

        MyFile.close();
    }
}

int main ()
{
    vector <string> vFileContent {"Ali", "Ahmad", "Mohammad"};
    SaveVectorToFile("MyFile.txt" , vFileContent);

    return 0;
}