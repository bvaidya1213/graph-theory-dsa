#include<iostream>
#include<conio.h>
using namespace std;
int first(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high) / 2;  
    if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
      return mid;
    else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
    else
      return first(arr, low, (mid -1), x, n);
  }
  return -1;
}
int last(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
      return mid;
    else if(x < arr[mid])
      return last(arr, low, (mid -1), x, n);
    else
      return last(arr, (mid + 1), high, x, n);      
  }
  return -1;
}
int count(int arr[], int x, int n)
{
  int i;
  int j;
  i = first(arr, 0, n-1, x, n);
  if(i == -1)
    return i;  
  j = last(arr, i, n-1, x, n);     
  return j-i+1;
}
int main()
{
  int n, i, x, arr[10];
  cout<<"enter the number of elements\n";
  cin>>n;
  for (i = 0; i < n; i++)
  {
      cout<<"enter element\n";
      cin>>arr[i];
  }
  cout<<"enter the element whose number of occurences to be found\n";
  cin>>x;
  int c = count(arr, x, n);
  cout<<x<<" occurs "<<c<<" times "<<endl;
  getch();
}
