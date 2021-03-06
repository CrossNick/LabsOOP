#include "stdafx.h"
#include "LinkedList.h"


struct LinkedList::Node {
	int value;
	Node *next;
	Node(int value) : value(value), next(nullptr)
	{

	}
};

LinkedList::LinkedList()
{
	_size = 0;
	head = tail = nullptr;
}

int LinkedList::size() const
{
	return _size;
}

bool LinkedList::isEmpty() const
{
	return head == nullptr;
}

std::string LinkedList::toString() const
{
	Node* tmp = tail;
	string result = "";
	while (tmp != nullptr)
	{
		result.append(to_string(tmp->value));
		result.append(" ");
		tmp = tmp->next;
	}
	return result;
}

bool LinkedList::push(int value)
{
	try {
		if (isEmpty())
			head = tail = new Node(value);
		else
		{
			Node* tmp = new Node(value);
			tmp->next = tail;
			tail = tmp;
		}
		_size++;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

int LinkedList::pop()
{
	if (!isEmpty())
	{
		int result = tail->value;
		Node* tmp = tail->next;
		delete tail;
		tail = tmp;
		_size--;
		return result;
	}
	return 0;
}

int LinkedList::peek() const
{
	if (!isEmpty())
		return tail->value;
	return 0;
}

int LinkedList::get(int index) const
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp = tail;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		return tmp->value;
	}
	return 0;
}

int LinkedList::set(int index, int value)
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp = tail;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		tmp->value = value;
		return value;
	}
	return 0;
}

bool LinkedList::insertAt(int index, int value)
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp = tail;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		Node *nd = new Node(value);
		nd->next = tmp->next;
		tmp->next = nd;
		_size++;
		return true;
	}
	return false;
}

int LinkedList::removeAt(int index)
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp;
		if (index == 1)
		{
			tmp = tail->next;
			delete tail;
			tail = tmp;
			_size--;
			return true;
		}
		tmp = tail;
		for (int i = 0; i < index-1; i++)
		{
			tmp = tmp->next;
		}
		int result = tmp->value;
		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		return result;
	}
	return 0;
}


LinkedList::~LinkedList()
{
	Node* tmp = tail;
	while (tmp != nullptr)
	{
		tail = tmp->next;
		delete tmp;
		tmp = tail;
	}
}