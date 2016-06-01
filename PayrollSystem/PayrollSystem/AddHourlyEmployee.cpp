#include "AddHourlyEmployee.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"


AddHourlyEmployee::~AddHourlyEmployee()
{
}

PaymentClassification* AddHourlyEmployee::getClassification() const
{
	return new HourlyClassification(mHourlyRate);
}

PaymentSchedule* AddHourlyEmployee::getSchedule() const
{
	return new WeeklySchedule();
}
