#include<iostream>
#include<fstream>

using namespace std;

/* Read Mode :
    Read The file content and print it in terminal here
    syntax : ios::in;
*/
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
// try edit the content in the file (save it) and run the prog, see the terminal
int main ()
{
    PrintFileContent ("MyFile.txt");
}