#pragma once
#include <iostream>
using namespace std;
class BankAccount {
protected:
	long long bankaccountID;
	char* owner;
	long double SavingsBalance;
	long double CheckingBalance;
	long double balance;
	friend class SavingsAccount;
	friend class CheckingAccount;
	friend class Customer;
	friend class Transaction;
public:
	BankAccount();
	BankAccount(long long bankaccountID, const char* owner, long double SavingsBalance, long double CheckingBalance);
	BankAccount(long long bankaccountID, const char* owner, long double balance);
	BankAccount(const BankAccount& bankacccopy);
	BankAccount(const Customer& customercopy);
	~BankAccount();
	bool operator == (const BankAccount bankacccopy);
	void getBankAccountInfo() const;
	void getBankAccountID() const;
	void getBankAccountOwner() const;
	void getBankAccountBalance() const;
	void setBankAccountID();
	void setBankAccountOwner();
	void setSavingsAccountBalance();
	void setCheckingAccountBalance();
	void setBankAccountInfo();
	virtual void processTransaction();
};
class SavingsAccount : protected BankAccount {
protected:
	double Percent;
	char PercentFrequency;
public:
	SavingsAccount(BankAccount bankacccopy);
	void getSavingsAccountBalance() const;
	void getSavingsAccountPercent() const;
	void getSavingsAccountPercentFrequency() const;
	void getSavingsAccountInfo() const;
	void setSavingsAccountPercent();
	void setSavingsAccountPercentFrequency();
	void setSavingsAccountInfo();
	void processTransaction() override;
};
class CheckingAccount : public BankAccount {
protected:
	bool CheckingAccountStatus;
	long double ChargePerMonth;
public:
	CheckingAccount(BankAccount bankacccopy);
	void getCheckingAccountBalance() const;
	void getCheckingAccountStatus() const;
	void getCheckingAccountChargePerMonth() const;
	void getCheckingAccountInfo() const;
	void setCheckingAccountStatus();
	void setChargePerMonth();
	void setCheckingAccountInfo();
	void processTransaction() override;
};