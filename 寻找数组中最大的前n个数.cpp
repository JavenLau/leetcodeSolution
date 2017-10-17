//寻找数组中最大的前n个数
//参考：编写一个函数返回数组中第三个最大数的下标，复杂度O(n)；
//编写一个函数返回数组中第三个最大数的下标。我最先想到的就是先排序，再取第三个最大数，最后将取得的第三个最大数再在原数组中遍历获取下标，然而这样的效率并不高。最后经面试官点拨了下，想到“排挤”的思想，即默认已有三个排序好的最大数 a[k] < a[m] < a[n]，再在数组中遍历与这三个数做比较，满足条件则交换相应的下标，挤出原数据，永远保证这三个数在已遍历的数中最大，最后再返回下标 k 。这样做时间复杂度只有 O(n)
#include <iostream>

using namespace std;

int main()
{
	int findtopn(int *, int);

	int a[] = {0,1,11,9,15,5,13,7,1,10};
	int k = findtopn(a, 10);
	//cout << k << endl;
}

//
int findtopn(int *a, int len)
{
	int k = 0;
	int m = 1;
	int n = 2;
	for(int i=0; i<len ; i++)
	{
		// 先判断a[i]是否大于第三个最大数
		if (a[i] >= a[k])
		{
			// 在判断a[i]是否大于第二个最大数
			if (a[i] >= a[m])
			{
				// 最后判断a[i]是否大于第一个最大数
				if (a[i] >= a[n])
				{
					// 交换相应的下标
					k = m; // 当满足第一个最大数时不要忘记先交换后两个最大数的坐标
					m = n;
					n = i;
				}
				else
				{
					k = m;
					m = i;
				}
			}
			else
			{
				k = i;
			}
		}
	}
	cout << k << endl << m << endl << n << endl;
	return k;
}


// public class Test1
// {
	// /*
	 // * 利用“排挤”的思想
	 // */
	// public static int findThirdM(int a[])
	// {
		// int b[];
		// int k = 0;
		// int m = 1;
		// int n = 2;
		// for(int i=0; i<a.length ; i++)
		// {
			// // 先判断a[i]是否大于第三个最大数
			// if (a[i] >= a[k])
			// {
				// // 在判断a[i]是否大于第二个最大数
				// if (a[i] >= a[m])
				// {
					// // 最后判断a[i]是否大于第一个最大数
					// if (a[i] >= a[n])
					// {
						// // 交换相应的下标
						// k = m; // 当满足第一个最大数时不要忘记先交换后两个最大数的坐标
						// m = n;
						// n = i;
					// }
					// else
					// {
						// k = m;
						// m = i;
					// }
				// }
				// else
				// {
					// k = i;
				// }
			// }
		// }
		// return k;
	// }
	// /*
	// * 先排序，再取下标的方法，复杂度大于O(n)
	// */
	// public static int findByBubble(int[] a)
	// {
		// // 先将数组存储在另一个数组中
		// int[] b = new int[a.length];
		// for (int i = 0; i < a.length; i++)
		// {
			// b[i] = a[i];
		// }
		// //利用冒泡排序找出最大的三个数，从大到下排序，
		// for (int i = 0; i < 3; i++)
		// {
			// for (int j = 0; j < a.length-1; j++)
			// {
				// if (a[j] < a[j+1])
				// {
					// a[j] = a[j+1];
				// }
			// }
		// }
		// //经上步骤获得的第三个最大数a[2]，再数组b中遍历取下标
		// for (int i = 0; i < b.length; i++)
		// {
			// if (a[2] == b[i])
			// {
				// return i;
			// }
		// }
		// return 0;
	// }

	// public static void main(String[] args)
	// {
		// int[] arr = {0,1,11,9,10,5,13,7,1,15};
		// System.out.println("第三个最大数的下标为："+findThirdM(arr));
		// System.out.println(findByBubble(arr));
	// }
// }
