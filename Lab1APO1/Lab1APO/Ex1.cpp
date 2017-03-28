// LAB1a.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

void print_set(const multiset<char>* mset, string name)
{
	multiset<char>::iterator it;

	cout << name << " = {";
	for (it = mset->begin(); it != mset->end(); ++it)

	{
		cout << *it << ", ";
	}
	cout << "\b\b}\n";
}

void remove_after(multiset<char>* mset, int count, int value)
{
	multiset<char>::iterator it;

	it = mset->find(value);
	if (it == mset->end())
		return;

	for (int i = 0; i<count && it != mset->end(); i++)
	{
		mset->erase(it++);
	}
}

int main()
{
	multiset<char> multiset1;
	multiset<char>::iterator it;
	for (int i = 'a'; i <= 'f'; i++)
	{
		multiset1.insert(multiset1.begin(), i);
	}
	cout << "Primul multiset1:\n";
	print_set(&multiset1, "Multisetet1");

	multiset1.erase('d');
	multiset1.erase(multiset1.begin());

	cout << "\nElementul d si primul sunt stersi din primul multiset.\n";
	print_set(&multiset1, "Multiset1");

	multiset1.insert('D');
	multiset1.insert('B');
	cout << "\nNoi elemente sunt introduse in primul set.\n";
	print_set(&multiset1, "Set1");

	char numbers[] = { 'A','B','C','D','E' };

	multiset<char> multiset2(numbers, numbers + 5);

	cout << "\nMultiset2:\n";
	print_set(&multiset2, "Set2");

	remove_after(&multiset1, 3, 'c');
	cout << "\n3 elemente dupa 'c' sunt sterse din primul multiset.\n";
	print_set(&multiset1, "Set1");

	for (it = multiset2.begin(); it != multiset2.end(); ++it)
	{
		multiset1.insert(*it);
	}
	cout << "\nElementele multisetului 2 sunt introduse in primul multiset.\n";
	print_set(&multiset1, "Multiset1");

	cin.get();
	return 0;
}