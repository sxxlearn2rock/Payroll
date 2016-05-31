#pragma once
#include <string>
#include "Transaction.h"

class PaymentClassification;
class PaymentSchedule;

using std::string;

class AddEmployeeTransaction : public Transaction
{
public:
	AddEmployeeTransaction(int empId, string name, string address)
		: mEmpid(empId), mName(name), mAddress(address) {}
	virtual ~AddEmployeeTransaction();

	virtual  PaymentClassification* getClassification() const = 0;
	virtual PaymentSchedule* getSchedule() const = 0;
	virtual void execute();

private:
	int mEmpid;
	string mName;
	string mAddress;
};

