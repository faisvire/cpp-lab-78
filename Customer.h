#pragma once
#include <iostream>
using namespace std;
class Customer {
protected:
	char* owner;
	char* phonenumber;
	long long bankaccountID;
	friend class BankAccount;
	friend class Transaction;
	friend class SavingsAccount;
	friend class CheckingAccount;
public:
	Customer();
	Customer(const char* owner, const char* phonenumber, long long bankaccountID);
	~Customer();
	Customer(const Customer& customercopy);
	Customer(const BankAccount& bankacccopy);
	Customer(const Transaction& transactioncopy);
	void SetFromFile(const char* name);
	void OutputToFile(const char* name);
	void getCustomerowner() const;
	void getCustomerphonenumber() const;
	void getCustomerbankaccountID() const;
	void getCustomerInfo() const;
	void setCustomerbankaccountID();
	void setCustomerowner();
	void setCustomerphonenumber();
	void setCustomerInfo();
	bool operator == (char* owner);
};