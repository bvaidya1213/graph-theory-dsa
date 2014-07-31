#include<iostream>
#include<conio.h>
using namespace std;
int cnt = 0;
struct node_info
{
    int no;
}*q = NULL,*r = NULL;
struct node
{
    node_info *pt;
    node *next;
}*top = NULL,*p = NULL,*np = NULL;
void push(node_info *ptr)
{
    np = new node;
    np->pt = ptr;
    np->next = NULL;
    if (top == NULL)
    {
        top = np;
    }
    else
    {
        np->next = top;
        top = np;
    }
}
node_info *pop()
{
    if (top == NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        p = top;
        top = top->next;
        return(p->pt);
        delete(p);
    }
}           
int topo(int *v,int am[][7],int i)
{
    q = new node_info;
    q->no = i;
    push(q);
    v[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (am[i][j] == 0  || (am[i][j] == 1 && v[j] == 1))
            continue;
        else if(am[i][j] == 1 && v[j] == 0)
        {
            cnt++;
            topo(v,am,j);
        }
    }
    q = pop();
}
void addEdge(int am[][7],int src,int dest)
{
     am[src][dest] = 1;
	 am[dest][src] = 1;
     return;
}
int main()
{
    int v[7],am[7][7],amt[7][7],c = 0,a,b,x = 0;
    for (int i = 0; i < 7; i++)
    {
        v[i] = 0;
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            am[i][j] = 0;
        }
    }
    while (c < 9)
	{
		cout<<"Enter the source and destination\n";
		cin>>a>>b;
		addEdge(am, a, b);
		c++;
	}
	for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            amt[i][j] = am[i][j];
        }
    }
	for (int i = 0; i < 7; i++)
    {
		for(int j = 0; j < 7; j++)
		{
			am[i][j] = 0;
			am[j][i] = 0;
		}
		if (i < 6)
		{
		    topo(v, am, i + 1);
        }
        else
        {
            topo(v, am, 0);
        }
		if (cnt < 5)
		{
			cout<<endl<<i<<" is an articulation point"<<endl;
		}
		cnt = 0;
		for (int j = 0; j < 7; j++)
        {
            am[i][j] = amt[i][j];
			am[j][i] = amt[j][i];
			v[j] = 0;
        }
        while (top != NULL)
        {
              pop();
        }
	}
	getch();
}
		
