#pragma once
#include "Container.h"
class IndexedContainer :
	public Container
{
public:
	virtual int get(int index) const =0;
	virtual int set(int index, int value) =0;
	virtual ~IndexedContainer()=0{}
};

