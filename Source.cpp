#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	string num;
	int numbers[100];
	ofstream outfile ("outfile.txt");
	for (int i = 0; i < 100; ++i) {
		outfile << rand() << endl;
	}
	outfile.close();
	fstream out("outfile.txt", ios::in);
	for (int i = 0; i < 100; ++i) {
		getline(out, num);
		numbers[i] = stoi(num);
	}
	sort(numbers, numbers+100);
	for (int i = 0; i < 100; ++i) {
		cout << numbers[i] << endl;
	}
	return 0;
}