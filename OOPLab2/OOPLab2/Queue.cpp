#include "stdafx.h"
#include "Queue.h"

struct Queue::Node {
	int value;
	Node *next;
	Node(int value) : value(value), next(nullptr)
	{

	}
};

Queue::Queue()
{
	_size = 0;
	head = tail = nullptr;
}

int Queue::size() const
{
	return _size;
}

bool Queue::isEmpty() const
{
	return head == nullptr;
}

std::string Queue::toString() const
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

bool Queue::push(int value)
{
	try {
		if (isEmpty())
			head = tail =  new Node(value);
		else
		{
			tail->next = new Node(value);
			tail = tail->next;
		}
		_size++;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

int Queue::pop()
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

int Queue::peek() const
{
	if (!isEmpty())
		return head->value;
	return 0;
}


Queue::~Queue()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}
