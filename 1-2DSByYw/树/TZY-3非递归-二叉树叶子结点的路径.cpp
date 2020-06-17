#include<stdio.h>
#include<string.h>
#define MAXSIZE 20

typedef struct{
	char *node;
	int length;
} BTree; 

void printroot(BTree &T);

void createTree(BTree &T){
	T.node = new char[MAXSIZE];
	scanf("%s", T.node+1);
	T.length = strlen(T.node+1);
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		BTree T;
		createTree(T);
		printroot(T);
	}
	return 0;
}

void printroot(BTree &T){
	for(int i = 1;i<=T.length;i++){
		if(T.node[i]=='#'){
			continue;
		}
		else if((T.node[i*2]=='#'&&T.node[i*2+1]=='#') || (T.node[i*2]=='#'&&i*2+1>T.length) || (i*2>T.length && i*2+1>T.length) ){
			int l=i;
			while(l!=1){
				printf("%c",T.node[l]);
				l=l/2;
			}
			if(l==1){
				printf("%c\n",T.node[l]);
			}
		}
//		else if(T.node[i*2]=='#'&&(i*2+1)>T.length){
//			int l=i;
//			while(l!=1){
//				printf("%c",T.node[l]);
//				l=l/2;
//			}
//			if(l==1){
//				printf("%c\n",T.node[l]);
//			}
//		}
//		else if((i*2)>T.length && (i*2+1)>T.length){
//			int l=i;
//			while(l!=1){
//				printf("%c",T.node[l]);
//				l=l/2;
//			}
//			if(l==1){
//				printf("%c\n",T.node[l]);
//			}
//		}
	}
}