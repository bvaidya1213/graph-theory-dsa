#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	int lowindex,lowkey,temp,n;
	cout<<"enter the number of values\n";
    cin>>n;
    int a[n];
	cout<<"enter values of array\n";
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i <= n - 1; i++)
	{
		lowindex = i;
		lowkey = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < lowkey)
			{
				lowkey = a[j];
				lowindex = j;
			}
		}
		temp = a[i];
		a[i] = a[lowindex];
		a[lowindex] = temp;
	}
	cout<<"After sorting\n";
    for (int k = 0; k < n; k++)
    {
		cout<<a[k]<<endl;
    }	
	getch();
}
		
