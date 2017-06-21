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

typedef struct stackStruct
{
	void *ptr[100];
	int top;
}stack;

void initialize_stack(stack *s)
{
	s->top = 0;
}
int is_stack_empty(stack *s)
{
	if(s->top)
		return 0;
	else
		return 1;
}
void push(stack *s,void *node)
{
 //s->top++;
	s->ptr[s->top++]=node;
}
void *topelem(stack *s)
{
	return s->ptr[(s->top)-1];
}
void *pop(stack *s)
{
	return s->ptr[--(s->top)];
}

void preorderi(tree *root)
{
	tree *save[100];
	int top = 0;
	if (root == NULL)
	{
		return;
	}
	save[top++] = root;
	while (top != 0)
	{
		root = save[--top];
		printf("%d ", root->data);

  //order matters, first right then left on stack
  // right
	if (root->rchild != NULL)
		save[top++] = root->rchild;

  //left
	if (root->lchild != NULL)
		save[top++] = root->lchild;
	}
}


void inorderi(tree *root)
{
	tree *current,*pre;

	if(root == NULL)
		return;

	current = root;
	while(current != NULL)
	{
		if(current->lchild == NULL)
		{
			printf("%d ", current->data);
			current = current->rchild;
		}
		else
		{
			//Find the inorder predecessor of current node
			pre = current->lchild;
			while(pre->rchild != NULL && pre->rchild != current)
			pre = pre->rchild;

			//Make current as right child of its inorder predecessor
			if(pre->rchild == NULL)
			{
				pre->rchild = current;
				current = current->lchild;
			}
			//Revert the changes made in tree to restore the original tree by fixing the right child of predecssor
			else
			{
				pre->rchild = NULL;
				printf("%d ",current->data);
				current = current->rchild;
			}
		}
	}
}

void postorderi(tree *root) {
	if (root==NULL)
		return;
	stack smemory;
	stack *s = &smemory;
	initialize_stack(s);
	push(s,root);
	tree *prev = NULL;

	while (is_stack_empty(s)==0)
	{
		tree *curr = (tree *) topelem(s);
  
		if (!prev || prev->lchild == curr || prev->rchild == curr)
		{
			if (curr->lchild)
			{
				push(s,curr->lchild);
			}
			else if (curr->rchild)
			{
				push(s,curr->rchild);
			}
			else
			{
				printf("%d ",curr->data);
				pop(s);
			}
		}
		// we are traversing up the tree from the left
		else if (curr->lchild == prev)
		{
			if (curr->rchild)
			{
				push(s,curr->rchild);
			}
			else
			{
				printf("%d ",curr->data);
				pop(s);
			}
		}
		// we are traversing up the tree from the right
		else if (curr->rchild == prev)
		{
			printf("%d ",curr->data);
			pop(s);
		}	
		prev = curr;  // record previously traversed node
	}
}

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

void postorderr(tree* root)
{
	if(root)
	{
		postorderr(root->lchild);
		postorderr(root->rchild);
		printf("%d ",root->data);
	}
}

void inorderr(tree* root)
{
	if(root)
	{
		inorderr(root->lchild);
		printf("%d ",root->data);
		inorderr(root->rchild);		
	}
}

void preorderr(tree* root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorderr(root->lchild);
		preorderr(root->rchild);
	}
}



int main()
{
	tree* z = (tree*)malloc(sizeof(tree));
	printf("\nEnter the Root - ");
	scanf("%d",&z->data);
	z = gen(z);
	printf("Tree Generated!\n");
	printf("\npreorder  recursive - ");
	preorderr(z);
	printf("\ninorder   recursive - ");
	inorderr(z);
	printf("\npostorder recursive - ");
	postorderr(z);
	printf("\npreorder  iterative - ");
	preorderi(z);
	printf("\ninorder   iterative - ");
	inorderi(z);
	printf("\npostorder iterative - ");
	postorderr(z);
	getch();
	return 0;
}