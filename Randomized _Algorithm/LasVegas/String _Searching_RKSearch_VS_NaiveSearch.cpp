#include <iostream>
#include <string.h>
using namespace std;

void NaiveSearch(const char *pat, const char *txt);
int RKSearch(const char *pat, const char *txt, int q);
int main() {
	const char *txt = "Can you can a can as a canner can can a can";
	const char *pat = "can a";
	
	printf("NaiveSearch:\n");
	NaiveSearch(pat, txt);
	
	const int q = 2047;
	printf("RKSearch:\n");
	RKSearch(pat, txt, q);
	
	return 0;
}

void NaiveSearch(const char *pat, const char *txt) {
	int PLen = strlen(pat);
	int SLen = strlen(txt);

	/* ��һ��������ƥ�� */
	for(int i=0; i<=SLen - PLen; i++) {
		int j;

		/* ƥ��ô����ַ� */
		for(j=0; j<PLen; j++) {
			if(txt[i+j] != pat[j])
				break;
		}
		/* ������������ƥ�����û�б���� */
		if(j==PLen) {
			printf("pattern found at index %d\n", i);
		}
	}
}

int RKSearch(const char *pat, const char *txt, int q) {
	const int b = 32; // ��ĸ�����ַ����� 
	long i, j;
	long SsHash = 0; // ���� 
	long PtHash = 0; // ģʽ�� 
	long x = 1; // ������Hashֵ�������ʽ�еĹ̶�ֵ 
	int PLen = strlen(pat);
	int SLen = strlen(txt);// ���ڳ��� or ģʽ������ 
	/* ����hw(i+2)�еĹ̶�ֵ */
	for(i=0; i<PLen-1; i++) {
		x = (x * b) % q;
	}
	/* �����һ���Ӵ����е�Hashֵ */
	for(i=0; i<PLen; i++) {
		SsHash = (SsHash * b + txt[i]) % q;
	}
    /* ����ģʽ����Hashֵ */
	for(i=0; i<PLen; i++) {
		PtHash = (PtHash * b + pat[i]) % q;
	}
    /* ��������ƥ�� */ 
	for(i=0; i<SLen-PLen; i++) {
		if(PtHash == SsHash) {
			for(j=0; j<PLen; j++) {
				if(txt[i+j] != pat[j])
					break;
			}
			/* ������������ƥ�����û�б���� */
			if(j==PLen) {
				printf("pattern found at index %d\n", i);
			}
		}
		/* ������һ�����ڵ�Hashֵ */ 
		if(i<SLen-PLen) {
			SsHash = ((SsHash - txt[i] * x) * b + txt[i + PLen]) % q;
			if(SsHash<0){
				SsHash = SsHash+q;
			}		
		}
	}
}
