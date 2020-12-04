#include <iostream>
#include "Bank.h"

using std::cout;
using std::cin;
using std::endl;

Bank BankAccount;

void(*operations[])()={
    [](){
        int money;
        int currency;
        cout << "Getting money" << endl;
        cout << "Money: ";
        cin >> money;
        cout << "Currency (AMD-1, USD-2, RUB-3): ";
        cin >> currency;
        BankAccount.Get(money, currency - 1);
    },
    [](){
        int money;
        int currency;
        cout << "Cashing Money" << endl;
        cout << "Money: ";
        cin >> money;
        cout << "Currency (AMD-1, USD-2, RUB-3): ";
        cin >> currency;
        BankAccount.Cash(money, currency - 1);
    },
    [](){
        int money;
        int currency;
        int currency1;
        cout << "Changeing Money" << endl;
        cout << "Money: ";
        cin >> money;
        cout << "Currency from (AMD-1, USD-2, RUB-3): ";
        cin >> currency;
        cout << endl;
        cout << "Currency from (AMD-1, USD-2, RUB-3): ";
        cin >> currency1;
        BankAccount.Change(money, currency - 1, currency1 - 1);
    },
    [](){
        cout << "Showing Balance" << endl;
        BankAccount.GetBalance();
    }, 
    [](){
        cout << "Showing operations" << endl;
        BankAccount.getOperations();
    } 
};

int main(){
    while(true){
        int operation;
        cout << "1. Send Money" << endl << "2. Cash Money" << endl << "3. Change Money" << endl << "4. Get Balance" << endl << "5. Get Operations" << endl << "6. Exit" << endl <<  "Select: ";
        cin >> operation;
        if(operation == 6) break;
        operations[operation - 1]();
    }
    return 0;
}