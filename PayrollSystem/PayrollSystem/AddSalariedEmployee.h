#pragma once
#include <string>
#include "AddEmployeeTransaction.h"

using std::string;

class AddSalariedEmployee : public AddEmployeeTransaction
{
public:
	AddSalariedEmployee(int id, string name, string address, double salary)
		: AddEmployeeTransaction(id, name, address), mSalary(salary) {}
	~AddSalariedEmployee();

	PaymentClassification* getClassification() const;
	PaymentSchedule* getSchedule() const;
private:
	double mSalary;
};

