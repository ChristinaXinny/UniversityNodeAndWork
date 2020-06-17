#include<stdio.h>
#include<stdlib.h>

typedef struct LinkListNode{
	int  data;       //数据域
	struct LinkListNode  *next;   //指针域
}LNode, *LinkList;   

// 创建n个结点的链表
void CreateList_T(LinkList &L, int n){//尾插法
printf("Enter %d numbers:",n);
	L = new LNode;//创建一个新的头结点【只有指针域没有数据域】
	LNode *p = L;//创建一个指向结点的指针p并使得p指向头结点
	if(n==0){
		L->next=NULL;
	}
	while(n--){
		LNode *a = new LNode;//创建一个结点 用new 
		scanf("%d",&a->data);
		a->next = NULL;
		p->next = a;
		p = p->next;
	}
} 

void CreateList_H(LinkList &L, int n){//头插法
printf("Enter %d numbers:",n);

	L = new LNode; 
	L->next = NULL; // 头结点 
	for ( int i=n; i>0; i--){
		// 创建一个结点p
		LNode *p = new LNode;
		// 读入p的data域
		scanf("%d",&p->data);
		// 将p插入到首元节点之前（头结点之后）
		p->next = L->next;
		L->next = p;
	}

} 


// 打印链表 
void PrintList(LinkList L) {
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

// 根据序号查找 
// 返回序号为i（序号从1开始）的结点的地址，找不到返回NULL 
LNode* FindI(LinkList L, int i){
	LNode *p = L->next;
	int index = 1;
	while(p!=NULL){
		if(index==i){
			return p;
		}
		index++;
		p=p->next;
	}
	return NULL;
}

// 根据值查找
// 返回值为e的第一个节结点的地址，找不到返回NULL 
LNode* FindV(LinkList L, int e){
	LNode *p = L->next;
	
	while(p!=NULL){
		if(e==p->data){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 根据序号查找前驱 
// 返回序号为i（序号从1开始）的结点的前驱结点的地址，找不到返回NULL 
LNode* FindIP(LinkList L, int i){
	LNode *p = L;
	if(i==1){
		return L;
	}
	int index = 1;
	while(p!=NULL){
		if(i-1==index){
			return p;
		}
		p = p->next;
		index++;
	}
	return NULL;
}

// 根据值查找前驱 
// 返回值为e的第一个结点的前驱结点的地址，找不到返回NULL 
LNode* FindVP(LinkList L, int e); 

// 在位置i（从1开始）插入元素e 
// 成功返回1，失败返回0 
int Insert(LinkList &L, int i, int e); 

// 删除位置i的元素 
// 成功返回1，失败返回0 
int Del(LinkList &L, int i); 

int main(){
	LinkList L;
	int cmd, e, n, i;
	LNode *p;
	int re;
	printf("Number of input linked list data:");
	scanf("%d", &n);
//	printf("\n");
	printf("11【Tail】 || 22【Head】:");
	
	int frs;
	scanf("%d",&frs);
	
	switch (frs) {
		case 11:
			CreateList_T(L, n);
			break;
		case 22:
			CreateList_H(L, n);
			break;
		default:
			printf("OMG!!");
	}
	printf("\n");
	printf("Input command：\n0:print; \n1:Find by sequence number;  \n2:Find by value \n3:Find the precursor according to the serial number;  \n4:Find the precursor according to the value\n5:Insert element\n6:Delete element\n");
	while (scanf("%d", &cmd) != EOF )  { // 选择操作 
		switch (cmd) {
		case 0:
			PrintList(L);
			break;
		case 1: // 根据序号查找 
			scanf("%d", &i);
			p = FindI(L, i);
			if ( p!=NULL) printf("%d\n", p->data);
			else printf("Not Found\n");
			break; 
				
		case 2: // 根据值查找 
			scanf("%d", &e);
			p = FindV(L, e);
			if ( p!=NULL) printf("%d\n", p->data);
			else printf("Not Found\n");
			break; 
			
		case 3: // 根据序号查找前驱 
			scanf("%d", &i);
			p = FindIP(L, i);
			if ( p!=NULL) printf("%d\n", i-1);
			else printf("Not Found\n");
			break; 
			
		case 4: // 根据值查找前驱 
			scanf("%d", &e);
			p = FindVP(L, e);
			if ( p!=NULL) printf("%d\n", p->next->data);
			else printf("Not Found\n");
			break; 
			
		case 5: // 在位置i插入元素e
			scanf("%d %d", &i, &e);
			re = Insert(L, i, e);
			if (re) printf("OK\n");
			else printf("ERROR\n");
			break; 
				
		case 6: // 删除位置i的元素 
			scanf("%d", &i);
			re = Del(L, i);
			if (re) printf("OK\n");
			else printf("ERROR\n");
			break; 
			
		default:
			printf("Unknow Command.\n");
			break;
		}
	}
	return 0;
} 

// 根据值查找前驱 
// 返回值为e的第一个结点的前驱结点的地址，找不到返回NULL 
LNode* FindVP(LinkList L, int e){
	LNode *p = L;
	while(p->next!=NULL){
		if(p->next->data == e){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 在位置i（从1开始）插入元素e 
// 成功返回1，失败返回0 
int Insert(LinkList &L, int i, int e){
	LNode *p = FindIP(L,i);//p指向要插入位置的前面位置
	if(p==NULL)return 0;
	LNode *a = new LNode;
	a->data = e;
	a->next = p->next;
	p->next = a;
	return 1;
}

// 删除位置i的元素 
// 成功返回1，失败返回0 
int Del(LinkList &L, int i){
	if(L->next==NULL){//这里是说明当L是空表时 无法删除
		return 0;
	}
	LNode *p = FindIP(L, i);
	if(!p||!p->next) return 0;
	LNode *r = p->next;
 	p->next = r->next;
	delete r;
	return 1;
}