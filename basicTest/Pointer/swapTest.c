#include <stdio.h>
// test pass in both C and C++ with Dev-C++ 5.11 
void falseSwap(int a, int b);
void trueSwap(int *pa, int *pb);

int main(){ 
    int a = 4;
    int b = 5;
    
    //swap(a, b);
    trueSwap(&a, &b);
	printf("a=%d, b=%d", a, b);

    return 0;
} 

void falseSwap(int a, int b){
	int tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

void trueSwap(int *pa, int *pb){
	int tmp;
	
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;	
}
