#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

#define MAXS 80

typedef struct{
	char *ch;
	int length;
} HString; // 堆式顺序存储

void createString(HString &S){
	S.ch = new char[MAXS];
//	gets(S.ch+1);
	scanf("%s",S.ch+1);
	S.length = strlen(S.ch+1); 
}

// 使用BF算法进行模式匹配，字符比较次数 
int charCompBF(HString S, HString T);

int main(){
	HString S, T;
	createString(S);
	createString(T);
	int num = charCompBF(S, T);
	printf("%d", num); 
}


// 使用BF算法进行模式匹配，字符比较次数 
int charCompBF(HString S, HString T){
	int ans = 0;
//	int temp=1;
//	printf("%d %d", S.length,T.length);
	int i=1,j=1;
	while ( j<=T.length && i<=S.length) {
//		printf("S=%c %d, T=%c %d\n", S.ch[i], i, T.ch[j], j);
		ans++;
		if (S.ch[i]==T.ch[j]) {
			i++;
			j++;
		}
		else{
			i=i-j+2;
			j=1;
		}
	}		
	return ans;
}