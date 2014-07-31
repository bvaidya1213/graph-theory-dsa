#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
    int sum = 0,ret = 0,n;
    cout<<"enter the number of values\n";
    cin>>n;
    int a[n];
	cout<<"enter values of array\n";
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
    for (int i = 0; i < n; i++)
	{
		sum = sum + a[i];
		if (ret < sum)
		{
			ret = sum;
		}
		if (sum < 0)
		{
			sum = 0;
		}
	}
	cout<<"Minimum subarray sum:"<<ret;
	getch();
}
