#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

// 函数结果状态码 
typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef struct{
    ElemType  *elem; 
    int front;
    int rear;
    int size;
}SqQueue;  

// 初始化空队列，数组长度为 MAXSIZE  
void init(SqQueue &Q);

// 将队头元素赋值到e中。成功返回OK，否则返回ERROR 
Status front(SqQueue Q, int &e);

// 将e入队。成功返回OK，否则返回ERROR 
Status enqueue(SqQueue &Q, ElemType e);

// 出队。成功返回OK，否则返回ERROR 
Status dequeue(SqQueue &Q);

int main(){
	int cmd, e, re;
	SqQueue Q;
	init(Q); 
	while(~scanf("%d",&cmd)){
		switch(cmd){
			case 1:	// get front 
				re = front(Q, e);
				if(re) printf("%d\n", e);
				else printf("ERROR\n");
				break;
			case 2: // enqueue 
				scanf("%d", &e);
				re = enqueue(Q,e);
				if(re) printf("OK\n");
				else printf("ERROR\n");
				break;
			case 3:	// dequeue 
				re = dequeue(Q);
				if(re) printf("OK\n");
				else printf("ERROR\n");
				break;
			default:
				printf("Unknown Command\n");
				break;
		}
	}
}

// 初始化空队列，数组长度为 MAXSIZE  
void init(SqQueue &Q){
	Q.elem = new int [MAXSIZE];
	Q.front = 1;
	Q.rear = 0;
	Q.size = 0;
}

int isEmpty(SqQueue Q){
	return Q.size == 0;
}

int isFull(SqQueue Q){
	return Q.size == MAXSIZE;
}

// 将队头元素赋值到e中。成功返回OK，否则返回ERROR 
Status front(SqQueue Q, int &e){
	if(isEmpty(Q))return ERROR;
	e = Q.elem[Q.front];
	return OK;
}

// 将e入队。成功返回OK，否则返回ERROR 
Status enqueue(SqQueue &Q, ElemType e){
	if(isFull(Q))return ERROR;
	if(++Q.rear == MAXSIZE)Q.rear=0;
	Q.elem[Q.rear] = e;
	Q.size++;
	return OK;
}

// 出队。成功返回OK，否则返回ERROR 
Status dequeue(SqQueue &Q){
	if(isEmpty(Q))return ERROR;
	if(++Q.front==MAXSIZE)Q.front=0;
	Q.size--;
	return OK;
}