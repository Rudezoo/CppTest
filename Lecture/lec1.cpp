#include <iostream>
#include <random>

using namespace std;

//랜덤 강화 확률

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

		cout << "업그레이드 수치를 입력해주세요 : ";
		cin >> iUpgrade;

		//이때 1-3 구간은 100%, 4-6구간은 40%,
		//7-9구간은 10%, 10-13구간의 1%, 14-15 구간은 0.01%

		if (iUpgrade <= 3)
		{
			cout << "강화 성공" << endl;
		}
		else if (iUpgrade >= 4 && iUpgrade <= 6)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <= 40.f)
			{
				cout << "강화 성공" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "강화 실패" << endl;
			}
		}
		else if (iUpgrade >= 7 && iUpgrade <= 9)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <= 10.f)
			{
				cout << "강화 성공" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "강화 실패" << endl;
			}
		}
		else if (iUpgrade >= 10 && iUpgrade <= 13)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <= 1.f)
			{
				cout << "강화 성공" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "강화 실패" << endl;
			}
		}
		else if (iUpgrade >= 14 && iUpgrade <= 15)
		{
			float enf = RandomRange(0, 100000) / 1000.f;
			if (enf <=0.01f)
			{
				cout << "강화 성공" << endl;
			}
			else
			{
				cout << enf << endl;
				cout << "강화 실패" << endl;
			}
		}
	}
}