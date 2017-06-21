#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

struct tree
{
	char data;
	struct tree *rchild;
	struct tree *lchild;
};

tree * create_tree(char postfix[])
{
	tree * temp;
	tree * stack[20];
	int i=0, k=0;
	char symbol;
	while(postfix[i]!='\0')
	{
		symbol = postfix[i];
		temp=(tree*)malloc(sizeof(tree));
		temp->data=symbol;
		temp->lchild=temp->rchild=NULL;
		if(isalnum(symbol))		
			stack[k++]=temp;
		 else				 	
		{				    
			temp->rchild=stack[--k]; 		 				     	
			temp->lchild=stack[--k];  
			stack[k++]=temp;
		}
		i++;
	}
return(stack[--k]);	
}	

float eval(tree * root)
{
	float num;
	switch(root->data)
	{
		case '+':return eval(root->lchild)+ eval(root->rchild);
		case '-' :return eval(root->lchild)- eval(root->rchild);
		case '/':return eval(root->lchild)/ eval(root->rchild);
		case '*' :return eval(root->lchild)* eval(root->rchild);
		case '$':
		case '^':return pow(eval(root->lchild), eval(root->rchild));
		default :return((float) root->data - 48);
	}
} 


void trav(tree* root)
{
	if(root)
	{
		trav(root->lchild);
		printf("%c ",root->data);
		trav(root->rchild);
	}
}

int main()
{
	tree* z = (tree*)malloc(sizeof(tree));
	char post[100];
	printf("Enter the postfix expression - ");
	scanf("%s",&post);
	z = create_tree(post);
	printf("\nTree Generated!\n");
	printf("\nPrinting INFIX expression - ");
	trav(z);
	float t = eval(z);
	printf("\n\nValue of expression - %f",t);	
	printf("\n\nall done \n");
	getch();
    return 0;
}
