#include <iostream>
#include <random>
#include<vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

enum AI_Mode {
	AM_EASY = 1,
	AM_HARD = 2
};

enum LINE_NUMBER {
	LN_H1 = 0,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
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
				if (Aimatrix[j * 5 + i] == INT_MAX) {
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




		if (Bingo >= 5 || AiBingo >= 5) {
			if (Bingo == AiBingo) {
				cout << "Draw!" << endl;
				return 0;
			}
			else {
				if (Bingo >AiBingo) {
					cout << "Player �¸�!" << endl;
					return 0;
				}else{
					cout << "Ai �¸�!" << endl;
					return 0;
				}
			}
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
			input = iNoneSelect[Random_Value(0, iNoneSelectCount)];

			break;
		case AM_HARD:
			//���� ������ ������ �ϼ� ���ɼ��� ���� ���� ���� ã�Ƽ� ���ٿ� �ִ� ������ �ϳ��� * �θ����.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� ���� ���� ������ ã�Ƴ���
			for (int i = 0; i < 5; i++) {
				iStarCount = 0;
				for (int j = 0; j < 5; j++) {
					if (Aimatrix[i * 5 + j] == INT_MAX) {
						iStarCount++;
					}
				}

				//�� �ټ��� �̸�, ������ ���� ���� ������ ������ Ŀ�� ���� ���� ����(lik max value)
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ���� ���� ���� ������ ã�Ƴ���
			for (int i = 0; i < 5; i++) {
				iStarCount = 0;
				for (int j = 0; j < 5; j++) {
					if (Aimatrix[j * 5 + i] == INT_MAX) {
						iStarCount++;
					}
				}

				//�� �ټ��� �̸�, ������ ���� ���� ������ ������ Ŀ�� ���� ���� ����(lik max value)
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			//����->������ �밢��
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6) {
				if (Aimatrix[i] == INT_MAX) {
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			//����->������ �밢��
			iStarCount = 0;
			for (int i = 4; i < 24; i += 4) {
				if (Aimatrix[i] == INT_MAX) {
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}


			//���ɼ��� ���� ������ iLine�� ����
			//���پȿ� *�� �ƴ� ������ �ϳ��� �����Ѵ�.

			//�������� ���
			if (iLine <= LN_H5) {
				for (int i = 0; i < 5; i++) {
					if (Aimatrix[iLine * 5 + i] != INT_MAX) {
						input = Aimatrix[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_H5) {
				for (int i = 0; i < 5; i++) {
					if (Aimatrix[i * 5 + (iLine - 5)] != INT_MAX) {
						input = Aimatrix[i * 5 + (iLine - 5)];
						break;
					}
				}
			}
			else if (iLine == LN_LT) {
				for (int i = 0; i < 25; i += 6) {
					if (Aimatrix[i] != INT_MAX) {
						input = Aimatrix[i];
						break;
					}
				}
			}
			else if (iLine == LN_RT) {
				for (int i = 4; i < 24; i += 4) {
					if (Aimatrix[i] != INT_MAX) {
						input = Aimatrix[i];
						break;
					}
				}
			}


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