#include<iostream>
#include<vector>
#include<string>
#include<fstream>

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

void DeleteRecordFromFileUsingVector (string FileName, string Record)
{
    vector <string> vFileContent;
    fstream MyFile;

    LoadDataFromFileToVector(FileName, vFileContent);

    for (string &Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }

    SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line ;

        while (getline(MyFile, Line)) // take first line from MyFile and store it on Line
        {
            cout << Line << endl;
        }

        MyFile.close();
    }
}

int main () 
{
    cout << "\nFile content before delete : \n";
    PrintFileContent ("MyFile.txt");

    DeleteRecordFromFileUsingVector ("MyFile.txt", "Suhaib");

    cout << "\n\nFile content after delete : \n";
    PrintFileContent("MyFile.txt");



}