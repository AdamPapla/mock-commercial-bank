#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Date struct used to record date of actions such as account opening/transactions
struct date{
    int day;
    int month;
    int year;
    date(int day, int month, int year) : day {day}, month{month}, year {year} {}
    // Override << to allow printing date. Include setw() for alignment
    friend ostream &operator<< (ostream &os, const date d) {
        os << d.day << "/" << d.month << "/" << setw(15) << left << d.year;
        return os;
    }
};

// Transaction class. Contains all necessary details of a transaction, including
// date of transaction, amount, type of transaction, message attached
class transaction{
public:
    // Custom constructor with meber initialisation list.
    transaction(date tDate, double amount, string transType, string message) : transactionDate {tDate}, transType {transType}, amount {amount}, message {message}{
    }
    // Define how a transaction is to be printed
    friend ostream &operator<< (ostream &os, const transaction t){
        os << t.transactionDate << setw(15) << left << t.transType << setw(50) << left << t.message << setw(10) << left << t.amount << endl;
        return os;
    }

private: 
    date transactionDate;
    double amount;
    string transType;
    string message;
};


#endif