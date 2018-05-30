#include <iostream>
#include <mem.h>
#include <math.h>
/*
�Ľ���ɸѡ��
ɸѡ�����ظ�ɸ��Ҳ����ĳ���������м�����������Щ��Ϊ�׵�ָ�� 
ѡ����С������ɸѡ
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
		//��ÿ����������������С������ɸȥһ��
		//e.g. 12 = 6*2(i=6)=4*3(i=4); 2��12����С�����ӣ�3����
		//4*3���ᷢ������Ϊ4*2(i=4),���ʱ��4%2==0���Ͳ����¸�����3��
        for (int j = 0; (j < iNum)  && (i * prime[j] < maxNum); j++){
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0)// ��i����ǰ��������ʱ�����¸���������
                break;
        }
    }
    cout<< iNum <<endl;
    return 0;	
} 
