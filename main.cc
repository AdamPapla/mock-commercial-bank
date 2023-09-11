#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "bankAccount.h"
using namespace std;

int bankAccount::numAccounts = 0;
int main(void){
    date todaysDate(10,9,2023);
    bankAccount("Adam Graham", 10.0, todaysDate);
    return 0;
}

