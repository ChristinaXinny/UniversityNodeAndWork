#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef int Status;
#define OK 1
#define ERROR 0 

#define MAX 20    // 字符串长度限制 

typedef struct BNode { 
	int code;           // 编号
    char title[MAX];    // 书名
    int num; 			// 数量 
	struct BNode *next;
}BNode, *BookList;                

// 根据用户输入，创建n个图书的列表
// 采用头插法 
void createList(BookList &L, int n);

// 依次显示所有图书的code, title和 num，以空格分隔
// 每本书一行 
void printList(BookList L);

// 根据code查找
// 成功返回图书结点地址， 失败返回NULL 
BNode* findCode(BookList L, int code); 

// 根据图书信息，将其插入到列表头部，表中不允许有重复code的图书 
// 成功返回OK，失败返回ERROR 
Status insert(BookList &L, int code, char *title, int num);

//  根据code删除图书 
// 成功返回OK，失败返回ERROR 
Status del(BookList &L, int code);

// 根据code更新图书数量
// 成功返回OK，失败返回ERROR  
Status update(BookList &L, int code, int num);
  
int main()
{
	// 变量声明
	BookList L;	// 读者列表
	
	// 临时变量 
	int n, cmd, re, code, num; 
	char title[MAX];
	BNode *pos;		

	// 初始化读者列表 
	scanf("%d", &n);
	createList(L, n); 
	
	while (scanf("%d", &cmd) != EOF) {  
		switch (cmd) {
		case 0:				// 打印 
			printList(L);
			break;
		case 1:				// 查找 
			scanf("%d", &code); 
			pos = findCode(L, code);
			if(pos==NULL) printf("Not Found\n");
			else printf("%d\n", pos->code);
			break;
		case 2:				// 插入 	
			scanf("%d%s%d", &code, title, &num);
			re = insert(L, code, title, num); 
			if (re) printf("OK\n");
			else printf("ERROR\n");
			break;
		case 3:				// 删除 
			scanf("%d", &code); 
			re = del(L, code); 
			if (re) printf("OK\n");
			else printf("ERROR\n");
			break;
		case 4:			// 更新 
			scanf("%d%d", &code, &num);
			re = update(L, code, num); 
			if (re) printf("OK\n");
			else printf("ERROR\n");
			break;
		default:
			printf("Unknown Command.\n");
			break;
		}
	}
	return 0;
}

// 根据用户输入，创建n个图书的列表
// 采用头插法 
void createList(BookList &L, int n){
	L = new BNode;
	BNode *p = L->next;
	if(n==0){
		L->next = NULL;
	}
	while(n--){
		BNode *a = new BNode;
		scanf("%d %s %d",&a->code, a->title, &a->num);
		a->next = p;
		L->next = a;
		p = a;
	}
}

// 依次显示所有图书的code, title和 num，以空格分隔
// 每本书一行 
void printList(BookList L){
	BNode *p = L->next;
	while(p){
		printf("%d %s %d\n",p->code, p->title, p->num);
		p = p->next;
	}
}

// 根据code查找
// 成功返回图书结点地址， 失败返回NULL 
BNode* findCode(BookList L, int code){
	BNode *p = L->next;
	while(p){
		if(p->code == code){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 根据图书信息，将其插入到列表头部，表中不允许有重复code的图书 
// 成功返回OK，失败返回ERROR 
Status insert(BookList &L, int code, char *title, int num){
	if(findCode(L, code))return ERROR;
	BNode *a = new BNode;
	a->code = code;
	strcpy(a->title, title);
	a->num = num;
	a->next = L->next;
	L->next = a;
	return OK;
}

//  根据code删除图书 
// 成功返回OK，失败返回ERROR 
Status del(BookList &L, int code){
	BNode *p = L->next;
	if(p->code == code){
		L->next = p->next;
		delete p;
		return OK;
	}
	while(p->next){
		if(p->next->code == code){
			BNode *a = p->next;
			p->next = a->next;
			delete a;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}


// 根据code更新图书数量
// 成功返回OK，失败返回ERROR  
Status update(BookList &L, int code, int num){
	BNode *p = L->next;
	while(p){
		if(p->code == code){
			p->num = num;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
	
}