#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define SIZE 5

int reverseEdArr[SIZE]{};
int posArr[SIZE]{};
int multArr[SIZE]{};

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int * reverse(int arr[], int size){
    
    for(int i = 0; i < size; i++)
        reverseEdArr[i] = arr[size - 1 - i];
    return reverseEdArr;
}

int * changePos(int arr[], int size){
    
    for(int i = 0; i < size; i++)
        (i == 0) ? posArr[0] = arr[size - 1] : (i == size - 1) ? posArr[size - 1] = arr[size - 2] : posArr[i] = arr[i - 1];
    return posArr;  
}

int * arrMult(int arr[], int size){
    for(int i = 0; i < size; i++)
        (i == size - 1) ? multArr[size - 1] = arr[size - 1] * arr[0] : multArr[i] = arr[i] * arr[i + 1];
    return multArr;
}


int multFuncMult(int arr[], int arr1[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i] * arr1[i];
    return sum;
}

int main(){
    int inputArr[SIZE]{};
    for(int i = 0; i < SIZE; i++)
        cin >> inputArr[i];
    int* addr1;
    int* addr2;
    int* addr3;
    addr1 = reverse(inputArr, SIZE);
    printArr(addr1, SIZE);
    addr2 = changePos(inputArr, SIZE);
    addr1 = reverse(addr2, SIZE);
    printArr(addr1, SIZE);
    addr3 = arrMult(inputArr, SIZE);
    addr1 = reverse(addr3, SIZE);
    printArr(addr1, SIZE);
    addr2 = changePos(inputArr, SIZE);
    addr3 = arrMult(inputArr, SIZE);
    cout << multFuncMult(addr2, addr3, SIZE);
}