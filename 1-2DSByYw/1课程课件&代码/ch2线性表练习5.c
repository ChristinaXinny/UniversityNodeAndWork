//尾插法
Status CreateList_T (LinkList &L, int n) {
	L = new LNode;
	L->next = NULL;  
	LNode *r = L; 	
	for (i=0; i<n; i++){
		LNode *p = new LNode; // 创建一个结点p
		// 读入p的data域
		scanf("%d",&p->data);
		// 将p的next域赋值为NULL 
		p->next=NULL:
		// 将p链接到r的后面	
		r->next = p;
		// r 指向新创建的节点
		r = p;
	}
	return OK; 	
}// CreateList_T 




//头插法
Status CreateList_H (LinkList &L, int n) {
	
	L = new LNode; 
	L->next = NULL; // 头结点 
	for (i=n; i>0; i--){
		// 创建一个结点p
		LNode *p = new LNode;
		// 读入p的data域
		scanf("%d",&p->data);
		// 将p插入到首元节点之前（头结点之后）
		p->next = L->next;
		L->next = p;
	}
	return OK; 	
}// CreateList_H 

