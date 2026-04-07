#include <iostream>
#include<fstream>
#include <vector>
#include <string>

using namespace std;

void LoadDataFromFileToVector (string FilaName, vector <string> &vFileContent)
{
    fstream MyFile;
    MyFile.open(FilaName, ios::in);
    
    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

int main ()
{
    vector <string> vFileContent;

    LoadDataFromFileToVector ("MyFile.txt" , vFileContent);

    for (string &Line : vFileContent)
    {
        cout << Line << endl;
    }
    return 0;
}