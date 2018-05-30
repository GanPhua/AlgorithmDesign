#include <iostream>
#include <math.h>
/*
筛选法 
*/
using namespace std;
int main(){
    int i, iNum = 1, maxNum=10000;
    bool* isPrime = new bool[maxNum+1];
    isPrime[2] = true;
    for(i=3;i<maxNum;i++){
    	isPrime[i++] = true;//奇数为设为true 
    	isPrime[i] = false;
	}
	if(maxNum % 2 != 0)
	    isPrime[maxNum] = true;  

    for(i=3;i<maxNum;i+=2){
    	if(isPrime[i]){//开始时将3的倍数筛掉 
    		iNum++;
    		if(i<sqrt((double)maxNum))
    		    for(int j=i*i;j<=maxNum;j+=i)
    		        isPrime[j] = false;
		}
	}
    cout<< iNum <<endl;
    return 0;	
} 
