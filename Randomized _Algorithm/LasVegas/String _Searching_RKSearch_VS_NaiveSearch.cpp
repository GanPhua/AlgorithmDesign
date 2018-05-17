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

	/* 逐一滑动窗口匹配 */
	for(int i=0; i<=SLen - PLen; i++) {
		int j;

		/* 匹配该窗口字符 */
		for(j=0; j<PLen; j++) {
			if(txt[i+j] != pat[j])
				break;
		}
		/* 上述单个窗口匹配过程没有被打断 */
		if(j==PLen) {
			printf("pattern found at index %d\n", i);
		}
	}
}

int RKSearch(const char *pat, const char *txt, int q) {
	const int b = 32; // 字母集的字符个数 
	long i, j;
	long SsHash = 0; // 窗口 
	long PtHash = 0; // 模式串 
	long x = 1; // 窗口内Hash值计算递推式中的固定值 
	int PLen = strlen(pat);
	int SLen = strlen(txt);// 窗口长度 or 模式串长度 
	/* 计算hw(i+2)中的固定值 */
	for(i=0; i<PLen-1; i++) {
		x = (x * b) % q;
	}
	/* 计算第一个子窗口中的Hash值 */
	for(i=0; i<PLen; i++) {
		SsHash = (SsHash * b + txt[i]) % q;
	}
    /* 计算模式串的Hash值 */
	for(i=0; i<PLen; i++) {
		PtHash = (PtHash * b + pat[i]) % q;
	}
    /* 滑动窗口匹配 */ 
	for(i=0; i<SLen-PLen; i++) {
		if(PtHash == SsHash) {
			for(j=0; j<PLen; j++) {
				if(txt[i+j] != pat[j])
					break;
			}
			/* 上述单个窗口匹配过程没有被打断 */
			if(j==PLen) {
				printf("pattern found at index %d\n", i);
			}
		}
		/* 计算下一个窗口的Hash值 */ 
		if(i<SLen-PLen) {
			SsHash = ((SsHash - txt[i] * x) * b + txt[i + PLen]) % q;
			if(SsHash<0){
				SsHash = SsHash+q;
			}		
		}
	}
}
