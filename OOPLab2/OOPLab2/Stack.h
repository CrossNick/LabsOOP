#pragma once
#include "PushPopContainer.h"
class Stack : public PushPopContainer
{
private:
	struct Node;
	Node *head;
	int _size;
public:
	Stack();
	int size() const override;
	bool isEmpty() const override;
	std::string toString() const override;
	bool push(int value) override;
	int pop() override;
	int peek() const override;
	virtual ~Stack();
};

