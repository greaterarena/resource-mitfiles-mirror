#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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

tree * destruct(tree * root, int data)
{
	tree *cur,*parent,*suc,*q;
	if(root==NULL)
	{
		printf("\nTree is empty! Data not found\n");
		return root;
	}
	parent = NULL;
	cur = root;
	while(cur!=NULL)
	{
		if(data==cur->data)
			break;
		parent = cur;
		cur = (data<cur->data)?cur->lchild:cur->rchild;
	}
	if(cur==NULL)
	{
		printf("\nData not found\n");
		return root;
	}
	if(cur->lchild==NULL)
		q = cur->rchild;
	else if(cur->rchild == NULL)
		q = cur->lchild;
	else
	{
		suc = cur->rchild;
		while(suc->lchild!=NULL)
			suc = suc->lchild;
		suc->lchild=cur->lchild;
		q=cur->rchild;
	}
	if(parent==NULL)
		return q;
	if(cur==parent->lchild)
		parent->lchild=q;
	else
		parent->rchild=q;
	free(cur);
	return root;
}

void trav(tree* root)
{
	if(root)
	{
		printf("%d ",root->data);
		trav(root->lchild);
		trav(root->rchild);
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
	printf("\npreorder traversal - ");
	trav(z);
	printf("\n");
	while(1)
	{
		int data;
		printf("\nenter data to delete from the tree or -1 to exit -> ");
		scanf("%d",&data);
		if(data == -1)
			break;
		z = destruct(z,data);
		printf("\npreorder traversal - ");
		trav(z);
	}
	printf("\npreorder traversal - ");
	trav(z);
	printf("\nexecutin complete\n");
	getch();
    return 0;
}