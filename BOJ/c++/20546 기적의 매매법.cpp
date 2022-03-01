#include <iostream>
using namespace std;
int money;//�����̿� �������� ����
int days[15]; //�� ���� �ְ�

// 1.14 ���� �������� �ڻ��� return
int getJ(int m) {
	int b_stock = 0;
	for (int i = 0; i < 14; i++) {
		if (days[i] <= m) {
			b_stock += m / days[i];
			m = m % days[i];
		}
	}
	return (m + b_stock * days[13]);
}

// 1.14 ���� �������� �ڻ��� return
int getS(int m) {
	int isIncreasing = 0; // n�� ° ���� �����
	int isDecreasing = 0; // n�� ° ���� �϶���

	int b_stock = 0; // �����ϰ� �ִ� �ֽ� ��
	int prevDay = days[0];
	for (int i = 1; i < 14; i++) {

		if (days[i] < prevDay) {
			isDecreasing++;
			isIncreasing = 0;
		}
		else if (days[i] > prevDay) {
			isIncreasing++;
			isDecreasing = 0;
		}
		if (isDecreasing >= 3) {
			if (days[i] <= m) {
				b_stock += m / days[i];
				m = m % days[i];
			}
		}
		else if (isIncreasing >= 3) {
			m += (days[i] * b_stock);
			b_stock = 0;
		}
		prevDay = days[i];
	}
	return (m + b_stock * days[13]);
}
int main() {
	cin >> money;
	for (int i = 0; i < 14; i++) cin >> days[i];

	int j = getJ(money);
	int s = getS(money);
	if (s == j) {
		cout << "SAMESAME\n";
	}
	else if (s > j) {
		cout << "TIMING\n";
	}
	else cout << "BNP\n";
	return 0;
}