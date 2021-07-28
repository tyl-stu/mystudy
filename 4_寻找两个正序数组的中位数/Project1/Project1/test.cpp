#include<iostream>
using namespace std;
#include<vector>

template <class T>
void printIterator(const vector<T>& vec)//�ɴ�ӡvector��Ԫ�أ�ֻ����ʽ
{
	//vector<T>::iterator it = vec.begin();//�����ᱨ����Ϊ���������б��е��õ���const�����Դ˴�Ӧ��ʹ��const_iterator����const������
	vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

/* ����1�������������*/
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

/* ����2���������������*/
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> n1 = nums1;
	vector<int> n2 = nums2;
	int n = n1.size();
	int m = n2.size();

	if (n > m)  //��֤����1һ�����
	{
		return findMedianSortedArrays(n2, n1);
	}

	// Ci Ϊ��i������ĸ�,����C1Ϊ2ʱ��ʾ��1������ֻ��2��Ԫ�ء�LMaxiΪ��i�����������Ԫ�ء�RMiniΪ��i�����������Ԫ�ء�
	int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //����Ŀǰ���������'#'��������1��2*n����

	while (lo <= hi)   //����
	{
		c1 = (lo + hi) / 2;  //c1�Ƕ��ֵĽ��
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