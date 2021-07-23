#pragma once

typedef char DataType;
//二叉树的节点  二叉链
typedef struct BNode
{
	struct BNode *_left;
	struct BNode *_right;
	DataType _data;
}BNode;

