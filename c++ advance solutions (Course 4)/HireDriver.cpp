#include <iostream>
using namespace std;

struct stInfo {
    int age;
    bool HasDriverLicesne;
    bool HasRecommendation;
};

stInfo ReadInfo () 
{
    stInfo info;
    cout << "Enter your age : "; cin >> info.age ;
    cout << "do u have a hire driver ? (0-1) "; cin >> info.HasDriverLicesne;
    cout << "do u have a recommendation ? (0-1) "; cin >> info.HasRecommendation;

    return info;
}

bool IsAccepted(stInfo info)
{
    if (info.HasRecommendation == true)
        return true;
    else
        return (info.age > 21 && info.HasDriverLicesne);
}

void PrintResult (stInfo info)
{
    if(IsAccepted(info))
        cout << "\n Hired" << endl;
    else
        cout << "\n Rejected" << endl;
}

int main () {
    PrintResult(ReadInfo());
    return 0;
}