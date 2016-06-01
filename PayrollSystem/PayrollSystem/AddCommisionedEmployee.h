#pragma once
#include "AddEmployeeTransaction.h"
#include <string>

using std::string;

class AddCommisionedEmployee : public	AddEmployeeTransaction
{
public:
	AddCommisionedEmployee(int id, string name, string address, double salary, double rate)
		:AddEmployeeTransaction(id, name, address), mSalary(salary), mCommisionRate(rate) {}
	~AddCommisionedEmployee();

	PaymentClassification* getClassification() const ;
	PaymentSchedule* getSchedule() const;

private:
	double mSalary;
	double mCommisionRate;
};

