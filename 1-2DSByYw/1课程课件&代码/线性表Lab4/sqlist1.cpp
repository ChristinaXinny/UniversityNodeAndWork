#include<stdio.h>
#include<stdlib.h> 

// 函数结果状态码 
typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 10	// 顺序表可能达到的最大长度 

typedef int ElemType;	// 元素数据类型 

typedef  struct {
	ElemType  *elem;     //指向数据元素的基地址
	int      length;     // 当前长度
} SqList;  // 顺序表

/*顺序表基本操作，序号i从1开始 */
// 初始化空表 
void init(SqList &L){
	L.elem = new ElemType[MAXSIZE];
	L.length = 0;
} 
// 根据用户输入，为表中前 n 个元素赋值 
void assign(SqList &L, int n);

// 遍历，打印表中元素，
// 每个元素后一个空格，输出全部元素后换行 	
void traverseList(SqList L);

// 取值，将序号i的元素存入e 	
Status getElem(SqList L, int i, ElemType &e);	

// 查找，返回元素e的序号 
int locateElem(SqList L, ElemType e);

int main(){
	SqList list;
	int cmd, result, e, n, i;
	scanf("%d", &n);
	init(list); 
	assign(list, n);
	while (scanf("%d", &cmd) != EOF )  { // 选择操作 
		switch (cmd) {
		case 0:
			traverseList(list);
			break;
		case 1:
			scanf("%d", &i);
			result = getElem(list, i, e);
			if (result) printf("%d\n", e);
			else printf("Error\n");
			break; 
		case 2:
			scanf("%d", &e);
			result = locateElem(list, e);
			if (result) printf("%d\n", result);
			else printf("Error\n");
			break; 		
		default:
			printf("Unknow Command.\n");
			break;
		}
	}
	return 0;
} 

void assign(SqList &L, int n){
	for(int i=0; i<n; i++){
		scanf("%d", &L.elem[i]);
	} 
	L.length = n;
} 

void traverseList(SqList L){
	for(int i=0; i<L.length; i++){
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

Status getElem(SqList L, int i, ElemType &e){
	if( i<1 || i>L.length ) return ERROR;
	e = L.elem[i-1];
	return OK;
}

int locateElem(SqList L, ElemType e){
	for(int i=0; i<L.length; i++){
		if( L.elem[i] == e ) return i+1;
	}
	return 0;
}

/*
5 
1 3 5 7 9
0
1 1
1 5
1 0
1 6
2 5
2 2


10 
1 2 3 4 5 6 7 8 9 10
0
1 5
2 11

*/




