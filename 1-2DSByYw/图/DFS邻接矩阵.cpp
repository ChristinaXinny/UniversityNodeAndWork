#include<stdio.h>
#include<string.h>
#include <queue>

#define MVNum 10                //最大顶点数 
typedef struct{ 
  	char vexs[MVNum];           //顶点表 
  	int arcs[MVNum][MVNum];     //邻接矩阵 
  	int vexnum,arcnum;  
}AMGraph; 

int visited[MVNum];

void create(AMGraph &g);
void DFS(AMGraph &g, int v);
void BFS(AMGraph &G, int v);
void dfs(AMGraph &G, int v, int &count);//判断是否连通

int main(){
	AMGraph g;
	create(g);
	memset(visited, 0, sizeof(visited));
//	DFS(g, 0);
//	BFS(g, 0);
	int count =0 ;
	dfs(g, 0, count);
	if(count==g.vexnum)printf("yes");
	else printf("no");
	printf("\n");	
}

void create(AMGraph &g){
	scanf("%d %d", &g.vexnum, &g.arcnum);
	getchar();
	for(int k=0; k<g.vexnum; k++){
		scanf("%c",&g.vexs[k]);
		getchar();//读一个空格
	}
//	初始为0
	memset(g.arcs, 0, sizeof(g.arcs));
	for(int k=0; k<g.arcnum; k++){
		char a, b;
		scanf("%c",&a);
		getchar();//吃空格
		scanf("%c",&b);
		
//		找下标
		int i, j;//a-->i   b-->j
		for(int k=0; k<g.vexnum; k++){
			if(a==g.vexs[k]){
				i = k;
			}
			if(b==g.vexs[k]){
				j = k;
			}
		}
		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;
		getchar();
	}

}

//int DFSSS()

//int count = 0;
void dfs(AMGraph &g, int i, int &count)
{
//	int j = 0;
	visited[i] = 1;
	count++;
	for(int j=0; j<g.vexnum; j++){
		if(g.arcs[i][j]==1 && visited[j]!=1)//i和j有关系相邻，并且j顶点没有被访问过
		{
			dfs(g, j, count);
		}
	}
}
//void DFSSS(AMGraph &g, int v);
//
//void DFS(AMGraph &g, int v){
//	for(int i=0; i<g.vexnum; i++){
//		if(visited[v]!=1){
//			DFSSS(g, v);
//		}
//	}
//}	
//void DFSSS(AMGraph &g, int v){
//	printf("%c ",g.vexs[v]);
//	visited[v] = 1;
//	for(int j=0; j<g.vexnum; j++){
//		if(g.arcs[v][j]==1 && visited[j]!=1){
//			DFSSS(g, j);
//		}
//	}
//}


int FirstAdjVex(AMGraph G,int v)
{
	//查找与数组下标为v的顶点之间有边的顶点，返回它在数组中的下标
	for(int i=0; i<G.vexnum; i++){
		if( G.arcs[v][i]!=0  ){
			return i;
		}
	}
	return -1;
}

int NextAdjVex(AMGraph G,int v,int w)
{
	//从前一个访问位置w的下一个位置开始，查找之间有边的顶点
	for(int i=w+1; i<G.vexnum; i++){
		if(G.arcs[v][i]!=0 && i!=v){
			return i;
		}
	}
	return -1;
}

void BFS(AMGraph &G, int v){
//	queue<int> Q;
	std::queue<int> Q;
//	int v = 0;
	visited[v] = 1;
	printf("%c ",G.vexs[v]);
	Q.push(v);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int w = FirstAdjVex(G, u); w>=0; w = NextAdjVex(G, u, w)){
			if(visited[w]!=1){
				printf("%c ",G.vexs[w]);
				visited[w] = 1;
				Q.push(w);
			}
		}
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

1 2 4 8 5 3 6 7
---------------------
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

a b d h e c f g 
---------------------
4 3
A B C D
A B
A C
C D
A B C D 
*/



/*BFS 
9 10
a b c d e f g h i
a b
d g
b e
a d
a e
b c
c f
h i
g h
e g
----------------------
8 9
1
2
3
4
5
6
7
8
1 2
2 4
2 5
1 3
3 6
5 8
7 6
7 3
8 4
1 2 3 4 5 6 7 8 

*/