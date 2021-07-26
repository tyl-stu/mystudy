/*
2. �������
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ�� 1��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[7,0,8]
���ͣ�342 + 465 = 807.

ʾ�� 2��
���룺l1 = [0], l2 = [0]
�����[0]

ʾ�� 3��
���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
�����[8,9,9,9,0,0,0,1]


��ʾ��
ÿ�������еĽڵ����ڷ�Χ [1, 100] ��
0 <= Node.val <= 9
��Ŀ���ݱ�֤�б��ʾ�����ֲ���ǰ����
*/
#include<iostream>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
// ����1
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int tmp = 0;
		int s = 0;
		ListNode* _head = nullptr; ListNode* _next = nullptr;
		while (l1 || l2)
		{
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;

			if(n1 +n2 +tmp > 9)
			{
			    s = n1 +n2 +tmp - 10;
			    tmp = 1;
			}
			else
			{
			    s = n1 +n2 +tmp;
			    tmp = 0;
			}
			if (!_head)
			{
				_head = _next = new ListNode(s);
			}
			else
			{
				_next->next = new ListNode(s);
				_next = _next->next;
			}
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (tmp != 0)
			_next->next = new ListNode(tmp);
		return _head;
	}
};

//����2    �Ƽ�����2
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int tmp = 0;
		int s = 0;
		ListNode* _head = nullptr; ListNode* _next = nullptr;
		while (l1 || l2)
		{
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;

			s = n1 + n2 + tmp;
			if (!_head)
			{
				_head = _next = new ListNode(s % 10);
			}
			else
			{
				_next->next = new ListNode(s % 10);
				_next = _next->next;
			}
			tmp = s / 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (tmp != 0)
			_next->next = new ListNode(tmp);
		return _head;
	}
};