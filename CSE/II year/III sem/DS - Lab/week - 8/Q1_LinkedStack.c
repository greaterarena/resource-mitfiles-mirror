#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE first;

void Push(int);
void Pop();
void Display();
NODE getNode();
int main()
{
    int Choice, num;
    first=NULL;
    while(1)
    {
        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Display.\n");
        printf("0. Exit.\n");
        printf("Enter your choice: ");
        scanf ("%d", &Choice);
        if (Choice==0)
            break;
        switch(Choice)
        {
          case 1:
            printf("Enter the element: ");
            scanf ("%d", &num);
            Push(num);
            break;

          case 2:
            Pop();
            break;

          case 3:
            Display();
            break;

          default:
            printf("Invalid Choice.\n");
        }
    }
    return 0;
}

void Push (int num)
{
    NODE temp = getNode();
    temp->info=num;

    if (first==NULL)
        first=temp;

    else
    {
        temp->link=first;
        first=temp;
    }
}

void Pop()
{
    NODE temp;
    if (first==NULL)
        printf("The Stack is empty.\n");
    else
    {
        printf("The popped element is: %d\n", first->info);
        temp=first;
        first=first->link;
        free(temp);
    }
}

void Display()
{
    NODE temp;
    temp=first;
    if (temp==NULL)
        printf("The stack is empty.\n");
    else
    {
        printf("The Stack is:\n");
        while (temp!=NULL)
        {
            printf("%d\n", temp->info);
            temp=temp->link;
        }
        printf("\n\n");
    }
}

NODE getNode()
{
    NODE temp;
    temp=(NODE) malloc(sizeof(struct node));
    temp->link=NULL;
    return temp;
}
