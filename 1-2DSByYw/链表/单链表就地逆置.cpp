#include<stdio.h>
#include<stdlib.h> 

typedef int ElemType;	// 元素数据类型 

typedef struct LNode{
     ElemType   data;       //数据域
     struct LNode  *next;   //指针域
}LNode,*LinkList; 

void createLList(LinkList &L, int n); // 采用尾插法创建链表 
void inverseLList(LinkList &L); // 链表就地逆置，不创建任何结点 
void printLList(LinkList L); // 打印链表，每个数字后有一空格 

int main(){
	int n; 
	LinkList list;
	scanf("%d",&n);
	createLList(list, n);
	printLList(list); 
	inverseLList(list);
	printLList(list); 	
}


// 采用尾插法创建链表 
void createLList(LinkList &L, int n){
	L = new LNode;
	LNode *p = L;
	if(n==0)L->next = NULL;
	
	while(n--){
		LNode *a = new LNode;
		scanf("%d",&a->data);
		a->next = NULL;
		p->next = a;
		p = a;
	}
}


 // 链表就地逆置，不创建任何结点 
void inverseLList(LinkList &L){
	
	LNode *p,*q,*r;
	p=L->next;
	r=L;
	r->next=NULL;

	while(p!=NULL){
		q=p->next;
		p->next=r->next;
		r->next=p;
		p=q;
	}
	
	
//	LNode *p = L->next;
//	LNode *q = L->next;
//	while(p->next!=NULL){
//		p = p->next;
//		
//	}
//	L->next = p;
}


// 打印链表，每个数字后有一空格 
void printLList(LinkList L){
	LNode *p = L->next;
	printf("%d",p->data);
	p = p->next;
	while(p!=NULL){
		printf(" %d",p->data);
		p = p->next;
	}
	printf("\n");
}
