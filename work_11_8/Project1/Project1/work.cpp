#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<stdio.h>
#include<stdlib.h>

//�������������ֵ
//void print(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int a[5] = { 0, 0, 0, 0, 0 };
//	int b[5] = { 1, 2, 3, 4, 5 };
//	
//	int n1 = sizeof(a) / sizeof(a[0]);
//	int n2 = sizeof(b) / sizeof(b[0]);
//	print(a, n1);
//	print(b, n2);
//	if (n1 == n2)
//	{
//		for (int i = 0; i < n1; i++)
//		{
//			int t = a[i];
//			a[i] = b[i];
//			b[i] = t;
//		}
//	}
//	print(a, n1);
//	print(b, n2);
//	system("pause");
//	return 0;
//}
//************************************************************
////��������
//void init(int a[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = 0;
//	}
//}
//void scanf_arr(int a[], int n)
//{
//	printf("������:>");
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//}
//void print(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//void reverse1(int a[], int n)
//{
//	for (int i = 0; i < n / 2; i++)
//	{
//		int t = a[i];
//		a[i] = a[n - i- 1];
//		a[n- i - 1] = t;
//	}
//}
//
//
//int main()
//{
//	int n;
//	printf("�����������Ԫ����:>");
//	scanf("%d", &n);
//	int *arr = (int *)malloc(n);
//	init(arr,n);//�����ʼ��
//	scanf_arr(arr, n);//�޸������ֵ
//	reverse1(arr,n);//��������
//	print(arr, n);//�����ӡ
//
//	system("pause");
//	return 0;
//}
//*******************************************
//ð������
//void order(int a[],int n)
//{
//	for (int j = 0; j<n; j++)
//	{
//		for (int i = j; i<n; i++)
//		{
//			if (a[j]>a[i])//��С����
//			{
//				int t = a[j];
//				a[j] = a[i];
//				a[i] = t;
//			}
//		}
//		
//	}
//	
//}
//
//int main()
//{
//	printf("����һ�����ĸ�����>");
//	int n;
//	scanf("%d", &n);
//	int *arr=(int *)malloc(n);
//	printf("������:>");
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	
//	order(arr,n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//free(arr);
//	system("pause");
//	return 0;
//}
//*****************************************************************
////�޵ݹ���쳲�������
//void nonum(int n)
//{
//	int *p = (int *)malloc(n);
//	if (n > 2)
//	{
//		*p = 1;
//		*(p + 1) = 1;
//		for (int i = 2; i < n; i++)
//		{
//			*(p + i) = *(p + i - 2) + *(p + i - 1);
//		}
//	}
//	else if (n == 2)
//	{
//		*(p + 1) = 1;
//	}
//	printf("%d\n", *(p + n - 1));
//	//free(p);
//}
//
////�еݹ���쳲�������
//int yanum(int n)
//{
//	if (n > 2)
//	{
//		return yanum(n - 1) + yanum(n - 2);
//
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	printf("������һ������>");
//	int n;
//	scanf("%d", &n);
//	nonum(n);
//	int s = yanum(n);
//	printf("s = %d\n", s);
//	system("pause");
//	return 0;
//}
//********************************************************************
////�õݹ�ʵ��n��k�η�
//int multi(int n, int k)
//{
//	if (k > 0)
//	{
//		return n*multi(n, --k);
//	}
//	else
//		return 1;
//	
//}
//
//int main()
//{
//	printf("���������>");
//	int n;
//	scanf("%d", &n);
//	printf("���������>");
//	int k;
//	scanf("%d", &k);
//	int x;
//
//	x = multi(n, k);
//	printf("x = %d\n", x);
//
//	system("pause");
//	return 0;
//}
//*****************************************************************
//��һ�����ֵĸ�λ���֮��
//int  DigitSum(int n)
//{
//	if (n != 0)
//	{
//		int a = n % 10;
//		int sum = a + DigitSum(n / 10);
//		return sum;
//	}
//	else
//		return 0;
//
//}
//
//int main()
//{
//	int n=0; int s;
//	printf("������һ���Ǹ�������>");
//	scanf("%d", &n);
//
//	s = DigitSum(n);
//	printf("sum = %d\n", s);
//	system("pause");
//	return 0;
//}
//************************************************************
////���ַ���ʵ���ַ�������
//void reverse_string_1(char * str)
//{
//	printf("%s\n", str);
//	int l = strlen(str);
//	//printf("l = %d\n", l);
//	char *left = str;
//	char *right = str + l - 1;
//	printf("left = %s\n", left);
//	printf("right = %s\n", right);
//	while (left < right)
//	{
//		char t;
//		t = *left;
//		*left = *right;
//		*right = t;
//		printf("left_swap = %s\n", left);
//		printf("right_swap = %s\n", right);
//		
//		left++;
//		right--;
//		printf("left_1 = %s\n", left);
//		printf("right_1 = %s\n", right);
//		
//	} 
//	//printf("�޵ݹ飺%s\n", str);
//	
//}
//
//void reverse_string(char * str) 
//{
//	int len = strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	
//	*(str + len - 1) = '\0';
//	if (strlen(str + 1) >= 2)
//		reverse_string(str + 1);
//
//	*(str + len - 1) = tmp;
//	
//	/*printf("�еݹ飺%s", str);*/
//	
//}
//
//void reverse_string_2(char *str)
//{
//	int len = strlen(str);
//	for (int i = 0; i < len / 2; i++)
//	{
//		//char a = *(str + len - i);
//
//		char t = *(str+i);
//		*(str + i) = *(str + len - i-1);
//		*(str + len - i-1) = t;
//		
//		/*printf("str = %s\n", str + i);
//		printf("str+len-i=%s\n", str+len-i-1);*/
//	}
//	//printf("%s\n", str);
//}
//int main()
//{
//	//char *p = malloc(100);
//	char p[100];
//	printf("������һ���ַ���:>");
//	scanf("%s",p);
//	//reverse_string_1(p);//�޵ݹ�  ��Щ�鷳
//	//reverse_string_2(p);//�޵ݹ�  ��
//	reverse_string(p);//�еݹ�
//	printf("���ú��ַ���Ϊ��%s", p);
//	system("pause");
//	return 0;
//} 
////*************************************************************************************
////�еݹ� �޵ݹ� ��ȡ�ַ�������
//int func_1(const char *c)
//{
//	if (*c == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + func_1(c + 1);
//	}
//}
//
//int func_2(const char *c)
//{
//	int i = 0;
//	while (*c != '\0')
//	{
//		i += 1;
//		c += 1;
//	}
//	return i;
//}
//
//int main()
//{
//	//char *p = "abcdefgh";
//	//char p[100];
//	char *p = malloc(100);
//	printf("������һ���ַ�����>");
//	scanf("%s", p);
//	printf("�ַ�����%s\n", p);
//	int v1,v2;
//	v1 = func_1(p);// �еݹ�
//	printf("�еݹ飺%s ���ַ�����Ϊ��%d\n",p, v1);
//	v2 = func_2(p);
//	printf("�޵ݹ飺%s ���ַ�����Ϊ��%d\n", p, v2);
//	free(p);
//	system("pause");
//	return 0;
//}
//********************************************************************
// �еݹ顢�޵ݹ� ��׳�
//int func_1(int m)
//{
//	if (m <= 1)
//		return 1;
//	else
//		return m*func_1(m - 1);
//}
//
//int func_2(int m)
//{
//	if (m <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		int j = 1;
//		for (int i = 1; i <= m; i++)
//		{
//			j *= i;
//		}
//		return j;
//	}
//}
//
//int main()
//{
//	int n,v1,v2;
//	printf("������һ������:>");
//	scanf("%d", &n);
//
//	v1 = func_1(n); //�еݹ�
//	printf("�ݹ� ��%d �Ľ׳�Ϊ %d\n", n,v1);
//	v2 = func_2(n); //�޵ݹ�
//	printf("�޵ݹ� ��%d �Ľ׳�Ϊ %d\n", n, v2);
//	system("pause");
//	return 0;
//}
// *********************************************************
////��ӡһ��������ÿһλ
//void func(unsigned int j)
//{
//	if (j / 10 != 0)
//	{
//		func(j / 10);
//	}
//	printf("%d\n", j % 10);
//}
//
//int main()
//{
//	unsigned int i;
//	printf("������һ��������>");
//	scanf("%d", &i);
//	func(i);
//	system("pause");
//	return 0;
//}