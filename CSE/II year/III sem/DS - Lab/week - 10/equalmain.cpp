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

int search(tree* a, tree* b)
{

    if (a==NULL && b==NULL)
        return 1;

    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            search(a->lchild, b->lchild) &&
            search(a->rchild, b->rchild)
        );
    }

    return 0;
}

int main()
{
	printf("Generating Tree 1");
	tree* z1 = (tree*)malloc(sizeof(tree));
	printf("\nEnter the Root - ");
	scanf("%d",&z1->data);
	z1 = gen(z1);
	printf("\nTree Generated!\n");
	printf("\nGenerating Tree 2");
	tree* z2 = (tree*)malloc(sizeof(tree));
	printf("\nEnter the Root - ");
	scanf("%d",&z2->data);
	z2 = gen(z2);
	printf("\nTree Generated!\n");
	printf("\nCommencing comparison\n");
	printf("\nSearch result - ");
	int z = search(z1,z2);
	if(z == 1)
		printf("TREES ARE EQUAL\n");
	else
		printf("TREES ARE NOT EQUAL\n");	
	getch();
	return 0;
}