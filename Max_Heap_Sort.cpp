#include <iostream>
#define HEAP_SIZE 11
using namespace std;
int length;
void Max_Heap(int A[],int i)
{
	int largest,temp;
	int left_i = 2*i;
	int right_i = 2*i+1;
	if (left_i<=length && A[left_i]>A[i])
		largest = left_i;
	else
		largest = i;
	if(right_i<=length && A[right_i]>A[largest])
		largest = right_i;
	if (largest != i)
	{
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		Max_Heap(A,largest);
	}	
}
void Build_Max_Heap(int a[],int n)
{
	for (int i = n/2;i>0;i--)
		Max_Heap(a,i);
}
/*
int main()
{
	int n;
	while (cin >> n)
	{
		length = n-1;
		int value;
		int counting = 0;
		int* st = new int[n];
		for (int i=0;i<n;i++)
		{
			if (i==0)
				cin >> value;
			else
				cin >> st[i];
		}
		Build_Max_Heap(st,length);
		while (value<=st[1])
		{
			value++;
			st[1]--;
			counting++;
			Max_Heap(st,1);
		}
		cout << counting <<endl;
	}
	return 0;
}*/
int main()
{
	int temp;
	int st[HEAP_SIZE] = {-1,4,1,3,2,16,9,10,14,8,7};
	length=HEAP_SIZE-1;
	Build_Max_Heap(st,length);
	for (;length>1;length--)
	{
		Max_Heap(st,1);
		temp = st[length];
		st[length] = st[1];
		st[1] = temp;
	}
	for (int j =1;j<HEAP_SIZE;j++)
	{
		cout << st[j] << " ";
	}
	return 0;
}