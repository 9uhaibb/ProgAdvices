#include <iostream>
using namespace std;

// The goal is to add node at the begining of the linked list

// Create a node
class Node
{
public:
    int value;
    Node* next;
};

void InsertAtBeginning(Node*& head, int value)
{

    // Allocate memory to a node
    Node* new_node = new Node();

    // insert the data
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;

}

// Print the linked list
void PrintList(Node* head)

{
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    
    InsertAtBeginning(head, 1); // new_node->value = 1, new_node->next = NULL, head = point to 1
    InsertAtBeginning(head, 2); // new_node->value = 2, new_node->next = point to 1, head = point to 2
    InsertAtBeginning(head, 3); // new_node->value = 3, new_node->next = point to 2, head = point to 3
    InsertAtBeginning(head, 4); // new_node->value = 4, new_node->next = point to 3, head = point to 4
    InsertAtBeginning(head, 5); // new_node->value = 5, new_node->next = point to 4, head = point to 5

    PrintList(head);

    system("pause>0");

}