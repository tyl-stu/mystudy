#ifndef __LIST_H__
#define __LIST_H__


typedef int LDataType;

//����ڵ�:���� + ָ��
typedef struct  listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//����
typedef struct list  //�����������ֻ�����������ͷָ��
{
	//�����һ���ڵ�ĵ�ַ
	listNode * _head;
}list;

#endif