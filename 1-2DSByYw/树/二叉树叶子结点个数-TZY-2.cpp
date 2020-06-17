#include<stdio.h>
#include<string.h>
#define MAXSIZE 20

typedef struct{
	char *node;
	int length;
} BTree; 

void createTree(BTree &T){
	T.node = new char[MAXSIZE];
	scanf("%s", T.node+1);
	T.length = strlen(T.node+1);
}

void leaf(BTree T){
	int count = 0;
	for(int i = 1; i<=T.length; i++){
		if(T.node[i]=='#'){
			continue;
		}
		else if(T.node[i*2]=='#'&&T.node[i*2+1]=='#'){
			count++;
		}
		else if(T.node[i*2]=='#'&&(i*2+1)>T.length){
			count++;
		}
		else if((i*2)>T.length&&(i*2+1)>T.length){
			count++;
		}
	}
	printf("%d\n",count);
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		BTree T;
		createTree(T);
		leaf(T); 
	}

}

