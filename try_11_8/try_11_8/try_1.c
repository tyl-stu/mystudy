#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 10;
	///scanf("%d", &n);
	//printf("%d\n", n);

	////动态开辟空间 malloc,释放用 free
	//int *p = (int *)malloc(sizeof(int)*n);
	//for (int i = 0; i < n; i++)
	//{
	//	p[i] = i;
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d\n", p[i]);
	//}
	//free(p);

	char ar[100] = { 0 };
	
	scanf("%s", &ar);
	printf("%s ", ar);

	system("pause");
	return 0;
}