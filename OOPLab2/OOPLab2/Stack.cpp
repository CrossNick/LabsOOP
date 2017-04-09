#include "stdafx.h"
#include "Stack.h"

struct Stack::Node{
	int value;
	Node *next;
	Node(int value) : value(value), next(nullptr)
	{	

	}
};

Stack::Stack()
{
	_size = 0;
	head = nullptr;
}

int Stack::size() const
{
	return _size;
}

bool Stack::isEmpty() const
{
	return head==nullptr;
}

std::string Stack::toString() const
{
	Node* tmp = head;
	string result = "";
	while (tmp != nullptr)
	{
		result.append(to_string(tmp->value));
		result.append(" ");
		tmp = tmp->next;
	}
	return result;
}

bool Stack::push(int value)
{
	try {
		if (isEmpty())
			head = new Node(value);
		else
		{
			Node* tmp = new Node(value);
			tmp->next = head;
			head = tmp;
		}
		_size++;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

int Stack::pop()
{
	if (!isEmpty())
	{
		int result = head->value;
		Node* tmp = head->next;
		delete head;
		head = tmp;
		_size--;
		return result;
	}
	return 0;
}

int Stack::peek() const
{
	if (!isEmpty())
		return head->value;
	return 0;
}


Stack::~Stack()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}
