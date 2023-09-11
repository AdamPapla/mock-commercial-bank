#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct date{
    int day;
    int month;
    int year;
    date(int day, int month, int year) : day {day}, month{month}, year {year} {}
    friend ostream &operator<< (ostream &os, const date d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
};
class transaction{
public:
    transaction(date tDate, double amount, string transType, string message) : transactionDate {tDate}, amount {amount}, message {message}{
        cout << "Constructing transaction of amount " << amount << " on " << transactionDate << " with message "  << message << endl;
    }

    friend ostream &operator<< (ostream &os, const transaction t){
        os << t.transactionDate << "\t" << t.transType << "\t" << t.message << "\t" << t.amount << endl;
        return os;
    }

private: 
    date transactionDate;
    double amount;
    string transType;
    string message;
};


#endif