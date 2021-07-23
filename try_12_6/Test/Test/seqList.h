#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define SLDataType int

typedef struct SeqList
{
	SLDataType * nums;		//指向动态开辟的数组
	size_t size;			//有效数据个数
	size_t capacity;		//容量空间的大小

}SeqList;

void initseqList(SeqList *s1);  //初始化一个空的顺序表
void seqListCheckCapacity(SeqList *s1);//检查顺序表的容量，为空则为其开辟空间
void seqListPushBack(SeqList *s1, SLDataType val);//尾插函数
void seqListPopBack(SeqList *s1);//尾删函数
void seqListPushFront(SeqList *s1, SLDataType val);//头插函数
void seqListPopFront(SeqList *s1);//头删函数
void seqListInsert(SeqList *s1, int pos, SLDataType val);//在任意位置插数函数

void seqListErase(SeqList *s1, int pos);//擦除pos索引上的数值
void seqListDestory(SeqList *s1);//销毁这个数组内容

int seqListEmpty(SeqList *s1);//判断数组是否为空
int seqListSize(SeqList *s1);//求得数组中数的个数
void seqListFind(SeqList *s1, SLDataType val);//在数组中找寻 val 数的位置

void seqListPrint(SeqList *s1);//打印顺序表中内容
void seqListElement(SeqList *s1, int pos);//查看pos位置的数据

#endif