#include <iostream>
#include <random>

using namespace std;

//���� ��ȭ Ȯ��

float RandomRange(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);

	float percent = dis(gen) / (max / 100);

	return dis(gen);
}

int main()
{

	while (1)
	{

		int iUpgrade;

		cout << "���׷��̵� ��ġ�� �Է����ּ��� : ";
		cin >> iUpgrade;

		//�̶� 1-3 ������ 100%, 4-6������ 40%,
		//7-9������ 10%, 10-13������ 1%, 14-15 ������ 0.01%

		if (iUpgrade <= 3)
		{
			cout << "��ȭ ����" << endl;
		}
		else if (iUpgrade >= 4 && iUpgrade <= 6)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <= 40.f)
			{
				cout << "��ȭ ����" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "��ȭ ����" << endl;
			}
		}
		else if (iUpgrade >= 7 && iUpgrade <= 9)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <= 10.f)
			{
				cout << "��ȭ ����" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "��ȭ ����" << endl;
			}
		}
		else if (iUpgrade >= 10 && iUpgrade <= 13)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <= 1.f)
			{
				cout << "��ȭ ����" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "��ȭ ����" << endl;
			}
		}
		else if (iUpgrade >= 14 && iUpgrade <= 15)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <=0.01f)
			{
				cout << "��ȭ ����" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "��ȭ ����" << endl;
			}
		}
	}
}