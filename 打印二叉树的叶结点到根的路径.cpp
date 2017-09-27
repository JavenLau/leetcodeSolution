/*
 *Author: ZhangHaiba
 *Date: 2014-1-30
 *File: print_all_path_of_binary_tree.c
 *
 *a demo shows how to print all path of binary tree in dictionary order
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define LEN 1024
#define CMD_LEN 128
#define MOD 100

typedef struct node * link;
typedef struct node
{
	int item;
	link left;
	link right;
} node;


//public
link NODE(int item, link left, link right);
link bt_create_by_random(int n);
void bt_show_by_tree(link root);
void print_all_path(link root);
void print_all_path_dict_order(link root);

//private
void tree_print(link root, FILE *fd);
link bt_create_by_random_core(int n);

//private
int path[LEN];
int cnt = 0;

int main(void)
{
	int n;

	scanf("%d", &n);
	link bt_tree_a = bt_create_by_random(n);
	bt_show_by_tree(bt_tree_a);
	printf("print all path in DFS order:\n");
	print_all_path(bt_tree_a);
	printf("print all path in dictionary order:\n");
	print_all_path_dict_order(bt_tree_a);
	return 0;
}


void print_all_path(link root)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		path[cnt++] = root->item;
		int i;
		for (i = 0; i < cnt; ++i)
			printf(i == cnt-1 ? "%d\n" : "%d ", path[i]);
		cnt--;
		return;
	}
	path[cnt++] = root->item;
	print_all_path(root->left);
	print_all_path(root->right);
	cnt--;
}

void print_all_path_dict_order(link root)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		path[cnt++] = root->item;
		int i;
		for (i = 0; i < cnt; ++i)
			printf(i == cnt-1 ? "%d\n" : "%d ", path[i]);
		cnt--;
		return;
	}
	path[cnt++] = root->item;
	if (root->left == NULL)
		print_all_path_dict_order(root->right);
	else if (root->right == NULL)
		print_all_path_dict_order(root->left);
	else
	{
		if (root->left->item < root->right->item)
		{
			print_all_path_dict_order(root->left);
			print_all_path_dict_order(root->right);
		}
		else
		{
			print_all_path_dict_order(root->right);
			print_all_path_dict_order(root->left);
		}
	}
	cnt--;
}


link NODE(int item, link left, link right)//节点初始化
{
	link born = (link)malloc( sizeof (node) );
	born->item = item;
	born->left = left;
	born->right = right;
	return born;
}

link bt_create_by_random(int n)
{
	srand( (unsigned)time(NULL) );
	return bt_create_by_random_core(n);
}

link bt_create_by_random_core(int n)
{
	if (n <= 0)
		return NULL;
	if (n == 1)
		return NODE(rand()%MOD, NULL, NULL);
	link root = NODE(rand()%MOD, NULL, NULL);
	int left_n = rand()%(n-1)+1, right_n = (n-1) - left_n;
	root->left = bt_create_by_random_core(left_n);
	root->right = bt_create_by_random_core(right_n);
	return root;
}


void bt_show_by_tree(link root)
{
	char cmd[CMD_LEN];

	sprintf(cmd, "rm -f ./tree_src.txt");
	system(cmd);

	FILE *fd = fopen("./tree_src.txt", "a+");
	fprintf(fd, "\n\t\\tree");
	tree_print(root, fd);
	fprintf(fd, "\n\n");
	fclose(fd);

	sprintf(cmd, "cat ./tree_src.txt | ~/tree/tree");
	system(cmd);
}

void tree_print(link root, FILE *fd)
{
	fprintf(fd, "(");
	if (root != NULL)
	{
		fprintf(fd, "%d", root->item);
		tree_print(root->left, fd);
		tree_print(root->right, fd);
	}
	fprintf(fd, ")");
}