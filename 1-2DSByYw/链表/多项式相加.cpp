#include<stdio.h>
#include<stdlib.h>

typedef struct LinkListNode{
	int  coef;	 	//系数  x左边的 coefficient 
	int  index;       //指数 头上的
//	char symbol			//符号 系数的符号
	struct LinkListNode  *next;   //指针域
}LNode, *LinkList; 

void CreateList(LinkList &L, int n);

void PrintList(LinkList L);

void Merge(LinkList A, LinkList B, LinkList &C);

//void symbol(LinkList )

int main (){
	int m,n;
	LinkList lm;
	LinkList ln;
	scanf("%d %d",&m,&n);
	CreateList(lm, m);
	CreateList(ln, n);
	PrintList(lm);
	PrintList(ln);
	LinkList L;
	Merge(lm, ln, L);
	PrintList(L);
}

void CreateList(LinkList &L, int n){
	L = new LNode;//创建一个新的头结点【只有指针域没有数据域】
	LNode *p = L;//创建一个指向结点的指针p并使得p指向头结点
	while(n--){
		LNode *a = new LNode;//创建一个结点 用new 
		scanf("%d %d",&a->coef,&a->index);
		a->next = NULL;
		p->next = a;
		p = p->next;
	}
}

void symble (LNode *p){
	if(p->coef==0){
		if(p->next->coef > 0){
			printf("+");
		}
	}
	if(p->coef>0){
		printf("+");
	}
}

void PrintList(LinkList L){
	LNode *p = L->next;
//	int d = 1;
	while(p!=NULL){
		if(p->coef==0){
			p = p->next;
//			if(p!=NULL)
//				symble(p);
			continue;
		}
		if(p->index==0){
			if(p->coef>0)
				printf("1");
			else{
				printf("-1");
			}
			p = p->next;
			if(p!=NULL)
				symble(p);
			continue;
		}
		if(p->index==1){
			if(p->coef==1){
				printf("x");
			}
			else if(p->coef==-1){
				printf("-x");
			}
			else {
				printf("%dx",p->coef);
			}
		}
		else{
			if(p->coef==1){
				printf("x^%d",p->index);
			}
			else if(p->coef==-1){
				printf("-x^%d",p->index);
			}
			else {
				printf("%dx^%d",p->coef,p->index);
			}
			
		}	
		p = p->next;
		if(p!=NULL&&p->coef!=0)
			symble(p);
	}
	printf("\n");
}


void Merge(LinkList A, LinkList B, LinkList &C){
	LNode *pa = A->next;
	LNode *pb = B->next;
	C = new LNode;
	LNode *pc = C;
//	printf("dddd\n");
	while(pa!=NULL || pb!=NULL){
		LNode *elem = new LNode;
		if(pa==NULL){
			elem->coef = pb->coef;
			elem->index = pb->index;
//			elem = elem->next;
			pb = pb->next;
		}
		else if(pb==NULL){
			elem->coef = pa->coef;
			elem->index = pa->index;
//			elem = elem->next;
			pa = pa->next;
		}
		else if(pa->index == pb->index){
			elem->coef = pa->coef+pb->coef;
			elem->index = pa->index;
//			elem = pc->next;
			pa = pa->next;
			pb = pb->next;
		}
		else if(pa->index < pb->index){
			elem->coef = pa->coef;
			elem->index = pa->index;
//			elem = elem->next;
			pa = pa->next;
		}
		else if(pa->index > pb->index){
			elem->coef = pb->coef;
			elem->index = pb->index;
//			elem = elem->next;
			pb = pb->next;
		}
		elem->next = NULL;
		pc->next = elem;
		pc = elem;
//		printf("index=%d,coef=%d\n",pc->index,pc->coef);
	}
	LNode *p = C->next;
//	printf("gggg");
//	while(p!=NULL){
//		printf("index=%d,coef=%d\n",pc->index,pc->coef);
//		p = p->next;
//	}
}



//陶子源————————————————————————————————————————————————————————————————————————————————————————
#include<stdio.h>
#include<stdlib.h>
typedef struct PNode{   
   int  coef;		//系数 
   int   expn;		//指数 
   struct PNode  *next;	//指针域
}PNode,*Poly; 

void createList(Poly &L,int);   //创建链表 
void printList(Poly L);  //打印链表 
void addPoly(Poly A, Poly B, Poly &C);

int main()
{
	int n,m;
	Poly A, B, C;
	scanf("%d %d",&n,&m);
	createList(A,n);
	//scanf("%d",&n);
	createList(B,m);
	addPoly(A,B,C);
	printList(A);
	printList(B);
	printList(C);
	return 0;
} 

void createList(Poly &L,int k){
	L = new PNode;
	PNode *p = L;	
	while(k--){
		p->next = new PNode;
		scanf("%d %d",&p->next->coef,&p->next->expn);
		p = p->next;
	}
	p->next=NULL; 
}

//void createList(Poly &ll,int n)
//{
//	ll=new PNode;
//	PNode *l=ll;
//	int a,b;
//	while(n--)
//	{
//		scanf("%d %d",&a,&b);
//		if(a==0)continue;
//		l->next=new PNode;
//		l=l->next;
//		l->coef=a,l->expn=b;
//		l->next=NULL;
//	}
//}

//void printList(Poly L)
//{
//	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
//	int kk=0;
//	while(L->next!=NULL){
//		kk++;
//		L=L->next;
//		if(kk==1){//第一个数 
//				if(L->coef==0){//a=0
//					continue;
//				}else if(L->coef==1){//a=1      剩下都有b是0  1  其他的情况 
//					if(L->expn==0){
//						printf("%d",L->coef);//就是1 
//					}else if(L->expn==1){
//						printf("x");
//					}else{
//						printf("x^%d",L->expn);
//					}
//				}else{//a是其他情况 
//					if(L->expn==0){
//						printf("%d",L->coef);
//					}else if(L->expn==1){
//						printf("%dx",L->coef);
//					}else{
//						printf("%dx^%d",L->coef,L->expn);
//					}
//				}
//		} else{//不是第一个 
//		
//				if(L->coef>=0){//正数和0 
//					if(L->coef==0){//a=0
//						continue;
//					}else if(L->coef==1){//a=1      剩下都有b是0  1  其他的情况 
//						if(L->expn==0){
//							printf("+%d",L->coef);//就是1 
//						}else if(L->expn==1){
//							printf("+x");
//						}else{
//							printf("+x^%d",L->expn);
//						}
//					}else{//a是其他情况 
//						if(L->expn==0){
//							printf("+%d",L->coef);
//						}else if(L->expn==1){
//							printf("+%dx",L->coef);
//						}else{
//							printf("+%dx^%d",L->coef,L->expn);
//						}
//					}
//				}else{
//					{ 
//						if(L->expn==0){
//							printf("%d",L->coef);
//						}else if(L->expn==1){
//							printf("%dx",L->coef);
//						}else{
//							printf("%dx^%d",L->coef,L->expn);
//						}
//					}
//				}
//		}
//	}
//	printf("\n");
//}


void printList(Poly L)
{
	int kk=0;
	while(L->next!=NULL){
		kk++;
		L=L->next;
		if(kk==1){//第一个数 
				if(L->coef==0){//a=0
					continue;
				}else if(L->coef==1){//a=1      剩下都有b是0  1  其他的情况 
					if(L->expn==0){
						printf("%d",L->coef);//就是1 
					}else if(L->expn==1){
						printf("x");
					}else{
						printf("x^%d",L->expn);
					}
				}else{//a是其他情况 
					if(L->expn==0){
						printf("%d",L->coef);
					}else if(L->expn==1){
						printf("%dx",L->coef);
					}else{
						printf("%dx^%d",L->coef,L->expn);
					}
				}
		} else{//不是第一个 
		
				if(L->coef>=0){//正数和0 
					if(L->coef==0){//a=0
						continue;
					}else if(L->coef==1){//a=1      剩下都有b是0  1  其他的情况 
						if(L->expn==0){
							printf("+%d",L->coef);//就是1 
						}else if(L->expn==1){
							printf("+x");
						}else{
							printf("+x^%d",L->expn);
						}
					}else{//a是其他情况 
						if(L->expn==0){
							printf("+%d",L->coef);
						}else if(L->expn==1){
							printf("+%dx",L->coef);
						}else{
							printf("+%dx^%d",L->coef,L->expn);
						}
					}
				}else{
					{ 
						if(L->expn==0){
							printf("%d",L->coef);
						}else if(L->expn==1){
							printf("%dx",L->coef);
						}else{
							printf("%dx^%d",L->coef,L->expn);
						}
					}
				}
		}
	}
	printf("\n");
}

void addPoly(Poly A, Poly B, Poly &C){
	C = new PNode;
	PNode *pc=C;
	PNode *pa=A->next;
	PNode *pb=B->next;
	while(pa&&pb){
		pc->next=new PNode;
		if(pa->expn==pb->expn){
			int sum=0;
			sum=pa->coef+pb->coef;
			if(sum!=0){
				pc->next->expn=pa->expn;
				pc->next->coef=sum;
				pa=pa->next;
				pb=pb->next;
				pc=pc->next;
			}else{
//				pc->next->coef=0;
//				pc->next->expn=0;
//				pc=pc->next;
				pa=pa->next;
				pb=pb->next;
			} 
		}else if(pa->expn<pb->expn){
			pc->next->expn=pa->expn;
			pc->next->coef=pa->coef;
			pa=pa->next;
			pc=pc->next;
		}else{
			pc->next->expn=pb->expn;
			pc->next->coef=pb->coef;
			pb=pb->next;
			pc=pc->next;
		}
	}
	while(pa){
		pc->next=new PNode;
		pc->next->expn=pa->expn;
		pc->next->coef=pa->coef;
		pa=pa->next;
		pc=pc->next;
	}
	while(pb){
		pc->next=new PNode;
		pc->next->expn=pb->expn;
		pc->next->coef=pb->coef;
		pb=pb->next;
		pc=pc->next;
	}
	pc->next=NULL;
}



