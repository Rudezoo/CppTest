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

		//�׽�Ʈ

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


		cout << "���� �� : ";
		cout << Bingo << endl;

		cout << "[";
		for (int i = 0; i<inputs.size(); i++) {
			cout << inputs[i] << ",";
		}
		cout <<"]"<<endl;

		if (Bingo >= 5) {
			cout << "���� �¸�!" << endl;
			return 0;
		}


		cout << "�ߺ����� �ʴ� ���ڸ� �Է��ϼ��� (1~25����, 0�� ����) : ";
		int input = 0;
		cin >> input;

		if (input > 25) {
			MessageBox(nullptr, TEXT("1~25������ ���ڸ� �Է����ּ���!"), TEXT("Message"), MB_OK);
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
				MessageBox(nullptr, TEXT("�ߺ����� �ʴ� ���ڸ� �Է��ϼ��� !"), TEXT("Message"), MB_OK);
			}

		}

		for (int i = 0; i < 25; i++) {
			if (m[i] == input) {
				m[i] = INT_MAX;
			}
		}
	}


}