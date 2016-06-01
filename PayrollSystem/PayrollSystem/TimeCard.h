#pragma once
class TimeCard
{
public:
	TimeCard(long date, double hours)
		: mDate(date), mHours(hours) {}
	~TimeCard();

	long getDate() { return mDate; }
	double getHours() { return mHours; }

private:
	long mDate;
	double mHours;
};

