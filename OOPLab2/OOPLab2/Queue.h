#pragma once
#include "PushPopContainer.h"
class Queue : public PushPopContainer
{
private:
	struct Node;
	Node *head;
	Node *tail;
	int _size;
public:
	Queue();
	int size() const override;
	bool isEmpty() const override;
	std::string toString() const override;
	bool push(int value) override;
	int pop() override;
	int peek() const override;
	virtual ~Queue();
};

