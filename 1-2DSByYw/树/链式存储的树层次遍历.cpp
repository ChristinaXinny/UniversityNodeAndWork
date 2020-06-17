#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
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

// 输出二叉链表的层次遍历结果 
void level(BTree T);
 
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
		level(T);	
	}
}

// 根据二叉树的顺序存储（数组），创建并返回二叉链表 
void create(BTree &T, char s[]){
	BTree p[MAXSIZE]={NULL};
	for(int i=1; i<=strlen(s+1); i++){
		if(s[i] != '#'){	
			p[i] = new BTNode;
			p[i]->left = p[i]->right = NULL;
			p[i]->data = s[i];
		}
	}
	for(int i=1;i<=strlen(s+1)/2;i++){
		if(p[i]!=NULL){
			if(2*i<=strlen(s+1)){
				 p[i]->left=p[i*2];
			}
			if(2*i+1<=strlen(s+1)){
			 p[i]->right=p[i*2+1];
			}
		}
		else{
			p[i] = NULL;
		}
	}
	T = p[1];
}

// 输出二叉链表的层次遍历结果 
void level(BTree T){
	queue<BTNode*> q;
	printf("%c",T->data);
	q.push(T);
	while(!q.empty()){
		BTNode *p = q.front();
		q.pop();
		if(p->left!=NULL){
			printf("%c",p->left->data);
			q.push(p->left);
		}
		if(p->right!=NULL){
			printf("%c",p->right->data);
			q.push(p->right);
		}
	}
	printf("\n");
	
}
