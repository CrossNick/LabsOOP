#pragma once
#include "IndexedContainer.h"
class StaticArray : public IndexedContainer
{
private:
	int* arr;
	int _size;
public:
	StaticArray(int sz);
	int size() const override;
	bool isEmpty() const override;
	virtual std::string toString() const override;
	int get(int index) const override;
	int set(int index, int value) override;
	virtual ~StaticArray();
};

