#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct stack1
{
    int data1;
    stack1 *next1;
}*top1=NULL,*q1=NULL,*np1=NULL;
struct stack2
{
    int data2;
    stack2 *next2;
}*top2=NULL,*q2=NULL,*np2=NULL;
void push1(int x)
{
    np1 = new stack1;
    np1->data1 = x;
    np1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = np1;
    }
    else
    {
        np1->next1=top1;
        top1=np1;
    }
}
int pop1()
{
    int x;
    if(top1==NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        q1=top1;
        top1=top1->next1;
        x=q1->data1;
        delete q1;
        return x;
    }
}       
void push2(int x)
{
    np2 = new stack2;
    np2->data2 = x;
    np2->next2 = NULL;
    if (top2 == NULL)
    {
        top2 = np2;
    }
    else
    {
        np2->next2=top2;
        top2=np2;
    }
}
int pop2()
{
    int x;
    if(top2==NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        q2=top2;
        top2=top2->next2;
        x=q2->data2;
        delete q2;
        return x;
    }
}       
int main()
{
    int n,x,i = 0;
    cout<<"Enter the number of elements to be entered into queue\n";
    cin>>n;
    while (i < n)
    {
		cout<<"enter the element to be entered\n";
		cin>>x;
		push1(x);
		i++;
	}
	while (top1 != NULL)
		push2(pop1());
	cout<<"\n\n Elements dequeued...\n\n";
	while (top2 != NULL)
	{
		cout<<pop2()<<endl;
	}
	getch();
}
Output
Enter the number of elements to be entered into queue
7
enter the element to be entered
2
enter the element to be entered
5
enter the element to be entered
1
enter the element to be entered
9
enter the element to be entered
4
enter the element to be entered
7
enter the element to be entered
6


 Elements dequeued...

2
5
1
9
4
7
6
