

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