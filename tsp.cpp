#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void 
int main()
{
    int v[4], am[4][4];
    for(int i = 0; i < 7; i++)
    v[i]=0;
    for(int i = 0; i < 7; i++)
    {
            cout<<"enter the values for adjacency matrix row:"<<i+1<<endl;
            for(int j = 0; j < 7; j++)
            {
                cin>>am[i][j];
            }
    }
    getch();
}
