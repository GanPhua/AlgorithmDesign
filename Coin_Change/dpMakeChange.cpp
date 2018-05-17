/*动态规划解最少硬币兑换 */
#include <iostream>
using namespace std;
void dpMakeChange(int coinCount[], int amount, int coinValueList[], int n, int coinsUsed[]);
void printCoins(int coinsUsed[], int amount);
int main() {
	int amount = 124;
	int coinValueList[] = { 1, 3, 5 };
	int n = sizeof(coinValueList) / sizeof(coinValueList[0]);
	int coinCount[amount + 1] = { 0 };
	int coinsUsed[amount + 1] = { 0 };

	dpMakeChange(coinCount, amount, coinValueList, n, coinsUsed);
	cout << "最优解就是最少值为：" << coinCount[amount] << endl;
	printCoins(coinsUsed, amount);
}

void dpMakeChange(int coinCount[], int amount, int coinValueList[], int n, int coinsUsed[]) {
	for (int j = 1; j <= amount; j++) {
		coinCount[j] = j;
		for (int i = 1; i <= n; i++) {
			if (j >= coinValueList[i] && (1 + coinCount[j - coinValueList[i]]) < coinCount[j]) {
				coinCount[j] = 1 + coinCount[j - coinValueList[i]];
				coinsUsed[j] = coinValueList[i];
			}
		}
	}
}

void printCoins(int coinsUsed[], int amount) {
	cout << "依此使用以下面额硬币:" << endl;
	int coin = amount;
	while (coin > 0) {
		int thisCoin = coinsUsed[coin];
		cout << thisCoin << endl;
		coin = coin - thisCoin;
	}
}