#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 5

typedef struct {
    int front;
    int rear;
    char arr[max_size];
}q;

void init(q* x){
    x->front = 0;
    x->rear = -1;
}

void insertq(q* x,char item){
    if(x->rear==max_size-1){
        printf("\n\a Queue is full element cannot be inserted\n");
        return 0;
        }
    else
    x->arr[++x->rear] = item;
}

char deleteq(q* x){
    if(x->front>x->rear){
        printf("\n Queue is empty\n");
        return 0;
    }
    else
       return x->arr[x->front++];
}

void displayq(q* x){
    int i;
    printf("\n");
    for(i=x->front;i<=x->rear;i++){
            printf("\t%c",x->arr[i]);
    }
    printf("\n");
}

int main()
{
    int c;
    q q1;
    init(&q1);
    char x;
    while(1){
        printf("\n1. Insert\t2. Delete\t3. Display\t4. Exit -> ");
        scanf("%d",&c);
        getchar();
        switch(c){
        case 1: printf("\n Element -> ");
                scanf("%c",&x);
                getchar();
                insertq(&q1,x);
                break;
        case 2: x = deleteq(&q1);
                if(x)
                printf("\nDeleted -> %c\n",x);
                else{}
                break;
        case 3: displayq(&q1);
                break;
        default:exit(0);
        }
    }
    return 0;
}
