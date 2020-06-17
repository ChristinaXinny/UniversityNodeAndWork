#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType   data;       
    struct LNode  *next; 
}LNode,*LinkList;  

void createList(LinkList &L, int n); // 创建链表 
void printList(LinkList L); // 打印链表 
void merge(LinkList A, LinkList B, LinkList &C); // 合并 

int main(){
	int n;
	LinkList A, B, C; 
	scanf("%d", &n);
	createList(A, n);
	scanf("%d", &n);
	createList(B, n);
	merge(A,B,C);
	printList(A);
	printList(B);
	printList(C);	
}

// 创建链表 
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


void printList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

// 合并
void merge(LinkList A, LinkList B, LinkList &C){
	LNode *pa = A->next;
	LNode *pb = B->next;
	C = new LNode;
	LNode *pc = C;
	while(pa!=NULL || pb!=NULL){
		LNode *elem = new LNode;
		if(pa==NULL){
			elem->data = pb->data;
			pb = pb->next;
		}
		else if(pb == NULL){
			elem->data = pa->data;
			pa = pa->next;
		}
		else if(pa->data > pb->data){
			elem->data = pb->data;
			pb = pb->next;
		}
		else{
			elem->data = pa->data;
			pa = pa->next;
		}
		elem->next = NULL;
		pc->next = elem;
		pc = elem;
	}
}