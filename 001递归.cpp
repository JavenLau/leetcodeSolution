#include <iostream>
using namespace std;

int max(int a[], int n)
{
  int temp;
  if(n == 1)
	  temp = a[0];
  else
	  temp = max(a, n-1)>a[n-1] ? max(a, n-1): a[n-1];
  return temp;
}

int fac(int n)
{
	int temp;
	if(n == 1 || n == 0)
		temp = 1;
	else
		temp = fac(n-1) * n;
	return temp;
}

void main()
{
	int a[5] = {2, 7, 8, 5, 1};
	cout<< max(a, 5) << endl;
	cout<< fac(4) << endl;
}
