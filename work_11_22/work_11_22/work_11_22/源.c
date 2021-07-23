#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include <errno.h>//必须包含的头文件
//int main()
//{
//	FILE * pFile;
//	pFile = fopen("unexist.ent", "r");
//	if (pFile == NULL)
//		printf("Error opening file unexist.ent: %s \n", strerror(errno));
//	//errno: Last error number
//	system("pause");
//	return 0;
//}
//Edit; Run

//编译 strtok()
//int main()
//{
//	char str[] = "- This, a sample string.";
//	char * pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	system("pause");
//	return 0;
//}
//******************************************************************
////模拟 strncpy()
//char *my_strncpy(char *s1, char *s2,int n)
//{
//
//	assert(s1 != NULL && s2 != NULL);//1\检查参数
//	char *p1 = s1;
//	char *p2 = s2; //2、保护参数
//	int m = strlen(p2);
//	if (n <= m)
//	{
//		while (*p2)
//		{
//			*p1++ = *p2++;
//		}
//		*p1 = '\0';
//		return s1;
//	}
//	else
//	{
//		while (*p2)
//		{
//			*p1++ = *p2++;
//		}
//		for (int i = 0; i < n - m; i++)
//		{
//			*p1++ = '0';
//		}
//		*p1 = '\0';
//		return s1;
//	}
//
//}
//
//int main()
//{
//	char str1[20] = "hello";
//	char *str2 = "bit";
//	printf("str1 = %s\n", str1);
//	char *ret;
//	ret = my_strncpy(str1, str2, 5);
//	printf("str1 = %s\n", str1);
//	printf("ret = %s\n", ret);
//	system("pause");
//	return 0;
//}
//*****************************************************************
//模拟 strlen()
//int my_strlen(const char *dst)
//{
//	assert(dst != NULL);
//	const char *p = dst;
//	int n = 0;
//	while (*p)
//	{
//		n++;
//		p++;
//	}
//	return n;
//}
//
//int main()
//{
//	char str1[20] = "hello";
//	
//	printf("str1 = %s\n", str1);
//	int ret = my_strlen(str1);
//	printf("str1 = %s\n", str1);
//	printf("strlen('%s') = %d\n", str1,ret);
//	system("pause");
//	return 0;
//}
//*******************************************************8
////模拟 strcpy()
//char *mystrcpy(char *s1, char *s2)
//{
//	////int n1 = strlen(s1), n2 = strlen(s2);
//	/////*if (n1 < n2)
//	////{
//	////	s1 = (char *)malloc(n2);
//	////}*/
//	////for (int i = 0; i < n2; i++)
//	////{
//	////	*(s1 + i) = *(s2 + i);
//	////}
//	////*(s1 + n2) = '\0';
//	////return s1;
//	//while (*s2 != '\0')
//	//{
//	//	*s1 = *s2;
//	//	s1++;
//	//	s2++;
//	//}
//	//return s1;
//
//	assert(s1 != NULL && s2 != NULL);//1\检查参数
//	char *p1 = s1;
//	char *p2 = s2; //2、保护参数
//	//int n1 = strlen(p1), n2 = strlen(p2);
//
//	while (*p2 )
//	{
//		*p1++ = *p2++;
//	}
//	*p1 = '\0';
//	return s1;
//
//}
//
//int main()
//{
//	char str1[20] = "hello";
//	char *str2 = "bit";
//	printf("str1 = %s\n", str1);
//	char *ret;
//	ret = mystrcpy(str1, str2);
//	printf("str1 = %s\n", str1);
//	printf("ret = %s\n", ret);
//	system("pause");
//	return 0;
//}
//*********************************************************************8
//模拟 strcmp()
//int my_strcmp(const char *dst, const char *src)
//{
//	assert(dst != NULL && src != NULL);
//	const char *p1 = dst;
//	const char *p2 = src;
//	if (strlen(p1) > strlen(p2))
//		return 1;
//	else if (strlen(p1) < strlen(p2))
//		return -1;
//	else
//	{
//		while (*p1)
//		{
//			if (*p1 > *p2)
//			{
//				return 1;
//			}
//			else if (*p1 < *p2)
//			{
//				return -1;
//			}
//			p1++; 
//			p2++;
//		}
//		return 0;
//	}
//}
//
//int main()
//{
//	char dst[20] = "abc";
//	char *src = "abc";
//	printf("dst = %s \n", dst);
//	printf("src = %s \n", src);
//	int ret = my_strcmp(dst, src);
//	//printf("%s \n", dst);
//	printf("%d \n", ret);
//
//	system("pause");
//	return 0;
//}
//*********************************************************************
//模拟实现 strcat()
char *my_strcat(char *dst, char * src)
{
	assert(dst != NULL&&src != NULL);
	char *p1 = dst;
	const char *p2 = src;
	int n = strlen(p1);
	while (*p2)
	{
		*(p1 + n) = *p2;
		p1++;
		p2++;
	}
	return dst;
}

int main()
{
	char dst[20] = "abcd123";
	char *src = "dcba";
	printf("%s \n", dst);
	char *s = my_strcat(dst, src);
	printf("%s \n", dst);
	printf("%s \n", s);

	system("pause");
	return 0;
}
//********************************************************
//模拟实现 strstr()
//char *my_strstr(const char*dst, const char*src)
//{
//	assert(dst != NULL && src != NULL);
//	const char *p1 = dst;
//	const char *p2 = src;
//	int n;
//	while (*p1)
//	{
//		for (n = 0; *(p1 + n) == *(p2 + n); n++)
//		{
//			if (!*(p2 + n + 1))
//				return p1;
//		}
//		p1++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char dst[20] = "abcd12ghi123hjj";
//	char *src = "123";
//	printf("%s \n", dst);
//	char *s = my_strstr(dst, src);
//	//printf("%s \n", dst);
//	printf("%s \n", s);
//
//	system("pause");
//	return 0;
//}
//**********************************************************
//模拟实现 memmove()
//void *my_memmove(void *dst, void *src, size_t count)
//{
//	assert(dst != NULL && src != NULL);
//	char *p1 = dst;
//	const char *p2 = src;
//	//printf("%s ", (char *)p1);
//	//printf("%s ", (char *)p2 + count);
//	if ((p1 <= p2) || ((char *)p1 >= (char *)p2 + count))//不发生地址重叠
//	{
//	//	printf("bbbbbb ");
//		while (count--)
//		{
//			*(char *)p1 = *(char *)p2;
//			p1 = (char *)p1 + 1;
//			p2 = (char *)p2 + 1;
//		}
//
//	}
//	else//会发生地址重叠
//	{
//	//	printf("hahhah ");
//		p1 = (char *)p1 + count - 1;
//		p2 = (char *)p2 + count - 1;
//
//		while (count--)
//		{
//			*(char *)p1 = *(char *)p2;
//			p1 = (char *)p1 - 1;
//			p2 = (char *)p2 - 1;
//		}
//	}
//	
//	return dst;
//}
//int main()
//{
//	char dst[20] = "abcd";
//	char *src = "fghaasd";
//	printf("%s \n", dst);
//	void *s = my_memmove(dst , src, 4);
//	printf("%s \n", dst);
//	printf("%s \n", s);
//
//	system("pause");
//	return 0;
//}
//*************************************************************8
//模拟实现 memcpy()
//void *my_memcpy(void *dst, void *src, size_t count)
//{
//	assert(dst != NULL && src != NULL);
//	void *p1 = dst;
//	const void *p2 = src;
//	while (count--)
//	{
//		*(char *)p1 = *(char *)p2;
//		p1 = (char *)p1 + 1;
//		p2 = (char *)p2 + 1;
//	}
//	return dst;
//}
//
//int main()
//{
//	char dst[20] = "abcdefghijk";
//	char *src = "fgha";
//	printf("%s \n", dst);
//	void *s = my_memcpy(dst+2, dst, 4);
//	printf("%s \n", dst);
//	printf("%s \n", s);
//
//	system("pause");
//	return 0;
//}