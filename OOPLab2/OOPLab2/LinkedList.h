#pragma once
#include "PushPopContainer.h"
#include "InsertableContainer.h"
class LinkedList :
	public PushPopContainer, public InsertableContainer
{
private:
	struct Node;
	Node *head;
	Node *tail;
	int _size;
public:
	LinkedList();
	int size() const override;
	bool isEmpty() const override;
	std::string toString() const override;
	bool push(int value) override;
	int pop() override;
	int peek() const override;
	int get(int index) const override;
	int set(int index, int value) override;
	bool insertAt(int index, int value) override;
	int removeAt(int index) override;
	virtual ~LinkedList();
};

