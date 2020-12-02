#include <iostream>

using std::cout;
using std::cin;
using std::endl;



int getDigits(int n){
    if(!n)
        return 0;
    return (n % 10 + getDigits(n / 10));
}

int findFactorial(int n){
    if(n == 1)
        return 1;
    return (n * findFactorial(n - 1));
}

int findLen(int n){
    if(!n)
        return 0;
    return (1 + findLen(n / 10));
    }

int main(){
    int num;
    cin >> num;
    cout << getDigits(num) << endl;
    cout << findLen(num) << endl; 
    cout << findFactorial(num);
    return 0;
}
