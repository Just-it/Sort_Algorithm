#include <iostream>
#define  SIZE 15
using namespace std;
struct bucket
{
	double value;
	struct bucket* next;
};
void Bucket_Sort(double* A,int n,int length)
{
	struct bucket* B = new struct bucket[n];
	for (int i=0;i<n;i++)
	{
		B[i].value = 0;
		B[i].next = NULL;
	}
	for (int i=0;i<length;i++)
	{
		int pos=(int)(A[i]*n);
		B[pos].value++;
		struct bucket* node = new struct bucket;
		node->value = A[i];
		node->next = NULL;
		struct bucket* p=B+pos;
		struct bucket* p1=B[pos].next;
		while (p1)
		{
			if (node->value < p1->value)
			{
				p->next = node;
				node->next = p1;
				break;
			}
			p = p1;
			p1 = p1->next;
		}
		if (p1==NULL)
			p->next = node;
	}
	int counting = 0;
	for (int i=0;i<n;i++)
	{
		if (B[i].value>0)
		{
			struct bucket* p=B[i].next;
			while (p)
			{
				A[counting++] = p->value;
				p = p->next;
			}
		}
	}
	return ;
}
int main()
{
	double arr[SIZE]={0.79,0.13,0.16,0.64,0.39,0.20,0.89,0.53,0.71,0.42,0.56,0.18,0.99,0.05,0.49};
	Bucket_Sort(arr,10,SIZE);
	for (int i=0;i<SIZE;i++)
	{
		cout << arr[i] <<endl;
	}
	return 0;
}