#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * ReverseList (Node* head) {
    Node * prev = NULL;
    Node * next = NULL; 
    Node * current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}