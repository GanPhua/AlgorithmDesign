#include <iostream>
#include <math.h>
/*
һ����Գ����ظ������
�Ľ����洢�Ѿ��ҵ����������ٴ�����ʱֻ��������Ϊ���� 
*/
using namespace std;
int main(){
	int iNum = 1; // 2 is prime
	int iRecN = 1; //��¼�������е���������
	int maxNum = 10000;
	int sqrtMaxN = (int)sqrt(maxNum);
	int iSize = (int)((float)sqrtMaxN/log(sqrtMaxN)*1.25);
	int *iPrime = new int[maxNum==3?1:iSize];
	bool isPrime;
	for(int i =3; i <= maxNum; i+=2){
		isPrime = true;
		for (int j=1; j<iRecN; j++){
			if(i%iPrime[j]==0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			if(i<=sqrtMaxN){ 
		        iPrime[iRecN] = i;
		        iRecN++;
		        iNum = iRecN;
		    }else
		        iNum++;		    
	    }
	}
	cout<< iNum <<endl;
	return 0;
}
