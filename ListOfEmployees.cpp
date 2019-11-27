#include "ListOfEmployees.h"

ListOfEmployees::ListOfEmployees()
	:head(nullptr)
{
}

ListOfEmployees::ListOfEmployees(ListOfEmployees& rhs)
{
	head = nullptr;
	*this = rhs;
}

ListOfEmployees::~ListOfEmployees()
{
	while (head) {
		deleteAtFront();
	}
}

void ListOfEmployees::insertAtFront(string n, double s)
{
	NodeOfEmp* newNode = new NodeOfEmp(n, s);
	if (!head) {
		head = newNode;
	}
	else {
		NodeOfEmp* tempPtr = head;
		newNode->next = tempPtr;
		head = newNode;
	}
}

void ListOfEmployees::insertAtEnd(string n, double s)
{
	NodeOfEmp* newNode = new NodeOfEmp(n, s);
	if (!head) {
		head = newNode;
	} 
	else {
		NodeOfEmp* tempNode = head;

		while (tempNode->next) {
			tempNode = tempNode->next;
		}

		tempNode->next = newNode;
	}

}

void ListOfEmployees::deleteAtFront()
{
	if (head) {
		NodeOfEmp* tempPtr = head;
		head = head->next;
		delete tempPtr;
	}
}

void ListOfEmployees::deleteAtEnd()
{
	if (head) {
		NodeOfEmp* tempNode = head;

		while (tempNode->next->next) {
			tempNode = tempNode->next;
		}

		delete tempNode->next;
		tempNode->next = nullptr;
	}
}

void ListOfEmployees::remove(int pos)
{
	if (pos < 1) {
		cout << "Invalid position" << endl;
	} 
	else if (pos == 1) {
		deleteAtFront();
	}
	else {
		NodeOfEmp* leadPtr = head->next;
		NodeOfEmp* trailPtr = head;
		int counter = 2;
		while (leadPtr) {
			if (counter == pos) {
				trailPtr->next = leadPtr->next;
				delete leadPtr;
				break;
			}
			trailPtr = trailPtr->next;
			leadPtr = leadPtr->next;
		}


	}
}

void ListOfEmployees::remove(string name)
{
	if (head) {
		if (head->data.name == name) {
			NodeOfEmp* tempPtr = head;
			head = head->next;
			delete tempPtr;
		}
		else {
			NodeOfEmp* trailPtr = head;
			NodeOfEmp* leadPtr = head->next;
			while (leadPtr) {
				if (leadPtr->data.name == name) {
					trailPtr->next = leadPtr->next;
					delete leadPtr;
					break;
				}
				trailPtr = trailPtr->next;
				leadPtr = leadPtr->next;

			}
		}
	}

}

void ListOfEmployees::insert(int pos, string n, double s)
{
	if (!head) {
		insertAtFront(n, s);
	}
	else {

		NodeOfEmp* newNode = new NodeOfEmp(n, s);
		NodeOfEmp* trailPtr = head;
		NodeOfEmp* leadPtr = head->next;

		if (pos == 1) {
			head = newNode;
			head->next = trailPtr;
		}
		else {
			int counter = 2;

			while (leadPtr) {
				if (pos == counter) {
					trailPtr->next = newNode;
					newNode->next = leadPtr;
					break;
				}
				leadPtr = leadPtr->next;
				trailPtr = trailPtr->next;
				++counter;
			}

			if (!leadPtr) {
				cout << "Position doesn't exist on the list" << endl;
			}
		}
	}
}
double ListOfEmployees::getSalary(string n)
{
	NodeOfEmp* tempNode = head;

	while (tempNode) {
		if (tempNode->data.name == n) {
			return tempNode->data.salary;
		}
		tempNode = tempNode->next;
	}
	if (!tempNode) {
		cout << "Employee not found" << endl;
	}
	return 0.0;
}

ostream& ListOfEmployees::display(ostream& out) const
{
	out << "List Of Employees:" << endl;
	NodeOfEmp* tempPtr = head;

	while (tempPtr) {
		out << "Name: " << tempPtr->data.name << endl;
		out << "Salary: $ " << tempPtr->data.salary << endl;

		tempPtr = tempPtr->next;
	}

	return out;
}

ListOfEmployees& ListOfEmployees::operator=(ListOfEmployees& rhs)
{
	if (this != &rhs) {
		if (head) {
			while (head) {
				deleteAtFront();
			}
		}
		NodeOfEmp* copyPtr = nullptr;
		NodeOfEmp* origPtr = rhs.head;
		while (origPtr) {
			if (!head) {
				head = copyPtr = new NodeOfEmp(origPtr->data.name, origPtr->data.salary);
				//copyPtr->next = origPtr->next;
			}
			else {
				copyPtr->next = new NodeOfEmp(origPtr->data.name, origPtr->data.salary);
				copyPtr = head->next;
			}
			origPtr = origPtr->next;
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, ListOfEmployees& l)
{
	l.display(out);
	return out;
}
