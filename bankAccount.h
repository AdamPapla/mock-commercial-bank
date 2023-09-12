#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;

class bankAccount {
public: 
	bankAccount(string customer, double openingBalance, date d) : holder {customer}, balance {openingBalance}, openDate {d}, accountNum {numAccounts}, active {1}{
		accountNum = numAccounts;
		numAccounts++;
		cout << customer << " opening account number " << accountNum << " with balance " << openingBalance << endl;
	}
	bankAccount (const bankAccount &other) : holder {other.holder}, balance {other.balance}, openDate {other.openDate}, active {1}{}
	bankAccount (bankAccount &&) = default;
	~bankAccount() = default;
	bankAccount& operator=(const bankAccount&) = default;
	bankAccount& operator=(bankAccount&&) = default;
	double getBal() const{
		return balance;}
	int getAccountNum() const{
		return accountNum;}
	int getStatus() const{
		return active;}
	string getHolder() const{
		return holder;}
	void showHistory(){
		for (transaction t : history) cout << t << endl;
	}
	void showBal() const{
		cout << "Balance for " << holder << "'s account: " << balance << endl;}
	void deposit(double amount, date dDate, string message);
	void withdraw(double amount, date dDate, string message);
	void transfer(double amount, bankAccount &targetAccount, date dDate, string message);
	void close(void){history.clear(); active = 0;}
private:
	string holder;
	int accountNum;
	double balance;
	date openDate;
	vector<transaction> history;
	static int numAccounts;
	int active;
};
#endif