#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;
};

void InsertAtBeginning(Node*& head, int value)
{

    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = head;

    head = new_node;

}

void PrintList(Node* head)

{
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

Node* Find(Node* head, int Value)
{
    while (head != NULL)
    {
        if (head->value == Value)
            return head;

        head = head->next;
    }

    return NULL;
}

void InsertAfter(Node* prev_node, int newValue)
{
    if (prev_node == NULL)
    {
        cout << "\nthe given Previous Node cannot be null\n";
        return;
    }

    Node* new_node = new Node();

    new_node->value = newValue;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
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

int main()
{
    Node* head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);

    PrintList(head);


    system("pause>0");

}