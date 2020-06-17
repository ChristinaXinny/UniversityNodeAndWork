#include<stdio.h>
#include<string.h>

#define MVNum 100                       	//最大顶点数 
typedef struct{ 
  	char vexs[MVNum];            	//顶点表 
  	int arcs[MVNum][MVNum];      	//邻接矩阵 
  	int vexnum,arcnum;              //图的当前顶点数和边数 
}AMGraph; 

void create(AMGraph &g);
 
void display(AMGraph &g){
	for (int i=0; i<g.vexnum; i++){
		for (int j=0; j<g.vexnum; j++){
			printf("%d ", g.arcs[i][j]);
		}
	printf("\n");
	}
} 

int main(){
	AMGraph g;
	create(g);
	display(g);
}

void create(AMGraph &g){
	scanf("%d %d", &g.vexnum, &g.arcnum);
	getchar();
	for(int k=0; k<g.vexnum; k++){
//		char c;
//		scanf("%c %c",&g.vexs[i], &c);
		scanf("%c",&g.vexs[k]);
		getchar();//读一个空格
	}
//	初始为0
	memset(g.arcs, 0, sizeof(g.arcs));
	for(int k=0; k<g.arcnum; k++){
//		char a, b, c;//b是空格
//		scanf("%c%c%c",&a, &b, &c);
		char a, b;
		scanf("%c",&a);
		getchar();//吃空格
		scanf("%c",&b);
		
//		找下标
		int i, j;//a-->i   b-->j
		for(int k=0; k<g.vexnum; k++){
			if(a==g.vexs[k]){
				i = k;
//				printf("i---%d ",i);
			}
			if(b==g.vexs[k]){
				j = k;
//				printf("j---%d ",j);
			}
		}
		
		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;
		getchar();
	}
}