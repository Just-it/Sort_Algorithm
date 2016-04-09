#include <iostream>
#define N 21
using namespace std;
int main()
{
	int* ary = new int[N];
	for (int i=1;i<N;i++)
	{
		ary[i] = rand()%100;
		cout << ary[i]<<" ";
	}
	cout << endl;
	/*ֱ�Ӳ�������
	int i,j;
	for (i=2;i<N;i++)
	{
		if (ary[i]<ary[i-1])
		{
			ary[0] = ary[i];
			for (j=i-1;ary[0]<ary[j]&&j>0;j--)
			{
				ary[j+1] = ary[j];
			}
			ary[j+1] = ary[0];
		}
	}*/
	//�����۰���ҸĽ���������
	for (int i=2;i<N;i++)
	{
		if (ary[i]<ary[i-1])
		{
			ary[0] = ary[i];
			int low = 1;
			int high = i-1;
			while (low<=high)
			{
				int mid = (low+high)/2;
				if (ary[mid] > ary[0])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j=i-1;j>high;j--)
			{
				ary[j+1] = ary[j];
			}
			ary[high+1] = ary[0];
		}
	}
	for (int i=1;i<N;i++)
	{
		cout << ary[i]<<" ";
	}
	cout << endl;
	return 0;
}