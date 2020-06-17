#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MVNum 10

typedef struct ArcNode {
	   int adjvex;			// 该边的起始点位置(下标)
	   struct ArcNode *nextarc;   	 // 指向下一条边的指针
}ArcNode;	 // 边结点 

typedef struct { 	
	   char data; 	// 顶点信息
	   ArcNode *firstarc;   // 指向第一条依附该顶点的边 
}VNode;	  // 表头结点 

typedef struct 	
{     VNode vexs[MVNum];	// 顶点数组 
	  int vexnum, arcnum; 	  
}ALGraph; 

void create(ALGraph &g);

void display(ALGraph &g){
	int i = 0;
	for (i=0; i<g.vexnum; i++){
		printf("%c: ", g.vexs[i].data);
		ArcNode *p = g.vexs[i].firstarc;
		while(p!=NULL){
			printf("%c ", g.vexs[p->adjvex].data);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int main(){
	ALGraph g;
	create(g);
	display(g);
}


void create(ALGraph &g){
	//	先输入 顶点 边数
//		printf("输入顶点数和边数\n");
		scanf("%d %d",&g.vexnum, &g.arcnum);
		getchar();
	//	先把顶点表初始化
		for(int k=0; k<g.vexnum; k++){
			char e;
			scanf("%c",&e);
			g.vexs[k].data = e;
			g.vexs[k].firstarc = NULL;
			getchar();
		}
		
	//	在建立边链表 头插
		ArcNode *p;
		for(int k=0; k<g.arcnum; k++){
			char a, b;
			scanf("%c",&a);
			getchar();
			scanf("%c",&b);
			getchar();
			int i,j;
			for(int d=0; d<g.vexnum; d++){
				if(a==g.vexs[d].data)i=d;
				if(b==g.vexs[d].data)j=d;
			}
			p = new ArcNode;
			p->adjvex = j;
			p->nextarc = g.vexs[i].firstarc;
			g.vexs[i].firstarc = p;
			p = new ArcNode;
			p->adjvex = i;
			p->nextarc = g.vexs[j].firstarc;
			g.vexs[j].firstarc = p;
			
		}

}

/*
8 9
1 2 3 4 5 6 7 8
1 2
2 4
2 5
4 8
5 8
1 3
3 6
6 7
7 3

1: 3 2 
2: 5 4 1 
3: 7 6 1 
4: 8 2 
5: 8 2 
6: 7 3 
7: 3 6 
8: 5 4 
----------------------
4 3
A B C D
A B
A C
C D

A: C B 
B: A 
C: D A 
D: C 
----------------------
8 9
a b c d e f g h
a b
a c
b d
b e
e h
d h
c f
c g
f g

a: c b 
b: e d a 
c: g f a 
d: h b 
e: h b 
f: g c 
g: f c 
h: d e 
*/