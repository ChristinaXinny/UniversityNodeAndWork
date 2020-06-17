
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

// 在表中的第 i 位置插入元素 e 
Status listInsert(SqList &L, int i, ElemType e);

// 删除表中的第 i 个 元素 
Status listDelete(SqList &L, int i); 


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
		case 3:
			scanf("%d %d", &i, &e);
			result = listInsert(list, i, e);
			if (result) printf("OK\n");
			else printf("Error\n");
			break; 
		case 4:
			scanf("%d", &i);
			result = listDelete(list, i);
			if (result) printf("OK\n");
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
		printf("%d\n ", L.elem[i]);
	}
}


Status listInsert(SqList &L, int i, ElemType e){
	if((i<1)||(i>L.length+1))
		return ERROR;
	if(L.length >= MAXSIZE)
		return ERROR;
	i--;
	for(int j=L.length-1;j>=i;j--){
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i]=e;
	L.length++;
	return OK;
}

Status listDelete(SqList &L, int i){
	if((i<1)||(i>L.length))
		return ERROR;
	i--;
	for(int j=i+1;j<L.length;j++){
		L.elem[j-1]=L.elem[j];
	}
	L.length--;
	return OK;
}