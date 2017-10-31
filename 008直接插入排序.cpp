#include <iostream>

using namespace std;

void printmat(int *a, int len)
{
	for(int i = 0; i<len; i++)
		cout << i << endl;	
}

void swap(int a[], int low, int high)
{
	int temp;
	temp = a[low];
	a[low] = a[high];
	a[high] = temp;
}

void bubblesort(int *a, int len)
{
	for(int i = 0; i< len; i++)
	{
		for(int j = len-1; j<=i; j--)
		{
			if(a[j]>a[j+1])
			{
				swap(a,j,j+1);
			}			
		}
	}
	printmat(a, len);
}

int main()
{
	int a[] = {9,1,5,8,3,7,4,6,2};
	bubblesort(a, 9);
}