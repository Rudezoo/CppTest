#include <iostream>
#include <random>
#include<vector>
#include <algorithm>
#include <Windows.h>

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
	vector<int> inputs;

	for (int i = 0; i < 25; i++) {
		m[i] = i + 1;
	}

	Mix(m);

	while (1) {

		system("cls");
		int Bingo = 0;

		//for (int i = 0; i < 5; i++) {
		//	for (int j = 0; j < 5; j++) {
		//		if (m[i * 5 + j] == INT_MAX) {
		//			cout << "*\t";
		//		}
		//		else {
		//			cout << m[i * 5 + j] << "\t";
		//		}

		//	}
		//	cout << endl;
		//}

		//테스트

		int star1 = 0;
		int star2 = 0;

		for (int i = 0; i < 5; i++) {
			star1 = star2 = 0;
			for (int j = 0; j < 5; j++) {
				if (m[i * 5 + j] == INT_MAX) {
					star1++;
				}
				if (m[j * 5 + i] == INT_MAX) {
					star2++;
				}
			}
			if (star1 == 5) {
				Bingo++;
			}
			if (star2 == 5) {
				Bingo++;
			}
		}

		star1 = 0;

		for (int i = 0; i < 25; i +=6) {
			if (m[i] == INT_MAX) {
				star1++;
			}
			if (star1 == 5) {
				Bingo++;
			}
		}

		star1 = 0;

		for (int i = 4; i < 24; i +=4) {
			if (m[i] == INT_MAX) {
				star1++;
			}
			if (star1 == 5) {
				Bingo++;
			}
		}


		cout << "빙고 수 : ";
		cout << Bingo << endl;

		cout << "[";
		for (int i = 0; i<inputs.size(); i++) {
			cout << inputs[i] << ",";
		}
		cout <<"]"<<endl;

		if (Bingo >= 5) {
			cout << "게임 승리!" << endl;
			return 0;
		}


		cout << "중복되지 않는 숫자를 입력하세요 (1~25사이, 0은 종료) : ";
		int input = 0;
		cin >> input;

		if (input > 25) {
			MessageBox(nullptr, TEXT("1~25사이의 숫자를 입력해주세요!"), TEXT("Message"), MB_OK);
			continue;
		}
		else if (input == 0) {
			break;
		}
		else {
			if ((find(inputs.begin(), inputs.end(), input)==inputs.end()) ) {
				inputs.push_back(input);
			}
			else {
				MessageBox(nullptr, TEXT("중복되지 않는 숫자를 입력하세요 !"), TEXT("Message"), MB_OK);
			}

		}

		for (int i = 0; i < 25; i++) {
			if (m[i] == input) {
				m[i] = INT_MAX;
			}
		}
	}


}