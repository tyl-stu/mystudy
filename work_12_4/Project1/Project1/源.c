#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//.数组中数字出现的次数
//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
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

////消失的数字
////数组nums包含从0到n的所有整数，但其中缺了一个。
////请编写代码找出那个缺失的整数。在O(n)时间内完成
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
//	printf("缺少的数是：%d\n ", t^m);
//
//	system("pause");
//	return 0;
//}