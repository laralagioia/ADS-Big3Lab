#include <iostream>
using namespace std;
#include "ListOfEmployees.h"
#include "Employee.h"
#include "NodeOfEmp.h"

int main() {
	ListOfEmployees myList, myOtherList;
	myList.insertAtFront("Lara", 111.23);
	myList.insertAtFront("Evan", 111.23);
	myList.insertAtEnd("Stephen", 111.23);

	myList.deleteAtEnd();
	double d = myList.getSalary("Lara");
	d = myList.getSalary("Stephen");

	myOtherList = myList;

	myList.insert(4, "Vitor", 111.23);
	myList.insert(1, "Vitor", 111.23);
	myList.insert(3, "Anne", 111.23);

	cout << myList;
	cout << myOtherList;

	myList.remove(2);
	myList.remove(0);
	myList.remove(1);
	myList.remove("Lara");
	myList.remove("Anne");


	return 0;

}