// LAB1a.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Persoana
{
private:
	string nume;
	string prenume;

public:

	Persoana(string nume, string prenume);
	friend bool operator<(const Persoana& ch1, const Persoana& ch2);
	friend ostream& operator<<(ostream& os, const Persoana& ch);
};

bool operator<(const Persoana& ch1, const Persoana& ch2)
{
	return ch1.nume < ch2.nume;
}

ostream& operator<<(ostream& os, const Persoana& ch)
{
	os << "<" << ch.nume << " " << ch.prenume << ">";
	return os;
}
Persoana::Persoana(string nume, string prenume)
{
	this->nume = nume;
	this->prenume = prenume;

}

void print_set(const multiset<Persoana>* mset, string name)
{
	multiset<Persoana>::iterator it;

	cout << name << " = {";
	for (it = mset->begin(); it != mset->end(); ++it)

	{
		cout << *it << ", ";
	}
	cout << "\b\b}\n";
}

void remove_after(multiset<Persoana>* mset, int count, Persoana value)
{
	multiset<Persoana>::iterator it;

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
	multiset<Persoana> multiset1;
	multiset<Persoana>::iterator it;

	Persoana p1 = Persoana("Nume1", "Prenume1");
	Persoana p2 = Persoana("Nume2", "Prenume2");
	Persoana p4 = Persoana("Nume4", "Prenume4");
	Persoana p5 = Persoana("Nume5", "Prenume5");
	Persoana p3 = Persoana("Nume3", "Prenume3");

	for (int i = 1; i <= 5; i++)
	{
		multiset1.insert(Persoana("Nume" + to_string(i), "Prenume" + to_string(i)));
	}


	cout << "Primul multiset1:\n";
	print_set(&multiset1, "multiset1");

	multiset1.erase(Persoana("Nume1", "Prenume1"));
	multiset1.erase(multiset1.begin());

	cout << "\nPrimele 2 nume si prenume sunt stersi din primul multiset.\n";
	print_set(&multiset1, "Multiset1");

	multiset1.insert(Persoana("Nume1", "Prenume1"));
	multiset1.insert(p1);

	cout << "\nNoi elemente sunt introduse in primul multiset.\n";
	print_set(&multiset1, "Multiset1");

	Persoana nume[] = { Persoana("N","P") ,Persoana("N","P") ,Persoana("N","P") ,Persoana("N","P") ,Persoana("N","P") , };

	multiset<Persoana> multiset2(nume, nume + 5);

	cout << "\nMultiset2:\n";
	print_set(&multiset2, "Multiset2");

	remove_after(&multiset1, 3, p2);
	cout << "\n3 nume si prenume dupa cel cu '' sunt sterse din primul multiset.\n";
	print_set(&multiset1, "Multiset1");

	for (it = multiset2.begin(); it != multiset2.end(); ++it)
	{
		multiset1.insert(*it);
	}
	cout << "\nElementele setului 2 sunt introduse in primul set.\n";
	print_set(&multiset1, "Set1");

	cin.get();
	return 0;
}