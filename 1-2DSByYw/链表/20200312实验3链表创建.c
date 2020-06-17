#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

// 创建n个整数结点的链表（无头结点） 
node* create(int n);

void output(node *p); // 打印链表 

int main(){
	int n;
	while(~scanf("%d", &n) && n){
		struct node *p = create(n);
		output(p);
	}
	return 0;
}

node* create(int n){
	node* s = (node*)malloc(sizeof(node));
	node* temp = NULL;
	scanf("%d",&s->data);
	s->next = NULL;
	temp = s;
	for(int i=2; i<=n; i++){
		node* a = (node*)malloc(sizeof(node));
		scanf("%d",&a->data);
		a->next = NULL;
		s->next=a;
		s = s->next;
	}	
	return temp;
}

void output(node *p){
	while (p!=NULL) {
		printf("%d\n",p->data);
		p=p->next;
	}
}




node* create(int n){
 int temp;
 node *p=new node;
 scanf("%d",&p->data);
 node *q=p;
 
 for(int k=1;k<n;k++)
 {
	q->next =new node;
	scanf("%d",&temp);
	q->next->data=temp;
	if(k==n)
	{
	 q->next=NULL;
	}
	else
	{
	 q=q->next;
	}
 }
 q->next = NULL;
 return p;
} 


void output(node *p)
{
 while(p!=NULL)
 {
	printf("%d\n",p->data);
	p=p->next ;
 }
}