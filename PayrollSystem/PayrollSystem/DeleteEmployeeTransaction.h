#pragma once
#include "Transaction.h"

class DeleteEmployeeTransaction : public Transaction
{
public:
	DeleteEmployeeTransaction(int empId)
		: mEmpId(empId) {}
	~DeleteEmployeeTransaction();

	void execute();

private:
	int mEmpId;
};

