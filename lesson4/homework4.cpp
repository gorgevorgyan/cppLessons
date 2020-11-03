#include <iostream>
#include <string.h>
#include <sstream>


using std::cout;
using std::endl;
using std::cin;

int getNum() {
	int num;
	cin >> num;
	while (num < 1 || num > 1000) {
		for (int i = 0; i < 2; i++) {
			cout << "Entered number should be in [1,1000] interval" << endl;
			cin >> num;
			if (num >= 1 && num <= 1000)
				return num;
		}
		cout << "You entered incorrect number 3 times. Exiting.";
		return -1;
	}
	return num;
}

void checkNumDigitSum(int num) {
	int myNum = num;
	int sumNum = num;
	int digitSum = 0;
	while (myNum != 0) {
		digitSum += myNum % 10;
		myNum /= 10;
	}
	if (!(sumNum % digitSum))
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;
}

void findNums(int n) {
	for (int i = 1; i < n - 1; i++) {
		int iState = i;
		int iSum = 0;
		while (iState != 0) {
			iSum += iState % 10;
			iState /= 10;
		}
		if (!(i % iSum))
			cout << i << endl;
	}
}

int main() {

	int myNum = getNum();
	if (myNum != -1) {
		checkNumDigitSum(myNum);
		findNums(myNum);
	}
	return 0;

}

