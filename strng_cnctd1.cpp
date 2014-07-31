#include<iostream>
#include<conio.h>
using namespace std;
struct node_info
{
    int no;
    int lv_time,st_time;
}*q = NULL,*r = NULL;
struct node
{
    node_info *pt;
    node *next;
}*top = NULL,*p = NULL,*np = NULL;
struct node1
{
    node1 *link;
    node_info *pt1;
}*head = NULL,*m = NULL,*n = NULL,*np1 = NULL;
int c = 0;
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
void store(node_info *ptr1)
{
    np1 = new node1;
    np1->pt1 = ptr1;
    np1->link = NULL;
    if (c == 0)
    {
        head = np1;
        m = head;
		m->link = NULL;
        c++;
    }
    else
    {
        m = head;
		np1->link = m;
		head = np1;
	}
}
void topo(int *v,int am[][7],int i)
{
    q = new node_info;
    q->no = i;
    q->st_time = c;
    cout<<"start time for "<<q->no<<":"<<c<<endl;
    push(q);
    v[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (am[i][j] == 0  || (am[i][j] == 1 && v[j] == 1))
            continue;
        else if(am[i][j] == 1 && v[j] == 0)
        {
            c++;
            topo(v,am,j);
        }
    }
    c++;
    q = pop();
    q->lv_time = c;
    cout<<"leave time for "<<q->no<<":"<<c<<endl;
    push(q);
    return;
}
int main()
{
    int v[7],am[7][7],amt[7][7];
    for (int i = 0; i < 7; i++)
    {
        v[i] = 0;
    }
    for (int i = 0; i < 7; i++)
    {
        cout<<"enter the values for adjacency matrix row:"<<i + 1<<endl;
        for (int j = 0; j < 7; j++)
        {
            cin>>am[i][j];
        }
    }
    topo(v,am,0);
	/*for (int i = 0; i < 7; i++)
    {
		v[i] = 0;
        for (int j = 0; j < 7; j++)
        {
			amt[j][i]=am[i][j];
		}
	}*/
    getch();
}
