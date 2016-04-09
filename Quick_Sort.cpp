#include <iostream>
#include <math.h>
using namespace std;
//快速排序
void QuickSort(int A[],int p,int r)
{
	if (p>=r)
		return ;
	int x=A[r];
	int i=p-1;
	int temp;
	for (int j=p;j<r;j++)
	{
		if (A[j]<=x)
		{
			i++;
			temp = A[i];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	i++;
	A[r] = A[i];
	A[i] = x;
	QuickSort(A,p,i-1);
	QuickSort(A,i+1,r);
}
//计数排序
void Counting_Sort(int A[],int B[],int n,int k,int order)
{
	int* C = new int[k+1];
	int* remaind = new int[n];
	int value = pow(10,order);
	for (int i=0;i<=k;i++)
		C[i] = 0;
	for (int i=0;i<n;i++)
	{
		remaind[i] = (A[i]/value)%10;
		C[remaind[i]]++;
	}
	for (int i=1;i<=k;i++)
		C[i] = C[i]+C[i-1];
	for (int j=n-1;j>=0;j--)
	{
		B[C[remaind[j]]-1] = A[j];
		C[remaind[j]]--;
	}
	for (int j=0;j<n;j++)
		cout << B[j] << endl;
}
//基数排序
void Radix_Sort(int A[],int n,int d)
{
	int** B=new int*[d];
	for (int i=0;i<d;i++)
	{
		B[i] = new int[n];
	}
	for (int i=0;i<d;i++)
	{
		Counting_Sort(A,B[i],n,9,i);
		for (int j=0;j<n;j++)
			A[j] = B[i][j];
	}
}
int main()
{
	int st[10]={12,10,20,30,23,50,90,80,60,42};
	int st1[10];
	//QuickSort(st,0,9);
	Radix_Sort(st,10,2);
	return 0;
}