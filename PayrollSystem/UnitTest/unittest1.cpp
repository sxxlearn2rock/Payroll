#include "stdafx.h"
#include "CppUnitTest.h"

#include "../PayrollSystem/PayrollDatabase.h"
#include "../PayrollSystem/AddSalariedEmployee.h"
#include "../PayrollSystem/Employee.h"
#include "../PayrollSystem/PaymentClassification.h"
#include "../PayrollSystem/PaymentSchedule.h"
#include "../PayrollSystem/PaymentMethod.h"
#include "../PayrollSystem/HoldMethod.h"
#include "../PayrollSystem/SalariedClassification.h"
#include "../PayrollSystem/MonthlySchedule.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern PayrollDatabase gPayrollDatabase;

namespace UnitTest
{	
	static const double DOUBLE_TOLETATE = 0.0000001;

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int empId = 1;
			AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
			t.execute();

			Employee* e = gPayrollDatabase.getEmployee(empId);
			Assert::AreEqual("Bob", e->getName().c_str());

			PaymentClassification* pc = e->getClassification();			
			SalariedClassification* sc = static_cast<SalariedClassification*>(pc);
			Assert::IsNotNull(sc);
			Assert::AreEqual(1000.00, sc->getSalary(), DOUBLE_TOLETATE);

			PaymentSchedule* ps = e->getSchedule();
			MonthlySchedule* ms = static_cast<MonthlySchedule*>(ps);
			Assert::IsNotNull(ms);

			PaymentMethod* pm = e->getMethod();
			HoldMethod* hm = static_cast<HoldMethod*>(pm);
			Assert::IsNotNull(hm);
		}

	};
}