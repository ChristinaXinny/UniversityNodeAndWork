#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int ElemType;
typedef  struct {
	ElemType  *elem;
	int      length;
} SqList; 

void createList(SqList &L, int n); // 创建 
void printList(SqList L); // 打印 
void merge(SqList A, SqList B, SqList &C); // 合并 

int main(){
	int n;
	SqList A, B, C; 
	scanf("%d", &n);
	createList(A, n);
	scanf("%d", &n);
	createList(B, n);
	merge(A,B,C);
	printList(A);
	printList(B);
	printList(C);	
}

void createList(SqList &L, int n){
	L.elem = new ElemType[MAXSIZE];
	for(int i=0; i<n; i++){
		scanf("%d", &L.elem[i]);
	}
	L.length = n;
} 

void printList(SqList L){
	for(int i=0; i<L.length; i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
} 

void merge(SqList A, SqList B, SqList &C){
	C.elem = new ElemType[MAXSIZE];
	int maxlength;
	if(A.length>B.length){
		maxlength = A.length;
	}
	else{
		maxlength = B.length;
	}
	C.length = A.length+B.length;
//	int maxlength = A.length > B.length ? A.length : B.length;
	int a=0;
	int b=0;
	for(int i=0; i<C.length; i++){
		if(a>=A.length){
			C.elem[i] = B.elem[b];
			b++;
		}
		else if(b>=B.length){
			C.elem[i] = A.elem[a];
			a++;
		}
		else if(A.elem[a]<B.elem[b]){
			C.elem[i] = A.elem[a];
			a++;
		}
		else{
			C.elem[i] = B.elem[b];
			b++;
		}
		
	}
}