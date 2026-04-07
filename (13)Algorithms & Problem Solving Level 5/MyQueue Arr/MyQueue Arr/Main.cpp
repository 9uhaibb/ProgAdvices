#include <iostream>
#include "clsDynamicArray.h"
#include"clsQueueArr.h"


int main()
{
	clsQueueArr <int> MyQueue;

	MyQueue.push(10);
	MyQueue.push(20);
	MyQueue.push(30);
	MyQueue.push(40);
	MyQueue.push(50);

	cout << "\nQueue : \n";
	MyQueue.print();

	MyQueue.pop();
	cout << "\n\nQueue after pop:\n";
	MyQueue.print();

	//Extention 1
	cout << "\n\nItem(2) : " << MyQueue.GetItem(2);

	//Extention 2
	MyQueue.Reverse();
	cout << "\n\nQueue after reverse:\n";
	MyQueue.print();

	//Extention 3
	MyQueue.UpdateItem(2, 500);
	cout << "\nUpdate index 2 to 500:\n";
	MyQueue.print();

	//Extention 4
	MyQueue.InsertAfter(2, 3000);
	cout << "\ninsert 3000 After index 2:\n";
	MyQueue.print();

	//Extention 5
	MyQueue.InsertAtFront(80);
	cout << "\ninsert 80 At front :\n";
	MyQueue.print();

	//Extention 6
	MyQueue.InsertAtBack(90);
	cout << "\ninsert 90 At back:\n";
	MyQueue.print();

	//Extention 7
	MyQueue.Clear();
	cout << "\nQueue after clear:\n";
	MyQueue.print();



}
