#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Bank{
    private:
        int AMD = 500;
        int USD = 1;
        int RUB = 50;
        int passedOperations = 0;
        const int operationMaxLimit = 20;
        string * operations = new string [operationMaxLimit]{""};
   // Bank(){
     //   cout << "Bank balance: " << endl << "AMD: " << AMD << endl << "USD: " << USD << endl << "RUB: " << RUB << endl << "Operations Left: " << operationMaxLimit - passedOperations << endl; 
    //}
    public:
        void Get(int money, int currency);
        void Change(int money, int fromCurrency, int toCurrency);
        void Cash(int money, int currency);
        void getOperations();
        void GetBalance();
        
};

// money   get  from(0, 1, 2) - 0
// money   Cash from(0, 1, 2) - 0
// money  change from (0, 1, 2)  to (0, 1, 2) - 0

