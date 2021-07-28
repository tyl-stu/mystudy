#include<iostream>
using namespace std;
#include<vector>

template <class T>
void printIterator(const vector<T>& vec)//可打印vector的元素，只读形式
{
	//vector<T>::iterator it = vec.begin();//该语句会报错，因为函数参数列表中调用的是const，所以此处应该使用const_iterator，即const迭代器
	vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

/* 方法1：结合两个向量*/
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
//{
//	vector<int> n1 = nums1;
//	vector<int> n2 = nums2;
//	vector<int> n;
//	/*int l1 = n1.size(); int l2 = n2.size();
//	int len = n1.size() + n2.size();*/ 
//	double ans = 0; int max;
//	/*while (!n1.empty() || !n2.empty())
//	{
//		if (!n1.empty() && n2.empty())
//		{
//			n.push_back(n1.back());
//			n1.pop_back();
//		}
//		else if (n1.empty() && !n2.empty())
//		{
//			n.push_back(n2.back());
//			n2.pop_back();
//		}
//		
//		if (!n1.empty() && !n2.empty() && n1.back() > n2.back())
//		{
//			n.push_back(n1.back());
//			n1.pop_back();
//		}
//		else if (!n1.empty() && !n2.empty() && n1.back() < n2.back())
//		{
//			n.push_back(n2.back());
//			n2.pop_back();
//		}
//		else if (!n1.empty() && !n2.empty() && n1.back() == n2.back())
//		{
//			n.push_back(n1.back());
//			n1.pop_back();
//			n.push_back(n2.back());
//			n2.pop_back();
//		}
//	}*/
//	while (!n1.empty() && !n2.empty())
//	{
//		if (n1.back() > n2.back())
//		{
//			n.push_back(n1.back());
//			n1.pop_back();
//		}
//		else if (n1.back() < n2.back())
//		{
//			n.push_back(n2.back());
//			n2.pop_back();
//		}
//		else if (n1.back() == n2.back())
//		{
//			n.push_back(n1.back());
//			n1.pop_back();
//			n.push_back(n2.back());
//			n2.pop_back();
//		}
//	}
//	while (!n1.empty() || !n2.empty())
//	{
//		if (!n1.empty() && n2.empty())
//		{
//			n.push_back(n1.back());
//			n1.pop_back();
//		}
//		else if (n1.empty() && !n2.empty())
//		{
//			n.push_back(n2.back());
//			n2.pop_back();
//		}
//	}
//	
//	int len = n.size();
//	if (len % 2 == 0)
//	{
//		ans = (double)(n[len / 2] + n[len / 2 - 1]) / (double)2;
//	}
//	else if (len % 2 == 1)
//	{
//		if (len == 1)
//			ans = n[len - 1];
//		else if (len > 1)
//			ans = n[len / 2];
//	}
//	return ans;
//}

/* 方法2：不结合两个向量*/
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> n1 = nums1;
	vector<int> n2 = nums2;
	int n = n1.size();
	int m = n2.size();

	if (n > m)  //保证数组1一定最短
	{
		return findMedianSortedArrays(n2, n1);
	}

	// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
	int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

	while (lo <= hi)   //二分
	{
		c1 = (lo + hi) / 2;  //c1是二分的结果
		c2 = m + n - c1;

		LMax1 = (c1 == 0) ? INT_MIN : n1[(c1 - 1) / 2];
		RMin1 = (c1 == 2 * n) ? INT_MAX : n1[c1 / 2];
		LMax2 = (c2 == 0) ? INT_MIN : n2[(c2 - 1) / 2];
		RMin2 = (c2 == 2 * m) ? INT_MAX : n2[c2 / 2];

		if (LMax1 > RMin2)
			hi = c1 - 1;
		else if (LMax2 > RMin1)
			lo = c1 + 1;
		else
			break;
	}
	return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;

}

void test()
{
	vector<int> n1; n1.push_back(1); n1.push_back(2);
	vector<int> n2; n2.push_back(1); 
	double aaa = findMedianSortedArrays(n1, n2);
	cout << aaa << endl;
	cout << (3.0 / 2);
	cout << "  " << (double)3/(double)2;
}

int main()
{
	test();
	system("pause");
	return 0;
}