#pragma once
#include <map>

class Employee;

class PayrollDatabase
{
public:
	PayrollDatabase();
	~PayrollDatabase();

	Employee* getEmployee(int empId);
	void addEmployee(int empId, Employee*);
	void clear(){ mEmployees.clear(); }

private:
	std::map<int, Employee*> mEmployees;
};

