#include "AddEmployeeTransaction.h"
#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include "PaymentMethod.h"
#include "HoldMethod.h"
#include "Employee.h"
#include "PayrollDatabase.h"

extern PayrollDatabase gPayrollDatabase;

AddEmployeeTransaction::~AddEmployeeTransaction()
{
}

void AddEmployeeTransaction::execute()
{
	PaymentClassification* pc = getClassification();
	PaymentSchedule* ps = getSchedule();
	PaymentMethod* pm = new HoldMethod();
	Employee* e = new Employee(mEmpid, mName, mAddress);
	e->setClassification(pc);
	e->setSchedule(ps);
	e->setMethod(pm);
	gPayrollDatabase.addEmployee(mEmpid, e);
}
