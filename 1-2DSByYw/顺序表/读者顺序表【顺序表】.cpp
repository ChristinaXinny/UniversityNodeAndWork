#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define MAXN 20	// 名字数组长度限制 
#define MAXR 5	// 读者数量限制 

typedef int Status;
#define OK 1
#define ERROR 0 

typedef struct {	// 读者的结构体
	int id;			
	char name[MAXN];	
	int book;			
} Reader;				

typedef struct {	// 读者顺序表
	Reader *elem;	 
	int length;	
} ReaderList;

// 初始化读者列表readers，表的最大长度为MAXR
// 从控制台依次读取每个读者的id，姓名和所借阅图书数量 
void create(ReaderList &L, int n); 

// 依次显示所有读者id,name和book，用空格分隔
// 每个读者显示一行 
void printList(ReaderList L);

// 根据id查找读者 
// 成功返回读者的序号（从1开始），失败返回0  
int findId(ReaderList L, int id);

// 根据信息，将读者插入到表的尾部 
// 插入成功返回 OK，否则返回 ERROR 
Status insert(ReaderList &L, int id, char *name, int book);

// 根据id，删除读者 
// 删除成功返回 OK，否则返回 ERROR 
Status del(ReaderList &L, int id); 

int main() {
	ReaderList L;	// 读者列表
	
	// 临时变量 
	int cmd, re, id, book, n;
	char name[MAXN];

	// 初始化读者列表 
	scanf("%d", &n); 
	create(L,n); 
	
	while (scanf("%d", &cmd) != EOF) { // 选择操作 
		switch (cmd) {
		case 0:				// 打印 
			printList(L);
			break;
		case 1:				// 查找 
			scanf("%d", &id);
			re = findId(L, id); 
			if (re) printf("%d\n", re);
			else printf("Not Found\n");
			break;
		case 2:
			scanf("%d %s %d", &id, name, &book);
			re = insert(L, id, name, book);
			if(re) printf("OK\n");
			else printf("ERROR\n"); 
			break;
		case 3:
			scanf("%d", &id);
			re = del(L, id);
			if(re) printf("OK\n");
			else printf("ERROR\n"); 
			break;
		default:
			printf("Unknow Command.\n");
			break;
		}
	}
	return 0;
}

// 初始化读者列表readers，表的最大长度为MAXR
// 从控制台依次读取每个读者的id，姓名和所借阅图书数量 
void create(ReaderList &L, int n){
	L.elem = new Reader[MAXR];
	L.length = n;
	for(int i=0; i<n; i++){
		scanf("%d %s %d",&L.elem[i].id,L.elem[i].name, &L.elem[i].book);
	}
}

// 依次显示所有读者id,name和book，用空格分隔
// 每个读者显示一行 
void printList(ReaderList L){
	for(int i=0; i<L.length; i++){
		printf("%d %s %d\n",L.elem[i].id, L.elem[i].name, L.elem[i].book);
	}
}

// 根据id查找读者 
// 成功返回读者的序号（从1开始），失败返回0  
int findId(ReaderList L, int id){
	for(int i=0; i<L.length; i++){
		if(L.elem[i].id == id){
			return i+1;
		}
	}
	return 0;
}

// 根据信息，将读者插入到表的尾部 
// 插入成功返回 OK，否则返回 ERROR 
Status insert(ReaderList &L, int id, char *name, int book){
	if(L.length==MAXR)return ERROR;
	L.elem[L.length].id=id;
	strcpy(L.elem[L.length].name,name);
//	L.elem[L.length].name=name;

	L.elem[L.length].book=book;
	L.length++;
	return OK;
}


// 根据id，删除读者 
// 删除成功返回 OK，否则返回 ERROR 
Status del(ReaderList &L, int id){
	for(int i=0; i<L.length; i++){
		if(L.elem[i].id == id){
			for(int j=i; j<=L.length-1; j++){
				L.elem[j] = L.elem[j+1];
			}
			L.length --;
			return OK;
		}
	}
	return ERROR;
}