#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct tree
{
	int data;
	struct tree *rchild;
	struct tree *lchild;
};


tree* gen(tree *x)
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


int main()
{
	printf("the world is full of uncertainty so why dont we go ahead and \n\n");
	printf("create a binary tree because thats just what we do in the lab\n");
	tree* z = (tree*)malloc(sizeof(tree));
	printf("\nEnter the Root value of the holy tree - ");
	scanf("%d",&z->data);
	z = gen(z);
	printf("\nyou have made the earth a greener place thank you the tree shall\n");
	printf("help us fight global warming woohoo!\n");
	getch();
	return 0;
}