

typedef struct biNode
{
	int data;
	struct biTree *lchild, *rchild;
}biNode, *biTree;

//初始化二叉树
void createBiTree(biTree *T)
{	
	int index;
	char ch;
	scanf("%c", &ch);
	
	if('ch'== NULL)
		*T == NULL;
	else
	{
		biTree *T = biTree malloc(sizeof(biTNode));
		if(!*T)
			exit(overflow);
		T->data = ch;
		createBiTree(&(T->lchild));
		createBiTree(&(T->rchild));
	}
}

//返回二叉树深度
int biTreeDepth(biTree *T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i = biTreeDepth(T->lchild);
	else 
		i = 0;
	if(T->rchild)
		j = biTreeDepth(T->rchild);
	else 
		j = 0;
	return i>j ? i+1:j+1;
}