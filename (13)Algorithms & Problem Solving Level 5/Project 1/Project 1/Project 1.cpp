#include <iostream>
#include "clsDblLinkedList.h"
#include"clsMyQueue.h"

using namespace std;

int main()
{
	clsMyQueue <int> MyQueue;

	MyQueue.push(10);
	MyQueue.push(20);
	MyQueue.push(30);
	MyQueue.push(40);
	MyQueue.push(50);

	cout << "\nQueue : \n";
	MyQueue.print();

	MyQueue.pop();
	cout << "\n\nQueue after pop():\n";
	MyQueue.print();

	//Extention 1
	cout << "\n\nItem(2) : " << MyQueue.GetItem(2);

	//Extention 2
	MyQueue.Reverse();
	cout << "\n\nQueue after reverse():\n";
	MyQueue.print();

	//Extention 3
	MyQueue.UpdateItem(2, 500);
	cout << "\nQueue after Update(2,500):\n";
	MyQueue.print();

	//Extention 4
	MyQueue.InsertAfter(2, 3000);
	cout << "\nQueue after insertAfter(2,3000):\n";
	MyQueue.print();

	//Extention 5
	MyQueue.InsertAtFront(80);
	cout << "\nQueue after insertAtFront(80):\n";
	MyQueue.print();

	//Extention 6
	MyQueue.InsertAtBack(90);
	cout << "\nQueue after insertAtback(90):\n";
	MyQueue.print();

	//Extention 7
	MyQueue.Clear();
	cout << "\nQueue after clear():\n";
	MyQueue.print();



}
