#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    clsDblLinkedList <int> MyDblLinkedList;

    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Values after Insert Nodes are:\n";
    MyDblLinkedList.PrintList();

    cout << "\nList Size : " << MyDblLinkedList.Size() << endl;


}
