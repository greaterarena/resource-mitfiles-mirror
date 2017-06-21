#include <iostream>

using namespace std;

class tree{
    public:
        int val;
        tree* l;
        tree* r;

        tree(){
            val = 0;
            l = NULL;
            r = NULL;
        }

        tree(int x){
            val = x;
            l = NULL;
            r = NULL;
        }

        void insert(int v, tree* root){
            if(v<root->val)
            {
                if(root->l==NULL){
                    tree* temp = new tree(v);
                    root->l = temp;
                    cout<<"inserted\n";
                    return;
                }
                else
                    insert(v,root->l);

            }
            else{
                if(root->r==NULL){
                    tree* temp = new tree(v);
                    root->r = temp;
                    cout<<"inserted\n";
                    return;
                }
                else
                    insert(v,root->r);
            }
        }

        void search(int key, tree* root){
            if(key==root->val)
            {
                  cout<<"\nkey found";
                  return;
            }
            if(key<root->val)
            {
                if(root->l!=NULL)
                    search(key,root->l);
                else{
                    cout<<"\nNo match found";
                    return;
                }
            }
            if(key>root->val)
                if(root->r!=NULL)
                    search(key,root->r);
                else{
                    cout<<"\nNo match found";
                    return;
                }
        }

        void preorder(tree* root){
            if(root!=NULL){
                cout<<root->val;
                preorder(root->l);
                preorder(root->r);
            }
        }
        void inorder(tree* root){
           if(root!=NULL){
                inorder(root->l);
                cout<<root->val;
                inorder(root->r);
            }
        }
        void postorder(tree* root){
            if(root!=NULL){
                postorder(root->l);
                postorder(root->r);
                cout<<root->val;
            }
        }
};

int main()
{
    int i1;
    cout<<"enter root - ";
    cin>>i1;
    tree* root = new tree(i1);
    tree* temp = root;

    int c, in1, in2;

    while(true){
        cout<<"\n1. Add\n2. Search\n3. Inorder\n4. Preorder\n5. postorder\n6. Exit\nEnter choice - ";
        cin>>c;
        switch(c){
            case 1: cout<<"\nEnter value to insert - ";cin>>in1;root->insert(in1, root);temp=root;break;
            case 2: cout<<"\nEnter value to search - ";
                    cin>>in1;
                    root->search(in1, root);
                    break;
            case 3: cout<<"\n";root->inorder(temp);break;
            case 4: cout<<"\n";root->preorder(temp);break;
            case 5: cout<<"\n";root->postorder(temp);break;;
            case 6: return 0;
            default : cout<<"invalid input";break;
        }
    }
    return 0;
}
