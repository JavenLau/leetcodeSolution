//来自于：数组中重复的数字(剑指offer)+时间复杂度O（n）空间复杂度O（1）的想法

#include <stdio.h>
#include<algorithm> 

using namespace std;

bool dulplicate(int num[], int len, int *dul)
{
	if(len <= 1)	return false;
	
	for(int i=0; i<len; i++)
	{
		if(num[i]<0 || num[i]>len)	return false;
		while(num[i] != i)
		{
			if(num[i] == num[num[i]] )
			{
				*dul = num[i];
				return true;
			}
			swap(num[i], num[num[i]]);
		}
	}
}

int main()
{
	int a[] = {2,4,6,1,2,5,3};
	int *dul;
	dulplicate(a, 7, dul);
	printf("%d\n", *dul);
}