#include <iostream>
using namespace std;
void greedyMakeChange(int coinValueList[], int coinCount[], int amount, int n); 
int main() {
	//�������У���һ��Ϊ��Ǯ���ڶ��ж�Ӧ��һ��λ��Ϊ��Ӧ�ĸ��� 
	int amount = 11;
	int coinValueList[] = { 5, 3, 1 };
	int n = sizeof(coinValueList) / sizeof(coinValueList[0]);
	int coinCount[n] = { 0 };
	greedyMakeChange(coinValueList, coinCount, amount, n);
	for (int i = 0; i < n; ++i) {
		printf("%d\t", coinValueList[i]);
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		printf("%d\t", coinCount[i]);
	}
	return 0;
}

void greedyMakeChange(int coinValueList[], int coinCount[], int amount, int n){
	int i = 0;
	while (amount > 0 && i < n) {
		int count = amount / coinValueList[i];
		amount -= count * coinValueList[i];
		coinCount[i] = count;
		i++;
	}
}
