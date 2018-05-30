#include <iostream>
#include <math.h>
/*一般的试除法
输入：maxNum >=3 
输出：maxNum以内素数个数 

将 n 用 2 到 int(sqrt(n)) 
如果余数为 0 输出合数，否则为素数
这里我们只对奇数进行试除
除数也为奇数 
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
