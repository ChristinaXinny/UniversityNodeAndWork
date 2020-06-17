#include<stdio.h>
#include<stdlib.h>

// 函数结果状态码 
typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef struct QNode{
    ElemType   data;       //数据域
    struct QNode  *next;   //指针域
}QNode;  

typedef struct{
	QNode *front; // 队头 
	QNode *rear;  // 队尾 
}LinkQueue;

// 初始化空队列  
void init(LinkQueue &Q);

// 将队头元素赋值到e中。成功返回OK，否则返回ERROR 
Status front(LinkQueue Q, int &e);

// 将e入队，返回OK 
Status enqueue(LinkQueue &Q, ElemType e);

// 出队。成功返回OK，否则返回ERROR 
Status dequeue(LinkQueue &Q);

int main(){
	int cmd, e, re;
	LinkQueue Q;
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


// 初始化空队列  
void init(LinkQueue &Q){
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
}

int isEmpty(LinkQueue Q){
	return Q.front->next==NULL;
}

// 将队头元素赋值到e中。成功返回OK，否则返回ERROR 
Status front(LinkQueue Q, int &e){
	if(isEmpty(Q))return ERROR;
	e = Q.front->next->data;
	return OK;
}

// 将e入队，返回OK 
Status enqueue(LinkQueue &Q, ElemType e){
	QNode *p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
	
}

// 出队。成功返回OK，否则返回ERROR 
Status dequeue(LinkQueue &Q){
	if(isEmpty(Q))return ERROR;
	QNode *p = new QNode;
	p = Q.front;
	Q.front = p->next;
	free(p);
	return OK;
}