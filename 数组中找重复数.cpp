//来自于：数组中重复的数字(剑指offer)+时间复杂度O（n）空间复杂度O（1）的想法
//http://blog.csdn.net/u010579068/article/details/49514745

#include <stdio.h>
#include<algorithm>

using namespace std;

//solution 1
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

//solution 2 哈希表
bool dulplicate(int num[], int len, int *dul)
{
	if(len <= 1)	return false;

	int hash[100] = {0};
	for(int i = 0; i < len; i++)
	{
		hash[num[i]]++;
		if(hash[num[i]] > 1)//如果出现的次数大于1则返回
		{
			*dul = num[i];
			return true;
		}
	}
}

//solution 3 排序以后检查
bool dulplicate(int num[], int len, int *dul)
{
	if(len <= 1)	return false;

	for(int i=0; i<len; i++)
	{
		if(num[i]<0 || num[i]>len)	return false;

		sort(num, num + len);
		for(int i = 0; i < len-1; i++)
		{
			if(num[i] == num[i+1])
			{
				*dul = num[i];
				return true;
			}
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