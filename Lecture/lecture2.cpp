#include <iostream>
#include <random>
#include <chrono>
#include <conio.h> //콘솔창에서 입출력 하는 기능을 제공해준다

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

		//게임 성공 체크

		bool bWin = true;

		for (int i = 0; i < 24; i++) {
			if (iNumber[i] != i + 1) {
				bWin = false;
			}
		}

		if (bWin) {
			cout << "게임 성공!" << endl;
			return 0;
		}

		cout << "w : 위, s: 아래 , a: 왼쪽  ,d:오른쪽 , q: 종료 ==> ";
		
		char input = _getch(); //문자를 1개를 입력받는 함수. Enter를 치지않아도 인식된다.
		
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
			cout << "게임을 종료합니다" << endl;
			return 0;
		default:
			break;
		}
	}


	return 0;
}