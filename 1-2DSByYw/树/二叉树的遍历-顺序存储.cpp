#include <stdio.h>
#include <string.h>
#define MAXSIZE 20

typedef struct{
	char *node;
	int length;
} BTree;

void createTree(BTree &T){
	T.node = new char[MAXSIZE];
	scanf("%s",T.node+1);
	T.length = strlen(T.node+1);
}

//先序遍历算法(DLR)
void preorder(BTree T, int i ) {	//bt为根指针
	if(T.node[i]!='#' && i<=T.length){
		printf("%c",T.node[i]);
		preorder(T, 2*i);
		preorder(T, (2*i)+1);
	}
}

//中序遍历算法(LDR)
void inorder(BTree T , int i) {	//bt为根指针
	if(T.node[i]!='#' && i<=T.length){
		inorder(T, 2*i);
		printf("%c",T.node[i]);
		inorder(T,(2*i)+1);
	}
}

//后序遍历算法(LRD)
void postorder(BTree T , int i ) {	//bt为根指针
	if(T.node[i]!='#' && i<=T.length){
		postorder(T, 2*i);
		postorder(T, 2*i+1);
		printf("%c",T.node[i]);
	}
	
	
}

int main(int argc, char *argv[]) {
	BTree T;
	createTree(T);
	preorder(T,1);
	printf("\n");
	inorder(T,1);
	printf("\n");
	postorder(T,1);
	printf("\n");
	
	
	
}