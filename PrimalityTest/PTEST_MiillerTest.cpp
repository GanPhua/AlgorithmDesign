#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
//ref: https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/ 
//输出maxNum以内的素数个数
 
/*课本上的实现a^m (mod n)
int exp_mod(int a, int m, int n){
	int i,c,k=0;
	int *b=new int[m];
	while(m!=0){
		b[k++]=m%2;
		m/=2;
	}
	c=1;
	for(i=k-1;i>=0;i--){
		c=(c*c)%n;
		if(b[i]==1)//课本这里写错了 
			c=(a*c)%n;
	}
	delete b;
	return c;
}
*/

/*位运算实现 a^m (mod n)*/
int power(int a, unsigned int m, int n)
{
    int res = 1;
    a = a % n;  //a大于等于n 
    while (m > 0)
    {
        // m为偶数 
        if (m & 1)
            res = (res*a) % n;
        m = m>>1; // m = m/2
        a = (a*a) % n;
    }
    return res;
}

bool miillerTest(int q, int m, int n)
{
    // a \in [2,n-2]
    int a = 2 + rand() % (n - 4);
 
    // Compute a^m % n
    int x = power(a, m, n);
 
    if (x == 1  || x == n-1)//1或-1 
       return true;

    for(int j=0; j<q; j++)
    {   // 考察测试序列的前一个 
        x = (x * x) % n;

        if (x == 1)
		    return false;
        if (x == n-1)
		    return true;
    }

    return false;
}

bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    //n-1 = 2^d * r
    int m = n - 1;
    int q=0;
    while (m % 2 == 0){
    	m /= 2;
    	q++;
	}

    for (int i = 0; i < k; i++)
         if (miillerTest(q, m, n) == false)
              return false;
    return true;
}

int main(){
    int maxNum = 1000;
    int k = (int)(log(maxNum)+1);
    int iNum = 1;
    for (int n = 3; n < 10000; n++){
       if (isPrime(n, k)){
       	    iNum++;
            //cout << n << " ";
	   }
    }
    cout<<iNum<<endl;
    return 0;
}
