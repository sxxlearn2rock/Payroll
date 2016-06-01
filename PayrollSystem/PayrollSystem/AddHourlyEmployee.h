#pragma once
#include "AddEmployeeTransaction.h"
#include <string>

using std::string;

class AddHourlyEmployee : public AddEmployeeTransaction
{
public:
	AddHourlyEmployee(int id, string name, string address, double rate)
		:AddEmployeeTransaction(id, name, address), mHourlyRate(rate) {}
	~AddHourlyEmployee();

	PaymentClassification* getClassification() const ;
	PaymentSchedule* getSchedule() const ;

private:
	double mHourlyRate;
};

