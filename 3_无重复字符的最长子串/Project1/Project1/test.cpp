#include<iostream>
using namespace std;
#include<string>
#include<unordered_set>  //��ϣ��
/*
std:: unordered_set ::count
size_type count ( const key_type& k ) const;
ʹ���ض�������Ԫ��
������������ֵΪk��Ԫ�ز������ҵ���Ԫ��������Ϊunordered_set�����������ظ�ֵ������ζ����������д��ھ��и�ֵ��Ԫ�أ���ú���ʵ���Ϸ���1�����򷵻�0��
*/

int lengthOfLongestSubstring(string s)
{
	/*unordered_set<char> obj;
	int len = s.size();
	int j = 0;
	int ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (i != 0)
		{
			obj.erase(s[i - 1]);
		}
		while (j < len && !obj.count(s[j]))
		{
			obj.insert(s[j]);
			j++;
		}
		ans = ans > j - i + 0 ? ans : j - i + 0;
	}
	return ans;*/
	if (s.size() == 0) return 0;
	unordered_set<char> lookup;
	int maxStr = 0;
	int left = 0;
	for (int i = 0; i < s.size(); i++){
		while (lookup.find(s[i]) != lookup.end()){
			lookup.erase(s[left]);
			left++;
		}
		maxStr = maxStr > i - left + 1 ? maxStr : i - left + 1;
		lookup.insert(s[i]);
	}
	return maxStr;

	
}

void test()
{
	string s = "abcabcbb"; // ��һ���ַ���a,���һ����b
	string s1 = "bbbbbb";
	cout << s[0] << "  " << s[s.size()-1] << endl;
	int len = lengthOfLongestSubstring(s);
	cout << "max = " << len << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}