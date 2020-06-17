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

// 删除非空链表中第一个最小元素
void deleteMin(LinkList &L);


int main(){
	int n;
	while(~scanf("%d", &n)){
		LinkList L;
		createList(L, n);
		deleteMin(L); 
		printList(L);
	}
	return 0;
}

// 根据用户输入，创建顺序表 
void createList(LinkList &L, int n){ 
	L = new LNode;
	LNode *p = L;
	if(n==0){
		L->next = NULL;
	}
	while(n--){
		LNode *a = new LNode;
		scanf("%d",&a->data);
		a->next = NULL;
		p->next = a;
		p = p->next;
	}
}

// 打印表中元素，
// 每个元素后一个空格，输出全部元素后换行 	
void printList(LinkList L){
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

// 删除非空顺序表中的第一个最大元素 
void deleteMin(LinkList &L){
	int min = L->next->data;
	LNode *p = L->next;
	LNode *temp = L;
	LNode *del = NULL;
	if(p->next==NULL){
		del = p;
	}
	else{
		while(p!=NULL){
			if(p->next ==NULL){
				break;
			}
				if(min > p->next->data){
					min = p->next->data;
					temp = p;
					p = p->next;
				}
				else{
					p = p->next;
				}
				
			}

	}
		del = temp->next;
	temp->next = del->next;
	delete del;
	
}