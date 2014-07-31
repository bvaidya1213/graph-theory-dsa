#include<stdio.h>
#include<conio.h> 
#include<iostream>
using namespace std;
/* Function to swap values at two pointers */
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(int *a, int b[][4], int i, int n) 
{
   int j, k; 
   if (i == n)
   {
      for (k = 0; k <= n; k++)
      {
         b[i][k] = a[k];
      }
      b[i][k] = b[i][0];
   }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, b, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 
 
/* Driver program to test above functions */
int main()
{
    int i, j;
   int a[] = {0,1,2};
   int b[6][4];  
   permute(a, b, 0, 2);
   for (i = 0; i < 6; i++)
   {
       cout<<endl;
       for (j = 0; j < 4; j++)
       {
           cout<<b[i][j]<<"\t";
       }
   }
   getch();
}
