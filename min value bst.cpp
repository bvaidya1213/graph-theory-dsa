#include<iostream>
using namespace std;
#include<conio.h>
int min;  
struct tree
{
       tree *l,*r;
       int data;
}*root=NULL,*p=NULL,*np=NULL,*q;     
void create()
{
       int value,c=0;
       while(c<7)
       {
            if(root==NULL)
            {
                          root=new tree;
                          cout<<"enter value of root node\n";
                          cin>>root->data;
                          root->r=NULL;
                          root->l=NULL;
            }
            else
            {
              //  inorder(root);
                p=root;
                cout<<"enter value of node\n";
                cin>>value;
                while(true)
                {
                      if(value<p->data)
                      {
                                 if(p->l==NULL)
                                 {
                                 p->l=new tree;
                                 p=p->l;
                                 p->data=value;
                                 p->l=NULL;
                                 p->r=NULL;
                                 cout<<"value entered in left\n";
                                 break;
                                 }
                                 else if(p->l!=NULL)
                                 {
                                 p=p->l;
                                 }
                        }
                       else if(value>p->data)
                       {
                                  if(p->r==NULL)
                                  {
                                   p->r=new tree;
                                   p=p->r;
                                   p->data=value;
                                   p->l=NULL;
                                   p->r=NULL;
                                   cout<<"value entered in right\n";
                                   break;
                                   }
                                   else if(p->r!=NULL)
                                  {
                                   p=p->r;
                                   }
                        }
                   }
                 }
                 c++;
            }
       }
       int inorder(tree *p)
       {
            int min;
            while(p->l != NULL)
            {
            p=p->l;
            }
            return(p->data);
       }
       int main()
       {
           int x,min;
           create();
           cout<<"printing traversal in inorder\n";
           x=inorder(root);
           cout<<"Minimum value in tree:"<<x<<endl;
           getch();
       }                
