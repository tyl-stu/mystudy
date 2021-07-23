#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1、基本数据类型的自身对齐值
//2、自定义类型（Test）的自身对齐值
//3、程序的指定对齐值
//4、自定义类型的有效对齐值 ==>> 按较小的值对齐

//typedef struct Test  //按24字节对齐
//{
//	char a;   //  1 + 7
//	double b; //  8
//	int c;    //  4 + 4
//}Test;
//
//typedef struct Test2  //按16字节对齐
//{
//	char a;   // 1 + 3
//	int c;    // 4
//	double b; // 8
//}Test2;
//******************************
////#pragma pack(2) //按2字节对齐，即结构体中的数据类型对齐值应为2的倍数
////#pragma pack(1)  //按1字节对齐，即结构体中总对齐值为各个数据类型对齐值的和
//#pragma pack(4) 
//typedef struct Test  //按14字节对齐
//{
//	char a;   //  1 + 1
//	int c;    //  4 
//	double b; //  8
//}Test;
//#pragma pack(1) 
//typedef struct Test2  //按3字节对齐
//{
//	char a;   //  1 
//	char c;   //  1
//	char b;   //  1
//}Test2;
//*******************************************************************8
//typedef struct Test    // 按40字节对齐 
//{
//	// 按最大的字节对齐，即8字节
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
//typedef struct Test    // 按 80 + 16 + 8 + 8 = 112 字节对齐 
//{
//	// 按最大的字节对齐，即8字节
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
//typedef struct Test    // 按 14 + 2 + 4 =20 字节对齐 
//{
//	// 按2字节的倍数对齐
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
//typedef struct Test    // 按 13 + 2 + 4 = 19字节对齐 
//{
//	// 按2字节的倍数对齐
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
//typedef struct Test    // 按 8 + 16 + 8 =32 字节对齐 
//{
//	// 按2字节的倍数对齐
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
//typedef struct Test    // 按 8 + 16 + 8 =32 字节对齐 
//{
//	// 按2字节的倍数对齐
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
//	//int _d : 30;//按位数算下来需要47位，且位域不可跨字节存储，所以需要7个字节，但int开辟是4个字节，所以需要8个字节
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4; //需要3个字节
//};

//int main()
//{
//	printf("%d\n", sizeof(Test));//按24字节对齐
//	//printf("%d\n", sizeof(Test2));//按16字节对齐
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
//	////练习4-结构体嵌套问题
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

enum Day//星期  -- enum 为枚举
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
