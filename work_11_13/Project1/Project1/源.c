#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 2;
	int *p = a;
	int *q = &a;
	char *c = "abcd";
	printf("%d : \n", p);
	printf("%d : %p\n", *q, q);
	printf("%c : %p\n", *c, c);
	system("pause");
	return 0;
}

//��һ�������е���������ǰ��ż�����ں�
//void  swap(int *a,int len)
//{
//	int *left = a;
//	int *right = (a + len - 1);
//	while (left < right)
//	{
//		//��ǰ������ż��
//		while ((left < right) && (*left % 2 != 0))
//		{
//			left++;
//		}
//		//�Ӻ���ǰ������
//		while ((left < right) && (*right % 2 == 0))
//		{
//			right--;
//		}
//		//��ǰ��λ����ż����λ�ã�ǰ��Ϊ�棬���Ϊż
//		if (left < right)
//		{
//			int t = *left;
//			*left = *right;
//			*right = t;
//		}
//	}
//
//}
//void swap1(int arr[], int n)
//{
//	int ou[50] = { 0 },ji[50] = { 0 }, all[50] = { 0 };
//	static int j1 = 0, j2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			ou[j1] = arr[i];
//			j1++;
//		}
//		else
//		{
//			ji[j2] = arr[i];
//			j2++;
//		}
//	}
//	for (int i = 0; i < j2; i++)
//	{
//		printf("%d ", ji[i]);
//		all[i] = ji[i];
//	}printf("\n");
//	for (int i = 0; i < j1; i++)
//	{
//		printf("%d ", ou[i]);
//		all[j2 + i] = ou[i];
//	}printf("\n");
//	
//	for (int i = 0; i < j1 + j2; i++)
//	{
//		printf("%d ", all[i]);
//	}printf("\n");
//
//}
//int main()
//{
//	int arr[8] = { 0 };//
//	printf("�������飺>");
//	for (int i = 0; i < 8;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//	int l = sizeof(arr) / sizeof(arr[0]);
//	swap(arr, 8);
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//	system("pause");
//	return 0;
//}
//***********************************************************************************************
//************************************************************************************************
//�����Զ��庯����������֮����ϰ
//int *www(int *a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *(a+i));
//	}printf("\n");
//	return a;//������������׵�ַ������Ҫ�� *a
//}
//int *vvv(int n)
//{
//	int *m = &n;
//	printf("%d ", m);
//	return m;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int *brr = www(arr, 5);  //�˴��� brr �൱�ڸ�ֵ �˺����з�������ĵ�ַ
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *(brr+i));
//	}
//	
//	printf("\n");
//	system("pause");
//	return 0;
//}
//***********************************************************************************************
//************************************************************************************************
//ģ�� strcpy()
//strcpy(a,b)��b�е��ַ������Ƹ�a
//void strcpy1(char *a, char *b)
//{
//	int  i = 0;
//	while (*(b + i) != '\0')
//	{
//		*(a + i) = *(b + i);
//		i++;
//	}
//	*(a + i ) = '\0';
//}
//int main()
//{
//		
//	printf("���� a �ַ�����>");
//	char *arr = (char *)malloc(50);
//	scanf("%s", arr);
//	printf("%s \n", arr);
//	printf("���� b �ַ�����>");
//	char *brr = (char *)malloc(50);
//	scanf("%s", brr);
//	printf("%s \n", brr);
//	strcpy1(arr, brr);
//	printf("strcpy(a,b) = %s\n", arr);
//	free(arr);
//	free(brr);
//	system("pause");
//	return 0;
//}
//****************************************************************
//ģ��strlen()
//int strlen1(char *p)
//{
//	int i = 0;
//	int count = 0;
//	while (*(p++) != '\0')
//	{
//		count++;
//		//i++;
//	}
//	return count;
//}
//int main()
//{
//	printf("����һ���ַ�����>");
//	char arr[50] = { 0 };
//	scanf("%s", arr);
//	printf("%s \n", arr);
//	int count = strlen1(arr);
//	printf("�ַ�������: %d\n", count);
//	system("pause");
//	return 0;
//}
//*******************************************************8
//������ѭ������
//�������ɼ� bite 11��13�յ���ҵ
//int main()
//{
//	//�˳�������������  1��Խ��(��Ϊ����ֻ��10λ����ѭ����12�Σ����Ի�Խ��)  2����ѭ��
//	//��ѭ������Ϊ  ���i�ĵ�ַ��arr[9]�ĵ�ַ��8���ֽڣ���2�����α���
//	//��ѭ������12��ʱ��arr[12]=0�Ὣi��ֵ��Ϊ0���Ӷ�������ѭ��
//
//	int j = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (int i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello bit\n");
//	}
//	system("pause");
//	return 0;
//}
//**********************************************************************************
//����ˮ���� --- ������ɼ�Ϊ�Ȳ����У��� 2*n-1
//int sum(int n)
//{
//	int ret = n;
//	int t = 0;
//	while (n)
//	{
//		if (n % 2 != 0)
//		{
//			t++;
//		}
//		if (t > 1 && t % 2 == 0)
//		{
//			ret = ret + 1;
//		}
//		n = n / 2;
//		ret = ret + n;
//	}
//	
//	return ret;
//}
//int main()
//{
//	printf("����Ǯ����>");
//	int r;
//	scanf("%d", &r);
//	int ret = sum(r);
//	printf("������ˮ�ĸ���Ϊ��%d \n", ret);
//	system("pause");
//	return 0;
//}