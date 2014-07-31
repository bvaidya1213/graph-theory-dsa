#include<iostream>
#include<set>
#include<stdio.h>
using namespace std;
#include<conio.h>
#define INFINITY 999
struct node
{
	int cost;
	int value;
	int from;
}a[7];
void addEdge(int am[][7],int src,int dest,int cost)
{
     am[src][dest] = cost;
     am[dest][src] = cost;
     return;
}
void bell(int am[][7])
{
	int i,j,k,c = 0,temp,b[7],cnt;
	a[0].cost = 0;
	a[0].from = 0;
	a[0].value = 0;
	for (i = 1; i < 7; i++)
	{
		a[i].from = 0;
		a[i].cost = INFINITY;
		a[i].value = 0;
	}
	while (c < 7)
	{
		cnt = 0;
		for (i = 0; i < 7; i++)
		{
			if (a[i].cost != INFINITY && a[i].value != 1)
			{
				b[cnt]=a[i].cost;
				cnt++;
			}
			else
			{
                continue;
            }
		}
		for (i = 0; i < 7; i++)
		{
            cout<<b[i]<<endl;
         }
		std::set<int> myset (b,b + 7);
		std::set<int>::iterator it = myset.begin();
		//int min = *it;
		//cout<<min<<endl;
		//std::cout<<*it;
		std::cout<<'\n';
		for (i = 0; i < 7; i++)
		{
			if (a[i].cost == *it && a[i].value == 0)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		temp = i;
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
		c++;
	}
	cout<<"Cost"<<"\t"<<"Source Node"<<endl; 
	for (j = 0; j < 7; j++)
	{
		cout<<a[j].cost<<"\t"<<a[j].from<<endl;
	}
}
int main()
{
    int n,am[7][7],c = 0,i,j,cost;
    cout<<"Enter the no of vertices\n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
	bell(am);
	getch();
}
