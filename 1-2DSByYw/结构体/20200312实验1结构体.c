#include <stdio.h>
#include <stdlib.h> 

#define MAXN 80
// 学生结构体定义 
typedef struct student{
	int id;
	char name[MAXN];
} stud;

// 根据用户的输入，创建一个学生结构体 
// 返回一个指向结构体的指针 
stud* create();

// 输出学生信息，每个成员间一个空格，并换行 
void output(stud* p);

int main(){
	stud *p = create();
	output(p);
	return 0;
} 

stud* create(){
	stud* s = (stud*)malloc(sizeof(stud));
	scanf("%d %s",&s->id,s->name);
	return s;
}

void output(stud* p){
	printf("%d %s",p->id,p->name);
}

