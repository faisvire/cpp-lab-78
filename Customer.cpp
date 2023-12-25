#include "BankAccount.h"
#include "Customer.h"
#include "Transaction.h"
using namespace std;
#include <iostream>
#include <fstream>
size_t LengthString(const char* str);
void copyString(char* strk2, const char* strk, int strk2Size);
Customer::Customer() {
	owner = nullptr;
	phonenumber = nullptr;
	bankaccountID = 0;
}
Customer::Customer(const char* owner, const char* phonenumber, long long bankaccountID) {
	this->phonenumber = new char[LengthString(phonenumber)];
	copyString(this->phonenumber, phonenumber, LengthString(phonenumber));
	this->owner = new char[LengthString(owner)];
	copyString(this->owner, owner, LengthString(owner));
	this->bankaccountID = bankaccountID;
}
Customer::~Customer() {
	if (owner != nullptr) delete[] owner;
	if (phonenumber != nullptr) delete[] phonenumber;
}
Customer::Customer(const Customer& customercopy) {
	if (customercopy.owner != nullptr) {
		this->owner = new char[LengthString(customercopy.owner)];
		copyString(this->owner, customercopy.owner, LengthString(customercopy.owner));
	}
	else owner = nullptr;
	if (customercopy.phonenumber != nullptr) {
		this->phonenumber = new char[LengthString(customercopy.phonenumber)];
		copyString(this->phonenumber, customercopy.phonenumber, LengthString(customercopy.phonenumber));
	}
	else phonenumber = nullptr;
	this->bankaccountID = customercopy.bankaccountID;
}
Customer::Customer(const BankAccount& bankacccopy) {
	this->bankaccountID = bankacccopy.bankaccountID;
	if (bankacccopy.owner != nullptr) {
		this->owner = new char[LengthString(bankacccopy.owner)];
		copyString(this->owner, bankacccopy.owner, LengthString(bankacccopy.owner));
	}
	else owner = nullptr;
	phonenumber = 0;
	this->setCustomerphonenumber();
}
Customer::Customer(const Transaction& transactioncopy) {
	this->bankaccountID = 0;
	this->setCustomerowner();
	phonenumber = 0;
	this->setCustomerphonenumber();
}
void Customer::SetFromFile(const char* name) {
	ifstream potok(name);
	if (!potok.is_open()) {
		cerr << "Невозможно открыть файл";
		return;
	}
	string customercopy;
	string phonenumbercopy;
	long long bankaccountIDcopy;
	potok >> customercopy;
	potok >> phonenumbercopy;
	potok >> bankaccountIDcopy;
	potok.close();
	this->bankaccountID = bankaccountIDcopy;
	this->owner = new char[customercopy.length() + 2];
	strcpy_s(this->owner, customercopy.length() + 2, customercopy.c_str());
	owner[LengthString(owner)] = '\0';
	this->phonenumber = new char[phonenumbercopy.length() + 2];
	strcpy_s(this->phonenumber, phonenumbercopy.length() + 2, phonenumbercopy.c_str());
	phonenumber[LengthString(phonenumber)] = '\0';
	cout << "Информация из файла успешно считана" << endl;
}
void Customer::OutputToFile(const char* name) {
	ofstream output(name);
	if (output.is_open()) {
		output << "Информация о клиенте: " << endl;
		if (owner != nullptr) {
			output << "Имя клиента: ";
			for (size_t i = 0; owner[i] != '\0'; ++i) {
				output << owner[i];
			}
			output << endl;
		}
		else output << "Имя клиента не указано" << endl;
		if (phonenumber != nullptr) {
			output << "Телефонный номер клиента: ";
			for (size_t i = 0; phonenumber[i] != '\0'; ++i) {
				output << phonenumber[i];
			}
			output << endl;
		}
		else output << "Телефонный номер клиента не указан" << endl;
		output << "Номер счета клиента: " << bankaccountID << endl;
		output.close();
		cout << "Информация о клиенте успешно записана в файл" << endl;
	}
	else cerr << "Невозможно открыть файл для записи";
}
void Customer::getCustomerowner() const {
	if (owner != nullptr) cout << "Имя клиента: " << owner << endl;
	else cout << "Имя клиента не указано" << endl;
}
void Customer::getCustomerphonenumber() const {
	if (phonenumber != nullptr) cout << "Телефонный номер клиента: " << phonenumber << endl;
	else cout << "Телефонный номер клиента не указан" << endl;
}
void Customer::getCustomerbankaccountID() const {
	cout << "Номер счета клиента: " << bankaccountID << endl;
}
void Customer::getCustomerInfo() const {
	cout << "Информация о клиенте: " << endl;
	this->getCustomerowner();
	this->getCustomerbankaccountID();
	this->getCustomerphonenumber();
}
void Customer::setCustomerbankaccountID() {
	if (owner == nullptr) {
		long long bankaccountIDcopy;
		cout << "Введите номер счета клиента: ";
		cin >> bankaccountIDcopy;
		this->bankaccountID = bankaccountIDcopy;
	}
}
void Customer::setCustomerowner() {
	if (owner == nullptr) {
		cout << "Введите имя клиента: ";
		if (this->owner != nullptr) delete[] this->owner;
		char owner[50];
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}
		fgets(owner, sizeof(owner), stdin);
		// для strcmp
		owner[strcspn(owner, "\n")] = '\0';
		this->owner = new char[LengthString(owner)];
		copyString(this->owner, owner, LengthString(owner));
	}
}
void Customer::setCustomerphonenumber() {
	cout << "Введите телефонный номер клиента: ";
	if (this->phonenumber != nullptr) delete[] this->phonenumber;
	char phonenumber[50];
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	fgets(phonenumber, sizeof(phonenumber), stdin);
	phonenumber[strcspn(phonenumber, "\n")] = '\0';
	this->phonenumber = new char[LengthString(phonenumber)];
	copyString(this->phonenumber, phonenumber, LengthString(phonenumber));
}
void Customer::setCustomerInfo() {
	cout << "Введите информацию о клиенте: " << endl;
	this->setCustomerowner();
	this->setCustomerbankaccountID();
	this->setCustomerphonenumber();
}
bool Customer::operator == (char* owner) {
	if (strcmp(owner, this->owner) == 0) return true;
	return false;
}