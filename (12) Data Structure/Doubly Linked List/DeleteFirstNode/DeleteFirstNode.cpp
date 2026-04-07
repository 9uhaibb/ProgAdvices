#include <iostream>

using namespace std;

// head points to the first node
// head->next points to the next node
// head-> prev points to the previous node (NULL)

class Node
{
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int value)
{
    /*
        1-Create a new node with the desired value.
        2-Set the next pointer of the new node to the current head of the list.
        3-Set the previous pointer of the current head to the new node.
        4-Set the new node as the new head of the list.
    */

    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL)
    {
        head->prev = new_node; // was pointing to null
    }
    head = new_node;
}

void PrintNodeDetails(Node* head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}

// Print the linked list
void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

Node* FindNode(Node* head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
            return head;
        head = head->next;
    }
    return NULL;
}

void DeleteFirstNode(Node* &head)
{
    if (head == NULL) // no nodes
        return;

    Node* FirstNode = head;
    
    head = head->next;

    if (head != NULL) // +1 nodes
    {
        head->prev = NULL;
    }
    delete FirstNode;
}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);

    Node* N1 = FindNode(head, 3);

    DeleteFirstNode(head);

    cout << "\n\nLinked List Contenet after delete First Node:\n";
    PrintList(head);
    PrintListDetails(head);



    system("pause>0");

}
