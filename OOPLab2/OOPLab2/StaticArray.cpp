#include "stdafx.h"
#include "StaticArray.h"


StaticArray::StaticArray(int sz)
{
	_size = sz;
	arr = new int[_size];
}

int StaticArray::size() const
{
	return _size;
}

bool StaticArray::isEmpty() const
{
	return _size ==0;
}

std::string StaticArray::toString() const
{
	string result = "";
	for (int i = 0; i < _size; i++)
	{
		result.append(to_string(arr[i]));
		result.append(" ");
	}
	return result;
}

int StaticArray::get(int index) const
{
	if(index<_size)
		return arr[index];
	return 0;
}

int StaticArray::set(int index, int value)
{
	if (index < _size)
		arr[index] = value;
	return value;
}


StaticArray::~StaticArray()
{
	delete[] arr;
}
