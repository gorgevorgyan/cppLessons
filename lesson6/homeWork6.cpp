#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

int myList[10] = {};

void setupList(){
    for(int i = 0; i < 5; i++){
        int myNum;
        cin >> myNum;
        myList[i] = myNum;
    }
}

float findSum(int state){
    int sum = ((!state || state == 2) ? 0 : 1);
    for(int i = 0; i < 5; i++){
        (!state || state == 2) ? sum += myList[i] : sum *= myList[i];
        }
    if(state == 2)
        return sum / 5;
    return sum;   
}

float findMedSum(float sum, float mult){
    return (sum + mult) / 2;
}

void (*homeworks[])()={

    [](){
        setupList();
        for (int i = 0; i < 3; i++)
            cout << findSum(i) << endl;
        cout << findMedSum(findSum(0), findSum(1)) << endl;
    },
    [](){
        int sortList[10]{};
        for(int i = 0; i < 10; i++){
            int getNum;
            cout << "Enter N" << i << ":";
            if(cin >> getNum){
                sortList[i] = getNum;
                std::sort(sortList, sortList + sizeof(sortList) / sizeof(sortList[0]));
                cout << "Array elements are: ";
                for(int j = 0; j < sizeof(sortList) / sizeof(sortList[0]); j++){
                    int listNum;
                    listNum = sortList[j];
                    if(listNum > 0)
                        cout << sortList[j] << " "; 
                }
                    
                cout << endl;
            }
            
            else{
                cout << "You should enter a number. Stopping.";
                return;
            }
        }
    },

};

int main(){
    cout << "Enter homeWork number(1, 2)";
    int hmNm;
    cin >> hmNm;
    homeworks[hmNm - 1]();
    return 0;
};