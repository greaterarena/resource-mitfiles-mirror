#include<iostream>
#include<malloc.h>

using namespace std;

struct node
{
    int l;
    int m;
    struct node* parent;
    struct node* left;
    struct node* middle;
    struct node* right;
};

typedef struct node* nodeptr;

void inorder(nodeptr r)
{
    if(r!=NULL)
    {

        inorder(r->left);
        if(r->l!=0)
            cout<<r->l<<" ";
        inorder(r->middle);
        if(r->m!=0)
            cout<<r->m<<" ";
        inorder(r->right);
    }
}

void sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j+1]<a[j])
			{
				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];
			}
		}
	}
}

nodeptr split(nodeptr r,nodeptr a,int val)
{
    int arr[3];int brr[3];
    if(a==r)   //if it is a root node
    {
        arr[0]=a->l;
        arr[1]=a->m;
        arr[2]=val;
        sort(arr,3);
        a->l=arr[1];
        a->m=0;
        a->left=(struct node*)malloc(sizeof(node));;
        a->middle=(struct node*)malloc(sizeof(node));;
        a->left->l=arr[0];
        a->left->m=0;
        a->left->parent=a;
        a->left->left=a->left->middle=a->left->right=NULL;
        a->middle->l=arr[2];
        a->middle->m=0;
        a->middle->left=a->middle->middle=a->middle->right=NULL;
        a->middle->parent=a;
        a->right=NULL;
        return a;
  }
  else
  {
      nodeptr p=a->parent;
      arr[0]=a->l;
      arr[1]=a->m;
      arr[2]=val;
      sort(arr,3);
      if(p->m==0)
      {
            p->m=arr[1];
            if(p->l>p->m)
            {
                int temp=p->l;
                p->l=p->m;
                p->m=temp;
            }
            p->right=p->middle;
            p->left=(struct node*)malloc(sizeof(node));
            p->left->l=arr[0];
            p->left->m=0;
            p->left->parent=p;
            p->left->left=p->left->middle=p->left->right=NULL;
            p->middle=(struct node*)malloc(sizeof(node));
            p->middle->l=arr[2];
            p->middle->m=0;
            p->middle->parent=p;
            p->middle->left=p->middle->middle=p->middle->right=NULL;
            return p;
        }
        else
        {
            nodeptr u=p->left;
            nodeptr d=p->right;
            nodeptr b= (struct node*)malloc(sizeof(node));
            b->l=arr[0];
            b->m=0;
            b->left=b->middle=b->right=NULL;
            nodeptr c= (struct node*)malloc(sizeof(node));
            c->l=arr[2];
            c->m=0;
            c->left=c->middle=c->right=NULL;
            nodeptr y=(struct node*)malloc(sizeof(node));
            y->l=arr[1];;
            y->m=0;
            y->parent=p->parent;
            brr[0]=p->l;
            brr[1]=p->m;
            brr[2]=arr[1];
            sort(brr,3);
            y->left=(struct node*)malloc(sizeof(node));
            y->left->l=brr[0];
            y->left->m=0;
            y->left->left=y->left->middle=y->left->right=NULL;
            y->left->parent=y;
            y->middle=(struct node*)malloc(sizeof(node));
            y->middle->l=brr[2];
            y->middle->m=0;
            y->middle->left=y->middle->middle=y->middle->right=NULL;
            y->middle->parent=y;
            y->right=NULL;
            a->parent=y->left;
            b->parent=y->left;
            c->parent=y->right;
            d->parent=y->right;
            y->left->left=u;
            y->left->middle=b;
            y->left->right=NULL;
            y->middle->middle=d;
            y->middle->right=NULL;
            y->middle->left=c;
            return y;
            }
    }
}

nodeptr find(nodeptr r,int val)
{
    if((r==NULL))
        return r;
    if(val<r->l)
    {
       if(r->left==NULL)
            return r;
        else
            return (find(r->left,val));
    }
    else if((r->m!=0)&& (val>r->m))
   {
        if(r->right==NULL)
            return r;
        else
            return (find(r->right,val));
   }
    else
   {
       if(r->middle==NULL)
            return r;
        else
            return (find(r->middle,val));
   }
}

nodeptr insert(nodeptr r,int val)
{
    nodeptr a=find(r,val);
    if(a==NULL)
    {
        a=(struct node*)malloc(sizeof(node));
        a->l=a->m=0;
        a->l=val;
        a->left=a->middle=a->right=NULL;
        a->parent=NULL;
        return a;
    }
    else if((a->m==0))
    {
        a->m=val;
        if(a->l>a->m)
        {
            int temp=a->l;
            a->l=a->m;
            a->m=temp;
        }
        return r;
    }
    else
    {
        nodeptr k=split(r,a,val);
        if(k->parent==NULL)
        {
            return k;
        }
        return r;
    }
}

int main()
{
    int n;int m;
    nodeptr r=NULL;
    cout<<"Enter Number of Elements: ";
    cin>>n;
    cout<<"Now enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>m;
        r=insert(r,m);
    }
    inorder(r);
 }
