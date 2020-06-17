#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

// 函数结果状态码 
typedef int Status;
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef struct SNode{
    ElemType   data;       //数据域
    struct SNode  *next;   //指针域
}SNode,*LinkStack;  

// 初始化一个空栈 
void init(LinkStack &S);

// 判空。空栈返回1，否则返回0 
int isEmpty(LinkStack S);

// 将栈顶元素赋值给e。操作成功返回OK，否则返回ERROR 
Status top(LinkStack S, ElemType &e);

// 将e入栈。返回OK 
Status push(LinkStack &S, ElemType e);

// 出栈。操作成功返回OK，否则返回ERROR 
Status pop(LinkStack &S);

int main(){
	int cmd, e, re;
	LinkStack S;
	init(S); 
	while(~scanf("%d",&cmd)){
		switch(cmd){
			case 1:	// get top 
				re = top(S, e);
				if(re) printf("%d\n", e);
				else printf("ERROR\n");
				break;
			case 2: // push 
				scanf("%d", &e);
				re = push(S,e);
				if(re) printf("OK\n");
				else printf("ERROR\n");
				break;
			case 3:	// pop 
				re = pop(S);
				if(re) printf("OK\n");
				else printf("ERROR\n");
				break;
			default:
				printf("Unknown Command\n");
				break;
		}
	}
}


// 初始化一个空栈 
void init(LinkStack &S){
	S = new SNode;
	S->next = NULL;
}

// 判空。空栈返回1，否则返回0 
int isEmpty(LinkStack S){
	if(S->next==NULL)
	return 1;
	else return 0;
	
}
// 将栈顶元素赋值给e。操作成功返回OK，否则返回ERROR 
Status top(LinkStack S, ElemType &e){
	if(isEmpty(S))return ERROR;
	e = S->next->data; 
	return OK;

}

// 将e入栈。返回OK 
Status push(LinkStack &S, ElemType e){
	SNode *elem = new SNode;
	elem->data = e;
	elem->next = S->next;
	S->next = elem;
	return OK;
}

// 出栈。操作成功返回OK，否则返回ERROR 
Status pop(LinkStack &S){
	if(isEmpty(S))return ERROR;
	SNode *p = S->next;
	S->next = p->next;
	delete p;
	return OK;
}
