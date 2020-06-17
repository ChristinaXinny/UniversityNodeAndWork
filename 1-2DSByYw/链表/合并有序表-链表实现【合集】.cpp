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


//陶子源
void merge(LinkList A, LinkList B, LinkList &C){
	C = new LNode;
	LNode *pa = A->next;
	LNode *pb = B->next;
	LNode *pc = C;
	while(pa!=NULL && pb!=NULL ){
		if(pa->data < pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc =pb;
			pb = pb->next;
		}
	}
	if(pa==NULL){
		pc->next = pb;
	}
	else {
		pc->next = pa;
	}
}


//林洛瑶：
//void merge(LinkList A, LinkList B, LinkList &C)// 合并 
//{
//	C = new LNode;
// LNode *pa=A->next;
// LNode *pb=B->next;
// LNode *pc=C->next;
// C=A;
// pc=C;
// while(pa&&pb)
// {
//  if(pa->data<=pb->data)
//  {
//	pc->next=pa;
//	pc=pa;
//	pa=pa->next;
//  }
//  else
//  {
//	pc->next=pb;
//	pc=pb;
//	pb=pb->next;
//  }
// }
// pc->next=pa?pa:pb;
// delete B;
//}


//这个少了最后一个数字
//void merge(LinkList A, LinkList B, LinkList &C){
//	LNode *pa = A->next;
//	LNode *pb = B->next;
//	C = new LNode;
//	LNode *pc = C;
//	while(pa && pb){
//		LNode *elem = new LNode;
//		if(pa->data > pb->data){
//			elem->data = pb->data;
//			pb = pb->next;
//		}
//		else {
//			elem->data = pa->data;
//			pa = pa->next;
//		}
//		elem->next = NULL;
//		pc->next = elem;
//		pc = elem;
//	}
//}


//同长度可以
//void merge(LinkList A, LinkList B, LinkList &C){
//	LNode *pa = A->next;
//	LNode *pb = B->next;
//	C = new LNode;
//	LNode *pc = C;
//	while(pa!=NULL || pb!=NULL){
//		LNode *elem = new LNode;
//		if(pa==NULL || pa->data > pb->data){
//			elem->data = pb->data;
//			pb = pb->next;
//		}
//		else if(pb == NULL || pa->data < pb->data){
//			elem->data = pa->data;
//			pa = pa->next;
//		}
//		elem->next = NULL;
//		pc->next = elem;
//		pc = elem;
//	}
//}


//会把AB链打断：
void merge(LinkList A, LinkList B, LinkList &C){
 C = new LNode;
 LNode *pa = A->next;
 LNode *pb = B->next;
 LNode *pc = C;
 while(pa!=NULL && pb!=NULL ){
  if(pa->data < pb->data){
	pc->next = pa;
	pc = pa;
	pa = pa->next;
  }
  else {
	pc->next = pb;
	pc =pb;
	pb = pb->next;
  }
 }
 if(pa==NULL){
  pc->next = pb;
 }
 else {
  pc->next = pa;
 }
}