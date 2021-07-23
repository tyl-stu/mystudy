#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//******************************************************************
//实现数组值和整数相加后，将和分为一个数组的功能
//方法一：有问题
//void PushFront(int *s1, int val,int num)//头插函数
//{
//	if (s1 == NULL)
//		return;
//	
//	int end = num;
//	while (end > 0)
//	{
//	s1[end] = s1[end - 1];
//	end--;
//	}
//	s1[0] = val;
//	num++;
//	
//}
//void addToArrayForm(int* A, int ASize, int K, int * returnSize)
//{
//	if (K == 0)
//	{
//		*returnSize = ASize;
//		return A;
//	}
//	int i = 0; int j = K;//i 为k的位数
//	while (j>0)
//	{
//		j /= 10;
//		i++;
//	}
//
//	//比较A数组与K的长度，以确定需要分配的空间大小,为防止溢出都+1
//	int num = (ASize + 1>i + 1) ? ASize + 1 : i + 1;
//	printf("num = %d\n", num);
//	int *B;
//	B = (int*)malloc(sizeof(int)*num);
//
//	//分配好数组可以进行相加了，从数组尾部开始加
//	//循环结束条件为A加完或者K的每位都加完
//	int n = num - 1;
//	int flag = 0;//标志位，判断是否溢出
//	//int sum = K;
//	int sum = K;
//	for (int i1 = n - 1; i1 >= 0 ; i1--)
//	{
//		sum = sum + (i1 >= 0 ? A[i1] : 0);
//		B[i1] = sum % 10;
//		sum = sum / 10;
//
//	}
//	printf("sum = %d\n", sum);
//	if (sum != 0)
//	{
//		int end = n;
//		while (end > 0)
//		{
//			B[end] = B[end - 1];
//			end--;
//		}
//		B[0] = sum;
//		n++;
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", B[i]);
//	}
//	//for (int i = n - 1; i >= 0 || K; i--){
//	//	int sum = K + (i >= 0 ? A[i] : 0);
//	//	K = (K ? K / 10 : 0);
//	//	int m = sum % 10;
//	//	B[n--] = m;
//	//	printf("n = %d,B[n--]= %d \n", n, m);
//	//}
//	////if(flag)B[n--]=1;//A和K都比较完需要确认count,这样可以确定最终返回的数组大小
//	//*returnSize = num;//分配的新数组大小
//	//return B;//最终返回的需
//
//	/*if (K == 0)
//	{
//		*returnSize = ASize;
//		return A;
//	}
//	int i = ASize - 1; int i1 = 1;
//	int sum = K;
//	while (i >= 0)
//	{
//		sum = sum + A[i];
//		A[i] = sum % 10;
//		sum = sum / 10;
//		i--;
//	}
//	printf("i=%d ,sun = %d\n", i,sum);
//	printf("ASize=%d ,ASize++ = %d\n", ASize, ASize+1);
//	int *B=NULL;
//	
//	if (sum==0)
//	{
//		*returnSize = ASize;
//		B = A;
//	}
//	else
//	{
//		
//		ASize++;
//		*returnSize = ASize;
//		printf("sun = %d\n", sum);
//		printf("ASize=%d \n", ASize);
//		B = (int *)realloc(A, sizeof(int) * 1);
//		PushFront(B, ASize, sum);
//	}
//	for (int i = 0; i < ASize; i++)
//	{
//		printf("%d ", B[i]);
//	}*/
//
//	//if (K == 0)
//	//{
//	//	*returnSize = ASize;
//	//	return A;
//	//}
//	//	
//	//int n = 0;int mul = 0;
//	//while (n < ASize)  //求A中元素构成的整数
//	//{
//	//	mul = mul * 10 + A[n++];
//	//}
//	//int sum = mul + K;//求和
//	//
//	//int i = 0; int j = sum;
//	//while (j >0)
//	//{
//	//	j /= 10;
//	//	i++;
//	//}
//	//returnSize = &i;
//	//printf("%d \n", *returnSize);
//	//int *B = (int *)malloc(*returnSize * sizeof(int));
//	//int m = sum; int i1 = 1;
//	//printf("%d \n", m);
//	//i--;
//	//while (i >= 0)
//	//{
//	//	printf("i=%d \n", i);
//	//	B[i] = (m / i1) % 10;
//	//	printf("B[%d] = %d ",i, B[i]);
//	//	i1 *= 10;
//	//	i--;
//	//}
//	//return B;
//}
//
//int main()
//{
//	int nums[] = {  1 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int arr[] = { 0 };
//	
//	
//	addToArrayForm(nums, numsSize,976,0);
//	/*printf("%d ", *returnSize);
//	for (int i = 0; i < *returnSize; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//		free(arr);*/
//	system("pause");
//	return 0;
//}
//*****************
//方法二：可以实现，具体结果可见比特12月6号的作业
void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;

		++begin;
		--end;
	}
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	if (K == 0)
	{
		*returnSize = ASize;
		return A;
	}

	int nk = 0; int j = K;//nk 为k的位数
	while (j>0)
	{
		j /= 10;
		nk++;
	}

	//比较A数组与K的长度，以确定需要分配的空间大小,为防止溢出都+1
	int num = (ASize + 1>nk + 1) ? ASize + 1 : nk + 1;
	int *B;
	B = (int*)malloc(sizeof(int)*num);

	//从数组尾部开始加
	//循环结束条件为A加完或者K的每位都加完
	int flag = 0;//进位
	int nb = 0;//数组B的位数
	int i = ASize - 1;//用来确定A的高位
	while (i >= 0 || K>0)//此处应该使用while,使用for,很容易在A的位数小于K的位数这种情况下产生问题
	{
		int d1 = 0;
		if (i >= 0)
		{
			d1 = A[i--];
		}

		int d2 = 0;
		if (K>0)
		{
			d2 = K % 10;
			K /= 10;
		}

		int sum = d1 + d2 + flag;
		if (sum>9)
		{
			sum %= 10;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		B[nb] = sum;
		nb++;

	}
	if (flag == 1)
	{
		B[nb++] = 1;
	}
	reverse(B, 0, nb - 1);//数组B逆置
	*returnSize = nb;//分配的新数组大小
	return B;

}

// int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//   int* addRet = (int*)malloc(10001*sizeof(int));
//   //reti: 第i位的结果
//   int reti = 0;
//   //从低位开始相加
//   int ai = ASize-1;
//   int next = 0; // 进位值
//   while(ai >= 0 || K > 0)
//   {

//     int x1 = 0;
//     //如果ai没有越界，还有未相加的位，取出一位存入x1
//     if(ai >= 0)
//     {
//       x1 = A[ai];
//       --ai;
//     }

//     int x2 = 0;
//     //如果k大于0，获取k的第i位
//     if(K > 0)
//     {
//       x2 = K%10;
//       K /= 10;
//     }
//     //第i位的结果：每一位的值 + 进位
//     int ret = x1+x2+next;
//     //如果结果大于9，需要进位
//     if(ret > 9)
//     {
//       ret %= 10;
//       next = 1;
//     }
//     else
//     {
//       next = 0;
//     }
//     //存入第i位的结果到数组中
//     addRet[reti++] = ret;
//   }
//   //如果最高位有进位，需要在存入1
//   if(next == 1)
//   {
//     addRet[reti++] = 1;
//   }	
//   //逆置结果
//   reverse(addRet, 0, reti-1);
//   *returnSize = reti;

//   return addRet;
// }

//*****************************************************************************************
////.原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
//int removeElement(int* nums, int numsSize, int val)
//{
//	int n = 0, idx = 0;
//	while (n < numsSize)
//	{
//		if (nums[n] != val)
//		{
//			nums[idx++] = nums[n];
//		}
//		n++;
//	}
//	return idx;
//}
//
//int main()
//{
//	int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	printf("原数组：");
//	for (int i = 0; i < numsSize; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	int ret = removeElement(nums, numsSize,2);
//	printf("数组：");
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	system("pause");
//	return 0;
//}
//*****************************************************************************
////删除排序数组中的重复项
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize < 2)
//		return numsSize;
//	int n = 0, idx = 0;
//	while (n < numsSize)
//	{
//		if (nums[idx] != nums[n])
//		{
//			nums[++idx] = nums[n];	
//		}
//		n++;
//	}
//	
//	return idx+1;
//}
//int main()
//{
//	int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	printf("原数组：");
//	for (int i = 0; i < numsSize; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	int ret = removeDuplicates(nums, numsSize);
//	printf("现数组：");
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	system("pause");
//	return 0;
//}
//*******************************************************************************
////合并两有序数组
//void merge(int* num1, int num1Size, int m, int* num2, int num2Size, int n)
//{
//	/*if (num1Size > (n + m))
//	{
//		memcpy(num1 + m, num2, n * 4);
//		for (int i = 0; i < n + m; i++)
//		{
//			for (int j = i; j < n + m ; j++)
//			{
//				if (num1[i] > num1[j])
//				{
//					int t = num1[i];
//					num1[i] = num1[j];
//					num1[j] = t;
//				}
//			}
//		}
//		for (int i = 0; i < n + m; i++)
//		{
//			printf("%d ", num1[i]);
//		}printf("\n");
//	}
//*/
//
//	int sum = m + n - 1;
//	int m1 = m,n1 = n;//2 2
//	m1--; n1--;
//	while (m1 >= 0 && n1 >= 0)
//	{
//		if (num1[m1] >= num2[n1])
//		{
//			num1[sum] = num1[m1--];
//		}
//		else if (num1[m1]<num2[n1])
//		{
//			num1[sum] = num2[n1--];
//		}
//		//printf("num1[sum] = %d,n=%d,m=%d\n", num1[sum], n1, m1);
//		sum--;// n1--; m1--;
//
//	}
//	while (n1 >= 0)
//	{
//		num1[sum--] = num2[n1--];
//	}
//	for (int i = 0; i <n+m; i++)
//	{
//		printf("%d ", num1[i]);
//	}printf("\n");
//}
//
//int main()
//{
//	int num1[7] = { 2,4,5,6, 0, 0, 0 };
//	int num2[4] = { 1,2,3,4};
//	merge(num1, 7, 2, num2, 4, 4);
//	
//	system("pause");
//	return 0;
//}
//**********************************************************************
////实现数组的旋转
//void reverse(int *nums, int start, int end)
//{
//	while (start<end)
//	{
//		int t = nums[start];
//		nums[start] = nums[end];
//		nums[end] = t;
//		start++;
//		end--;
//	}
//}
//void rotate(int* nums, int numsSize, int k){
//	int n = numsSize;
//	
//	k %= n;
//	reverse(nums, 0, n - k - 1);
//	reverse(nums, n - k, n - 1);
//	reverse(nums, 0, n - 1);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//}
//
//int main()
//{
//	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int n = sizeof(nums) / sizeof(nums[0]);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	rotate(nums, n, 4);
//
//	system("pause");
//	return 0;
//}