#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct BTreeNode
{
	int *data;
	BTreeNode **child_ptr;
	bool leaf;
	int n;
}*root = NULL, *np = NULL, *x = NULL;
BTreeNode * init(int t)
{
	int i;
	np = new BTreeNode;
	np->data = new int[t - 1];
	np->child_ptr = new BTreeNode *[t];
	np->leaf = true;
	np->n = 0;
	for (i = 0; i < t; i++)
	{
		np->child_ptr[i] = NULL;
	}
	return np;
}
void traverse(BTreeNode *p)
{
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
		{
			traverse(p->child_ptr[i]);
		}
        cout << " " << p->data[i];
    } 
	if (p->leaf == false)
    {
		traverse(p->child_ptr[i]);
	}
	cout<<endl;
}
void sort(int *p, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
int split_child(BTreeNode *x, int i, int t)
{
	int j, mid;
	BTreeNode *np1, *np3, *y;
	np1 = init(t);
	if (i == -1)
	{
		mid = x->data[t / 2];
		np3 = init(t);
		np3->leaf = false;
		x->leaf = false;
		for (j = (t / 2 + 1); j < (t - 1); j++)
		{
			np3->data[j - (t / 2 + 1)] = x->data[j];
			np3->child_ptr[j - (t / 2 + 1)] = x->child_ptr[j];
			np3->n++;
			x->data[j] = 0;
			x->child_ptr[j] = NULL;
			x->n--;
		}
		np1->data[0] = mid;
		np1->child_ptr[np1->n] = x;
		np1->child_ptr[np1->n + 1] = np3;
		np1->n++;
		root = np1;
	}
	else
	{
		y = x->child_ptr[i];
		mid = y->data[t / 2];
		for (j = (t / 2 + 1); j < (t - 1); j++)
		{
			np1->data[j - (t / 2 + 1)] = y->data[j];
			np1->n++;
			y->data[j] = 0;
			y->n--;
		}
		x->child_ptr[i + 1] = np1; 
	}
	return mid;
}
void insert(int a, int t)
{
	int i, temp;
	x = root;
	if (x == NULL)
	{
		root = init(t);
		x = root;
	}
	else
	{
		if (x->leaf == true && x->n == (t - 1))
		{
			temp = split_child(x, -1, t);
			x = root;
		}
		else
		{
			while (x->leaf == false)
			{
				for (i = 0; i <= (x->n); i++)
				{
					if ((a > x->data[i]) && (a < x->data[i + 1]))
					{
						i++;
						break;
					}
					else if (a < x->data[i])
					{
						break;
					}
				}
				if ((x->child_ptr[i])->n == (t - 1))
				{
					temp = split_child(x, i, t);
					x->data[x->n] = temp;
					x->n++;
					continue;
				}
				else
				{
					x = x->child_ptr[i];
				}
			}
		}
	}
	x->data[x->n] = a;
	sort(x->data, x->n);
	x->n++;
}
int main()
{
    int i, n, t;
    cout<<"enter the no of elements to be inserted\n";
    cin>>n;
    for(i = 0; i < n; i++)
    {
          cout<<"enter the element\n";
          cin>>t;
          insert(t, 6);
          traverse(root);
    }
	cout<<"traversal of constructed tree\n";
	//traverse(root);
	getch();
}
