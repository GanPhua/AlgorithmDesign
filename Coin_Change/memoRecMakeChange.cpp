#include <iostream>
using namespace std ;
// 备忘录回溯法求解最少硬币
int memoRecMC(int coinValueList[], int n, int amount, int knownResults[], int coinsUsed[]);
void printCoins(int coinsUsed[], int amount);
int main() {
	int coinValueList[] = {5, 3, 1};
	int amount = 124;
	int knownResults[amount + 1] = {0};
	int coinsUsed[amount + 1] = {0};
	int n = sizeof(coinValueList) / sizeof(coinValueList[0]);
	int minCoins = memoRecMC(coinValueList, n, amount, knownResults, coinsUsed);
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

int memoRecMC(int coinValueList[], int n, int amount, int knownResults[], int coinsUsed[]){
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
   if(knownResults[amount] > 0)
      return knownResults[amount];
   else{
   	    for(int i = 0; i<n; ++i) {
		    if(coinValueList[i] <= amount) {
			    numCoins = 1 + memoRecMC(coinValueList, n, amount - coinValueList[i], knownResults, coinsUsed);
			    if(numCoins < minCoins){
			    	minCoins = numCoins;
				    knownResults[amount] = minCoins;
				    coinsUsed[amount] = coinValueList[i];
	    	    }
	    	}
	    }
	    return minCoins;
   }
}
