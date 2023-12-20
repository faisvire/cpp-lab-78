#include "BankAccount.h"
#include "Customer.h"
#include "Transaction.h"
using namespace std;
size_t LengthString(const char* str);
void copyString(char* strk2, const char* strk, int strk2Size);
BankAccount::BankAccount() {
		bankaccountID = 0;
		owner = nullptr;
		balance = 0;
		SavingsBalance = 0;
		CheckingBalance = 0;
	}
	// два вида конструкторов с параметрами -  в одном дается баланс двух счетов (накопительного и текущего), в другом - только баланс общего (накопительного + текущего) счета,
	// тогда накопительный и текущий счет остаются неизвестными (равными нпулю) до их инициализации через классы-наследники
BankAccount::BankAccount(long long bankaccountID, const char* owner, long double SavingsBalance, long double CheckingBalance) {
		this->bankaccountID = bankaccountID;
		this->owner = new char[LengthString(owner)];
		copyString(this->owner, owner, LengthString(owner));
		this->SavingsBalance = SavingsBalance;
		this->CheckingBalance = CheckingBalance;
		this->balance = SavingsBalance + CheckingBalance;
	}
BankAccount::BankAccount(long long bankaccountID, const char* owner, long double balance) {
		this->bankaccountID = bankaccountID;
		this->owner = new char[LengthString(owner)];
		copyString(this->owner, owner, LengthString(owner));
		this->balance = balance;
		SavingsBalance = 0;
		CheckingBalance = 0;
	}
BankAccount::BankAccount(const BankAccount& bankacccopy) {
		this->bankaccountID = bankacccopy.bankaccountID;
		if (bankacccopy.owner != nullptr) {
			this->owner = new char[LengthString(bankacccopy.owner)];
			copyString(this->owner, bankacccopy.owner, LengthString(bankacccopy.owner));
		}
		else owner = nullptr;
		this->SavingsBalance = bankacccopy.SavingsBalance;
		this->CheckingBalance = bankacccopy.CheckingBalance;
		this->balance = bankacccopy.balance;
	}
BankAccount::BankAccount(const Customer& customercopy) {
		this->bankaccountID = customercopy.bankaccountID;
		if (customercopy.owner != nullptr) {
			this->owner = new char[LengthString(customercopy.owner)];
			copyString(this->owner, customercopy.owner, LengthString(customercopy.owner));
		}
		else owner = nullptr;
		this->setSavingsAccountBalance();
		this->setCheckingAccountBalance();
		balance = SavingsBalance + CheckingBalance;
	}
BankAccount::~BankAccount() {
		if (owner != nullptr) delete[] owner;
	}
bool BankAccount::operator == (const BankAccount bankacccopy) {
		if (bankacccopy.bankaccountID != this->bankaccountID) return false;
		if (bankacccopy.balance != this->balance) return false;
		if (bankacccopy.SavingsBalance != this->SavingsBalance) return false;
		if (bankacccopy.CheckingBalance != this->CheckingBalance) return false;
		if (strcmp(bankacccopy.owner, this->owner) != 0) return false;
		return true;
	};
void BankAccount::getBankAccountInfo() const {
		cout << "Информация о данном счете: " << endl;
		this->getBankAccountID();
		this->getBankAccountOwner();
		this->getBankAccountBalance();
	}
void BankAccount::getBankAccountID() const {
		cout << "Номер счета: " << bankaccountID << endl;
	}
void BankAccount::getBankAccountOwner() const {
		if (owner != nullptr) cout << "Владелец счета: " << owner << endl;
		else cout << "Владелец счета отсутствует" << endl;
	}
void BankAccount::getBankAccountBalance() const {
		cout << "Баланс счета: " << balance << endl;
	}
void BankAccount::setBankAccountID() {
		long long bankaccountIDcopy;
		cout << "Введите номер счета: ";
		cin >> bankaccountIDcopy;
		this->bankaccountID = bankaccountIDcopy;
	}
void BankAccount::setBankAccountOwner() {
		cout << "Введите имя владельца счета: ";
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
void BankAccount::setSavingsAccountBalance() {
		long long SavingsBalancecopy;
		cout << "Введите баланс накопительного счета: ";
		cin >> SavingsBalancecopy;
		SavingsBalance = SavingsBalancecopy;
	}
void BankAccount::setCheckingAccountBalance() {
		long long CheckingBalancecopy;
		cout << "Введите баланс текущего счета: ";
		cin >> CheckingBalancecopy;
		CheckingBalance = CheckingBalancecopy;
	}
void BankAccount::setBankAccountInfo() {
	cout << "Введите информацию о данном банковском счете: " << endl;
	this->setBankAccountID();
	this->setBankAccountOwner();
	this->setSavingsAccountBalance();
	this->setCheckingAccountBalance();
	balance = SavingsBalance + CheckingBalance;
}
void BankAccount::processTransaction() {}
////////////////////////////////////////////////////////////////
// PercentFrequency (частота начисления процентов на счет) может иметь след.значения:
// m - monthly / a - annual / q - per quarter / s - semi-annual / n - none
SavingsAccount::SavingsAccount(BankAccount bankacccopy) {
	this->SavingsBalance = bankacccopy.SavingsBalance;
	Percent = 0;
	PercentFrequency = 'n';
}
void SavingsAccount::getSavingsAccountBalance() const {
	cout << "Баланс накопительного счета: " << SavingsBalance << endl;
}
void SavingsAccount::getSavingsAccountPercent() const {
	cout << "Накопительный процент счета: " << Percent << "%" << endl;
}
void SavingsAccount::getSavingsAccountPercentFrequency() const {
	if (PercentFrequency == 'n') cout << "Проценты не начисляются" << endl;
	else {
		cout << "Проценты на баланс накопительного счета начисляются ";
		switch (PercentFrequency) {
		case('m'): cout << "ежемесячно" << endl; break;
		case('a'): cout << "ежегодно" << endl; break;
		case('q'): cout << "ежеквартально" << endl; break;
		case('s'): cout << "раз в полгода" << endl; break;
		}
	}
}
void SavingsAccount::getSavingsAccountInfo() const {
	cout << "Информация о накопительном счете: " << endl;
	this->getSavingsAccountBalance();
	this->getSavingsAccountPercent();
	this->getSavingsAccountPercentFrequency();
}
void SavingsAccount::setSavingsAccountPercent() {
	double Percent;
	cout << "Введите накопительный процент счета: " << endl;
	cin >> Percent;
	this->Percent = Percent;
}
void SavingsAccount::setSavingsAccountPercentFrequency() {
	char PercentFrequency;
	cout << "Введите частоту начисления процентов на счет: " << endl;
	cout << "m - ежемесячно" << endl << "a - ежегодно" << endl << "q - ежеквартально" << endl << "s - раз в полгода" << endl;
	cin >> PercentFrequency;
	this->PercentFrequency = PercentFrequency;
}
void SavingsAccount::setSavingsAccountInfo() {
	cout << "Введите информацию о данном накопительном счете: " << endl;
	this->setSavingsAccountPercent();
	this->setSavingsAccountPercentFrequency();
}
void SavingsAccount::processTransaction() {
	Transaction t1;
	int a;
	long long id;
	cout << "Введите номер транзакции: " << endl;
	cin >> id;
	long double amount;
	cout << "Введите тип транзакции накопительного счета: " << endl << "1 - внесение депозита" << endl << "2 - начисление процентов" << endl;
	cin >> a;
	switch (a) {
	case(1): cout << "Обработка внесения депозита..." << endl << "Введите сумму депозита: ";
		cin >> amount;
		cout << "Внесение депозита прошло успешно." << endl;
		cout << "Сумма накопительного счета до внесения депозита: " << this->SavingsBalance << endl;
		cout << "Сумма накопительного счета после внесения депозита: " << this->SavingsBalance + amount << endl;
		this->SavingsBalance += amount;
		t1.amount = amount;
		t1.transactionID = id;

		break;
	case(2): cout << "Обработка начисления процентов..." << endl << "Введите число процентов: ";
		cin >> amount;
		cout << "Начисление процентов прошло успешно." << endl;
		cout << "Сумма накопительного счета до начисления процентов: " << this->SavingsBalance << endl;
		cout << "Сумма накопительного счета после начисления процентов: " << this->SavingsBalance + this->SavingsBalance * (amount * 0.01) << endl;
		this->SavingsBalance += this->SavingsBalance * (amount * 0.01);
		t1.amount = amount;
		t1.transactionID = id;
		break;
	}
	t1.getTransactionInfo();
}
///////////////////////////////////////////////////////
CheckingAccount::CheckingAccount(BankAccount bankacccopy) {
	this->CheckingBalance = bankacccopy.CheckingBalance;
	CheckingAccountStatus = false;
	ChargePerMonth = 0;
}
void CheckingAccount::processTransaction() {
	Transaction t1;
	int a;
	long long id;
	cout << "Введите номер транзакции: " << endl;
	cin >> id;
	long double amount;
	cout << "Введите тип транзакции текущего счета: " << endl << "1 - снятие наличных" << endl << "2 - списание расходов на коммунальные услуги" << endl << "3 - блокировка/открытие счета" << endl;
	cin >> a;
	switch (a) {
	case(1): cout << "Обработка снятия наличных..." << endl << "Введите сумму: ";
		cin >> amount;
		cout << "Снятие наличных прошло успешно." << endl;
		cout << "Сумма выдачи: " << amount << endl;
		cout << "Сумма текущего счета до снятия наличных: " << this->CheckingBalance << endl;
		cout << "Сумма текущего счета после снятия наличных: " << this->CheckingBalance - amount << endl;
		this->CheckingBalance -= amount;
		t1.amount = amount;
		t1.transactionID = id;
		break;
	case(2): cout << "Обработка списания расходов на коммунальные услуги..." << endl << "Введите сумму: ";
		cin >> amount;
		cout << "Списания расходов прошло успешно." << endl;
		cout << "Сумма накопительного счета до списания расходов: " << this->CheckingBalance << endl;
		cout << "Сумма накопительного счета после списания расходов: " << this->CheckingBalance - amount << endl;
		this->CheckingBalance -= amount;
		t1.amount = amount;
		t1.transactionID = id;

		break;
	case(3):	if (CheckingAccountStatus) {
		cout << "Обработка закрытия счета..." << endl;
		cout << "Ваш текущий счет был успешно заблокирован." << endl;
		this->CheckingAccountStatus = false;
	}
		   else {
		cout << "Обработка открытия счета..." << endl;
		cout << "Ваш текущий счет был успешно разблокирован." << endl;
		this->CheckingAccountStatus = true;
	}
		   t1.transactionID = id;
		   break;
	}
	t1.getTransactionInfo();
}
void CheckingAccount::getCheckingAccountBalance() const {
	cout << "Баланс текущего счета: " << CheckingBalance << endl;
}
void CheckingAccount::getCheckingAccountStatus() const {
	if (CheckingAccountStatus) cout << "Текущий счет активен" << endl;
	else cout << "Текущий счет заблокирован" << endl;
}
void CheckingAccount::getCheckingAccountChargePerMonth() const {
	cout << "Комиссия за обслуживание текущего счета составляет " << ChargePerMonth << " рублей в месяц" << endl;
}
void CheckingAccount::getCheckingAccountInfo() const {
	cout << "Информация о текущем счете: " << endl;
	this->getCheckingAccountBalance();
	this->getCheckingAccountStatus();
	this->getCheckingAccountChargePerMonth();
}
void CheckingAccount::setCheckingAccountStatus() {
	int CheckingAccountStatus;
	cout << "Введите состояние текущего счета: " << endl << "1 - счет активен" << endl << "0 - счет заблокирован" << endl;
	cin >> CheckingAccountStatus;
	switch (CheckingAccountStatus) {
	case(0): this->CheckingAccountStatus = false; break;
	case(1): this->CheckingAccountStatus = true; break;
	}
}
void CheckingAccount::setChargePerMonth() {
	long double ChargePerMonth;
	cout << "Введите комиссию за обслуживание текущего счета" << endl;
	cin >> ChargePerMonth;
	this->ChargePerMonth = ChargePerMonth;
}
void CheckingAccount::setCheckingAccountInfo() {
	cout << "Введите информацию о данном текущем счете: " << endl;
	this->setCheckingAccountStatus();
	this->setChargePerMonth();
}