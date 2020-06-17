#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 16 // name最大字符数 
#define MAXS 20 // 最大学生数 

typedef struct{
	int id;
	char name[MAXN];
	int score;	// 成绩 
}Stud;

typedef struct{
	Stud *elem;
	int length;
}StdList;

// 初始化一个空的学生列表 
void init(StdList &L);

// 输出列表中的所有学生信息
// 包括id、name和成绩，中间以空格分隔  
void output(StdList L);

// 根据id, name, score，将学生插入到列表适当的位置
// 假设学生id不重复，学生列表按id升序排列  
// 如果用户输入的id已存在，则插入失败
// 不必考虑列表已满的情况 
void insert(StdList &L, int id, char *name, int score);

// 根据id删除学生 
// 如果id不存在，则删除失败 
void del(StdList &L, int id); 

int main(){
	StdList list;
	int cmd, id, score;
	char name[MAXN];
	init(list); 
	while (scanf("%d", &cmd) != EOF )  { // 选择操作 
		switch (cmd) {
		case 0:
			output(list);
			break;
		case 1:
			scanf("%d %s %d", &id, name, &score);
			insert(list, id, name, score);
			break; 
		case 2:
			scanf("%d", &id);
			del(list, id);
			break; 		
		}
	}
	return 0;
} 

void init(StdList &L){
	L.elem = new Stud[MAXS];
	L.length = 0;
}

void output(StdList L){
	for(int i=0; i<L.length; i++){
		printf("%d %s %d\n", 
			L.elem[i].id, L.elem[i].name, L.elem[i].score);
	}
}

void insert(StdList &L, int id, char *name, int score){
	int i; 
	for(i=0; i<L.length; i++){
		if(L.elem[i].id == id) return;
		if(L.elem[i].id > id) break;
	}
	for(int j=L.length-1; j>=i; j--){
		L.elem[j+1] = L.elem[j];
	}
	Stud *s = new Stud;
	s->id = id;
	strcpy(s->name, name);
	s->score = score;
	L.elem[i] = *s;
	L.length++;
}

void del(StdList &L, int id){
	int i, flag=0;
	for(i=0; i<L.length; i++){
		if(L.elem[i].id == id){
			flag = 1;
			break;
		} 
	}
	if(flag){
		for(int j=i+1; j<L.length; j++){
			L.elem[j-1] = L.elem[j];
		} 
		L.length--;
	}
	
}

/*
1 121 aaa 20
1 121 aaa 20
2 121
1 122 abc 100
1 123 abc 100
0
1 111 bbb 100
1 131 ccc 50
0
2 100
2 120 
2 133
0
2 111
2 131
0
*/
 



