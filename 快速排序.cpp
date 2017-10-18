#include <iostream>

using namespace std;


void swap(int a[], int low, int high)
{
	int temp;
	temp = a[low];
	a[low] = a[high];
	a[high] = temp;
}

int findmid(int L[], int low, int high)
{
	int mid = L[low];
	while(low < high)
	{
		while(low<high && L[high]>=mid)
			high--;
		swap(L, low, high);

		while(low<high && L[low]<=mid)
			low++;
		swap(L, low, high);		
	}
	return low;	
}

void qqsort(int L[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = findmid(L, low, high);
	
		qqsort(L, low, mid-1);
		qqsort(L，mid+1, high);
	}
}

int main()
{
	int L[] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
	qqsort(L, 1, 9);
	for(int i = 0; i< 9; i++)
	{
		cout << L[i] << endl;
	}
}

