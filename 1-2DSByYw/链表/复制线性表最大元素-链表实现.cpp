#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int   data;       //数据域
    struct LNode  *next;   //指针域
}LNode,*LinkList;   

// 根据用户输入，创建n个结点的链表 
void createList(LinkList &L, int n); 

// 打印链表，每个元素后一个空格，打印结束换行 
void printList(LinkList L); 

// 复制非空链表中第一个最大元素
void duplicateMax(LinkList &L);


int main(){
	int n;
	while(~scanf("%d", &n)){
		LinkList L;
		createList(L, n);
		duplicateMax(L); 
		printList(L);
	}
	return 0;
}

// 根据用户输入，创建n个结点的链表 
void createList(LinkList &L, int n){
	L = new LNode;
	LNode *p = L;
	while(n--){
		LNode *a = new LNode;
		scanf("%d",&a->data);
		a->next = NULL;
		p->next = a;
		p = a;
	}
	
} 

// 打印链表，每个元素后一个空格，打印结束换行 
void printList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
} 

// 复制非空链表中第一个最大元素
void duplicateMax(LinkList &L){
	LNode *p = L->next;
	int max = p->data;
	LNode *temp = p;
	while(p!=NULL){
		if(max < p->data){
			max = p->data;
			temp = p;
		}
		p = p->next;
	}
	LNode *a = new LNode;
	a->data = max;
	a->next = temp->next;
	temp->next = a;
}