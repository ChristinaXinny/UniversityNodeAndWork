#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

// 函数结果状态码 
typedef int Status;
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef struct{
	ElemType *elem;
	int top;
}SqStack;

// 初始化空栈 
Status init(SqStack &S){
	S.elem = new ElemType[MAXSIZE];
	S.top = -1;
}

// 取栈顶元素赋值到e。成功返回OK，否则返回ERROR 
Status top(SqStack S, ElemType &e);

// e入栈。 成功返回OK，否则返回ERROR 
Status push(SqStack &S, ElemType e);

// 出栈。成功返回OK，否则返回ERROR  
Status pop(SqStack &S);

int main(){
	int cmd, e, re;
	SqStack S;
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

//int isEmpty(SqStack S){
//	return -1;
//}
//
//int isFull(SqStack S){
//	return S.top==MAXSIZE-1;
//
//}

// 取栈顶元素赋值到e。成功返回OK，否则返回ERROR 
Status top(SqStack S, ElemType &e){
	if(S.top==-1)return ERROR;
	e = S.elem[S.top];
	return OK;
}

// e入栈。 成功返回OK，否则返回ERROR 
Status push(SqStack &S, ElemType e){
	if(S.top==MAXSIZE-1)return ERROR;
	S.elem[++S.top] = e;
	return OK;
}

// 出栈。成功返回OK，否则返回ERROR  
Status pop(SqStack &S){
	if(S.top==-1)return ERROR;
	--S.top;
	return OK;
}
