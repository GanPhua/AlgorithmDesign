#include <iostream>
#include <math.h>
/*
ɸѡ�� 
*/
using namespace std;
int main(){
    int i, iNum = 1, maxNum=10000;
    bool* isPrime = new bool[maxNum+1];
    isPrime[2] = true;
    for(i=3;i<maxNum;i++){
    	isPrime[i++] = true;//����Ϊ��Ϊtrue 
    	isPrime[i] = false;
	}
	if(maxNum % 2 != 0)
	    isPrime[maxNum] = true;  

    for(i=3;i<maxNum;i+=2){
    	if(isPrime[i]){//��ʼʱ��3�ı���ɸ�� 
    		iNum++;
    		if(i<sqrt((double)maxNum))
    		    for(int j=i*i;j<=maxNum;j+=i)
    		        isPrime[j] = false;
		}
	}
    cout<< iNum <<endl;
    return 0;	
} 
