#pragma once
#include "PaymentClassification.h"

class SalariedClassification : public PaymentClassification
{
public:
	SalariedClassification(double s)
		: mSalary(s) {}
	~SalariedClassification();

	double getSalary(){ return mSalary; }
private:
	double mSalary;
};

