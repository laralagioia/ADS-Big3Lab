#include "NodeOfEmp.h"

NodeOfEmp::NodeOfEmp()
	:data(Employee()), next(nullptr)
{
}
 
NodeOfEmp::NodeOfEmp(string n, double s)
	:data(Employee(n,s)), next(nullptr)
{
}
