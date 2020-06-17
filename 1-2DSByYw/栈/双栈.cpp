#include <stdio.h> 
#include <stdlib.h>
#define MAXSIZE 5 

typedef int Status;
#define OK 1
#define ERROR 0

typedef  struct {
  int *elem;  
  int top1, top2;  		//栈顶下标 
}DStack;

// 初始化一个空的双栈 
void init(DStack &S){
	S.elem = new int[MAXSIZE];
	S.top1 = -1;
	S.top2 = MAXSIZE; 
}

// 将第i个栈的栈顶元素赋值给e 
Status top(DStack S, int i, int &e);

// 第i个栈入栈e。不必考虑操作失败的情况 
Status push(DStack &S, int i, int e);

// 第i个栈出栈。不必考虑操作失败的情况 
Status pop(DStack &S, int i);
 
int main(){
	int cmd, i, re;
	int e;
	DStack S;
	init(S);
	while (~scanf("%d", &cmd)){
		scanf("%d", &i);
		switch(cmd){
			case 1: 
				re = top(S, i, e);
				if(re) printf("%d\n", e);
				else printf("ERROR\n");
				break;
			case 2:
				scanf("%d", &e);
				re = push(S, i, e);
 				if(re) printf("OK\n");
 				else printf("ERROR\n");
 				break;
 			case 3:
 				re = pop(S, i);
 				if(re) printf("OK\n");
 				else printf("ERROR\n");
 				break;
		}
	}
}

// 将第i个栈的栈顶元素赋值给e 
Status top(DStack S, int i, int &e){
	if(i==1){
		if(S.top1==-1)return ERROR;
		e = S.elem[S.top1];
//		for(int i=0; i<=S.top1; i++){
//			printf("%d ",S.elem[S.top1]);
//		}
//		printf("*****%d\n",e);
//		printf("-----%d\n",S.elem[S.top1]);
	}
	else {
		if(S.top2==MAXSIZE)return ERROR;
		e = S.elem[S.top2];
//		printf("*****%d\n",e);
	}

//	int top; 
//	if(i==1)top = S.top1;
//	else top = S.top2;
//	
//	e = S.elem[top];
	return OK;
}

// 第i个栈入栈e。不必考虑操作失败的情况 
Status push(DStack &S, int i, int e){
	if(S.top1+1==S.top2)return ERROR;
//	int top; 
	if(i==1)
		S.elem[++S.top1] = e;
	else 
		S.elem[--S.top2] = e;
	
//	else top = S.top2;
//	if(top>=MAXSIZE)top = MAXSIZE-1;
//	top++;
//	printf("%d %d\n",S.top1,S.top2);
//	if(i==1)S.top1 = top;
//	else S.top2 = top;
	return OK;
	
	
	
	
}

// 第i个栈出栈。不必考虑操作失败的情况 
Status pop(DStack &S, int i){
	
	if(i==1){
		if(S.top1==-1)return ERROR;
		S.top1--;
	}
	else {
		if(S.top2==MAXSIZE)return ERROR;
		S.top2++;
		
	}

	
//	int top; 
//	if(i==1)top = S.top1;
//	else top = S.top2;
//	if(top==-1||)return ERROR;
//	top--;
//	if(i==1)S.top1 = top;
//	else S.top2 = top;
	return OK;

}