#pragma once
#include "PaymentClassification.h"
class CommisionedClassification : public PaymentClassification
{
public:
	CommisionedClassification(double salary, double rate)
		: mSalary(salary), mCommisionRate(rate) {}
	~CommisionedClassification();

	double getSalary() { return mSalary; }
	double getRate() { return mCommisionRate; }
private:
	double mSalary;
	double mCommisionRate;
};

