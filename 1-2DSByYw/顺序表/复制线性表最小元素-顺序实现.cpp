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

// 复制非空顺序表中第一个的最小的元素 
void duplicateMin(SqList &L);



int main(){
	int n;
	while(~scanf("%d", &n)){
		SqList L;
		createList(L, n);
		duplicateMin(L); 
		printList(L);
	}
	return 0;
}

// 根据用户输入，创建顺序表 
void createList(SqList &L, int n){
	L.elem = new ElemType[MAXSIZE]; 
	for(int i=0; i<n; i++){
		scanf("%d",&L.elem[i]);
	}
	L.length = n;
}

// 打印表中元素，
// 每个元素后一个空格，输出全部元素后换行 	
void printList(SqList L){
	for(int i=0; i<L.length; i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

// 复制非空顺序表中第一个的最小的元素 
void duplicateMin(SqList &L){
	int min = L.elem[0];
	int index = 0;
	for(int i=0;i<L.length; i++){
		if(min > L.elem[i]){
			min = L.elem[i];
			index = i;
		}
	}
//	index--;
	for(int i=L.length-1; i>=index; i--){
		L.elem[i+1] = L.elem[i];
	}
	L.elem[index]=min;
	L.length++;
}
