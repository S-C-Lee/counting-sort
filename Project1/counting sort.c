#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define size 10000
int a[size];
swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		a[m]++;
	}
	for (int i = 0; i < size-1; i++)
	{
		if (a[i] > 0)
		{
			printf("%d ", i);
			a[i]--;
		}
	}
}