#pragma once
#include "Transaction.h"

class TimeCardTransaction : public Transaction
{
public:
	TimeCardTransaction(long date, double hours, int empId)
		: mDate(date), mHours(hours), mEmpId(empId) {}
	~TimeCardTransaction();

	void execute();

private:
	int mEmpId;
	long mDate;
	double mHours;
};

