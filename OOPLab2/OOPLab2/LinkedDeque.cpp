#include "stdafx.h"
#include "LinkedDeque.h"

struct LinkedDeque::Node {
	int value;
	Node *next;
	Node *prev;
	Node(int value) : value(value), next(nullptr), prev(nullptr)
	{
	}
};

LinkedDeque::LinkedDeque():_size(0), head(nullptr), tail(nullptr)
{
}

int LinkedDeque::size() const
{
	return _size;
}

bool LinkedDeque::isEmpty() const
{
	return _size == 0;
}

std::string LinkedDeque::toString() const
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

bool LinkedDeque::pushFront(int value)
{
	if (isEmpty())
	{
		head = tail = new Node(value);
		_size++;
		return true;
	}
	else
	{
		head->prev = new Node(value);
		Node *tmp = head;
		head = head->prev;
		head->next = tmp;
		_size++;
		return true;
	}
	return false;
}

bool LinkedDeque::pushBack(int value)
{
	if (isEmpty())
	{
		head = tail = new Node(value);
		_size++;
		return true;
	}
	else
	{
		tail->next = new Node(value);
		Node *tmp = tail;
		tail = tail->next;
		tail->prev = tmp;
		_size++;
		return true;
	}
	return false;
}

int LinkedDeque::popFront()
{
	int result = head->value;
	Node* tmp = head->next;
	delete head;
	head = tmp;
	_size--;
	return result;
}

int LinkedDeque::popBack()
{
	int result = tail->value;
	Node* tmp = tail->prev;
	delete tail;
	tail = tmp;
	_size--;
	return result;
}

int LinkedDeque::peekFront() const
{
	return head->value;
}

int LinkedDeque::peekBack() const
{
	return tail->value;
}


LinkedDeque::~LinkedDeque()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}
