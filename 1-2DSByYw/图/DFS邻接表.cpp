#include<stdio.h>
#include<string.h>
#define MVNum 10

typedef struct ArcNode {
       int adjvex;		// 位置(下标)
       struct ArcNode *nextarc;  // 指向下一条边的指针
}ArcNode;	 // 边结点 

typedef struct { 	
       char data; 	// 顶点信息
       ArcNode *firstarc;   // 指向第一条依附该顶点的边 
}VNode;	  // 表头结点 

typedef struct 	
{     VNode vexs[MVNum];	// 顶点数组 
      int vexnum, arcnum; 	  
}ALGraph; 

int visited[MVNum];

void create(ALGraph &g); // 临界表中的表结点采用头插法
void dfs(ALGraph &g, int v);

int main(){
	ALGraph g;
	create(g);
	memset(visited, 0, sizeof(visited));
	dfs(g, 0);
	printf("\n");
}


void create(ALGraph &g){
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


void dfs(ALGraph &g, int v){
//	p指向arcnode 就是顶点后面的尾巴那些东西
	ArcNode *p;
	visited[v] = 1;
	printf("%c ",g.vexs[v].data);
	p = g.vexs[v].firstarc;
	while(p!=NULL){
		//p->adjvex 是顶点的下标 顶点未访问 递归访问
		if(visited[p->adjvex] != 1){			
			dfs(g, p->adjvex);
		}
		//p指向顶点的下一个邻接点
		p = p->nextarc;
	}
}


/*
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

a c g f b e h d 
---------------------
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

1 3 7 6 2 5 8 4 
---------------------
4 3
A B C D
A B
A C
C D
A C D B 
*/

