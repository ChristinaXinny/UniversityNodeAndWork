#include <stdio.h>
#include <string.h>
#define MAXSIZE 50

typedef struct{
	char *node;
	int length;
} BTree;

void createTree(BTree &T){
	T.node = new char[MAXSIZE];
	scanf("%s",T.node+1);
	T.length = strlen(T.node+1);
}

//a[]用来记录叶子节点的下标  j是a的下标
void leaf(BTree T, int i, int a[], int &j){
	if(T.node[i]!='#' && i<=T.length){
		if((2*i>T.length && 2*i+1 >T.length)||(T.node[2*i]=='#'&&T.node[2*i+1]=='#')){
			a[j] = i;
			j++;
		}
		leaf(T, 2*i+1, count, a, j);
		leaf(T, 2*i, count, a, j);
	}
}

void prin(BTree T, int i){
	if(i<=0)printf("\n");
	else {
		printf("%c",T.node[i]);
		prin(T, i/2);
	}	
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	while(n--){
		BTree T;
		createTree(T);
		int a[30];		//记录叶子节点的下标
		int len=0;		//len = count
		leaf(T, 1, a, len);
		for (int j=0; j<len-1; j++) { 		//把叶子节点的下标排序                           
			for (int i=0; i<len-1-j; i++){
				if(a[i]>a[i+1])  {
					int temp=a[i];    //小到大
					a[i]=a[i+1];    
					a[i+1]=temp;
				}
			}
		}  
		for(int i=0; i<len; i++){
			prin(T, a[i]);
		}  
	}
}

/*
5
ABC#DEF####GH
A#B##CD######EF############1234
ABC123DEF4GH5IJ6
12
abcdefghijklmnopqrst

DBA
FCA
GECA
HECA

CBA
1EDBA
2EDBA
3FDBA
4FDBA

F1BA
42BA
G2BA
H3CA
53CA
IDCA
JDCA
6E1BA

21
keba
lfca
mfca
ngca
ogca
phdba
qhdba
ridba
sidba
tjeba
*/