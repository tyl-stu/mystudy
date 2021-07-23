#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//.���������ֳ��ֵĴ���
//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
int main()
{
	int nums[] = { 4,1,4,5 };
	int t = 0;
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		t = t^nums[i];
	}
	printf("%d\n", t);
	int div = 1; 
	while ((div & t)==0)
	{
		div <<= 1;

	}
	printf("%d\n",div);
	int s[2] = {0};
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		if ((div & nums[i]) != 0)
		{
			s[0] = s[0]^nums[i];
		}
		else
		{
			s[1] = s[1]^nums[i];
		}
	}
	printf("%d %d ", s[0], s[1]);

	system("pause");
	return 0;
}

////��ʧ������
////����nums������0��n������������������ȱ��һ����
////���д�����ҳ��Ǹ�ȱʧ����������O(n)ʱ�������
//int main()
//{
//	
//	int nums[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
//	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
//	{
//		if (nums[0] < nums[i])
//		{
//			int t = nums[0];
//			nums[0] = nums[i];
//			nums[i] = t;
//		}
//	}
//	int n = nums[0];
//	int t = 0;
//	while (n)
//	{
//		t = t^n;
//		n--;
//	}
//	int m = 0;
//	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
//	{
//		m = m^nums[i];
//	}
//	
//	printf("ȱ�ٵ����ǣ�%d\n ", t^m);
//
//	system("pause");
//	return 0;
//}