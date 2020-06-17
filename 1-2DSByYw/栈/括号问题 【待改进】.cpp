#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef int Status;
#define OK 1
#define ERROR 0

typedef char ElemType;
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
void push(LinkStack &S, ElemType e);

// 出栈。操作成功返回OK，否则返回ERROR 
void pop(LinkStack &S);

int main (){
	char str[100];
	char a[]={'(','[','{'};
	char b[]={')',']','}'};
	while(~scanf("%s",str)){
		LinkStack S;
		init(S);
		int boolean = 3;
		char e;
		int len = strlen(str);
		for(int i=0; i<len; i++){
			if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
				push(S, a[i]);
			}
			else {
				for(int i=0; i<n; i++){
					
				}
				if(top(S, e)==0 || e!='('){
					printf("no\n");
					boolean= 4;
					break;
				}
				else{
					pop(S);
				}

			}
			
			
		
		
			switch (str[i]) {
				case '(': 
				case '[':
				case '{':
					push(S, a[i]);
					break;
				case ')':
					if(top(S, e)==0 || e!='(')
			}
			else if(a[i]=='}'){
				if(top(S, e)==0 || e!='{'){
					printf("no\n");
					boolean= 4;
					break;
				}
				else{
					pop(S);
				}
			}
			else if(a[i]==']'){
				if(top(S, e)==0 || e!='['){
					printf("no\n");
					boolean= 4;
					break;
				}
				else{
					pop(S);
				}

			}
		}
		if(boolean==3 && isEmpty(S)!=0){
			printf("yes\n");
		}
		else if(isEmpty(S)==0 && boolean==3){
			printf("no\n");
		}
	}
	return 0;
} 


// 初始化一个空栈 
void init(LinkStack &S){
	S = new SNode;
	S->next = NULL;
}

// 判空。空栈返回1==ok，否则返回0 ==ERROR;
int isEmpty(LinkStack S){
	if(S->next==NULL)
		return 1;
	else return 0;
	
}
// 将栈顶元素赋值给e。操作成功返回OK，否则返回ERROR 
Status top(LinkStack S, ElemType &e){
	if(isEmpty(S))return 0;
	e = S->next->data; 
	return 1;

}

// 将e入栈。返回OK 
void push(LinkStack &S, ElemType e){
	SNode *elem = new SNode;
	elem->data = e;
	elem->next = S->next;
	S->next = elem;
//	return OK;
}

// 出栈。操作成功返回OK，否则返回ERROR 
void pop(LinkStack &S){
//	if(isEmpty(S))return ERROR;
	SNode *p = S->next;
	S->next = p->next;
	delete p;
//	return OK;
}
