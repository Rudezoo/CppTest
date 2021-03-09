#include <iostream>
#include <random>
#include <conio.h>

using namespace std;

int Random_Value(int min, int max) {

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> dis(min, max);

	return dis(gen);
}

void Mix(int* matrix) {
	for (int i = 0; i < 100; i++) {
		int idx1 = Random_Value(0, 24);
		int idx2 = Random_Value(0, 24);

		int iTemp = matrix[idx1];
		matrix[idx1] = matrix[idx2];
		matrix[idx2] = iTemp;
	}
}

int main() {

	int m[25] = {};

	for (int i = 0; i < 25; i++) {
		m[i] = i + 1;
	}

	Mix(m);

	while (1) {

		system("cls");

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (m[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << m[i * 5 + j] << "\t";
				}

			}
			cout << endl;
		}

		cout << "숫자를 입력하세요 : ";
		int input = 0;
		cin >> input;

		cout << input << endl;

		for (int i = 0; i < 25; i++) {
			if (m[i] == input) {
				m[i] = INT_MAX;
			}
		}
	}


}