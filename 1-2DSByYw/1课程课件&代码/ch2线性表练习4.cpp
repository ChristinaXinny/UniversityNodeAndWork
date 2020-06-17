#include <stdio.h>

typedef struct LNode{
	int data; 
	struct LNode  *next;   
}LNode,*LinkList;   

void output (LinkList L) {
// 此处写上你的姓名和学号
//刘心怡 1901030043

// 给出缺少的代码	
	Lnode *p;
	p=L->next;
	while (p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
}
//参考算法：
//p=首元结点地址
//while(p!=NULL){
//     打印p所指节点的data域
//     p=下一个结点

Status InitList_L(LinkList &L){ 
	L=new LNode;   
	// if(L==NULL) exit(OVERFLOW);                 	
	L->next=NULL;　　　　　
	return OK; 
} 


int main(int argc, char *argv[]) 
{
	LNode *L;
	InitList_L(L);
	
	
}