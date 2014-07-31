#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node *next;
}*top = NULL,*p = NULL,*np = NULL;
int x;
void push(int n)
{
	np = new node;
	np->data = n;
	np->next = NULL;
	if (top == NULL)
	{
		top = np;
	}
	else
	{
		np->next=top;
		top=np;
	}
}
int pop()
{
	if (top == NULL)
	{
		cout<<"underflow\n";
	}
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		delete(p);
		return(x);
	}
}
int main()
{
    int n,c = 0,x;
    cout<<"Enter the number of values to be pushed onto stack\n";
    cin>>n;
    while (c < n)
    {
		cout<<"Enter the value to be pushed onto stack\n";
		cin>>x;
		push(x);
		c++;
	}
	cout<<"Popped Values\n\n";
	while(true)
	{
        if (top != NULL)
		    cout<<pop()<<endl;
		else
		    break;
	}
	getch();
}
