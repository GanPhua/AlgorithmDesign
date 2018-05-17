#include <iostream>
#include <stdio.h>
using namespace std ;
// 回溯法求解最少硬币
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
	// 如果需要兑换的面额为某一零钱面值时直接返回1
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
