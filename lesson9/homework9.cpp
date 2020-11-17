#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int breaker[1]{0};
int oddLen;
int evenLen;

int getNumber(int state){
    int num;
    cout << "Enter number: ";
    cin >> num;
    for(int i = 0; i < 2; i++){
        if((!state) ? (num >= 1 && num <= 10) : (num >= 1 && num <= 10000)) return num;
        else{
            cout << "Number must be " << ((state) ? "[1, 10000]" : "[1, 10]") << endl << "Enter Number: ";
            cin >> num;
        }
    }
    cout << "3 times wrong input." << endl;
    return 0;
}

int * appendElems(int n){
    int * elemsArr = new int[n];
    int gotNum;
    for(int i = 0; i < n; i++){
        gotNum = getNumber(1);
        if(gotNum) elemsArr[i] = gotNum;
        else return breaker;
    }
    return elemsArr;

}

int getArrLength(int arr[], int size, int type){
    int len = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == ((type) ? 1 : 0)) len++;
    }
    cout << ((type) ? "Odd " : "Even ") << "array length is " << len << endl;
    if(type) oddLen = len;
    else evenLen = len;
    return len; 
}

void someProcss(int arr[], int size, int proc){
    int out = ((proc != 1) ? 0 : 1);
    if(!proc || proc == 2){
        for(int i = 0; i < size; i++) out += arr[i];
        cout << ((!proc) ? "Sum " : "Avarage ") << "of array elements is " << ((!proc) ? out : out / size) << endl;
    }
    else{
        for(int i = 0; i < size; i++) out *= arr[i];
        cout << "Multiple of array elements is " << out << endl;
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int * getOdd(int arr[], int size){
    int * oddElems = new int[getArrLength(arr, size, 1)];
    int state = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2){
            oddElems[state] = arr[i];
            ++state;
        }
    }
    return oddElems;
}

int * getEven(int arr[], int size){
    int * evenElems = new int[getArrLength(arr, size, 0)];
    int state = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            evenElems[state] = arr[i];
            state++;
        }
    }
    return evenElems;
}

int findNumber(int arr[], int size, int type){
    int high = 0, low = 999999;
    if(type){
        for(int i = 0; i < size; i++){
            if(arr[i] > high) 
                high = arr[i];
        }
        cout << "The largest number is: " << high << endl;
        return high;
    }
    else{
        for(int i = 0; i < size; i++){
            if(arr[i] < low) low = arr[i];
        }
        cout << "The smallest number is: " << low << endl;
        return low;
    }
}

int main(){
    int size = getNumber(0);
    int * addrArr;
    int * addrOdd;
    int * addrEven;
    if(!size) return 0;
    addrArr = appendElems(size);
    if(!addrArr[0]) return 0;
    addrOdd = getOdd(addrArr, size);
    addrEven = getEven(addrArr, size);
    int arrSize = (sizeof(addrOdd) / sizeof(*addrOdd));
    for(int i = 0; i < 3; i++){
        cout << "Odd: ";
        someProcss(addrOdd, oddLen, i);
        cout << "Even: ";
        someProcss(addrEven, evenLen, i);
    }
    cout << "Odd: ";
    findNumber(addrOdd, oddLen, 0);
    cout << "Odd: ";
    findNumber(addrOdd, oddLen, 1);
    cout << "Even: ";
    findNumber(addrEven, evenLen, 0);
    cout << "Even: ";
    findNumber(addrEven, evenLen, 1); 
    delete addrEven;
    delete addrOdd;
    delete addrArr;
}