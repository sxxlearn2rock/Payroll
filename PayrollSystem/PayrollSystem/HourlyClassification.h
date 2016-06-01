#pragma once
#include "PaymentClassification.h"
#include "TimeCard.h"
#include <map>

using std::map;

class HourlyClassification : public PaymentClassification
{
public:
	HourlyClassification(double rate)
		: mHourlyRate(rate) {}
	~HourlyClassification();

	double getRate() { return mHourlyRate; }
	TimeCard* getTimeCard(long date) { return mTimeCards[date]; }
	void addTimeCard(TimeCard* timecard) { mTimeCards[timecard->getDate()] = timecard; }
private:
	double mHourlyRate;
	map<long, TimeCard*> mTimeCards;
};

