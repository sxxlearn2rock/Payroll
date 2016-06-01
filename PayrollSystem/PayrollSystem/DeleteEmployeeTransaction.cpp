#include "DeleteEmployeeTransaction.h"
#include "PayrollDatabase.h"

extern PayrollDatabase gPayrollDatabase;

DeleteEmployeeTransaction::~DeleteEmployeeTransaction()
{
}

void DeleteEmployeeTransaction::execute()
{
	gPayrollDatabase.deleteEmployee(mEmpId);
}
