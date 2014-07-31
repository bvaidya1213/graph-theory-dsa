#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void disp(float a[][6])
{
    int i, j;
    for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 6; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}
void getInverse(float a[][6])
{
	int i, j,k;
	for(j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (j != i)
			{
				for (k = 0; k < 6; k++)
				{
					a[i][k] = a[i][k] - ((a[i][j] / a[j][j]) * a[j][k]);
				}
			}
			else
			{
				for (k = 0; k < 6; k++)
				{
					a[i][k] = a[i][k] / a[i][j];
				}
			}
		}
		disp(a);
	}
} 
int main()
{
	float a[3][6];
    int i, j, k;
	cout<<"enter the 3 x 3 matrix whose inverse is to be computed\n";
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin>>a[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (j == (i + 3))
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}
	disp(a);
	for (k = 0; k < 6; k++)
	{
	    cout<<a[0][k]<<endl;
	}
	disp(a);
	/*getInverse(a);
	cout<<"inverse matrix\n";
	for (i = 0; i < 3; i++)
	{
		for (j = 3; j < 6; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}*/
	getch();
}
