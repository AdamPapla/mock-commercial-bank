#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
#include <vector>

#include "bankAccount.h"
using namespace std;
struct date{
    int day;
    int month;
    int year;
    friend ostream &operator<< (ostream &os, const date d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
};
class transaction{
public:
    transaction(date tDate, double amount, string message) : transactionDate {tDate}, amount {amount}, message {message}{
        cout << "Constructing transaction of amount " << amount << " on " << transactionDate << " with message "  << message << endl;
    }

private: 
    date transactionDate;
    double amount;
    string message
};


#endif