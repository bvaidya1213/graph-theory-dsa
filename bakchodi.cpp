#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int wm[7][7];
    for (int i = 0; i < 7; i++)
    {
        cout<<"enter the values for weight matrix row:"<<i + 1<<endl;
        for(int j = 0; j < 7; j++)
        {
            cin>>wm[i][j];
        }
    }
          int min=999,temp=0,temp1=0;
           for(int i=0;i<7;i++)
           {
                   for(int j=0;j<7;j++)
                   {
                           if ((wm[i][j] < min) && wm[i][j]!=0)
                           {
                                min=wm[i][j];
                                temp=i;
                                temp1=j;
                           }
                           else if (wm[i][j]==0)
                                continue;
                   }
           }
           cout<<temp<<endl;
           cout<<temp1<<endl;
           getch();
    }

