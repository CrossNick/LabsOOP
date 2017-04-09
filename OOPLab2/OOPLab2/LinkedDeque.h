#pragma once
#include "Deque.h"
class LinkedDeque : public Deque
{
private:
	struct Node;
	Node* head;
	Node* tail;
	int _size;
public:
	LinkedDeque();
	int size() const override;
	bool isEmpty() const override;
	std::string toString() const override;
	bool pushFront(int value) override;
	bool pushBack(int value) override;
	int popFront() override;
	int popBack() override;
	int peekFront() const override;
	int peekBack() const override;
	virtual ~LinkedDeque();
};

