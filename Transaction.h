#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Transaction {
protected:
	friend class Customer;
	friend class SavingsAccount;
	friend class CheckingAccount;
	friend class BankAccount;

	long long transactionID;
	long double amount;
public:
	Transaction();
	Transaction(const Transaction& transactioncopy);
	Transaction(const BankAccount& bankacccopy);
	Transaction(const Customer& customercopy);
	Transaction(long long bankaccountID, long double amount);
	void setTransactionID();
	void setTransactionamount();
	void setTransactionInfo();
	void getTransactionID() const;
	void getTransactionamount() const;
	void getTransactionInfo() const;
	void processTransaction(SavingsAccount& account);
	void processTransaction(CheckingAccount& account);
};