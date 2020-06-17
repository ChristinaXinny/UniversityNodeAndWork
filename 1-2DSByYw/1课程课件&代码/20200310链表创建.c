#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
	int data;
	struct Link *next;
} isLink;

isLink* itisLink(int n){
	isLink *p = NULL;
	isLink *temp = (isLink*)malloc(sizeof(isLink));
	temp->data = 1;
	temp->next = NULL;
	p = temp;
	for (int i=2;i<=n;i++) {
		isLink *a=(isLink*)malloc(sizeof(isLink));
		a->data = i;
		a->next = NULL;
		temp->next = a;
		temp=temp->next;
	}
	return p;
}

void OutPut(isLink *L){
	isLink *p = L;
	while (p!=NULL) {
		printf("%d ",p->data);
		p=p->next;
	}
}
int main(int argc, char *argv[]) 
{
	int n;
	scanf("%d",&n);
	isLink *L = itisLink(n);
	OutPut(L);
	free(L);
}