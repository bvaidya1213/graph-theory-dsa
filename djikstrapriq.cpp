#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
#define INFINITY 999
struct node
{
	int cost;
	int value;
	int from;
	int index;
}a[7],c[7];
void addEdge(int am[][7],int src,int dest,int cost)
{
     am[src][dest] = cost;
     am[dest][src] = cost;
     return;
}
void min_heapify(node *b,int i,int n)
{
    int j,temp;
    temp = b[i].cost;
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && b[j + 1].cost < b[j].cost)
            j = j + 1;
        if (temp < b[j].cost)
            break;
        else if (temp >= b[j].cost)
        {
            b[j/2].cost = a[j].cost;
            j = 2 * j;
        }
    }
    a[j / 2].cost = temp;
    return;
}
int build_minheap(node *b,int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(b,i,n);
    }
	return (b[0].index);
}
void bell(int am[][7])
{
	int i,j,k,count,x = 0,temp;
	a[0].cost = 0;
	a[0].from = 0;
	a[0].value = 0;
	a[0].index = 0;
	for (i = 1; i < 7; i++)
	{
		a[i].from = 0;
		a[i].cost = INFINITY;
		a[i].value = 0;
		a[i].index = i;
	}
	while (x < 7)
	{
		count = 0;
		for (i = 0; i < 7; i++)
		{
			if (a[i].cost != INFINITY && a[i].value == 0)
			{
				c[count] = a[i];
				count++;
			}
			else
			{
				continue;
			}
		}
		for (int i = 0; i < count; i++)
        {
            cout<<c[i].index<<":"<<c[i].cost<<endl;
        } 
        cout<<endl;
		temp = build_minheap(c,7);
		for (k = 0; k < 7; k++)
		{
			if (am[temp][k] + a[temp].cost < a[k].cost)
			{
				a[k].cost = am[temp][k] + a[temp].cost;
				a[k].from = temp;
			}
			else
			{
				continue;
			}
		}
		a[temp].value = 1;
		x++;
	}
	for (j = 0; j < 7; j++)
	{
		cout<<a[j].cost<<endl;
	}
}
int main()
{
    int am[7][7],c = 0,i,j,cost;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            am[i][j] = INFINITY;
        }
    }
	while (c < 12)
	{
		cout<<"Enter the source, destination and cost of edge\n";
		cin>>i>>j>>cost;
		addEdge(am, i, j, cost);
		c++;
	}
	for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout<<am[i][j]<<"\t";
        }
        cout<<endl;
    }
	bell(am);
	getch();
}
