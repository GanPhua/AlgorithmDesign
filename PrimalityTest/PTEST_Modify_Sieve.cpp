#include <iostream>
#include <mem.h>
#include <math.h>
/*
改进的筛选法
筛选法会重复筛，也就是某个数可能有几个数，以这些数为底的指数 
选用最小素因子筛选
*/
using namespace std;
int main(){
    const int maxNum = 10000;
    bool flag[maxNum];
	int* prime = new int[maxNum/3];
    int iNum = 0;
    memset(flag, false, sizeof(flag));
    for (int i = 2; i < maxNum; i++){
        if (!flag[i])
        	prime[iNum++] = i;
		//让每个合数仅被它的最小素因子筛去一次
		//e.g. 12 = 6*2(i=6)=4*3(i=4); 2是12的最小素因子，3不是
		//4*3不会发生，因为4*2(i=4),这个时候4%2==0，就不乘下个素数3了
        for (int j = 0; (j < iNum)  && (i * prime[j] < maxNum); j++){
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0)// 当i被当前素数整除时不与下个素数运算
                break;
        }
    }
    cout<< iNum <<endl;
    return 0;	
} 
