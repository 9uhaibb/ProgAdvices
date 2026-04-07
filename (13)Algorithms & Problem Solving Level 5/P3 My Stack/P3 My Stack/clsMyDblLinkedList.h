#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsMyDblLinkedList
{
protected:
	int _Size = 0;
public:

	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};

public:
	Node* head = NULL;
	// Requirements
	void PrintList()
	{
		Node* Current = head;
		while (Current != NULL)
		{
			cout << Current->value << " ";
			Current = Current->next;
		}
		cout << "\n";
		delete Current;
	};

	void InsertAtBeginning(T value)
	{
		Node* NewNode = new Node();

		NewNode->value = value;
		NewNode->next = head;
		NewNode->prev = NULL;

		if (head != NULL)
		{
			head->prev = NewNode;
		}
		head = NewNode;
		_Size++;
	}

	Node* Find(T value)
	{
		Node* Current = head;

		if (head == NULL)
		{
			return NULL;
		}

		while (Current != NULL)
		{
			if (Current->value == value)
			{
				return Current;
			}
			Current = Current->next;
		}
	}

	void InsertAfter(Node* Current, T value)
	{
		Node* NewNode = new Node();

		NewNode->value = value;
		NewNode->next = Current->next;
		NewNode->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = NewNode;
		}

		Current->next = NewNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* NewNode = new Node();
		NewNode->value = value;
		NewNode->next = NULL;

		if (head == NULL)
		{
			head = NewNode;
			NewNode->prev = NULL;
		}
		else
		{
			Node* Current = head;

			while (Current->next != NULL)
			{
				Current = Current->next;
			}

			Current->next = NewNode;
			NewNode->prev = Current;
		}
		_Size++;
	}

	// we're not search for the node cuz it's given as a parameter
	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
			return;

		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{

		if (head == NULL)
		{
			return;
		}

		Node* FirstNode = head;
		head = head->next;

		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete FirstNode;
		_Size--;

	}

	void DeleteLastNode()
	{

		if (head == NULL)
		{
			return;
		}


		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}

		Node* LastNode = head;

		while (LastNode->next != NULL)
		{
			LastNode = LastNode->next;
		}
		LastNode->prev->next = NULL;
		delete LastNode;
		_Size--;

	}

	//Extension 1

	int Size()
	{
		return _Size;
	}

	//Extension 2

	bool IsEmpty()
	{
		return _Size == 0;
	}

	//Extension 3

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}

	}

	//Extension 4

	void Reverse()
	{
		Node* temp = nullptr;
		Node* Current = head;

		while (Current != nullptr)
		{
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;
			Current = Current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	//Extension 5

	Node* GetNode(int Index)
	{
		int Counter = 0;

		if (Index > _Size - 1 || Index < 0)
		{
			return NULL;
		}

		Node* Current = head;
		while (Current != NULL && (Current->next != NULL))
		{
			if (Counter == Index)
				break;

			Current = Current->next;
			Counter++;
		}
		return Current;
	}

	//Extension 6

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->value;
	}

	//Extention 7

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
		{
			return false;
		}
		else
		{
			ItemNode->value = NewValue;
			return true;
		}
	}

	//Extention 8
	bool InsertAfter(int Index, T value)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		else
			return false;
	}
};

