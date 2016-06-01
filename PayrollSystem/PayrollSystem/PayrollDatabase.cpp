#include "PayrollDatabase.h"
#include "Employee.h"

PayrollDatabase gPayrollDatabase;

PayrollDatabase::PayrollDatabase()
{
}


PayrollDatabase::~PayrollDatabase()
{
}

Employee* PayrollDatabase::getEmployee(int empId)
{
	return mEmployees[empId];
}

void PayrollDatabase::addEmployee(int empId, Employee* e)
{
	mEmployees[empId] = e;
}

void PayrollDatabase::deleteEmployee(int empId)
{
	mEmployees.erase(empId);
}
