#pragma once

typedef char DataType;
//�������Ľڵ�  ������
typedef struct BNode
{
	struct BNode *_left;
	struct BNode *_right;
	DataType _data;
}BNode;

