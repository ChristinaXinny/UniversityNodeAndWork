#include<stdio.h>

int isStatus(int a[], int b[], int n){
	for(int i=0,j=n-1; i<n; i++,j--){
		if(a[i]!=b[j])
		{
			return 0;
		}
	}
	return 1;	
}

int isQueue(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int a[n],b[n];
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++){
			scanf("%d",&b[i]);
		}
		
		if(isQueue(a, b, n) && isStatus(a,b ,n)){
			printf("both\n");
			continue;
		}
		else if(isQueue(a, b, n)){
			printf("queue\n");
			continue;
		}
		else if(isStatus(a, b, n)){
			printf("stack\n");
			continue;
		}
		else{
			printf("neither\n");
		}
		
		
	}
}

/*
栈和队列是重要的数据结构。栈是“先进后出”（FILO）的数据结构，而队列是“先进先出”（FIFO）的数据结构。
给出进入结构和离开结构的一些整数次序（假定栈和队列中存储的都整数），请确定这个数据结构是栈还是队列。
假设所有数据在结束进入之前是不允许离开的。
输入要求
包含多个测试用例。
输入的第一行是一个整数T，表示测试用例的个数。然后给出T个测试用例。
每个测试用例包含3行：第一行给出一个整数N（1<=N<=100），表示整数个数。第二行给出用空格分隔的N个整数，表示进入结构的次序（即第一个数据最先进入）。第三行给出用空格分隔的N个整数，表示离开结构的次序（第一个数据是先离开）。
输出要求
对于每个测试用例，在一行中输入判定结果。
如果结果只能是一个栈，则输出“stack”；如果结构只能是一个队列，则输出“queue”；如果结构既可以是栈，也可以是队列，则输出“both”，否则输出“neither”。
测试数据示例 1

输入
输出
4
3
1 2 3
3 2 1
3
1 2 3
1 2 3
3
1 2 1
1 2 1
3
1 2 3
2 3 1
stack
queue
both
neither
*/
