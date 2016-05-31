#pragma once
#include <string>

class PaymentClassification;
class PaymentSchedule;
class PaymentMethod;

using std::string;

class Employee
{
public:
	Employee(int id, string name, string address)
		: mEmpId(id), mName(name), mAddress(address) {}
	~Employee();

	void setClassification(PaymentClassification* pc) { this->mPc = pc; }
	PaymentClassification* getClassification() { return mPc; }
	void setSchedule(PaymentSchedule* ps) { this->mPs = ps; }
	PaymentSchedule* getSchedule() { return mPs; }
	void setMethod(PaymentMethod* pm) { this->mPm = pm; }
	PaymentMethod* getMethod() { return mPm; }

	int getEmpId() { return mEmpId; }
	string getName() { return mName; }
	string getAddress(){ return mAddress; }


private:
	int mEmpId;
	string mName;
	string mAddress;
	PaymentClassification* mPc;
	PaymentSchedule* mPs;
	PaymentMethod* mPm;
};

