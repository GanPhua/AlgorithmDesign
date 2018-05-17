#include <iostream>
#include <stdio.h>
using namespace std ;
// ���ݷ��������Ӳ��
int recMC(int coinValueList[], int n, int amount, int coinsUsed[]);
void printCoins(int coinsUsed[], int amount);
int main() {
	int coinValueList[] = {5, 3, 1};
	int amount = 124;
	int minCoins;
	int coinsUsed[12] = {0};
	int n = sizeof(coinValueList) / sizeof(coinValueList[0]);
	minCoins = recMC(coinValueList, n, amount, coinsUsed);
	printf("minmunCoins = %d\n", minCoins);
	printCoins(coinsUsed, amount);
	system("pause");
	return 0;
}

void printCoins(int coinsUsed[], int amount) {
	int coin = amount;
	while(coin > 0) {
		int thisCoin = coinsUsed[coin];
		cout<< thisCoin << endl;
		coin = coin - thisCoin;
	}
}

int recMC(int coinValueList[], int n, int amount, int coinsUsed[]) {
	int minCoins = amount;
	int numCoins = 0;
	// �����Ҫ�һ������Ϊĳһ��Ǯ��ֵʱֱ�ӷ���1
	for(int i=0; i < n; i++) {
		int a = coinValueList[i];
		if (coinValueList[i] == amount) {
			coinsUsed[amount] = coinValueList[i];
			return 1;
		}
	}
	for(int i = 0; i<n; ++i) {
		if(coinValueList[i] <= amount) {
			numCoins = 1 + recMC(coinValueList, n, amount - coinValueList[i], coinsUsed);
			if(numCoins < minCoins){
				minCoins = numCoins;
				coinsUsed[amount] = coinValueList[i];
			}		
		}
	}
	return minCoins;
}
