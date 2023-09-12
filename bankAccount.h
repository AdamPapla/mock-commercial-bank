// File containing class definition of bank account class
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;

class bankAccount {
public: 
	// Define custom constructor with initialisation list.
	// Assigns account number based on how many accounts have already been created
	bankAccount(string customer, double openingBalance, date d) : holder {customer}, balance {openingBalance}, openDate {d}, accountNum {numAccounts}, active {1}{
		accountNum = numAccounts;	// Set account number = num accounts already created
		numAccounts++;	// Increment num accounts created
		cout << customer << " opening account number " << accountNum << " with balance " << openingBalance << endl;
	}
	// Getter functions
	double getBal() const{
		return balance;}
	int getAccountNum() const{
		return accountNum;}
	int getStatus() const{
		return active;}
	string getHolder() const{
		return holder;}
	// Print account history
	void showHistory(){
		for (transaction t : history) cout << t << endl;
	}
	void showBal() const{
		cout << "Balance for " << holder << "'s account: " << balance << endl;}
	// Declare functions for deposit, withdraw and transfer. Defined in bankAccount.cc.
	void deposit(double amount, date dDate, string message);
	void withdraw(double amount, date dDate, string message);
	void transfer(double amount, bankAccount &targetAccount, date dDate, string message);
	// Close account
	void close(void){history.clear(); active = 0;}
private:
	string holder;
	int accountNum;
	double balance;
	date openDate;
	vector<transaction> history;
	static int numAccounts;	// Records number of accounts created
	int active;	// Records if account has been closed
};
#endif