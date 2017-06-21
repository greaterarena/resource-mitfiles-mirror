#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAX_QUEUE 30 

struct tree
{
	int data;
	struct tree *rchild;
	struct tree *lchild;
};

 
tree * gen(tree * root, int data)
{
	tree *temp, *cur, *prev;
	temp = (tree*)malloc(sizeof(tree));
	temp->data=data;
	temp->rchild=temp->lchild=NULL;
	if(root==NULL)
		return temp;
	prev = NULL;
	cur = root;
	
	while(cur!=NULL)
	{
		prev = cur;
		if(data==cur->data)
		{
			printf("Duplicate entries not allowed\n");
			free(temp);
			return root;
		}
		if(data<cur->data)
			cur = cur->lchild;
		else
			cur = cur->rchild;
	}
	
	if(data < prev->data)
		prev->lchild = temp;
	else
		prev->rchild = temp;
	return root;
}

void level(tree *root)
{
	tree * q[MAX_QUEUE], *cur;
	int front = 0, rear = -1;
	q[++rear] = root;
	while(front<=rear)
	{
		cur = q[front++];
		printf("%d ",cur->data);
		if(cur->lchild!=NULL)
			q[++rear] = cur->lchild;
		if(cur->rchild!=NULL)
			q[++rear] = cur->rchild;
	}
}

int main()
{
	tree* z = (tree*)malloc(sizeof(tree));
	z->lchild=z->rchild=NULL;
	printf("\nenter the root for bst -> ");
	scanf("%d",&z->data);
	while(1)
	{
		int data;
		printf("\nenter data to insert into the tree or -1 to exit -> ");
		scanf("%d",&data);
		if(data == -1)
			break;
		z = gen(z,data);
	}
	printf("\nlevelorder traversal - ");
	level(z);
	printf("\n\nexecution complete\n");
	getch();
    return 0;
}