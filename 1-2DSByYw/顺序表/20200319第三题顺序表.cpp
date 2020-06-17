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

// 初始化一个空的学生列表
void init(StdList &L){
	L.elem = new Stud [MAXS];
	L.length = 0;
}



// 输出列表中的所有学生信息
// 包括id、name和成绩，中间以空格分隔  
void output(StdList L){
	for(int i=0; i<L.length; i++){
		printf("%d %s %d\n",L.elem[i].id,L.elem[i].name,L.elem[i].score);
	}
}

// 根据id, name, score，将学生插入到列表适当的位置 
// 如果用户输入的id已存在，则插入失败
// 不必考虑列表已满的情况 
void insert(StdList &L, int id, char *name, int score){
	L.elem[L.length].id = id;
	strcpy(L.elem[L.length].name, name);
	L.elem[L.length].score = score;
	L.length++;
//	printf("%d",L.length);
	if(L.length>1){
		for(int i=L.length-1; i>0; i--){
			if(id==L.elem[i-1].id){
				L.length--;
				break;
			}
		}
	}
	for(int i=0; i<L.length-2; i++){
		for(int j=0; j<L.length-i-2; j++){
			if(L.elem[j].id>L.elem[j+1].id){
				Stud temp = L.elem[j];
				L.elem[j] = L.elem[j+1];
				L.elem[j+1] = temp;
			}
		}
	}		
}

// 根据id删除学生 
// 如果id不存在，则删除失败 
void del(StdList &L, int id){
	for(int i=0; i<L.length; i++){
		if(id==L.elem[i].id){
			for(int j=i; j<L.length-1; j++){
				L.elem[j]=L.elem[j+1];
			}
			L.length--;
		}
	}
}