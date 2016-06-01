#pragma once
#include "PaymentClassification.h"

class HourlyClassification : public PaymentClassification
{
public:
	HourlyClassification(double rate)
		: mHourlyRate(rate) {}
	~HourlyClassification();

	double getRate() { return mHourlyRate; }
private:
	double mHourlyRate;
};

