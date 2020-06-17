#include <stdio.h>
#include <string.h>
#define MAXSIZE 20

typedef struct{
	char *node;
	int length;
} BTree;

//int count = 0;

void createTree(BTree &T){
	T.node = new char[MAXSIZE];
	scanf("%s",T.node+1);
	T.length = strlen(T.node+1);
}

//int leaf(BTree T, int i){
//	if(i>=T.length/2 || T.node[i]=='#'  )return 0;
//	return leaf(T, 2*i) + leaf(T, 2*i+1) +1;
//}

void leaf(BTree T, int i, int &count){
	if(T.node[i]!='#' && i<=T.length){
		if(i>T.length/2 || (T.node[2*i]=='#'&&T.node[2*i+1]=='#')){
			count++;
		}
		leaf(T, 2*i, count);
		leaf(T, 2*i+1, count);
	}
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	while(n--){
		BTree T;
		int count = 0;
		createTree(T);
		leaf(T, 1, count);
		printf("%d\n",count);
	}
}