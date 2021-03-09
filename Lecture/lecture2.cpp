#include <iostream>
#include <random>
#include <chrono>
#include <conio.h> //�ܼ�â���� ����� �ϴ� ����� �������ش�

using namespace std;

int Random_Value(int min, int max) {

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> dis(min, max);

	return dis(gen);
}



int main() {


	int iNumber[25] = {};
	int pos = 24;

	for (int i = 0; i < 24; i++) {
		iNumber[i] = i + 1;
	}

	iNumber[24] = INT_MAX;

	for (int i = 0; i < 100; i++) {
		int idx1 = Random_Value(0, 23);
		int idx2 = Random_Value(0, 23);

		int iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << "\n";

	while (1)
	{
		system("cls");
		for (int i = 0; i < 5; i++) {
			cout << "\t";
			for (int j = 0; j < 5; j++) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}

			}
			cout << "\n\n";
		}

		//���� ���� üũ

		bool bWin = true;

		for (int i = 0; i < 24; i++) {
			if (iNumber[i] != i + 1) {
				bWin = false;
			}
		}

		if (bWin) {
			cout << "���� ����!" << endl;
			return 0;
		}

		cout << "w : ��, s: �Ʒ� , a: ����  ,d:������ , q: ���� ==> ";
		
		char input = _getch(); //���ڸ� 1���� �Է¹޴� �Լ�. Enter�� ġ���ʾƵ� �νĵȴ�.
		
		switch (input)
		{
		case 'w':
		case 'W':
			if (pos - 5 >= 0) {
				iNumber[pos] = iNumber[pos - 5];
				iNumber[pos - 5] = INT_MAX;
				pos-= 5;
			}
			
			break;
		case 's':
		case 'S':
			if (pos +5 <=24) {
				iNumber[pos] = iNumber[pos + 5];
				iNumber[pos + 5] = INT_MAX;
				pos += 5;
			}

			break;
		case 'a':
		case 'A':
			if (pos%5!=0) {
				iNumber[pos] = iNumber[pos -1];
				iNumber[pos - 1] = INT_MAX;
				pos -=1;
			}

			break;
		case 'd':
		case 'D':
			if (pos % 5 != 4) {
				iNumber[pos] = iNumber[pos + 1];
				iNumber[pos + 1] = INT_MAX;
				pos += 1;
			}

			break;
		case 'Q':
		case 'q':
			cout << "������ �����մϴ�" << endl;
			return 0;
		default:
			break;
		}
	}


	return 0;
}