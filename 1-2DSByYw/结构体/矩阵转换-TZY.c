#include<stdio.h>
#include<stdlib.h>
#define  MAXSIZE  10

typedef struct {
	int  i, j; // 矩阵的行号和列号
	int  e;    // 该非零元的值
} Triple;  // 矩阵的三元组表示法

// 矩阵mb为转矩阵ma的转置 
void transport(Triple ma[], Triple mb[]);

int main(){
	Triple ma[MAXSIZE];
	Triple mb[MAXSIZE];

	// 下标为0处存矩阵的行数、列数和非0元素个数
	scanf("%d %d %d", &ma[0].i, &ma[0].j, &ma[0].e);
	int tu = ma[0].e;
	for(int i=1; i<=tu; i++){
		scanf("%d %d %d", &ma[i].i, &ma[i].j, &ma[i].e);
	}
	transport(ma,mb);
	for (int i=0; i<=tu; i++){
		printf("%d %d %d\n", mb[i].i, mb[i].j, mb[i].e);
	} 
}


bool cmp (Triple a[],Triple b[]);

void transport(Triple ma[], Triple mb[]){

	for(int i = 0;i<=ma[0].e;i++){
		mb[i].i=ma[i].j;
		mb[i].j=ma[i].i;
		mb[i].e=ma[i].e;
	}

	Triple mt[1];
	for(int j = 1 ;j <= mb[0].e;j++){
		for(int i=1;i<=mb[0].e-j;i++){
			if(cmp(&mb[i],&mb[i+1])){		
				Triple temp = mb[i+1];
				mb[i+1] = mb[i];    
				mb[i] = temp;
			}
		}
	}
}

bool cmp (Triple a[1],Triple b[1]){
	if(a[0].i>b[0].i)
			return true;
	if(a[0].i==b[0].i && a[0].j>b[0].j )
			return true;
	return false;
}