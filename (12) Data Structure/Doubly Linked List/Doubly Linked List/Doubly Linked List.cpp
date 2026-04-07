#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;
};

int main ()
{
	Node* head;

	Node* Node1 = NULL;
	Node* Node2 = NULL;
	Node* Node3 = NULL;

	Node1 = new Node();
	Node2 = new Node();
	Node3 = new Node();

	Node1->value = 1;
	Node2->value = 2;
	Node3->value = 3;

	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = NULL;

	Node1->prev = NULL;
	Node2->prev = Node1;
	Node3->prev = Node2;

	head = Node1;

	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}

	cout << endl << endl;

	Node* front;
	front = Node3;

	while (front != NULL)
	{
		cout << front->value << " ";
		front = front->prev;
	}




}