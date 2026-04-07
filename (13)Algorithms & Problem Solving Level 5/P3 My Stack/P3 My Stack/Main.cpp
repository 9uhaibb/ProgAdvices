#include <iostream>
#include "clsMyDblLinkedList.h"
#include"clsMyStack.h"

using namespace std;

int main()
{
	clsMyStack <int> MyStack;

	MyStack.push(10);
	MyStack.push(20);
	MyStack.push(30);
	MyStack.push(40);
	MyStack.push(50);

	cout << "\nStack : \n";
	MyStack.print();

	cout << "\n\nSize : " << MyStack.size();
	cout << "\nTop   : " << MyStack.top();
	cout << "\nBottom: " << MyStack.bottom();

	MyStack.pop();
	cout << "\n\nStack after pop():\n";
	MyStack.print();

	//Extention 1
	cout << "\n\nItem(2) : " << MyStack.GetItem(2);

	//Extention 2
	MyStack.Reverse();
	cout << "\n\nStack after reverse():\n";
	MyStack.print();

	//Extention 3
	MyStack.UpdateItem(2, 500);
	cout << "\nStack after Update(2,500):\n";
	MyStack.print();

	//Extention 4
	MyStack.InsertAfter(2, 3000);
	cout << "\nStack after insertAfter(2,3000):\n";
	MyStack.print();

	//Extention 5
	MyStack.InsertAtBottom(80);
	cout << "\nStack after insertAtBottom(80):\n";
	MyStack.print();

	//Extention 6
	MyStack.InsertAtTop(90);
	cout << "\nStack after insertAtTop(90):\n";
	MyStack.print();

	//Extention 7
	MyStack.Clear();
	cout << "\nStack after clear():\n";
	MyStack.print();



}


