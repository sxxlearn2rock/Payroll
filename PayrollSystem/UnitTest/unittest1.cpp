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
#include "../PayrollSystem/AddHourlyEmployee.h"
#include "../PayrollSystem/HourlyClassification.h"
#include "../PayrollSystem/WeeklySchedule.h"
#include "../PayrollSystem/AddCommisionedEmployee.h"
#include "../PayrollSystem/CommisionedClassification.h"
#include "../PayrollSystem/BiweeklySchedule.h"
#include "../PayrollSystem/DeleteEmployeeTransaction.h"
#include "../PayrollSystem/TimeCardTransaction.h"
#include "../PayrollSystem/TimeCard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern PayrollDatabase gPayrollDatabase;

namespace UnitTest
{	
	static const double DOUBLE_TOLETATE = 0.0000001;

	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD_INITIALIZE(setup)
		{
			gPayrollDatabase.clear();
		}

		TEST_METHOD(TestAddSalariedEmployee)
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

		TEST_METHOD(TestAddHourlyEmployee)
		{
			int empId = 2;
			AddHourlyEmployee t(empId, "Sam", "ShenZhen", 48.5);
			t.execute();

			Employee* e = gPayrollDatabase.getEmployee(empId);
			Assert::IsNotNull(e);
			Assert::AreEqual("Sam", e->getName().c_str());

			PaymentClassification* pc = e->getClassification();			
			HourlyClassification* hc = static_cast<HourlyClassification*>(pc);
			Assert::IsNotNull(hc);
			Assert::AreEqual(48.5, hc->getRate(), DOUBLE_TOLETATE);

			PaymentSchedule* ps = e->getSchedule();
			WeeklySchedule* ws = static_cast<WeeklySchedule*>(ps);
			Assert::IsNotNull(ws);

			PaymentMethod* pm = e->getMethod();
			HoldMethod* hm = static_cast<HoldMethod*>(pm);
			Assert::IsNotNull(hm);
		}

		TEST_METHOD(TestAddCommissionedEmployee)
		{
			int empId = 3;
			AddCommisionedEmployee t(empId, "Lance", "NewYork", 2500.00, 3.1);
			t.execute();

			Employee* e = gPayrollDatabase.getEmployee(empId);
			Assert::IsNotNull(e);
			Assert::AreEqual("Lance", e->getName().c_str());

			PaymentClassification* pc = e->getClassification();
			CommisionedClassification* cc = static_cast<CommisionedClassification*>(pc);
			Assert::IsNotNull(cc);
			Assert::AreEqual(2500.00, cc->getSalary(), DOUBLE_TOLETATE);

			PaymentSchedule* ps = e->getSchedule();
			BiweeklySchedule* bs = static_cast<BiweeklySchedule*>(ps);
			Assert::IsNotNull(bs);

			PaymentMethod* pm = e->getMethod();
			HoldMethod* hm = static_cast<HoldMethod*>(pm);
			Assert::IsNotNull(hm);
		}

		TEST_METHOD(TestDeleteEmployee)
		{
			int empId = 3;
			AddCommisionedEmployee t(empId, "Lance", "NewYork", 2500.00, 3.1);
			t.execute(); 
			{
				Employee* e = gPayrollDatabase.getEmployee(empId);
				Assert::IsNotNull(e);
			}

			DeleteEmployeeTransaction dt(empId);
			dt.execute();
			{
				Employee* e = gPayrollDatabase.getEmployee(empId);
				Assert::IsNull(e);
			}
		}

		TEST_METHOD(TestTimeCardTransaction)
		{
			int empId = 2;
			AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
			t.execute();

			TimeCardTransaction tct(10312001L, 8.0, empId);
			tct.execute();

			Employee * e = gPayrollDatabase.getEmployee(empId);
			Assert::IsNotNull(e);

			PaymentClassification* pc = e->getClassification();
			HourlyClassification* hc = static_cast<HourlyClassification*>(pc);
			Assert::IsNotNull(hc);
			TimeCard* tc = hc->getTimeCard(10312001L);
			Assert::IsNotNull(tc);
			Assert::AreEqual(8.0, tc->getHours(), DOUBLE_TOLETATE);
		}

	};
}