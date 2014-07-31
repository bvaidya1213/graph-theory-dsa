#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int c = 0;
struct node
{
    node *next;
    int data;
}*head = NULL,*p = NULL,*q = NULL,*np = NULL;
void create(int x)
{
    np = new node;
    np->data = x;
    np->next = NULL;
    if (c == 0)
    {
        head = np;
        p = head;
		p->next = NULL;
        c++;
    }
    else
    {
        p = head;
		q = p;
		if (p->data > np->data)
		{
			np->next = p;
			head = np;
		}
		else if (p->data < np->data)
		{
			while (p != NULL && q->data < np->data)
			{
				q = p;
				p = p->next;
				if (p == NULL)
				{
					q->next = np;
					np->next = NULL;
				}
				else if (np->data < p->data)
				{
					q->next = np;
					np->next = p;
					break;
				}
			}
		}
	}
}
void traverse()
{
	node *t = head;
	cout<<"\n\nlinear display of nodes currently present in linked list....\n\n";
	while (t != NULL)
	{
		cout<<t->data<<"\t";
		t = t->next;
	}
}
int main()
{
	int i=0,n,x;
	cout<<"enter the no of nodes\n";
	cin>>n;
	while (i < n)
	{
        cout<<"enter value of node\n";
        cin>>x;
		create(x);
		i++;
	}
	traverse();
	getch();
}
