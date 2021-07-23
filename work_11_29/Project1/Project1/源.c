#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int *findsigle(int br[], int m)
{
	//int x = 0;
	//int y = !(br[0] ^ br[1]);
	//for (int i = 0; i < m; i++)
	//{
	//	//printf("%d ", br[i]);
	//	x = x^br[i];
	//	y = !(y^br[i]);
	//}
	//printf("%d ", x);
	//printf("%d ", y);
	
	int cr[2];
	int g = 0;
	for (int i = 0; i < m; i++)
	{
		int r = 0;
		for (int j = 0; j < m; j++)
		{
			if (br[i] != br[j])
			{
				r++;
			}
		}
		if (r == 11)
		{
			cr[g] = br[i];
			g++;
		}
	}
	for (int j = 0; j < 2; j++)
	{
		printf("%d ", cr[j]);
	}
	return cr;
}

int main()
{
	int ar[] = { 5, 9, 6, 7, 2, 8, 5, 7, 6, 8, 2, 3 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int *ret = findsigle(ar, n);
	printf("两个单身狗为：%d 和 %d \n", *ret, *(ret + 1));
	//int y = !(br[0] ^ br[1]);
	/*int y = !(5^1);
	printf("%d ", y);*/
	system("pause");
	return 0;
}

//模拟实现 strncat
//char *my_strncat(char *dst, char * src,int n )
//{
//	assert(dst != NULL && src != NULL);
//	char *p1 = dst;
//	const char *p2 = src;
//
//	int m = strlen(p1);
//	
//	for (int i = 0; i < n;i++)
//	{
//		*(p1 + m) = *p2;
//		p1++;
//		p2++;
//	}
//	*(p1+m+n) = '\0';	
//	return dst;
//}
//
//int main()
//{
//	char dst[20] = "abcd123";
//	char *src = "dcbasdf";
//	printf("%s \n", dst);
//	char *s = my_strncat(dst, src,4);
//	printf("%s \n", dst);
//	printf("%s \n", s);
//
//	system("pause");
//	return 0;
//}
//***********************************************************************************
// 模拟实现 atoi()   即 字符串转整形
//int my_atoi(const char *str)
//{
//	assert(str != NULL);
//	char *s = str;
//	int n = 0;
//	while (*s)
//	{
//		if (*s == '-' && (*(s + 1) >= '0'&&*(s + 1) <= '9'))
//		{
//			s++;
//			for (int i = 0; i < strlen(s); i++)
//			{
//				if (*(s + i) >= '0' && *(s + i) <= '9')
//				{
//					n = (*(s + i) - '0') + n * 10;
//				}
//				else
//					break;
//			}
//			n = -1 * n;
//			break;
//		}
//		else if (*s >= '0' && *s <= '9')
//		{
//			for (int i = 0; i < strlen(s); i++)
//			{
//				if (*(s + i) >= '0' && *(s + i) <= '9')
//				{
//					n = (*(s + i) - '0') + n * 10;
//				}
//				else
//					break;
//			}
//			break;
//		}
//		s++;
//	}
//	printf("%d ", n);
//	return n;
//
//}
//
//int main()
//{
//	char *str = " 123.61 545";
//	int ret = my_atoi(str);
//	printf("%d ", ret);
//
//	system("pause");
//	return 0;
//}