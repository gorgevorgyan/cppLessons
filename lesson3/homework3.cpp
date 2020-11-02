#include <iostream>
#include <string.h>
#include <sstream>


using std::cout;
using std::endl;
using std::cin;

int numSum(int);

int numSum(int n) {
	int myNum = 0;
	std::string numS(n, '1');
	std::stringstream intValue(numS);
	intValue >> myNum;
	if (n > 1)
		return myNum + numSum(n - 1);
	else
		return 1;
}

void homeWork1() {   //Prime check
	int n, i, m = 0, result = 0;
	cin >> n;
	m = n / 2;
	for (i = 2; i <= m; i++)
	{
		if (n % i == 0)
		{
			cout << "No" << endl;
			result = 1;
			break;
		}
	}
	if (result == 0)
		cout << "YES" << endl;
}

void homeWork2() {   // Number Sum
	int num;
	cin >> num;
	cout << numSum(num);
}

void homeWork3() {	// Digit Sum
	int num, sum = 0;
	cin >> num;
	while (num < 100000 || num > 999999)
	{
		cin >> num;
	}
	while (num != 0)
	{
		sum = sum + num % 10;
		num = num / 10;
	}
	cout << sum;
}

void homeWork4() {		// Digit Counter
	int n, i, j, ctr, r;
	cin >> n;
	for (i = 0; i < 10; i++)
	{
		cout << "The frequency of " <<  i << "-s is ";
		ctr = 0;
		for (j = n; j > 0; j = j / 10)
		{
			r = j % 10;
			if (r == i)
			{
				ctr++;
			}
		}
		cout << ctr << endl;
	}
}

int main() {

	homeWork4();
	return 0;

}

