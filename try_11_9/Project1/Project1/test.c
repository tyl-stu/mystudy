#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 2;
	int *p = a;
	int *q = &a;
	int *g;
	g = a;
	printf("*p = %d\n", *p);
	printf("*q = %d\n", *q);
	printf("*g = %d\n", g);

	system("pause");
	return 0;
}