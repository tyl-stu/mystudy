#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

union Un   //ע�⣺��Ϊ�����壬����һ����ַ�ռ�
{
	short s[7];
	int n;
};
int main()
{
	printf("%d\n", sizeof(union Un));
	system("pause");
	return 0;
}

//************************************************************************************
//#define MAX_SIZE A+B
//#define MAX_SIZE_2 (A+B)
//struct _Record_Struct  //3�ֽ�
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//
//int main()
//{
//	int A = 2, B = 3;
//	struct _Record_Struct *pointer = (struct _Record_Struct*)malloc
//		(sizeof(struct _Record_Struct) * MAX_SIZE);
//	printf("%d ", (sizeof(struct _Record_Struct) * MAX_SIZE));// 3*2+3 = 9
//	printf("%d ", (sizeof(struct _Record_Struct) * MAX_SIZE_2)); // 3*( 2 + 3) = 15
//	system("pause");
//	return 0;
//}