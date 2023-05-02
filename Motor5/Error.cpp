#include <iostream>
using namespace std;

void fatalError(string errorString) {
	cout << errorString << "\n";
	cout << "Enter any key to quit" << "\n";
	int tmp;
	cin >> tmp;
	exit(-1);
}
