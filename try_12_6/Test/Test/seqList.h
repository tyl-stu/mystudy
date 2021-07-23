#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define SLDataType int

typedef struct SeqList
{
	SLDataType * nums;		//ָ��̬���ٵ�����
	size_t size;			//��Ч���ݸ���
	size_t capacity;		//�����ռ�Ĵ�С

}SeqList;

void initseqList(SeqList *s1);  //��ʼ��һ���յ�˳���
void seqListCheckCapacity(SeqList *s1);//���˳����������Ϊ����Ϊ�俪�ٿռ�
void seqListPushBack(SeqList *s1, SLDataType val);//β�庯��
void seqListPopBack(SeqList *s1);//βɾ����
void seqListPushFront(SeqList *s1, SLDataType val);//ͷ�庯��
void seqListPopFront(SeqList *s1);//ͷɾ����
void seqListInsert(SeqList *s1, int pos, SLDataType val);//������λ�ò�������

void seqListErase(SeqList *s1, int pos);//����pos�����ϵ���ֵ
void seqListDestory(SeqList *s1);//���������������

int seqListEmpty(SeqList *s1);//�ж������Ƿ�Ϊ��
int seqListSize(SeqList *s1);//������������ĸ���
void seqListFind(SeqList *s1, SLDataType val);//����������Ѱ val ����λ��

void seqListPrint(SeqList *s1);//��ӡ˳���������
void seqListElement(SeqList *s1, int pos);//�鿴posλ�õ�����

#endif