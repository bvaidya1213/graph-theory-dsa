#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int min(int a, int b)
{
    int x;
    if (a < b)
    {
          return a;
    }
    else
    {
        return b;
    }
}
int max(int a, int b)
{
    int x;
    if (a > b)
    {
          return a;
    }
    else
    {
        return b;
    }
}
int getMedian(int *ar1, int *ar2, int n)
{
	int x, i, j;
	if (n == 1)
	{
		x = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2;
		cout<<"\n"<<x;
	}
	else
	{
		i = n / 2;
		int *temp1 = new int[i + 1];
        int *temp2 = new int[i + 1];
		if (ar1[i] < ar2[i])
		{
			for (j = 0; j <= i; j++)
			{
				temp1[j] = ar1[i + j];
				temp2[j] = ar2[j];
			}
		}
		else if (ar1[i] > ar2[i])
		{
			for (j = 0; j <= i; j++)
			{
				temp1[j] = ar1[j];
				temp2[j] = ar2[i + j];
			}
		}
		getMedian(temp1, temp2, i);
	}
}
int main()
{
	int i, x, j;
	cout<<"enter the no of elements to be entered\n";
	cin>>i;
	int *ar1 = new int[i];
	int *ar2 = new int[i];
	cout<<"enter elements of array 1"<<endl;
	for (j = 0; j < i; j++)
	{
        cin>>ar1[j];
    }
    cout<<"enter elements of array 2"<<endl;
	for (j = 0; j < i; j++)
	{
        cin>>ar2[j];
    }  
    getMedian(ar1, ar2, i);
	getch();
}
