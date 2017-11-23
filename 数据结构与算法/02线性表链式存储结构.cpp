
/* --------------------------- */
/* 线性表链式存储结构--单链表 */
typedef struct
{
	int data;
	struct node *next;
}node, *linklist;

/* 线性表链式存储结构--单链表插入 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;  
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

/* 线性表链式存储结构--单链表删除 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

/* ----------------------------- */
/* 线性表链式存储结构--双向链表 */
typedef struct dulnode
{
	int data;
	struct dulnode *prior;
	struct dulnode *next;
}dulnode, *dullinklist;

/* 线性表链式存储结构--双向链表插入 */
s->prior = p;
s->next = p->next;
p->next->prior = s;
p->next =  s;

/* 线性表链式存储结构--双向链表删除 */
p->next->prior = p->prior;
p->prior->next = p->next;