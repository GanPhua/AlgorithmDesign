#include <stdio.h>
#define N 10 

int peace(int c[], int k);
void formatedOutput(int c[]);
int main() {
	int k;
	int c[N + 1];
	int breakFlag = 0;
	int stopFlag;	
	for (k = 0; k <= N; k++) {
		c[k] = 0;
	}
	k = 1;
	while (k >= 1) {
		while (c[k] <= N - 1) {
			c[k] = c[k] + 1;
			stopFlag = peace(c, k);
			if (k == N) { //合法着色
				if (stopFlag) {
					breakFlag = 1;
					break;
				}
			}
			else if (k < N) { // 部分解
				if (stopFlag)
					k++;
			}
		}
		if (breakFlag)
			break;
		c[k] = 0;
		k--;
	}
	if (breakFlag) {
		formatedOutput(c);
	}
	else
		printf("no solution");

	system("pause");
	return 0;
}

int peace(int c[], int k) {
	int i;
	int stopFlag = 1;
	if (k > 1)
		for (i = 1; i <= k - 1; i++) {
			if (c[k] == c[i] || c[k] - c[i] == k - i || c[k] - c[i] == i - k) {
				stopFlag = 0;
				break;
			}
		}
	return stopFlag;
}

void formatedOutput(int c[]) {
	int k;
	for (k = 1; k <= N; k++)
		printf("%d ", c[k]);
	printf("\n\n");
	int i = 1;
	while (i <= N) {
		int j = 1;
		while (j <= N) {
			if (j == c[i])
				printf("x ");
			else
				printf("0 ");
			j++;
		}
		printf("\n");
		i++;
	}

}
