//author:pangan@2013@qq.com
//opened by Dev-C++ or VS2017
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define N 200
/*启发式修补法解 N 后问题
1. 每行随机放置皇后
2. 从第一行开始：计算当前行的每个位置的冲突数，并将皇后移至最小冲突位置
3. 重复步骤2直至找到解
4. 如果步骤3没有做任何移动且没有找到解则重新从步骤1开始
*/

void calculateRowStatus(int row);
int minRowStatus(int row);
int checkStop();
void formatedOutput();
void randStart();
int queens[N + 1];//下标从1开始
int rowStatus[N + 1]; //用于存放行每个位置的冲突数


int main() {
	queens[0] = 0; //不需要

	int row;
	int stopFlag;//单次尝试是否成功
	int moveFlag;

	int t = 0;
	int maxTryTimes = 100; //单组最大尝试次数

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
			calculateRowStatus(row);//计算皇后在该行每列的冲突数
			moveFlag += minRowStatus(row);//移动皇后至该行最小冲突处
		}
		stopFlag = checkStop();////检查完全移动后是否符合要求
		if (stopFlag) {
			//formatedOutput();
			break;
		}
		else if (moveFlag == 0) {//既不停止也不移动
			randStart();
			RestartTimes++;
			printf("no stop and move, restart...\n\n");
			t = 0;
		}
		else if (t > maxTryTimes) {//单轮尝试最大次数
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
		queens[row] = rand() % N + 1; // 1-N的随机数
	}
}

void calculateRowStatus(int row) {
	int col;
	int k;
	rowStatus[0] = N; //将第一个设为一个大值
	queens[0] = queens[row];//将原始列位置记录在第0个位置
	for (col = 1; col <= N; col++) {//计算所有列的冲突数
		queens[row] = col;
		k = 1;
		rowStatus[col] = 0;
		while (k <= N) {//计算该行在该列对于每行的冲突数
			if (k != row) {
				if (queens[row] == queens[k] || queens[row] - queens[k] == row - k || queens[row] - queens[k] == k - row)
					rowStatus[col] = rowStatus[col] + 1;
			}
			k = k + 1;
		}//end for k
	}//end for col
}

/*确定该行皇后的移动*/
int minRowStatus(int row) {
	int i;
	int moveFlag;
	int minId = 0;
	for (i = 1; i <= N; i++) {
		if (rowStatus[i] < rowStatus[minId])
			minId = i;
		else if (rowStatus[minId] == rowStatus[i] && rand() % 2)//如果出现多个最小值随机选择
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
