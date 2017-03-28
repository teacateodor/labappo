// LAB1c.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class character
{
private:
	char c;
	char n;
public:
	character(char C) : c(C)
	{

		//n = c + 32;
		if (c >= 65 && c <= 90) {
			n = c + 32;
		}
		else n = c - 32;

	}

	bool operator==(const character& ch1) const
	{
		return this->c == ch1.c;
	}
	friend bool operator<(const character& ch1, const character& ch2);
	friend bool operator>(const character& ch1, const character& ch2);
	friend ostream& operator<<(ostream& os, const character& ch);
};

struct cmp_struct_desc {
	bool operator() (const character & ch1, const character & ch2) const
	{
		return ch1 > ch2;
	}
};

struct cmp_struct_cresc {
	bool operator() (const character & ch1, const character & ch2) const
	{
		return ch1 < ch2;
	}
};

bool operator<(const character& ch1, const character& ch2)
{
	return ch1.c < ch2.c;
}

bool operator>(const character& ch1, const character& ch2)
{
	return ch1.c > ch2.c;
}

ostream& operator<<(ostream& os, const character& ch)
{
	os << ch.c << "{" << ch.n << "}";
	return os;
}

bool comp_desc(const character& ch1, const character& ch2)
{
	return ch1 > ch2;
}

bool comp_cresc(const character& ch1, const character& ch2)
{
	return ch1 < ch2;
}

void print_set(const multiset<character, cmp_struct_desc>* Multiset, string name)
{
	multiset<character>::iterator it;
	cout << name << " = {";
	for (it = Multiset->begin(); it != Multiset->end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << "\b\b}\n";
}

void print_set(const multiset<character, cmp_struct_cresc>* Multiset, string name)
{
	multiset<character>::iterator it;
	cout << name << " = {";
	for (it = Multiset->begin(); it != Multiset->end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << "\b\b}\n";
}

void print_Queue(queue<character>*Queue, string name)
{
	queue<character> tmp_Queue;
	cout << name << " = {";
	while (!Queue->empty())
	{
		cout << Queue->front() << ", ";
		tmp_Queue.push(Queue->front());
		Queue->pop();
	}
	cout << "}\n";

	while (!tmp_Queue.empty())
	{
		Queue->push(tmp_Queue.front());
		tmp_Queue.pop();
	}
}

int main()
{
	multiset<character, cmp_struct_desc> Multiset1;
	multiset<character>::iterator it;

	for (int i = 0; i < 5; i++)
	{
		Multiset1.insert(character('A' + i));
		Multiset1.insert(character('b' + i));

	}
	print_set(&Multiset1, "Multiset");
	cout << "Multisetul sortat descrescator:\n";
	print_set(&Multiset1, "Multiset");

	character chr = character('D');
	cout << "\nElementul " << chr;
	if (!binary_search(Multiset1.begin(), Multiset1.end(), chr, comp_desc))
		cout << " nu";
	cout << " a fost gasit in Multiset.";

	chr = character('Z');
	cout << "\nElementul " << chr;
	if (!binary_search(Multiset1.begin(), Multiset1.end(), chr, comp_desc))
		cout << " nu";
	cout << " a fost gasit in Multiset.";




	queue<character> Queue;

	for (it = Multiset1.begin(); it != Multiset1.end(); ++it)
	{
		if (*it > ('a') && *it < ('f'))
		{
			Queue.push(*it);
		}
	}

	cout << "\n\nQueue:\n";
	print_Queue(&Queue, "Queue");


	multiset<character, cmp_struct_cresc> Multiset2;

	for (it = Multiset1.begin(); it != Multiset1.end(); ++it)
	{
		Multiset2.insert(*it);
	}

	cout << "\n\nSetul sortat crescator:\n";
	print_set(&Multiset2, "Multiset");


	while (!Queue.empty())
		Queue.pop();

	for (it = Multiset2.begin(); it != Multiset2.end(); ++it)
	{
		if (*it > ('a') && *it < ('f'))
		{
			Queue.push(*it);
		}
	}

	cout << "\nQueue sortata crescator:\n";
	print_Queue(&Queue, "Queue");

	while (!Queue.empty())
	{
		Multiset2.insert(Queue.front());
		Queue.pop();
	}

	cout << "\n\nMultisetul combinat cu elementele Queue:\n";
	print_set(&Multiset2, "Multisetul2");

	int count = 0;
	for (it = Multiset2.begin(); it != Multiset2.end(); ++it)
	{
		if (*it > 'a' - 1 && *it < 'z' + 1)
		{
			count++;
		}
	}

	cout << "\nIn Queue sunt " << count << " caractere minuscule.\n";

	count = 0;
	chr = character('N');
	for (it = Multiset2.begin(); it != Multiset2.end(); ++it)
	{
		if (*it == chr)
		{
			count++;
		}
	}
	cout << "\nElementul " << chr << (count ? "" : " nu") << " a fost gasit in set.\n\n";

	cin.get();
	return 0;
}