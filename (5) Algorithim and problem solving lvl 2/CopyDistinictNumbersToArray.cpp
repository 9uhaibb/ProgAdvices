#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void FillSource(int arrSource [100],int &SourceLength)
{
    arrSource[0] = 10 ;
    arrSource[1] = 10 ;
    arrSource[2] = 10 ;
    arrSource[3] = 50 ;
    arrSource[4] = 50 ;
    arrSource[5] = 70 ;
    arrSource[6] = 70 ;
    arrSource[7] = 70 ;
    arrSource[8] = 70 ;
    arrSource[9] = 90 ;

}

short FindNumberPositionINArray (int number,int array[100], int arrayLength)
{
    for (int i = 0; i <= arrayLength; i++)
    {
        if (number == array[i])
        {
            return i;
        }
    }
    return -1; // if u reach here, this means the number is not found.
}
bool ISNumberInArray(int number /*عنصر الفحص*/, int array[100], int arrayLength)
{
    // نفحص كل عنصر في المصفوفة
    for (int i = 0; i < arrayLength; i++)
    {
        // إذا وجدنا العنصر الذي نبحث عنه، نرجع true
        if (array[i] == number)
        {
            return true;
        }
    }
    // إذا لم نجد العنصر بعد البحث في كامل المصفوفة، نرجع false
    return false;
}

void AddElementInArray (int Number, int array [100], int &arrayLength)
{
    arrayLength++;
    array[arrayLength - 1] = Number;
}

void CopyDistinictNumbersToArra (int arrSource[100], int arrCopy [100], int SourceLength, int &CopyLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if(!ISNumberInArray(arrSource[i], arrCopy, CopyLength)) // اذا مش موجود
        {
            //CopyLength will increase in AddElement function
            AddElementInArray(arrSource[i], arrCopy, CopyLength);
        }
    }
}

void PrintArray(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

 int main ()
 {
    int arrSource[100], SourceLength = 10, arrDistinict [100], DistinictLength = 0;

    FillSource (arrSource, SourceLength);

    cout << "Array 1 Elements: \n";
    PrintArray(arrSource, SourceLength);

    CopyDistinictNumbersToArra (arrSource, arrDistinict, SourceLength, DistinictLength);

    cout << "Array 2 Distinict Numbers: \n";
    PrintArray(arrDistinict, DistinictLength);

 }