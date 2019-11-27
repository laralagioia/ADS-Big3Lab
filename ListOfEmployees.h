#pragma once
#ifndef LISTOFEMPLOYEES_H
#define LISTOFEMPLOYEES_H
#include <iostream>
using namespace std;
#include "Employee.h"
#include "NodeOfEmp.h"

class ListOfEmployees {
	friend ostream& operator <<(ostream& out, ListOfEmployees& l);
public:
	ListOfEmployees();
	ListOfEmployees(ListOfEmployees& rhs);
	~ListOfEmployees();
	void insertAtFront(string n, double s);
	void insertAtEnd(string n, double s);
	void deleteAtFront();
	void deleteAtEnd();
	void remove(int pos);
	void remove(string name);
	void insert(int pos, string n, double s);
	double getSalary(string n);
	ostream& display(ostream&) const;
	ListOfEmployees& operator =(ListOfEmployees& rhs);

private:
	NodeOfEmp* head;
};

#endif // !LISTOFEMPLOYEES_H
