#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;

class bankAccount {
public: 
	bankAccount(string customer, double openingBalance, date d) : holder {customer}, balance {openingBalance}, openDate {d}{
		numAccounts++;
		accountNum = numAccounts;
		cout << customer << " opening account with balance " << openingBalance << endl;
	}
	double getBal() const{
		return balance;
	}
	int getAccountNum() const{
		return accountNum;
	}
	void showBal() const{
		cout << "Balance for " << holder << "'s account: " << balance << endl;
	}
	void deposit(double amount, date dDate, string message);
	void withdraw(double amount, date dDate, string message);
	void transfer(double amount, bankAccount targetAccount, date dDate, string message);
private:
	string holder;
	int accountNum;
	double balance;
	date openDate;
	vector<transaction> history;
	static int numAccounts;
};
#endif