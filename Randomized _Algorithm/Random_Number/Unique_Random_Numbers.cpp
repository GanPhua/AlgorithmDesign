#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

int main(void) {
	int m=15; // Êä³öm¸ö
	int n=100;// ·¶Î§1~n
	int a[n];
	int i,t;
	int end=n-1;

	for(i=0; i<n; ++i) {
		a[i] = i + 1;
	}
	srand((unsigned)time(NULL));
	for(i=0; i<m; ++i) {
		t = rand() % n + 1;
		cout<<a[t]<<endl;
		a[t] = a[end];
		end = end - 1;
	}
	return 0;
}
