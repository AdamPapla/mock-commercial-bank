// File containing member functions for bank account class
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "bankAccount.h"
using namespace std;


void bankAccount::deposit(double amount, date dDate, string message){
    if (amount < 0){
        throw invalid_argument("Cannot deposit a negative sum");
    }
    balance += amount;
    transaction thisDeposit(dDate, amount, "deposit", message);
    history.push_back(thisDeposit);
    cout << "Depositing " << amount << " to account number " << accountNum << ". New balance "<< balance << endl;
}

void bankAccount::withdraw(double amount, date dDate, string message){
    if (amount < 0){
        throw invalid_argument("Cannot withdraw a negative sum");
    }
    else if (amount > balance){
        throw invalid_argument("Withdrawal amount is greater than account balance");
    }
    balance -= amount;
    transaction thisWithdrawal(dDate, amount, "withdrawal", message);
    history.push_back(thisWithdrawal);
    cout << "Withdrawing " << amount << " from account number " << accountNum << ". New balance "<< balance << endl;
}

void bankAccount::transfer(double amount, bankAccount &targetAccount, date dDate, string message){
    string withdrawalMessage = "Transfer to account num ";
    withdrawalMessage += to_string(targetAccount.getAccountNum()) + ": " + message;
    string depositMessage = "Transfer from account num ";
    depositMessage += to_string(accountNum);
    depositMessage += ": " + message;
    try{
        withdraw(amount, dDate, withdrawalMessage);
        targetAccount.deposit(amount, dDate, depositMessage);
    }
    catch(invalid_argument& e){
        throw invalid_argument(e.what());
    }
}