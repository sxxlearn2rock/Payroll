#include "AddSalariedEmployee.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"


AddSalariedEmployee::~AddSalariedEmployee()
{
}

PaymentClassification* AddSalariedEmployee::getClassification() const
{
	return new SalariedClassification(mSalary);
}

PaymentSchedule* AddSalariedEmployee::getSchedule() const
{
	return new MonthlySchedule();
}


