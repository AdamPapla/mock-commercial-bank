#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "transaction.h"
#include "bankAccount.h"
using namespace std;
// Initiate static variable number of accounts to 0
int bankAccount::numAccounts = 0;
int main(void){
    date todaysDate(12,9,2023); // Creating date object with todays date
    vector<bankAccount> accounts; // Container to store bank account
    string firstName;
    string lastName;
    cout << "Welcome to Aughnish Bank\n_____________________________________\n\n" << 
    "For help, enter \"help\" to see a list of available options" << endl;
    // Now read in from command line untiluser has finished entering commands
    while (true){
        cout << endl << "> ";
        string command;
        cin >> command;
        if (command == "end")   // If user types end, break
            break;
        // Opening account
        else if(command == "open"){
            int openBalance;
            // Read in details from command line then construct bank account object
            cin >> firstName >> lastName >> openBalance;
            accounts.push_back(bankAccount (firstName+lastName, openBalance, todaysDate));
        }
        // Deposit
        else if (command == "deposit"){
            int accountNum, amount;
            string message;
            cin >> accountNum >> amount;
            getline(cin, message);
            // Check if account exists and is open
            if (accountNum < 0 || accountNum > accounts.size() || (accounts[accountNum]).getStatus() == 0){
                cout << "Invalid account number entered. Account either does no exist or was closed" << endl;
                continue;
            }
            else{
                // Try to deposit, catching any exceptions
                try{
                accounts[accountNum].deposit(amount, todaysDate, message);}
                catch(invalid_argument &e){
                    cout << e.what() << endl;
                }
            }
        }
        // Withdraw
        else if (command == "withdraw"){
            int accountNum, amount;
            string message;
            cin >> accountNum >> amount;
            // Read in the remainder of the line into the message variable
            getline(cin, message);
            if (accountNum < 0 || accountNum > accounts.size() || (accounts[accountNum]).getStatus() == 0){
                cout << "Invalid account number entered. Account either does no exist or was closed" << endl;
                continue;
            }
            else{
                // Attempt to withdraw. Will throw error if attempting to withdraw too much/ a negative numbe
                try{
                accounts[accountNum].withdraw(amount, todaysDate, message);}
                catch(invalid_argument &e){
                    cout << e.what() << endl;
                }
            }
        }
        // Transfer
        else if (command == "transfer"){
            int sourceAccount, destAccount, amount;
            string message;
            cin >> sourceAccount >> destAccount >> amount;
            getline(cin, message);
            // Check that source account and destination account exist and are open
            if (sourceAccount < 0 || sourceAccount > accounts.size() || (accounts[sourceAccount]).getStatus() == 0){
                cout <<"Invalid source account for transfer. Account either does not exist or was closed"<< endl;
                continue;
            }
            else if (destAccount < 0 || destAccount > accounts.size() || (accounts[destAccount]).getStatus() == 0){
                cout << "Invalid destination account for transfer. Account either does not exist or was closed" <<endl;
                continue;
            }
            else{
                // Perform the transfer
                try{
                    accounts[sourceAccount].transfer(amount, accounts[destAccount], todaysDate, message);}
                catch(invalid_argument& e){
                    cout << e.what() << endl;
                }
            }
        }
        //Display account history
        else if (command == "history"){
            int account;
            cin >> account;
            if (account < 0 || account > accounts.size() || (accounts[account]).getStatus() == 0){
                cout << "Invalid account to display history. Account either does not exist or was closed" << endl;
                continue;
            }
            else{
                accounts[account].showHistory();
            }
            // Flush rest of line
            string junk;
            getline(cin, junk);
        }
        // Close account
        else if (command == "close"){
            int account;
            cin >> account;
            if (account < 0 || account > accounts.size() || (accounts[account]).getStatus() == 0){
                cout << "Invalid account to close. Account either does not exist or was already closed" << endl;
                continue;
            }
            else{
                accounts[account].close();
            }
            string junk;
            getline(cin, junk); // Read in any extra characters as junk
        }
        // Display all aopen accounts
        else if(command == "accounts"){
            for (bankAccount &a: accounts){
                if (a.getStatus() == 1){
                    cout << setw(10) << left << a.getAccountNum() << setw(20) << left << a.getHolder() << setw(10) << left << a.getBal() << endl;
                }
            } 
            string junk;
            getline(cin, junk);
        }
        // Print available options for user, as well as their arguments
        else if (command == "help"){
            cout << "Options:" << endl <<
                    setw(20) << left << "Open account:" << setw(10) << left << "open" << setw(24) << left <<  "firstname" << setw(24) << left 
                    << "lastname" << setw(12) << left << "openbal" <<endl << 
                    setw(20) << left << "Make deposit:" << setw(10) << left << "deposit" << setw(24) << left <<  "Account Num" << setw(24) << left 
                    << "Amount" << setw(12) << left << "Message" <<endl << 
                    setw(20) << left << "Make withdrawal:" << setw(10) << left << "withdraw" << setw(24) << left <<  "Account Num" << setw(24) << left 
                    << "Amount" << setw(12) << left << "Message" <<endl << 
                    setw(20) << left << "Make transfer:" << setw(10) << left << "transfer" << setw(24) << left <<  "Source Account Num" << setw(24) << left 
                    << "Dest Account Num" << setw(12) << left << "Amount" << setw(12) << left << "Message" << endl << 
                    setw(20) << left << "Account history:" << setw(10) << left << "history" << setw(24) << left <<  "Account Num" << endl << 
                    setw(20) << left << "Close account:" << setw(10) << left << "close" << setw(24) << left <<  "Account Num" << endl << 
                    setw(20) << left << "Show open accounts:" << setw(10) << left << "accounts" << endl;
        }
        else{
            cout << "Invalid option entered. Please type help to see available options" << endl;
        }

    }
    return 0;
}

