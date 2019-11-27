#pragma once
#ifndef NODEOFEMP_H
#define NODEOFEMP_H
#include "Employee.h"

class NodeOfEmp {
	friend class ListOfEmployees; 
public:
	NodeOfEmp();
	NodeOfEmp(string n, double s);
private:
	Employee data;
	NodeOfEmp* next;
};
#endif // !NODEOFEMP_H
