#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1�������������͵��������ֵ
//2���Զ������ͣ�Test�����������ֵ
//3�������ָ������ֵ
//4���Զ������͵���Ч����ֵ ==>> ����С��ֵ����

//typedef struct Test  //��24�ֽڶ���
//{
//	char a;   //  1 + 7
//	double b; //  8
//	int c;    //  4 + 4
//}Test;
//
//typedef struct Test2  //��16�ֽڶ���
//{
//	char a;   // 1 + 3
//	int c;    // 4
//	double b; // 8
//}Test2;
//******************************
////#pragma pack(2) //��2�ֽڶ��룬���ṹ���е��������Ͷ���ֵӦΪ2�ı���
////#pragma pack(1)  //��1�ֽڶ��룬���ṹ�����ܶ���ֵΪ�����������Ͷ���ֵ�ĺ�
//#pragma pack(4) 
//typedef struct Test  //��14�ֽڶ���
//{
//	char a;   //  1 + 1
//	int c;    //  4 
//	double b; //  8
//}Test;
//#pragma pack(1) 
//typedef struct Test2  //��3�ֽڶ���
//{
//	char a;   //  1 
//	char c;   //  1
//	char b;   //  1
//}Test2;
//*******************************************************************8
//typedef struct Test    // ��40�ֽڶ��� 
//{
//	// �������ֽڶ��룬��8�ֽ�
//	short a;   // 2 + 6
//	struct     // 24
//	{
//		int b;    // 4 + 4
//		double c; // 8
//		char d;   // 1 + 7
//	};
//	int e;     // 4 + 4
//}Test;
//*********************************************************************
//typedef struct Test    // �� 80 + 16 + 8 + 8 = 112 �ֽڶ��� 
//{
//	// �������ֽڶ��룬��8�ֽ�
//	short a;   // 2 + 6
//	struct     // 80 + 16 = 96
//	{
//		int b;    // 4 + 4
//		double c[10]; // 8 * 10
//		char d;   // 1 + 7
//	};
//	int e;     // 4 + 4
//}Test;
//***************************************************************************
//#pragma pack(2)
//typedef struct Test    // �� 14 + 2 + 4 =20 �ֽڶ��� 
//{
//	// ��2�ֽڵı�������
//	short a;   // 2
//	struct     // 4 + 8 + 2  = 14
//	{
//		int b;    // 4 
//		double c; // 8 
//		char d;   // 1 + 1
//	};
//	int e;     // 4
//}Test;
//*******************************************************************************8
//#pragma pack(10)
//typedef struct Test    // �� 13 + 2 + 4 = 19�ֽڶ��� 
//{
//	// ��2�ֽڵı�������
//	//short a;   // 2
//	//struct t    // 4 + 8 + 1  = 13
//	//{
//	//	int b;    // 4 
//	//	double c; // 8 
//	//	char d;   // 1 
//	//};
//	//int e;     // 4
//	short a;   // 2 + 6
//	struct t    // 4 + 8 + 4  = 16
//	{
//		double c; // 8 
//		int b;    // 4 
//		char d;   // 1 + 3
//	};
//	int e;     // 4 + 4
//}Test;
//*****************************************************************************
//typedef struct Test    // �� 8 + 16 + 8 =32 �ֽڶ��� 
//{
//	// ��2�ֽڵı�������
//	short a;   // 2 + 6
//	struct     // 4 + 8 + 4  = 16
//	{
//		double c; // 8 
//		int b;    // 4 
//		char d;   // 1 + 3
//	};
//	int e;     // 4 + 4
//}Test;
//***************************************************************
//typedef struct Test    // �� 8 + 16 + 8 =32 �ֽڶ��� 
//{
//	// ��2�ֽڵı�������
//	short a;   // 2 + 6
//	struct t    // 4 + 8 + 4  = 16
//	{
//		double c; // 8 
//		int b;    // 4 
//		char d;   // 1 + 3
//	};
//	int e;     // 4 + 4
//}Test;

//struct A
//{
//	//int _a : 2; 
//	//int _b : 5;
//	//int _c : 10;
//	//int _d : 30;//��λ����������Ҫ47λ����λ�򲻿ɿ��ֽڴ洢��������Ҫ7���ֽڣ���int������4���ֽڣ�������Ҫ8���ֽ�
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4; //��Ҫ3���ֽ�
//};

//int main()
//{
//	printf("%d\n", sizeof(Test));//��24�ֽڶ���
//	//printf("%d\n", sizeof(Test2));//��16�ֽڶ���
//	//Test t;
//	//t.a = 'a';
//	//t.b = 12.34;
//	//t.c = 8;
//	//****************************************
//	//struct S3
//	//{
//	//	double d;
//	//	char c;
//	//	int i;
//	//};
//	//printf("%d\n", sizeof(struct S3));//16
//	////��ϰ4-�ṹ��Ƕ������
//	//struct S4
//	//{
//	//	char c1;
//	//	struct S3 s3;
//	//	struct t
//	//	{
//	//		int a;
//	//		char b;
//	//	};
//	//	double d;
//	//};
//	//printf("%d\n", sizeof(struct S4));//16
//	//***********************************************
//	//printf("%d\n", sizeof(Test));
//	//printf("%d\n", sizeof(Test2));
//	/*Test t1;
//	Test::t t2;
//	t2.b = 10;*/
//
//	//printf("%d\n", sizeof(struct A));
//
//	system("pause");
//	return 0;
//}

enum Day//����  -- enum Ϊö��
{
	Mon,
	Tues,
	Wed,
	Thur = 8,
	Fri,
	Sat,
	Sun
};
void main()
{
	enum Day day = Fri;
	printf("%d ", day);

	system("pause");
}
