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

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);

    Node* N1 = Find(head, 3);

    InsertAfter(N1, 800);

    PrintList(head);


    system("pause>0");

}