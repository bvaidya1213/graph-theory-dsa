#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
void print_graph(int am[][5],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<am[i][j]<<"\t";
        }
        cout<<endl;
    } 
}
void addEdge(int am[][5],int src,int dest)
{
     am[src][dest] = am[dest][src] = 1;
     return;
}
int main()
{
    int n,am[5][5];
    cout<<"Enter the no of vertices\n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            am[i][j] = 0;
        }
    }
    addEdge(am, 0, 1);
    addEdge(am, 0, 4);
    addEdge(am, 1, 2);
    addEdge(am, 1, 3);
    addEdge(am, 1, 4);
    addEdge(am, 2, 3);
    addEdge(am, 3, 4);
    print_graph(am,n);
    getch();
}
