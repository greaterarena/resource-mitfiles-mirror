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

int search,flag = 0;

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

void tsearch(tree* root)
{
	if(root)
	{
		tsearch(root->lchild);
		if(root->data==search)
		{
			printf("[%d] ",root->data);
			flag = 1;
		}
		else
			printf("%d ",root->data);
		tsearch(root->rchild);		
	}
}

int main()
{
	tree* z = (tree*)malloc(sizeof(tree));
	printf("Enter the Root - ");
	scanf("%d",&z->data);
	z = gen(z);
	printf("\nTree Generated!\n");
	printf("\nEnter an element to search - ");
	scanf("%d",&search);
	printf("\nCommencing traversal and search using mode INORDER\n");
	printf("\nTraversal and Search result - ");
	tsearch(z);
	printf("\n");
	if(flag == 0)
		printf("\nELEMENT NOT FOUND\n");
	else
		printf("\nELEMENT FOUND REFER [x] in the above traversal\n");	
	getch();
	return 0;
}