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
int top(LinkStack S);

// 将e入栈。返回OK 
Status push(LinkStack &S, ElemType e);

// 出栈。操作成功返回OK，否则返回ERROR 
Status pop(LinkStack &S);

void printList(LinkStack L){
	SNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//先建立一个新的空栈 从头开始丢a中的一个一个数字进去 丢进去一个数值 就跟b相比 看看是否相等
//相等的话 就把刚刚放进栈里面的数字pop出来 之后b向后移动一位
//不相等的话 就把a在丢一个数值进栈里面
int isOK(int a[],int b[],int n){
	LinkStack S;
	init(S);
	int i=0,j=0;
	while(i<n){ 
		printf("--in  --%d  ",a[i]);
		push(S,a[i++]); //先把a的一个数值给进栈
		while(!isEmpty(S) && b[j]==top(S)){	//判断a是和b一样的 栈是不是空了
			pop(S);
			j++;
			printf("   b--%d  ",b[j]);
		}
		printf("   aaaa--%d  ",a[i]);
		printList(S);		
		printf("\n");
	}
	if(isEmpty(S))
		return 1;
	return 0;
}

//8 12345678 36754821

//比如 a=1，2，3，4，5，6，7，8
//	b=3，6，7，5，4，8，2，1
//先把a里面的1丢进栈里面 之后i++
//然后判断栈是不是空 【刚刚丢了个1，】
//b[j]==top(S)   -》 3！=1
//所以 又丢一个a的数 2进去
//然后 直到丢了3进去之后
//进入41行的循环 这个时候 b[j]==top(S)==3
//所以pop出来了3
//然后b现在++
//这个时候 栈里面有1，2
//





int isOkPrint(int a[],int b[],int n){
	LinkStack S;
	init(S);
	int i=0,j=0;
	while(i<n){
		push(S,a[i++]);
		printf("in\n");
		while(!isEmpty(S) && b[j]==top(S)){
			pop(S);
			printf("out\n");
			j++;
		}		
	}
	if(isEmpty(S))
		return 1;
	return 0;

}


int main(){
	int n;
	while(~scanf("%d",&n)){
		char aa[n], bb[n];
		int a[n], b[n];
		scanf("%s",aa);
		scanf("%s",bb);
		for(int i=0; i<n; i++){
			a[i] = aa[i]-'0';
			b[i] = bb[i]-'0';
		}
	//	printf("%s\n",aa);
	//	for(int i=0; i<n; i++){
	//		printf(" a-%d ",a[i]);
	//		printf(" b-%d ",b[i]);
	//		b[i] = (int)bb[i];
	//	}
		if(isOK(a, b, n)){
			printf("Yes.\n");
			isOkPrint(a, b, n);
			printf("FINISH\n");
		}
		else{
			printf("No.\n");
			printf("FINISH\n");
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
// 将栈顶元素赋值给e。操作成功返回e，否则返回ERROR 
int top(LinkStack S){
	int e;
	if(isEmpty(S))return ERROR;
	e = S->next->data; 
	return e;

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
