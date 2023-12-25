#include <iostream>
#include "BankAccount.h"
#include "Customer.h"
#include "Transaction.h"
using namespace std;
int main()
{
	cout << "Создание банковского счета, накопительного и текущего счетов на его основе, отображение их данных:" << endl << endl;
	BankAccount ba;
	ba.setBankAccountInfo();
	ba.getBankAccountInfo();
	cout << "-------------------" << endl;
	SavingsAccount sa(ba);
	sa.setSavingsAccountInfo();
	sa.getSavingsAccountInfo();
	cout << "-------------------" << endl;
	CheckingAccount ca(ba);
	ca.setCheckingAccountInfo();
	ca.getCheckingAccountInfo();
	cout << endl;
	cout << "Создание учетной записи, отображение ее данных:" << endl;
	Customer c(ba);
	c.getCustomerInfo();
	cout << "-------------------" << endl;
	cout << "Создание транзакции, отображение ее данных:" << endl;
	Transaction t;
	t.setTransactionInfo();
	t.getTransactionInfo();
	cout << "-------------------" << endl;
	cout << "Перегрузка функции в накопительном и текущем счетах: " << endl;
	sa.processTransaction();
	cout << "-------------------" << endl;
	ca.processTransaction();
	cout << "-------------------" << endl;
	cout << "Демонстрация работы с файлами: " << endl;
	Customer c1;
	c1.SetFromFile("input.txt");
	c1.OutputToFile("output");
}