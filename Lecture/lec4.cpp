#include <iostream>
#include <random>
#include<vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

enum AI_Mode {
	AM_EASY=1,
	AM_HARD=2
};

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
	int Aimatrix[25] = {};
	vector<int> inputs;

	for (int i = 0; i < 25; i++) {
		m[i] = i + 1;
		Aimatrix[i] = i + 1;
	}

	Mix(m);
	Mix(Aimatrix);

	//AI�� ���̵��� �����Ѵ�.

	int iAimode = 0;

	while (1)
	{
		system("cls");

		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "���̵��� �����ϼ��� : ";

		cin >> iAimode;

		if (iAimode >= AM_EASY && iAimode <= AM_HARD) {
			break;
		}

	}

	/*Easy ���� *�� �ٲ��� ���� ���� ����� �����(random)*/

	int iNoneSelect[25] = {}; //���þȵ� ��Ϲ迭
	int iNoneSelectCount = 0;


	while (1) {

		system("cls");
		int Bingo = 0;
		int AiBingo = 0;


		//�׽�Ʈ

		int star1 = 0;
		int star2 = 0;

		int star3 = 0;
		int star4 = 0;

		for (int i = 0; i < 5; i++) {
			star1 = star2 = 0;
			star3 = star4 = 0;
			for (int j = 0; j < 5; j++) {
				if (m[i * 5 + j] == INT_MAX) {
					star1++;
				}
				if (m[j * 5 + i] == INT_MAX) {
					star2++;
				}
				if (Aimatrix[i * 5 + j] == INT_MAX) {
					star3++;
				}
				if (Aimatrix[j* 5 + i] == INT_MAX) {
					star4++;
				}
			}
			if (star1 == 5) {
				Bingo++;
			}
			if (star2 == 5) {
				Bingo++;
			}

			if (star3 == 5) {
				AiBingo++;
			}
			if (star4 == 5) {
				AiBingo++;
			}
		}

		star1 = 0;
		star3 = 0;

		for (int i = 0; i < 25; i += 6) {
			if (m[i] == INT_MAX) {
				star1++;
			}
			if (Aimatrix[i] == INT_MAX) {
				star3++;
			}
			if (star1 == 5) {
				Bingo++;
			}
			if (star3 == 5) {
				AiBingo++;
			}
		}

		star1 = 0;
		star3 = 0;

		for (int i = 4; i < 24; i += 4) {
			if (m[i] == INT_MAX) {
				star1++;
			}
			if (Aimatrix[i] == INT_MAX) {
				star3++;
			}
			if (star1 == 5) {
				Bingo++;
			}
			if (star3 == 5) {
				AiBingo++;
			}
		}
		//������ ���
		cout << "\t======Player======" << endl;
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
		//����� ���
		cout << "���� �� : ";
		cout << Bingo << endl;
		cout << endl;

		cout << "\t======AI======" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Aimatrix[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << Aimatrix[i * 5 + j] << "\t";
				}

			}
			cout << endl;
		}
		//����� ���
		cout << "AI ���� �� : ";
		cout << AiBingo << endl;

		cout << endl;
		cout << "Player ���� �� :";

		cout << "[";
		for (int i = 0; i < inputs.size(); i++) {
			cout << inputs[i] << ",";
		}
		cout << "]" << endl;

		if (Bingo >= 5) {
			cout << "Player �¸�!" << endl;
			return 0;
		}
		if (AiBingo >= 5) {
			cout << "AI �¸�!" << endl;
			return 0;
		}


		/*������� �Է�*/
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
			if ((find(inputs.begin(), inputs.end(), input) == inputs.end())) {
				inputs.push_back(input);
			}
			else {
				MessageBox(nullptr, TEXT("�ߺ����� �ʴ� ���ڸ� �Է��ϼ��� !"), TEXT("Message"), MB_OK);
			}

		}

		/*AI�� ����, ������ �ܼ� ����? => �������ϴ�./ �ι�° ������� *�� �ٲ��� �ʴ� ������ �ϳ��� ����?*/
		/*�ܼ� �������ú��ٴ� ��� ������ �����ؼ�, ������ �ϼ��Ҽ� �ִ� ���ɼ��� ���� ������ ã�Ƴ���*/
		/*�߰������� ����� ���� ���� ����*/

		for (int i = 0; i < 25; i++) {
			if (m[i] == input) {
				m[i] = INT_MAX;
			}
			if (Aimatrix[i] == input) {
				Aimatrix[i] = INT_MAX;
			}
		}
		switch (iAimode) {
			case AM_EASY:
				//���þȵ� ���ڸ���� �����
				//���þȵ� ���ڰ����� ����� ���鶧 ī����
				iNoneSelectCount = 0;
				for (int i = 0; i < 25; i++) {
					if (Aimatrix[i] != INT_MAX) {
						iNoneSelect[iNoneSelectCount] = Aimatrix[i];
						iNoneSelectCount++;
					}
				}
				input =iNoneSelect[Random_Value(0, iNoneSelectCount)];
				
				break;
			case AM_HARD:
				break;

		}
	

		for (int i = 0; i < 25; i++) {
			if (m[i] == input) {
				m[i] = INT_MAX;
			}
			if (Aimatrix[i] == input) {
				Aimatrix[i] = INT_MAX;
			}
		}

	}


}