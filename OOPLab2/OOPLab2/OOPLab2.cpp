// OOPLab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>

int main()
{
	const int n = 10;
	vector<PushPopContainer*> arr1({ new Stack(), new Queue(), new LinkedList() });
	vector<IndexedContainer*> arr2({new StaticArray(n)});
	vector<Deque*> arr3({ new LinkedDeque()});
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr1.size(); j++)
			arr1[j]->push(i);
		for (int j = 0; j < arr2.size(); j++)
			arr2[j]->set(i,i);
		for (int j = 0; j < arr3.size(); j++)
		{
			arr3[j]->pushBack(i);
			arr3[j]->pushFront(i);
		}
	}
	for (int j = 0; j < arr1.size(); j++)
		cout << arr1[j]->toString() << endl;
	for (int j = 0; j < arr2.size(); j++)
		cout << arr2[j]->toString() << endl;
	for (int j = 0; j < arr3.size(); j++)
		cout << arr3[j]->toString() << endl;

	system("pause");
    return 0;
}

