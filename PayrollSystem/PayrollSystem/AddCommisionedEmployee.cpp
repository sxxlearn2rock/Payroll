#include "AddCommisionedEmployee.h"
#include "CommisionedClassification.h"
#include "BiweeklySchedule.h"

AddCommisionedEmployee::~AddCommisionedEmployee()
{
}

PaymentClassification* AddCommisionedEmployee::getClassification() const
{
	return new CommisionedClassification(mSalary, mCommisionRate);
}

PaymentSchedule* AddCommisionedEmployee::getSchedule() const
{
	return new BiweeklySchedule();
}
