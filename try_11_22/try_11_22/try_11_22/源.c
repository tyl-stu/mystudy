#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//int main()
//{
//	char a = -128;
//	printf("%x\n", a);
//	system("pause");
//	return 0;
//}

//void fun(char * p)
//{
//	while (*p)
//	{
//		*p -= 32;
//		p++;
//	}
//}
//int main()
//{
//	char str[] = "hello";//�˴�����ʹ���ַ������飬����ָ�룬�����õĶ����ǵ�ַ�����ǵ�ַ��ָ������ݣ��Ӷ�����
//	printf("%s \n", str);
//	fun(str);
//	printf("%s \n", str);
//
//	system("pause");
//	return 0;
//}

// strtok()֮ʵ��
//int main()
//{
//	//�˴�����ʹ���ַ�������в���������ָ�� ����������ǵ�ַ�������ַ������Ӷ��ᱨ��  ������
//	//char str[] = "- This, a sample string.";
//	char str[] = "123.45 78";
//	char * pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//
//	system("pause");
//	return 0;
//}

////ģ��ʵ�� memcpy()
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
//	char dst[20] = "abcdefghi";
//	char *src = "fgha";
//	printf("%s \n", dst);
//	void *s = my_memcpy(dst+4, dst, 5);
//	printf("%s \n", dst);
//	printf("%s \n", s);
//
//	system("pause");
//	return 0;
//}
//*****************************************************************
//�����ϵ�һЩ������֤
//int main()
//{
//	//char a = -1;
//	//signed char b = -1;
//	//unsigned char c = -1; //�Բ��뷽ʽ����
//	//printf("a=%d,b=%d,c=%d", a, b, c);
//
//	/*char a = 128;
//	printf("%d\n", a);
//	printf("%u\n", a);
//*/
//	/*char a[1000];
//	int i;
//	for (i = 0; i<1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));*/
//
//	/*int n = 9;
//	float *pFloat = (float *)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%d\n", *pFloat);*/
//
//	//��֤
//	/*int  n = 9;
//	int *p = &n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*p��ֵΪ��%d\n", *p);
//	*p = 5;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*p��ֵΪ��%d\n", *p);
//	
//	int *q = 6;*/
//
//	system("pause");
//	return 0;
//}
//***********************************************************************
// С��ģʽ�����˳����ʾ���ȸߺ��
//int main() //С��
//{
//	union
//	{
//		short k;
//		char i[2];
//	}*s,a;
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	//s->i[0] �ڵ͵�ַ��s->i[1]�ڸߵ�ַ  
//	//С��������ȸߺ�� ==> 3839
//	printf("%x\n", a.k);//3839
//
//	system("pause");
//	return 0;
//}
//*********************************************************************************
// �ж�ϵͳ��С�˻��Ǵ��ģʽ
//int check_sys()
//{
//	int i = 1;
//	printf("%u ", i);
//	return (*(char *)&i);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	system("pause");
//	return 0;
//}
//******************************************************************
//void main(int argc,char *argv[])
//{
//	int ret = atoi(argv[1]) + atoi(argv[2]);
//
//
//}
//**********************************************************************
//strncpy()֮ʹ��
//int main()
//{
//	char str1[20] = "hello";
//	char *str2 = "bit.";
//	printf("str1 = %s\n", str1);
//	char *ret;
//	ret = strncpy(str1, str2,3);
//	printf("str1 = %s\n", str1);
//	printf("ret = %s\n", ret);
//	system("pause");
//	return 0;
//}
//***************************************************************************
////ģ�� strcat()
//char *mystrcat(char *s1, char *s2)
//{
//	assert(s1 != NULL && s2 != NULL);
//	char *p1 = s1;
//	const char *p2 = s2;
//	int n = strlen(p1);
//	int m = strlen(p2);
//	printf("%c", *(p1 + n-1));
//	/*while (*p2 != '\0')
//	{
//		*(p1 + n) = *p2;
//		p1++;
//		p2++;
//	}*/
//	for (int i = 0; i < m; i++)
//	{
//		*(p1 + n+i) = *(p2+i);
//	}
//	return s1;
//
//}
//int main()
//{
//	char str1[20] = "hello";
//	char *str2 = "bit.";
//	printf("str1 = %s\n", str1);
//	char *ret;
//	ret = mystrcat(str1, str2);
//	printf("str1 = %s\n", str1);
//	printf("ret = %s\n", ret);
//
//	system("pause");
//	return 0;
//}
//************************************************************************
//ģ�� strcpy()
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
//	assert(s1 != NULL && s2 != NULL);//1\������
//	char *p1 = s1;
//	char *p2 = s2; //2����������
//	int n1 = strlen(p1), n2 = strlen(p2);
//
//	while (*p2 != '\0')
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
//*************************************************************************
//����ָ��κ���
//int main()
//{
//	//����ָ��κ���
//	//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int *ptr1 = (int *)(&aa + 1);
//	////(int *)��(*(aa + 1))ǿת�����ܸ�*ptr��ֵ
//	//int *ptr2 = (int *)(*(aa + 1));
//	//printf("%d,%d,", *(ptr1 - 1), *(ptr2 - 1));
//	//printf("%d", *(*(aa + 1) + 1));
//	////������*(aa + 1)ֻ��ָ������һ�У�Ȼ��**(aa + 1)��ָ������һ���е�����
//	//
//	/*char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
//	char**cp[] = { c + 3, c + 2, c + 1, c };
//	char***cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *--*++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);*/
//	
//	system("pause");
//	return 0;
//}