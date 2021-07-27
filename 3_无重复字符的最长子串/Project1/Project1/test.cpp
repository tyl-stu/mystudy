#include<iostream>
using namespace std;
#include<string>
#include<unordered_set>  //哈希表
/*
std:: unordered_set ::count
size_type count ( const key_type& k ) const;
使用特定键计算元素
在容器中搜索值为k的元素并返回找到的元素数。因为unordered_set容器不允许重复值，这意味着如果容器中存在具有该值的元素，则该函数实际上返回1，否则返回0。
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
	string s = "abcabcbb"; // 第一个字符是a,最后一个是b
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