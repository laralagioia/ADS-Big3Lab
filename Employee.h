#pragma once
#ifndef  EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee {
	friend class ListOfEmployees;
public:
	Employee();
	Employee(string n, double s); 

private:
	string name;
	double salary = 0;
};
#endif // ! EMPLOYEE_H
