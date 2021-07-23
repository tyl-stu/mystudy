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
//	// ftell()之实现
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
//	//// rewind() 之实现
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
//	////fseek() 之实现
//	//FILE * pFile;
//	//pFile = fopen("example.txt", "wb");
//	//fputs("This is an apple.", pFile);
//	//fseek(pFile, 9, SEEK_SET);
//	//fputs(" sam", pFile);
//	//fclose(pFile);
//
//	////打开文件
//	//pFile = fopen("myfile.txt", "w");
//	////判断文件是否为空
//	//if (NULL == pFile)
//	//{
//	//	printf("open file error.\n");
//	//	return;
//	//}
//	////往文件中输入内容
//	//for (int i = 0; i < 50; i++)
//	//{
//	//	fprintf(pFile, "%d\n", i);
//	//}
//	////关闭文件
//	//fclose(pFile);
//
//	//pFile = fopen("myfile.txt", "r");
//	////判断文件是否为空
//	//if (NULL == pFile)
//	//{
//	//	printf("open file error.\n");
//	//	return;
//	//}
//	//int a[50];
//	////往文件中输入内容
//	//for (int i = 0; i < 50; i++)
//	//{
//	//	fscanf(pFile, "%d", &a[i]);
//	//}
//	////关闭文件
//	//fclose(pFile);
//	//for (int i = 0; i < 20; i++)
//	//{
//	//	printf("%d ", a[i]);
//	//}
//
//	system("pause");
//	return 0;
//}

// 二维数组的空间开辟
//#define ROW 5
//#define COL 5
//
//int main()
//{
//	////二维数组的开辟，有些问题，但不影响最终值的输出
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
//	// 二维数组的开辟地址（true）
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
//柔性数组之验证
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
//课上习题之些许验证
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
//p空间的更改对str无影响,所以str依然为空，但p不为空,若想实现功能，可用二级指针！如上面程序
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
//此处是地址传递!！！！！！！！！！！，GetMemory()是将p字符串的首地址给返回
//但p的空间为临时空间，调用过GetMemory()之后就会被释放，所以指向p的空间为空
//但改为：static char p[] = "hello world"; 后，便不会出现以上问题
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
//释放空间后，str就变为了野指针，若想调用，需先将其置空，即一般情况需要添加 str = NULL 语句
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
////realloc malloc free 之实现
//int main()
//{
//	int *ptr = (int *)malloc(sizeof(int) * 5);
//	if (NULL != ptr)//判断ptr指针是否为空
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
//	//业务处理
//	free(p);
//
//	system("pause");
//	return 0;
//}
//***************************************************************
//  malloc  free 之实践
//int main()
//{
//	//代码1
//	int num = 0;
//	printf("input num:>");
//	scanf("%d", &num);
//	//int arr[num] = { 0 };  //错误
//	//代码2
//	int* ptr = NULL;
//	ptr = (int *)malloc( num * sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i<num; i++)
//		{
//			//两种方法皆可给ptr指向的空间赋值
//			//*(ptr + i) = i;
//			ptr[i] = i;
//		}
//	}
//	for (int i = 0; i<num; i++)
//	{
//		/*printf("%d ", *(ptr + i));*/
//		printf("%d ", ptr[i]);
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？
//
//	system("pause");
//	return 0;
//}