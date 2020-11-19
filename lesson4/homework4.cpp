#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int getNum(int start, int end, int wrong, int def=-1) {
	int num;
	int count = 0;
	while (true) {
	    cin >> num; 
	    if (num >= start && num <= end) 
	        break;
	    count++;
		if(count >= wrong){
		    cout << "You entered incorrect number 3 times. Exiting.";
		    return def;
		}
		cout << "Entered number should be in [1,1000] interval" << endl;
	}
	return num;
}

int calcSum(int myNum){
    int digitSum = 0;
    while (myNum != 0) {
		digitSum += myNum % 10;
		myNum /= 10;
	}
    return digitSum;
}

bool checkNumDigitSum(int num) {
	int digitSum = calcSum(num);
	return ((num % digitSum) == 0); 
}

int findNums(int start, int end) {
    int count = 0;
	for (int i = start; i <= end; i++) {
        if(checkNumDigitSum(i))
            count++;
	}
	return count;
}

int main() {

	int myNum = getNum(1, 1000, 3);
	if (myNum != -1) {
		cout << (checkNumDigitSum(myNum)) ? "Yes" : "No" << endl;
		cout << findNums(1, myNum - 1) << endl;
		cout << findNums(myNum + 1, 1000) << endl;
	}
	return 0;

}
