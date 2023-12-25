#include "BankAccount.h"
#include "Customer.h"
#include "Transaction.h"
using namespace std;
size_t LengthString(const char* str);
void copyString(char* strk2, const char* strk, int strk2Size);
Transaction::Transaction() {
	transactionID = 0;
	amount = 0;
}
Transaction::Transaction(const BankAccount& bankacccopy) {
	transactionID = 0;
	amount = 0;
}
Transaction::Transaction(const Customer& customercopy) {
	transactionID = 0;
	amount = 0;

}
Transaction::Transaction(long long transactionID, long double amount) {
	this->amount = amount;
	this->transactionID = transactionID;
}

void Transaction::setTransactionID(){
	long long TransactionIDcopy;
	cout << "Введите номер транзакции: ";
	cin >> TransactionIDcopy;
	this->transactionID = TransactionIDcopy;
}
void Transaction::setTransactionamount() {
	long double amountcopy;
	cout << "Введите сумму транзакции: ";
	cin >> amountcopy;
	this->amount = amountcopy;
}
void Transaction::setTransactionInfo() {
	cout << "Введите информацию о транзакции:" << endl;
	this->setTransactionID();
	this->setTransactionamount();
}

void Transaction::getTransactionID() const {
	cout << "Номер транзакции: " << transactionID << endl;
}
void Transaction::getTransactionamount() const {
	cout << "Сумма транзакции: " << amount << endl;
}
void Transaction::getTransactionInfo() const {
	cout << "Информация о транзакции: " << endl;
	this->getTransactionID();
	this->getTransactionamount();
}
void Transaction::processTransaction(SavingsAccount& account) {
	cout << "Обработка транзакции накопительного счета..." << endl;
	account.processTransaction();
}
void Transaction::processTransaction(CheckingAccount& account) {
	cout << "Обработка транзакции текущего счета..." << endl;
	account.processTransaction();
}