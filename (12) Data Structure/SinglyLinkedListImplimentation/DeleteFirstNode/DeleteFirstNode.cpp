#include <iostream>
using namespace std;

// head      : point to first node
// head.next : point to second node

class Node
{
public:
    int value;
    Node* next;
};

void PrintList(Node* head)

{
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

void InsertAtEnd(Node*& head, int Value)
{
    Node* New_Node = new Node();

    New_Node->value = Value;
    New_Node->next = NULL;

    if (head == NULL)
    {
        head = New_Node;
        return;
    }

    // assume the last node is the head
    Node* Last_Node = head;

    while (Last_Node->next != NULL)
    {
        Last_Node = Last_Node->next; // try Last_Node = head.next;
    }

    // when reaches here, then last node is really the last node
    Last_Node->next = New_Node;
    return;

}

void DeleteFirstNode(Node*& head)
{
 
    // ننشئ نود جديدة مساوية للهيدر لكي تؤشر على اول نود
    // نحرك او نغير الهيدر ليؤشر على النود التاليه
    // نحذف اول نود

    if (head == NULL) // if head -> NULL
        return;

    Node* Current = head; // (head = Current)
                          //        ↓
                          //        1  -> 2 -> 3...

    head = Current->next;  // Current -> 1  ,  head -> 2 -> 3 ...

    delete Current; 

    return;
}

void DeleteLastNode(Node*& head)
{
    if (head == NULL)
    {
        return;
    }

    Node* Current = head, * Prev = head;

    if (Current->next == NULL)
    {
        head = NULL;
        delete Current;
    }

    while (Current != NULL && Current->next != NULL)
    {
        Prev = Current;
        Current = Current->next;
    }

    Prev->next = NULL;
    delete Current;
}

int main()
{
    Node* head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);

    cout << "\nList:\n";
    PrintList(head);
    cout << endl;

    cout << "\nDel First:\n";
    DeleteFirstNode(head);
    PrintList(head);

    cout << "\nDel Last:\n";
    DeleteLastNode(head);
    PrintList(head);




    system("pause>0");

}