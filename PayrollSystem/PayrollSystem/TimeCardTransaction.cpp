#include "TimeCardTransaction.h"
#include "PayrollDatabase.h"
#include "PaymentClassification.h"
#include "HourlyClassification.h"
#include "Employee.h"

extern PayrollDatabase gPayrollDatabase;

TimeCardTransaction::~TimeCardTransaction()
{
}

void TimeCardTransaction::execute()
{
	Employee* e = gPayrollDatabase.getEmployee(mEmpId);
	if (e)
	{
		PaymentClassification* pc = e->getClassification();
		if (HourlyClassification* hc = static_cast<HourlyClassification*>(pc))
		{
			hc->addTimeCard(new TimeCard(mDate, mHours));
		}else
		{
			throw ("Tired to add timecard to non-hourly employee");
		}
	}else
	{
		throw ("No such employee.");
	}
}
