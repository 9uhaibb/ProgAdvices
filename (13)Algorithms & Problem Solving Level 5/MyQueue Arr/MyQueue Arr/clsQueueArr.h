#pragma once
#include <iostream>
#include "clsDynamicArray.h"

template <class T>
class clsQueueArr
{
private:
	clsDynamicArray <T> _Arr;
public:
	void print()
	{
		_Arr.PrintList();
	}
	void push(T Item)
	{
		_Arr.InsertAtEnd(Item);
	}

	void pop()
	{
		_Arr.DeleteFirstItem();
	}

	int size()
	{
		return _Arr.Size();
	}

	bool IsEmpty()
	{
		return _Arr.IsEmpty();
	}

	T front()
	{
		return _Arr.GetItem(0);
	}

	T back()
	{
		return _Arr.GetItem(size() - 1);
	}

	T GetItem(int Index)
	{
		return _Arr.GetItem(Index);
	}

	void Reverse()
	{
		_Arr.Reverse();
	}

	bool UpdateItem(int Index, T value)
	{
		return _Arr.SetItem(Index, value);
	}

	void InsertAfter(int Index, T value)
	{
		_Arr.InsertAfter(Index, value);
	}

	void InsertAtFront(T value)
	{
		_Arr.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_Arr.InsertAtEnd(value);
	}

	void Clear()
	{
		_Arr.Clear();
	}
};
