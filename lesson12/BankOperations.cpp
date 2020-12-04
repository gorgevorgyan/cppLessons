#include "Bank.h"
#include <string>
#include <iostream>

using std::to_string;
using std::cout;
using std::endl;

void Bank::GetBalance(){
    cout << "Bank balance: " << endl << "AMD: " << AMD << endl << "USD: " << USD << endl << "RUB: " << RUB << endl << "Operations Left: " << operationMaxLimit - passedOperations << endl;
}

enum Currency{AM, US, RU};

void Bank::Get(int money, int currency){
    if(currency == AM){
        AMD += money;
        operations[passedOperations] = "Accepted " + to_string(money) + " AMD";
    }
    else if(currency == US){
        USD += money;
        operations[passedOperations] = "Accepted " + to_string(money) + " USD";
    }
    else{
        RUB += money;
        operations[passedOperations] = "Accepted " + to_string(money) + " RUB";
    }
    ++passedOperations;
    GetBalance();
}

void Bank::Cash(int money, int currency){
    if(operationMaxLimit - passedOperations > 0){
        if(currency == AM){
            if(AMD >= money)
                AMD -= money;
            else{
                cout << "No enough money!" << endl;
                return;
            }
            operations[passedOperations] = "Cashed " + to_string(money) + " USD";
        }
        else if(currency == US){
            if(USD >= money)
                USD -= money;
            else{
                cout << "No enough money!" << endl;
                return;
            }
            operations[passedOperations] = "Cashed " + to_string(money) + " USD";
        }
        else{
            if(RUB >= money)
                RUB -= money;
            else{
                cout << "No enough money!" << endl;
                return;
            }
            operations[passedOperations] = "Cashed " + to_string(money) + " USD";
        }
        ++passedOperations;
        GetBalance();
    }
    else
        cout << "Operation Limit" << endl;
}

void Bank::Change(int money, int fromCurrency, int toCurrency){
    if(operationMaxLimit - passedOperations){
        if (fromCurrency == AM){
            if(AMD >= money)
                AMD -= money;
            else{
                cout << "No enough money" << endl;
                return;
            }
            if(toCurrency == US){
                USD += money * 0.002;
                operations[passedOperations] = "Change " + to_string(money) + " from AMD to USD ";
            }
            else{
                RUB += money * 0.1;
                operations[passedOperations] = "Change " + to_string(money) + " from AMD to RUB ";
            }
        }
        else if(fromCurrency == US){
            if(USD >= money)
                USD -= money;
            else{
                cout << "NO enough money"  << endl;
                return;
            }
            if(toCurrency == AM){
                AMD += money * 500;
                operations[passedOperations] = "Change " + to_string(money) + " from USD to AMD ";
            }
            else{
                RUB += money * 50;
                operations[passedOperations] = "Change " + to_string(money) + " from USD to RUB ";
            }
        }
        else{
            if(RUB >= money)
                RUB -= money;
            else{
                cout << "No enough money" << endl;
                return;
            }
            if(toCurrency == AM){
                AMD += money * 10;
                operations[passedOperations] = "Change " + to_string(money) + " from RUB to AMD ";
            }
            else{
                USD += money * 0.02;
                operations[passedOperations] = "Change " + to_string(money) + " from RUB to USD ";
            }
        }
        ++passedOperations;
        GetBalance();
    }
    else
        cout << "Operation limit!!" << endl;
}

void Bank::getOperations(){
    for(int i = 0; i < passedOperations; i++){
        if(operations[i] != "")
            cout << i + 1 << ". " << operations[i] << endl;
    }
}

// AMD = 0.002 - USD, 0.1 - RUB
// USD = 500 - AMD, 50 - RUB
// RUB = 10 - AMD, 0.02 - USD