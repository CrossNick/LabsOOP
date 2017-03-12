// OOPLab1_5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include "Triangle.h"

void showMenu()
{
	
	cout << "1. Get all angles\n";
	cout << "2. Get all sides\n";
	cout << "3. Resize base\n";
	cout << "4. Get all medians\n";
	cout << "5. Check for similarity\n";
	cout << "6. Exit\n";
	cout << "Select action:";
}

void PerformAction(const int choose, vector<Triangle>&v)
{
	int i;
	try {
		switch (choose)
		{
		case 1:
			cout << "Select triangle: ";
			cin >> i;
			cout << "A: " << v[i].GetAngleA() << " B: " << v[i].GetAngleB() << " C: " << v[i].GetAngleC() << "\n";
			break;
		case 2:
			cout << "Select triangle: ";
			cin >> i;
			cout << "Base: " << v[i].GetBase() << " A: " << v[i].GetSideA() << " B: " << v[i].GetSideB() << "\n";
			break;
		case 3:
			float newSize;
			cout << "Select triangle: ";
			cin >> i;
			cout << "Input new size: ";
			cin >> newSize;
			v[i].SetBase(newSize);
			break;
		case 4:
			cout << "Select triangle: ";
			cin >> i;
			cout << "Median A: " << v[i].GetMedianA() << " Median B: " << v[i].GetMedianB() << " Median Base: " << v[i].GetMedianBase() << "\n";
			break;
		case 5:
			int j;
			cout << "Select two triangle to check: ";
			cin >> i >> j;
			if (v[i].IsSimilarTo(v[j]))
				cout << "Triangles are similar\n";
			else
				cout << "Triangles are not similar\n";
			break;
		default:
			break;
		}
	}
	catch (exception ex)
	{
		throw ex;
	}
		
}
int main()
{
	vector<Triangle> v;
	Triangle::initVector(v, 5);
	int choose;
	do
	{
		system("cls");
		showMenu();
		cin >> choose;
		try
		{
			PerformAction(choose, v);
		}
		catch (exception ex)
		{
			cout << ex.what();
		}
		system("pause");
		
	} while (choose != 6);

	system("pause");
    return 0;
}

