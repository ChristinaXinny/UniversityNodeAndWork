#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20 //最大输入字符个数 

typedef  struct  BTNode {
		char data;
		struct  BTNode *left, *right;
} BTNode, *BTree;

void preorder(BTree T ) {
	if (T !=NULL){ 			
		printf("%c",T->data); 
		preorder(T->left); 	
		preorder (T->right); 	
	}
}

void inorder(BTree T ) {
	if (T !=NULL){ 			
		inorder(T->left); 
		printf("%c",T->data); 	
		inorder (T->right); 	
	}
}

void postorder(BTree T ) {
	if (T !=NULL){ 			
		postorder(T->left); 	
		postorder (T->right); 
		printf("%c",T->data); 	
	}
}

// 根据二叉树的顺序存储（数组），创建并返回二叉链表 
void create(BTree &T, char s[]); 
 
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char s[MAXSIZE+5];
		scanf("%s", s+1); 
		BTree T;
		create(T, s);
		preorder(T); printf("\n");
		inorder(T); printf("\n");
		postorder(T); printf("\n");	
	}
}


void create(BTree &T, char s[]){
	BTree p[MAXSIZE] = {NULL};
	for(int i=1; i<=strlen(s+1); i++){
		p[i] = new BTNode;
		p[i]->data = s[i];
		p[i]->left = p[i]->right = NULL;
	}
	for(int i=1; i<=strlen(s+1); i++){
		if(p[i]->data!='#'){
			if(i*2<=strlen(s+1)){
				p[i]->left = p[2*i];
			}
			if(i*2+1 <= strlen(s+1)){
				p[i]->right = p[2*i+1];
			}
		}
		else{
			p[i] = NULL;
		}
	}
	T = p[1];
	
}

////林洛瑶
//void create(BTree &T, char s[]){
//	int i;
//	BTree p[MAXSIZE] = {NULL};
//	for(i=1;i<=strlen(s+1);i++){
//		if(s[i]!='#'){
//			p[i] = new BTNode;
//			p[i]->data = s[i];
//			p[i]->left = NULL;
//			p[i]->right = NULL;
//		}
//	}
//	for(i=1;i<=strlen(s+1)/2;i++){
//		if(p[i]!=NULL){
//			if(2*i<=strlen(s+1)){
//				p[i]->left=p[i*2];
//			}
//			if(2*i+1<=strlen(s+1)){
//				p[i]->right=p[i*2+1];
//			}
//		}
//	}
//	T=p[1];
//}


//BTree p[MAXSIZE] = {NULL};
//BTNode *p = new BTNode;

//我的
//void create(BTree &T, char s[]){
//	BTree p[MAXSIZE]={NULL};
//	for(int i=1; i<=strlen(s+1); i++){
//		if(s[i] != '#'){	
//			p[i] = new BTNode;
//			p[i]->left = p[i]->right = NULL;
//			p[i]->data = s[i];
//		}
//	}
//	for(int i=1;i<=strlen(s+1)/2;i++){
//		if(p[i]!=NULL){
//			if(2*i<=strlen(s+1)){
//				 p[i]->left=p[i*2];
//			}
//			if(2*i+1<=strlen(s+1)){
//				p[i]->right=p[i*2+1];
//			}
//		}
//		else{
//			p[i] = 0;
//		}
//	}
//	T = p[1];
//}


//宋泓剑
//void create(BTree &T, char s[]){
//	BTNode *p=(BTNode*)malloc(sizeof(BTNode)*strlen(s));
//	for(int i=1;i<=strlen(s)-1;i++){
//		p[i].data=s[i];
//		p[i].left=NULL;
//		p[i].right=NULL;
//	}
//	for(int i=1;i<=strlen(s)-1;i++){
//		if(2*i<=strlen(s)&&s[2*i]!='#'&&s[2*i]!='\0')
//			p[i].left=&p[2*i];
//		if(2*i+1<=strlen(s)&&s[2*i+1]!='#'&&s[2*i+1]!='\0')
//			p[i].right=&p[2*i+1];
//	}
//	T=&p[1];
//}
