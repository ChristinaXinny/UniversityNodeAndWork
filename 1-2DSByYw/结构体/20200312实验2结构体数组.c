#include<stdio.h>
#include<stdlib.h>
#define MAXN 80

struct student{
	int id;
	char name[MAXN];
};

// 使用动态分配函数，创建一个长度为n的学生结构体数组
// 根据用户的输入为这n个学生赋值，并返回第一个元素地址  
struct student* create(int n);

// 根据id输出学生信息 
void output(struct student *stds, int n, int id);

// 输出所有学生信息 
void outputall(struct student *stds, int n){
	for(int i=0; i<n; i++){
		printf("%d %s\n", stds[i].id, stds[i].name);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	struct student *p = create(n);
	while(m--){
		int id;
		scanf("%d", &id);
		if(id==0) outputall(p, n);
		else output(p, n, id);	
	}
}

struct student* create(int n){
	struct student* stu = (struct student*)malloc(sizeof(struct student)*n);
	for(int i=0; i<n; i++){
		scanf("%d %s",&stu[i].id,stu[i].name);
	}
	return stu;
}

void output(struct student *stds, int n, int id){
	int c=0;
	for(int i=0; i<n; i++){
		if(id == stds[i].id){
			printf("%d %s\n",stds[i].id,stds[i].name);
			c++;
			break;
		}
	}
	if(c==0){
		printf("no such a student\n");
	}
}



//struct student* create(int n)
//{
// struct student *p=new struct student[n];
// for(int k=0;k<n;k++)
// {
//	scanf("%d %s",&p[k].id,&p[k].name);
// }
// return p;
//}
//void output(struct student *stds, int n, int id)
//{
// int temp=0;
// for(int k=0;k<n;k++)
// {
//	if(stds[k].id==id)
//	{
//	 printf("%d %s\n",stds[k].id,stds[k].name);
//	 temp++;
//	 break;
//	}
// }
// if(temp==0)
//	printf("no such a student\n");
//}
