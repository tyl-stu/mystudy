#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
#include<string.h>

int main()
{
	char *p = "123 56";
	printf("%d  %f ", atoi(p), (float)atoi(p));

	system("pause");
	return 0;
}

//int main()
//{
//	// ftell()֮ʵ��
//	//FILE * pFile;
//	//long size;
//	//pFile = fopen("myfile.txt", "rb");
//	//if (pFile == NULL) perror("Error opening file");
//	//else
//	//{
//	//	fseek(pFile, 0, SEEK_END); // non-portable
//	//	size = ftell(pFile);
//	//	fclose(pFile);
//	//	printf("Size of myfile.txt: %ld bytes.\n", size);
//	//}
//
//	//// rewind() ֮ʵ��
//	//int n;
//	//FILE * pFile;
//	//char buffer[27];
//	//pFile = fopen("myfile.txt", "w+");
//	//for (n = 'A'; n <= 'Z'; n++)
//	//	fputc(n, pFile);
//	//rewind(pFile);
//	//fread(buffer, 1, 26, pFile);
//	//fclose(pFile);
//	//buffer[26] = '\0';
//	//puts(buffer);
//
//	////fseek() ֮ʵ��
//	//FILE * pFile;
//	//pFile = fopen("example.txt", "wb");
//	//fputs("This is an apple.", pFile);
//	//fseek(pFile, 9, SEEK_SET);
//	//fputs(" sam", pFile);
//	//fclose(pFile);
//
//	////���ļ�
//	//pFile = fopen("myfile.txt", "w");
//	////�ж��ļ��Ƿ�Ϊ��
//	//if (NULL == pFile)
//	//{
//	//	printf("open file error.\n");
//	//	return;
//	//}
//	////���ļ�����������
//	//for (int i = 0; i < 50; i++)
//	//{
//	//	fprintf(pFile, "%d\n", i);
//	//}
//	////�ر��ļ�
//	//fclose(pFile);
//
//	//pFile = fopen("myfile.txt", "r");
//	////�ж��ļ��Ƿ�Ϊ��
//	//if (NULL == pFile)
//	//{
//	//	printf("open file error.\n");
//	//	return;
//	//}
//	//int a[50];
//	////���ļ�����������
//	//for (int i = 0; i < 50; i++)
//	//{
//	//	fscanf(pFile, "%d", &a[i]);
//	//}
//	////�ر��ļ�
//	//fclose(pFile);
//	//for (int i = 0; i < 20; i++)
//	//{
//	//	printf("%d ", a[i]);
//	//}
//
//	system("pause");
//	return 0;
//}

// ��ά����Ŀռ俪��
//#define ROW 5
//#define COL 5
//
//int main()
//{
//	////��ά����Ŀ��٣���Щ���⣬����Ӱ������ֵ�����
//	//int **par = (int *)malloc(sizeof(int) * ROW);
//	//for (int i = 0; i < COL; i++)
//	//{
//	//	*(par + i) = (int *)malloc(sizeof(int)*COL);
//	//}
//	//for (int i = 0; i < ROW; i++)
//	//{
//	//	for (int j = 0; j < COL; j++)
//	//	{
//	//		*(*(par + i) + j) = i;
//	//	}
//	//}
//	//for (int i = 0; i < ROW; i++)
//	//{
//	//	for (int j = 0; j < COL; j++)
//	//	{
//	//		printf("%d ", *(*(par + i) + j));
//	//	}
//	//	printf("\n");
//	//}
//	//for (int i = 0; i < COL; i++)
//	//{
//	//	free(par[i]);
//	//}
//	//free(par);
//	//**********************************************************************************
//	// ��ά����Ŀ��ٵ�ַ��true��
//	//int **par = (int **)malloc(sizeof(int *)*ROW);
//	//if (par == NULL)
//	//	return;
//	//for (int i = 0; i < ROW; i++)
//	//{
//	//	par[i] = (int *)malloc(sizeof(int)*COL);
//
//	//}
//	//for (int i = 0; i < ROW; i++)
//	//{
//	//	for (int j = 0; j < COL; j++)
//	//	{
//	//		//*(*(par + i) + j) = i;
//	//		par[i][j] = i;
//	//	}
//	//}
//	//for (int i = 0; i < ROW; i++)
//	//{
//	//	for (int j = 0; j < COL; j++)
//	//	{
//	//		printf("%d ", *(*(par + i) + j));
//	//	}
//	//	printf("\n");
//	//}
//	//for (int i = 0; i < ROW; i++)
//	//{
//	//	free(par[i]);
//	//}
//	//free(par);
//	system("pause");
//	return 0;
//}
//**************************************************************************
//��������֮��֤
//typedef struct Test
//{
//	int a[0];
//}Test;
//int main()
//{
//	Test t;
//	printf("%d ", sizeof(t));
//
//	system("pause");
//	return 0;
//}
//*****************************************************************************
//����ϰ��֮Щ����֤
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//}
//********************************************************************************************************
//p�ռ�ĸ��Ķ�str��Ӱ��,����str��ȻΪ�գ���p��Ϊ��,����ʵ�ֹ��ܣ����ö���ָ�룡���������
//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//******************************************************
//char * GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//	strcpy(p, "hello world");
//	printf(p);
//	return p;
//}
//void Test(void)
//{
//	char *str = NULL;
//	char *t = GetMemory(str);
//	//strcpy(str, "hello world");
//	printf(t);
//}
//***************************************************
//�˴��ǵ�ַ����!����������������������GetMemory()�ǽ�p�ַ������׵�ַ������
//��p�Ŀռ�Ϊ��ʱ�ռ䣬���ù�GetMemory()֮��ͻᱻ�ͷţ�����ָ��p�Ŀռ�Ϊ��
//����Ϊ��static char p[] = "hello world"; �󣬱㲻�������������
//char *GetMemory(void)
//{
//	static char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//*******************************************************************
//�ͷſռ��str�ͱ�Ϊ��Ұָ�룬������ã����Ƚ����ÿգ���һ�������Ҫ��� str = NULL ���
//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//void main()
//{
//	Test();
//	system("pause");
//}
//*****************************************************************************************************************
////realloc malloc free ֮ʵ��
//int main()
//{
//	int *ptr = (int *)malloc(sizeof(int) * 5);
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			ptr[i] = i;
//		}
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		/*printf("%d ", *(ptr + i));*/
//		printf("%d ", ptr[i]);
//	}printf("\n");
//
//	/*int*p = NULL;
//	p = realloc(ptr, 1000);*/
//	int *p = (int *)realloc(ptr, sizeof(int) * 100);
//	for (int i = 0; i<10; i++)
//	{
//		/*printf("%d ", *(ptr + i));*/
//		printf("%d ", p[i]);
//	}
//	//ҵ����
//	free(p);
//
//	system("pause");
//	return 0;
//}
//***************************************************************
//  malloc  free ֮ʵ��
//int main()
//{
//	//����1
//	int num = 0;
//	printf("input num:>");
//	scanf("%d", &num);
//	//int arr[num] = { 0 };  //����
//	//����2
//	int* ptr = NULL;
//	ptr = (int *)malloc( num * sizeof(int));
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i<num; i++)
//		{
//			//���ַ����Կɸ�ptrָ��Ŀռ丳ֵ
//			//*(ptr + i) = i;
//			ptr[i] = i;
//		}
//	}
//	for (int i = 0; i<num; i++)
//	{
//		/*printf("%d ", *(ptr + i));*/
//		printf("%d ", ptr[i]);
//	}
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�Ƿ��б�Ҫ��
//
//	system("pause");
//	return 0;
//}