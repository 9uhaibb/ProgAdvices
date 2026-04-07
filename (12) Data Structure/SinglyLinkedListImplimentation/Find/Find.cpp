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

Node * Find(Node* head, int Value)
{
    while (head != NULL)
    {
        if (head->value == Value)
            return head;

        head = head->next;
    }

    return NULL;
}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 1); 
    InsertAtBeginning(head, 2); 
    InsertAtBeginning(head, 3); 
    InsertAtBeginning(head, 4); 
    InsertAtBeginning(head, 5); 

    Node* Node1 = Find(head, 3);
    Node* Node2 = Find(head, 88);

    PrintList(head);

    if (Node1 == NULL)
        cout << "\nNode 1 not found\n";
    else
        cout << "\nNode 1 Found :)\n";

    if (Node2 == NULL)
        cout << "\nNode 2 not found\n";
    else
        cout << "\nNode 2 Found :)\n";



    system("pause>0");

}