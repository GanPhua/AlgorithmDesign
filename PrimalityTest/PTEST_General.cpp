#include <iostream>
#include <math.h>
/*һ����Գ���
���룺maxNum >=3 
�����maxNum������������ 

�� n �� 2 �� int(sqrt(n)) 
�������Ϊ 0 �������������Ϊ����
��������ֻ�����������Գ�
����ҲΪ���� 
*/
using namespace std;
int main(){
	int iNum = 1; // 2 is prime
	int maxNum = 10000;
	bool isPrime;
	for(int i =3; i <= maxNum; i+=2){
		isPrime = true;
		for (int j=3; j<=(int)sqrt(i); j+=2){
			if(i%j==0){
				isPrime = false;
				break;
			}
		}
		if(isPrime)
		    iNum++;	
	}
	cout<< iNum <<endl;
	return 0;
}
