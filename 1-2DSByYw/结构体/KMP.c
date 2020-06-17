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

// 使用 KMP 算法进行模式匹配，字符比较次数 
int charCompKMP(HString S, HString T);

int main(){
	HString S, T;
	createString(S);
	createString(T);
	int num = charCompKMP(S, T);
	printf("%d", num); 
}

void itisNext(HString T, int next[]){
	next[1] = 0;
	int i=1;
	int j=0;
	while ( i<T.length ){
		if(j==0 || T.ch[i]==T.ch[j]){
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
//			i++;
		}
	}
	int k= 1;
	while(k<=T.length){
		printf("%d ",next[k]);
		k++;
	}
}


//S T 都是从下标1开始 next我下标从1开始

// 使用 KMP 算法进行模式匹配，字符比较次数 
int charCompKMP(HString S, HString T){
	int next[T.length];
	int j=1;
	int i=1;
	itisNext(T, next);
	int ans = 0;
	while(i<=S.length && j<=T.length){
		ans++;
		printf("S=%c %d, T=%c %d\n", S.ch[i], i, T.ch[j], j);
		if(j==0 || S.ch[i]==T.ch[j]){
			if(j==0)ans--;
			i++;
			j++;
		}
		else{
			j = next[j];
//			i++;
		}
	}
	return ans;
}