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

void DeleteNode(Node* &head, int value)
{
// head  ->  1  -> 2  -> 3  -> 4  -> NULL

    if (head == NULL)
    {
        return;
    }

    Node* Current = head, * Previous = head;

    if (Current->value == value)
    {
        head = Current->next;
        delete Current;
    }

    while (Current->value != value && Current->next != NULL)
    {
        Previous = Current;
        Current = Current->next;
    }

    // when reaching here, the current is the node we're searching for
    // and the previos is the node before it

    // how to delete it? by making the prev point to the node that after the one we want to delete

    if (Current == NULL)
        return;
    Previous->next = Current->next;
    delete Current;

}

int main()
{
    Node* head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);

    PrintList(head);
    cout << endl;

    DeleteNode(head, 3);
    PrintList(head);


    system("pause>0");

}