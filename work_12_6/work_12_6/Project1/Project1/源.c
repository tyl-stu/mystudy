#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//******************************************************************
//ʵ������ֵ��������Ӻ󣬽��ͷ�Ϊһ������Ĺ���
//����һ��������
//void PushFront(int *s1, int val,int num)//ͷ�庯��
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
//	int i = 0; int j = K;//i Ϊk��λ��
//	while (j>0)
//	{
//		j /= 10;
//		i++;
//	}
//
//	//�Ƚ�A������K�ĳ��ȣ���ȷ����Ҫ����Ŀռ��С,Ϊ��ֹ�����+1
//	int num = (ASize + 1>i + 1) ? ASize + 1 : i + 1;
//	printf("num = %d\n", num);
//	int *B;
//	B = (int*)malloc(sizeof(int)*num);
//
//	//�����������Խ�������ˣ�������β����ʼ��
//	//ѭ����������ΪA�������K��ÿλ������
//	int n = num - 1;
//	int flag = 0;//��־λ���ж��Ƿ����
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
//	////if(flag)B[n--]=1;//A��K���Ƚ�����Ҫȷ��count,��������ȷ�����շ��ص������С
//	//*returnSize = num;//������������С
//	//return B;//���շ��ص���
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
//	//while (n < ASize)  //��A��Ԫ�ع��ɵ�����
//	//{
//	//	mul = mul * 10 + A[n++];
//	//}
//	//int sum = mul + K;//���
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
//������������ʵ�֣��������ɼ�����12��6�ŵ���ҵ
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

	int nk = 0; int j = K;//nk Ϊk��λ��
	while (j>0)
	{
		j /= 10;
		nk++;
	}

	//�Ƚ�A������K�ĳ��ȣ���ȷ����Ҫ����Ŀռ��С,Ϊ��ֹ�����+1
	int num = (ASize + 1>nk + 1) ? ASize + 1 : nk + 1;
	int *B;
	B = (int*)malloc(sizeof(int)*num);

	//������β����ʼ��
	//ѭ����������ΪA�������K��ÿλ������
	int flag = 0;//��λ
	int nb = 0;//����B��λ��
	int i = ASize - 1;//����ȷ��A�ĸ�λ
	while (i >= 0 || K>0)//�˴�Ӧ��ʹ��while,ʹ��for,��������A��λ��С��K��λ����������²�������
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
	reverse(B, 0, nb - 1);//����B����
	*returnSize = nb;//������������С
	return B;

}

// int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
//   int* addRet = (int*)malloc(10001*sizeof(int));
//   //reti: ��iλ�Ľ��
//   int reti = 0;
//   //�ӵ�λ��ʼ���
//   int ai = ASize-1;
//   int next = 0; // ��λֵ
//   while(ai >= 0 || K > 0)
//   {

//     int x1 = 0;
//     //���aiû��Խ�磬����δ��ӵ�λ��ȡ��һλ����x1
//     if(ai >= 0)
//     {
//       x1 = A[ai];
//       --ai;
//     }

//     int x2 = 0;
//     //���k����0����ȡk�ĵ�iλ
//     if(K > 0)
//     {
//       x2 = K%10;
//       K /= 10;
//     }
//     //��iλ�Ľ����ÿһλ��ֵ + ��λ
//     int ret = x1+x2+next;
//     //����������9����Ҫ��λ
//     if(ret > 9)
//     {
//       ret %= 10;
//       next = 1;
//     }
//     else
//     {
//       next = 0;
//     }
//     //�����iλ�Ľ����������
//     addRet[reti++] = ret;
//   }
//   //������λ�н�λ����Ҫ�ڴ���1
//   if(next == 1)
//   {
//     addRet[reti++] = 1;
//   }	
//   //���ý��
//   reverse(addRet, 0, reti-1);
//   *returnSize = reti;

//   return addRet;
// }

//*****************************************************************************************
////.ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)
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
//	printf("ԭ���飺");
//	for (int i = 0; i < numsSize; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	int ret = removeElement(nums, numsSize,2);
//	printf("���飺");
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	system("pause");
//	return 0;
//}
//*****************************************************************************
////ɾ�����������е��ظ���
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
//	printf("ԭ���飺");
//	for (int i = 0; i < numsSize; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	int ret = removeDuplicates(nums, numsSize);
//	printf("�����飺");
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", nums[i]);
//	}printf("\n");
//	system("pause");
//	return 0;
//}
//*******************************************************************************
////�ϲ�����������
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
////ʵ���������ת
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