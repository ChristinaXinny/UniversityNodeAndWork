#include<stdio.h>
#include<stdlib.h> 

#define MAXSIZE 10	// 顺序表可能达到的最大长度 
typedef int ElemType;	// 元素数据类型 

typedef  struct {
	ElemType  *elem;     //指向数据元素的基地址
	int      length;     // 当前长度
} SqList;  // 顺序表

// 根据用户输入，创建顺序表 
void createList(SqList &L, int n);

// 打印表中元素，
// 每个元素后一个空格，输出全部元素后换行 	
void printList(SqList L);

// 删除非空顺序表中的第一个最大元素 
void deleteMax(SqList &L);

int main(){
	int n;
	while(~scanf("%d", &n)){
		SqList L;
		createList(L, n);
		deleteMax(L); 
		printList(L);
	}
	return 0;
}

void createList(SqList &L, int n){
	L.elem = new ElemType[n];
	
	for(int i=0; i<n; i++){
		scanf("%d", &L.elem[i]);
	} 
	L.length = n;
}

// 打印表中元素，
// 每个元素后一个空格，输出全部元素后换行 	
void printList(SqList L){
	for(int i=0; i<L.length; i++){
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

// 删除非空顺序表中的第一个最大元素 
void deleteMax(SqList &L){
	int max = L.elem[0];
	int index = 0;
	for(int i=0; i<L.length; i++){
		if(max<L.elem[i]){
			index = i;
			max = L.elem[i];
		}
	}
	for(int i=index; i<L.length; i++){
		L.elem[i] = L.elem[i+1];
	}
	L.length--;
	
}
