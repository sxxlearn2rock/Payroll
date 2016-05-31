#pragma once
class Transaction
{
public:
	Transaction() {}
	virtual ~Transaction() {}

	virtual void execute() = 0;
};

