//author:pangan@2013@qq.com
//opened by Dev-C++ or VS2017
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define N 200
/*����ʽ�޲����� N ������
1. ÿ��������ûʺ�
2. �ӵ�һ�п�ʼ�����㵱ǰ�е�ÿ��λ�õĳ�ͻ���������ʺ�������С��ͻλ��
3. �ظ�����2ֱ���ҵ���
4. �������3û�����κ��ƶ���û���ҵ��������´Ӳ���1��ʼ
*/

void calculateRowStatus(int row);
int minRowStatus(int row);
int checkStop();
void formatedOutput();
void randStart();
int queens[N + 1];//�±��1��ʼ
int rowStatus[N + 1]; //���ڴ����ÿ��λ�õĳ�ͻ��


int main() {
	queens[0] = 0; //����Ҫ

	int row;
	int stopFlag;//���γ����Ƿ�ɹ�
	int moveFlag;

	int t = 0;
	int maxTryTimes = 100; //��������Դ���

	int RestartTimes = 0;
	int maxRunTimes = 1000;
    clock_t start,end;
    
    start = clock();
	randStart();
	while (RestartTimes <= maxRunTimes) {
		t++;
		queens;
		printf("Round=%d TryTimes=%d RestartTimes=%d\n", RestartTimes + 1, t, RestartTimes);
		moveFlag = 0;
		for (row = 1; row <= N; row++) {
			calculateRowStatus(row);//����ʺ��ڸ���ÿ�еĳ�ͻ��
			moveFlag += minRowStatus(row);//�ƶ��ʺ���������С��ͻ��
		}
		stopFlag = checkStop();////�����ȫ�ƶ����Ƿ����Ҫ��
		if (stopFlag) {
			//formatedOutput();
			break;
		}
		else if (moveFlag == 0) {//�Ȳ�ֹͣҲ���ƶ�
			randStart();
			RestartTimes++;
			printf("no stop and move, restart...\n\n");
			t = 0;
		}
		else if (t > maxTryTimes) {//���ֳ���������
			randStart();
			RestartTimes++;
			printf("single round try max times, restart...\n\n");
			t = 0;
		}
	}
	
	end = clock();  
    double duration =(double)(end-start)/CLOCKS_PER_SEC;
    printf("%f\n",duration); 
    
	if (!stopFlag) {
		printf("solve fail\n");
	}
	system("pause");
	return 0;
}
void randStart() {
	int row;
	for (row = 1; row <= N; row++) {
		queens[row] = rand() % N + 1; // 1-N�������
	}
}

void calculateRowStatus(int row) {
	int col;
	int k;
	rowStatus[0] = N; //����һ����Ϊһ����ֵ
	queens[0] = queens[row];//��ԭʼ��λ�ü�¼�ڵ�0��λ��
	for (col = 1; col <= N; col++) {//���������еĳ�ͻ��
		queens[row] = col;
		k = 1;
		rowStatus[col] = 0;
		while (k <= N) {//��������ڸ��ж���ÿ�еĳ�ͻ��
			if (k != row) {
				if (queens[row] == queens[k] || queens[row] - queens[k] == row - k || queens[row] - queens[k] == k - row)
					rowStatus[col] = rowStatus[col] + 1;
			}
			k = k + 1;
		}//end for k
	}//end for col
}

/*ȷ�����лʺ���ƶ�*/
int minRowStatus(int row) {
	int i;
	int moveFlag;
	int minId = 0;
	for (i = 1; i <= N; i++) {
		if (rowStatus[i] < rowStatus[minId])
			minId = i;
		else if (rowStatus[minId] == rowStatus[i] && rand() % 2)//������ֶ����Сֵ���ѡ��
			minId = i;
	}
	queens[row] = minId;
	if (minId == queens[0])
		return moveFlag = 0;
	else
		return moveFlag = 1;
}

int checkStop() {
	int stopFlag = 1;
	int row;
	int k = 1;
	for (row = 1; row <= N; row++) {
		k = 1;
		while (k <= N) {
			if (k != row) {
				if (queens[row] == queens[k] || queens[row] - queens[k] == row - k || queens[row] - queens[k] == k - row) {
					stopFlag = 0;
					return stopFlag;
				}
			}
			k = k + 1;
		}//end for k
	}//end for row
	return stopFlag;
}

void formatedOutput() {
	int k;
	int row = 1, col;
	printf("\nResult:\n\n");
	for (k = 1; k <= N; k++)
		printf("%d ", queens[k]);
	printf("\n\n");

	while (row <= N) {
		col = 1;
		while (col <= N) {
			if (col == queens[row])
				printf("x ");
			else
				printf("0 ");
			col++;
		}
		printf("\n");
		row++;
	}
}
