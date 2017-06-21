#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct tree
{
	int data;
	struct tree *rchild;
	struct tree *lchild;
};

int node = 0, leaf = 0;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int height(tree * root)
{
	if(root==NULL) return -1;
	return 1+max(height(root->lchild),height(root->rchild));
}

void count_node(tree* root)
{
	if(root==NULL) return;
	count_node(root->lchild);
	node++;
	count_node(root->rchild);
}

void count_leaf(tree* root)
{
	if(root==NULL) return;
	count_leaf(root->lchild);
	if(root->lchild==NULL && root->rchild==NULL) leaf++;
	count_leaf(root->rchild);
}

tree * gen(tree *x)
{
	int data;
	printf("enter the left child for %d  ->",x->data);
	scanf("%d",&data);
	if(data!=-1)
	{	tree* l1 = (tree*)malloc(sizeof(tree));
		x->lchild = l1;
		l1->lchild = NULL; l1->rchild = NULL;
		l1->data=data;
		gen(l1);
	}

	printf("enter the right child for %d ->",x->data);
	scanf("%d",&data);
	if(data!=-1)
	{	tree* l2 = (tree*)malloc(sizeof(tree));
		x->rchild = l2;
		l2->lchild = NULL; l2->rchild = NULL;
		l2->data=data;
		gen(l2);
	}

	return x;
}

void trav(tree* root)
{
	if(root)
	{
		trav(root->lchild);
		printf("%d ",root->data);
		trav(root->rchild);
	}
}

int main()
{
	tree* z = (tree*)malloc(sizeof(tree));
	printf("Enter the Root - ");
	scanf("%d",&z->data);
	z = gen(z);
	printf("\nTree Generated!\nPrinting Now in indorder - ");
	trav(z);
	int h = height(z);
	count_node(z);
	count_leaf(z);
	printf("\nHeight - %d",h);
	printf("\nNo of Nodes - %d",node);
	printf("\nNo of Leaves - %d",leaf);
	getch();
    return 0;
}
