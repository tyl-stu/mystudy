#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<map>
#include<unordered_map>

/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
////string add(string& str1, string& str2) //字符串相加 -- 自编
////{
////	int sz1 = str1.size(), sz2 = str2.size();
////	string rea;
////	int max = sz1,min = sz2;
////	if (max < sz2)
////	{
////		max = sz2;
////		min = sz1;
////	}
////	rea.reserve(max + 1);
////	string t1, t2,t,t3;
////	int n1, n2, ans = 0;
////	if (sz1 > sz2)//长的赋值给t，短的赋值给t2
////	{
////		t = str1;
////		t2 = str2;
////	}
////	else
////	{
////		t = str2;
////		t2 = str1;
////	}
////	t1 = t.substr(t.size() - min, min);
////	t3 = t.substr(0, t.size() - min);
////	
////	for (int i = t1.size() - 1; i >= 0; i--)
////	{
////		n1 = t1[i] - '0';
////		n2 = t2[i] - '0';
////		ans = n1 + n2 + ans;
////		if (ans > 9)
////		{
////			rea.insert(rea.begin(), ans % 10 + '0');
////			ans = ans / 10;
////		}
////		else
////		{
////			rea.insert(rea.begin(), ans + '0');
////			ans = 0;
////		}
////
////	}
////	
////	for (int i = t3.size() - 1; i >= 0; i--)
////	{
////		n1 = t3[i] - '0';
////		ans = n1 + ans;
////		if (ans > 9)
////		{
////			rea.insert(rea.begin(), ans % 10 + '0');
////			ans = ans / 10;
////		}
////		else
////		{
////			rea.insert(rea.begin(), ans + '0');
////			ans = 0;
////		}
////	}
////	if (ans != 0)
////	{
////		rea.insert(rea.begin(), ans + '0');
////	}
////	
////	return rea;
////}
//
//string add(string num1, string num2)//字符串相加程序 -- 老师
//{
//	int end1 = num1.size() - 1;
//	int end2 = num2.size() - 1;
//	//进位
//	int step = 0;
//	string ret;
//	//判断需要的长度
//	int len = end1 > end2 ? end1 + 2 : end2 + 2;
//	//增容
//	ret.reserve(len);
//	while (end1 >= 0 || end2 >= 0)
//	{
//		int cur = step;
//		if (end1 >= 0)
//			cur += num1[end1] - '0';
//		if (end2 >= 0)
//			cur += num2[end2] - '0';
//		if (cur >= 10)
//		{
//			cur -= 10;
//			step = 1;
//		}
//		else
//			step = 0;
//		ret += cur + '0';//此种是逆序，需要逆置
//		end1--;
//		end2--;
//	}
//	if (step == 1)
//	{
//		ret += '1';//方法二：此种是逆序，需要逆置
//	}
//	reverse(ret.begin(), ret.end());
//	return ret;
//}
//
//void test()
//{
//	string num1, num2;
//	string ans;
//	cin >> num1 >> num2;
//	cout << num1 << " " << num2 << endl;
//	if (num1 == "0" || num2 == "0")
//	{
//		ans.push_back('0');
//		cout << ans << endl;
//	}
//	int sz1 = num1.size(), sz2 = num2.size();
//	string a1;
//	a1.reserve(sz1 + 1);
//	string tmp;
//	ans.reserve(sz1 + sz2);
//
//	int n1 = 0, n2 = 0;
//	int n = 0;
//	for (int j = 0; j < sz1; j++)//将单个字符转换为数字,从末尾向前挨个乘求和
//	{
//		a1 = "";
//		n1 = num1[j] - '0';
//		for (int i = sz2-1; i >= 0; i--)//末尾数字
//		{
//			n2 = num2[i] - '0';//先将单个字符转为数字
//			n = n1*n2 + n;
//			if (n > 9)
//			{
//				a1.insert(a1.begin(), n % 10 + '0');
//				n = n / 10;
//			}
//			else
//			{
//				a1.insert(a1.begin(), n + '0');
//				n = 0;
//			}
//		}
//		if (n != 0)
//		{
//			a1.insert(a1.begin(), n + '0');
//			n = 0;
//			//a1.insert(a1.end(), '0');
//		}	
//		ans = add(ans, a1)+'0';
//	}
//
//	ans.pop_back();
//	cout << ans<< endl;
//
//}
//
////void test()
////{
////	string num1, num2;
////	string ans;
////	cin >> num1 >> num2;
////	cout << num1 << " " << num2 << endl;
////	/*if (num1 == "0" || num2 == "0")
////	{
////		ans.push_back('0');
////		return ans;
////	}*/
////	int sz1 = num1.size(), sz2 = num2.size();
////	ans.reserve(sz1 + sz2);
////	int n1 = 0, n2 = 0;
////	for (const char& e : num1)//将字符转换为数字
////	{
////		n1 = n1 * 10 + (e - '0');
////	}
////	int n = 0;
////	for (const char& e : num2)
////	{
////		n2 = e - '0';//先将单个字符转为数字
////		n = n * 10 + n2*n1;//转换的单个数字乘上面转换后的数字再进行相加
////	}
////	cout << n << endl;
////	string::iterator it = ans.begin();
////	while ((n % 10 != 0) || (n % 10 == 0 && n> 0))//作头插
////	{
////		ans.insert(ans.begin(),n % 10 + '0');
////		n = n / 10;
////	}
////	cout << ans << endl;
////	
////}
//
///*一个实现方法，适用性不高*/
////void test()
////{
////	string num1 = "2";
////	string num2 = "0";
////	int sz1 = num1.size();
////	int sz2 = num2.size();
////	int n1 = 0, n2 = 0;
////	for (const char& e : num1)
////	{
////		n1 = n1 * 10 + (e - '0');
////	}
////	for (const char& e : num2)
////	{
////		n2 = n2 * 10 + (e - '0');
////	}
////	int n = n1*n2;
////	string a;
////	if (n == 0)
////	{
////		a.push_back('0');
////	}
////	else
////	{
////		while ((n % 10 != 0) || (n % 10 == 0 && n> 0))
////		{
////			a.push_back(n % 10 + '0');
////			n = n / 10;
////		}
////	}
////	int i = 0; int j = a.size() - 1;
////	while (i < j)
////	{
////		char tmp = a[i];
////		a[i] = a[j];
////		a[j] = tmp;
////		i++;
////		j--;
////	}
////
////	cout << a << endl;
////}
//
//int main()
//{
//	test();
//	//cout << a << endl;
//	system("pause");
//	return 0;
//}

//void test()
//{
//	/*string str = "Hello Bit.";
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		if (*it != ' ')
//			cout << *it;
//		else
//			str.erase(it);
//		it++;
//	}*/
//
//	/*string s1 = "hello world";
//	string s2 = "change world";
//	string::iterator it = s1.begin();
//	swap(s1, s2);
//	it = s1.begin();
//	while (it != s1.end())
//		cout << *it;
//	cout << endl;*/
//
//	/*该程序相当于打印了所给string对象的内容*/
//	//string strText = "How are you?123";
//	//string strSeparator = " ";
//	//string strResult;
//	//int size_pos = 0;
//	//int size_prev_pos = 0;
//	//while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	//{
//	//	strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//	//	cout << strResult << " ";
//	//	size_prev_pos = ++size_pos;
//	//}
//	//if (size_prev_pos != strText.size())
//	//{
//	//	// 此时 size_prev_pos = 8, size_pos - size_prev_pos = -9(或一个很大的正数)
//	//	//相当于截取了从 strText 的第8位到最后一位的内容
//	//	strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//	//	cout << strResult << " ";
//	//}
//	//cout << endl;
//
//}

/*题目描述
找出字符串中第一个只出现一次的字符
输入描述:
输入几个非空字符串

输出描述:
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入
	asdfasdfo
	aabb
输出
	o
	-1
*/
//void display(string & str)
//{
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it;
//		it++;
//	}cout << endl;
//}
//
//int test(const string& str)
//{
//	
//		int i = 0;
//		int count[256] = { 0 };
//		for (const char& e : str)
//		{
//			count[e]++;
//		}
//		for (; i < str.size(); i++)
//		{
//			if (count[str[i]] == 1)
//			{
//				return i;
//			}
//		}
//		return -1;
//	
//
//}
//
//int main()
//{	
//	string str;
//	while (cin >> str)
//	{
//		int i = test(str);
//		if (i != -1)
//			cout << str[i] << endl;
//		else
//			cout << -1 << endl;
//	}
//	
//	system("pause");
//	return 0;
//}

/* 反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 示例：
 输入："Let's take LeetCode contest"
 输出："s'teL ekat edoCteeL tsetnoc"

  提示：
  在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//string swap_s(string s)
//{
//	char *start = (char *)s.c_str();
//	char *ends = start + s.size() - 1;
//	while (start < ends)
//	{
//		swap(*start, *ends);
//		start++;
//		ends--;
//	}
//	return s;
//
//}
//
//void test()
//{
//	string s = "Let's take LeetCode contest";
//	cout << s << s.size() << endl;
//	/*int i = s.find(" ", 0);
//	cout << s.c_str() << "  " << s.size() << "  " << i << endl;
//	cout << s.substr(0, i) << endl;
//	string s1 = swap_s(s.substr(0, i));
//	cout << s1 << endl;*/
//	int i = 0;
//	string s2;
//	while (i < s.size())
//	{
//		int j = s.find(' ', i+1);
//		
//		string t = swap_s(s.substr(i, j - i));//sustr（pos,n） 是从pos截取n个字符
//		cout << "i = " << i << "  " << "j = " << j << endl;
//		t.push_back(' ');
//		s2.append(t);
//		if (j == -1)
//		{
//			s2.pop_back();
//			break;
//		}
//		i = j + 1;
//	}
//	cout << s2 << " " << s2.size() << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/* 反转字符串 II
给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 
示例:
输入: s = "abcdefg", k = 2
输出: "bacdfeg"

提示：
该字符串只包含小写英文字母。
给定字符串的长度和 k 在 [1, 10000] 范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
//string swap_s(string s)
//{
//	char *start = (char *)s.c_str();
//	char *ends = start + s.size() - 1;
//	while (start < ends)
//	{
//		swap(*start, *ends);
//		start++;
//		ends--;
//	}
//	return s;
//}
//string reverseStr2(string s, int k)
//{
//	string t;
//	if ((1 <= s.size()) && (s.size() <= 10000) && (1 <= k) && (k <= 10000))
//	{
//		int n = 0;
//		while (s.size() > n)
//		{
//			if (n % (2 * k) == 0)
//			{
//				t.append(swap_s(s.substr(n, k)));
//				n += k;
//			}
//			if (s.size() > n)
//			{
//				t.append(s.substr(n, k));
//				n += k;
//			}
//		}
//	}
//	return t;
//}
//
//void test()
//{
//	string s = "a";
//	int k = 3;
//	
//	string s2 = reverseStr2(s, k);
//	cout << "s  = " << s << "  s.size()  = "<< s.size() <<"  k = " << k << endl;
//	cout << "s2 = " << s2 << "  s2.size() = " << s2.size() << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}


/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//bool isZimu(const char &ch)
//{
//	return ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9');
//}
//bool isPalindrome(string s)
//{
//	for (char &ch : s)//大写变小写
//	{
//		if ('A' <= ch && ch <= 'Z')
//			ch += 32;
//	}
//	int n_beg = 0;
//	int n_end = s.size() - 1;
//	while (n_beg < n_end)
//	{
//		//找出有效字符进行对比
//		while (n_beg < n_end && !isZimu(s[n_beg]))
//		{
//			n_beg++;
//		}
//		while (n_beg < n_end && !isZimu(s[n_end]))
//		{
//			n_end--;
//		}
//		if (s[n_beg] != s[n_end])
//			return false;
//		n_beg++;
//		n_end--;
//	}
//	return true;
//}
//void test()
//{
//	string str = "A man, a plan, a canal: Panama";
//	cout << isPalindrome(str) << endl;
//	//cout << isspace('1') << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*
题目描述
	计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。

输入描述:
	输入一行，代表要计算的字符串，非空，长度小于5000。
输出描述:
	输出一个整数，表示输入字符串最后一个单词的长度。

示例1
	输入
		hello nowcoder
	输出
		8
说明
最后一个单词为nowcoder，长度为8
https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&tqId=21282&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tab=answerKey
*/
//int numStr(string s)
//{
//	/*较为普通的解法，需擅用string类的函数*/
//	//int n_end = s.size() - 1;
//	//int n = 0;
//	////isspace('x') -- 判断'x'字符是否是空格，若是则返回true,反之返回false
//	//while (!isspace(s[n_end]))
//	//{
//	//	n++;
//	//	n_end--;
//	//}
//	//return n;
//	/* 使用 rfind() 函数*/
//	int pos = s.rfind(' ', s.size());
//	return s.size() - 1 - pos;
//}
//void test()
//{
//	//string s = "hello nowcoder";
//	string s;
//	getline(cin, s);
//	cout << numStr(s) << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*  字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 示例：
 s = "leetcode"
 返回 0

 s = "loveleetcode"
 返回 2
  

  提示：你可以假定该字符串只包含小写字母。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//int firstUniqChar(string s) {
//	/* 这种方法太麻烦，且有bug */
//	/*if (s.size() == 1)
//	{
//		return 0;
//	}
//	else
//	{
//		int num[26] = { 0 };
//		int begin = 0;
//		while (begin < s.size())
//		{
//			num[s[begin] - 'a']++;
//			begin++;
//		}
//		int t = s.size() - 1;
//		for (int i = 0; i < 26; i++)
//		{
//			if (num[i] == 1)
//			{
//				if (t > s.find('a' + i, 0))
//				{
//					t = s.find('a' + i, 0);
//				}
//			}
//
//		}
//		if (t >= s.size() - 1)
//			return -1;
//		return t;
//	}*/
//	
//	/* 老师提供的方法 */
//	int num[26] = { 0 };
//	for (const char& ch : s)
//		num[ch - 'a']++;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (num[s[i] - 'a'] == 1)
//			return i;
//	}
//	return -1;
//}
//void test()
//{
//	string s = "a";
//	cout << firstUniqChar(s) << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*  反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 示例 1：
 输入：["h","e","l","l","o"]
 输出：["o","l","l","e","h"]

 示例 2：
 输入：["H","a","n","n","a","h"]
 输出：["h","a","n","n","a","H"]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-string
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//void reverseString(vector<char>& s)
//{
//	
////	cout << s.size();
//	int beg = 0;
//	int en = s.size() - 1;
//	while (beg < en)
//	{
//		swap(s[beg], s[en]);
//		beg++; en--;
//	}
//	vector<char>::iterator it = s.begin();
//	while (it != s.end()) {
//		cout << *it << " ";
//		++it;
//	}
//}
//void test()
//{
//	/*char s[] = {"h", "e", "l", "l", "o"};
//	cout << s;*/
//	char a[] = { 'h', 'e', 'l', 'l', 'o' };
//	vector<char> s(a, a + sizeof(a) / sizeof(char));
//	vector<char>::iterator it = s.begin();
//	while (it != s.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	reverseString(s);
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

 提示：

 num1 和num2 的长度都小于 5100
 num1 和num2 都只包含数字 0-9
 num1 和num2 都不包含任何前导零
 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-strings
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//string addStrings(string num1, string num2)
//{
//	int flag = 0;//进位
//	int n1 = num1.size() - 1;
//	int n2 = num2.size() - 1;
//	string s;
//	int len = n1 > n2 ? n1 + 2 : n2 + 2;
//	s.reserve(len);
//	while (n1 >= 0 || n2 >= 0)
//	{
//		int cur = flag;
//		if (n1 >= 0)
//			cur = cur + num1[n1] - '0';
//		if (n2 >= 0)
//			cur = cur + num2[n2] - '0';
//		if (cur > 9)
//		{
//			flag = 1;
//			cur = cur % 10;
//		}
//		else
//			flag = 0;
//		//s.insert(s.begin(), cur + '0'); //方法一：头插
//		s += cur + '0';//方法二：尾插，兼反转
//		n1--; n2--;
//	}
//	if (flag == 1)
//		//s.insert(s.begin(), '1');
//		s += '1';
//	reverse(s.begin(), s.end());
//	return s;
//}
//void test()
//{
//	string s1 = "1234";
//	string s2 = "79";
//	cout << addStrings(s1, s2) << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*把字符串转换为整数
题目描述
	将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
	输入一个字符串,包括数字字母符号,可以为空
返回值描述:
	如果是合法的数值表达则返回该数字，否则返回0

示例1
	输入
		"+2147483647"
	返回值
		2147483647
示例2
	输入
		"1a33"
	返回值
		0

连接：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=6&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey
*/
//int StrToInt(string str)
//{
//	string::iterator it = str.begin();
//	int num = 0;
//	int flag = 1;
//	if (*it == '+' || *it == '-' || ('0' <= *it && *it <= '9'))
//	{
//		if (*it == '+')
//		{
//			it++;
//			flag = 1;
//		}
//		if (*it == '-')
//		{
//			it++;
//			flag = -1;
//		}
//		if ('0' <= *it && *it <= '9')
//		{
//			while (it != str.end())
//			{
//				if ('0' <= *it && *it <= '9')
//					num = num * 10 + *it - '0';
//				else
//					return 0;
//				it++;
//			}
//			return num * flag;
//		}
//		
//	}
//	else
//		return 0;
//}
//void test()
//{
//	string s = "-123";
//	cout << s << endl;
//	int t = StrToInt(s);
//	cout << t;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//void test()
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//}

/*连续子数组地最大和
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).
示例1
	输入
		[1,-2,3,10,-4,7,2,-5]
	返回值
		18
说明
	输入的数组为{1,-2,3,10,—4,7,2,一5}，和最大的子数组为{3,10,一4,7,2}，因此输出为该子数组的和 18。
	https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2&tab=answerKey
*/
//int FindGreatestSumOfSubArray(vector<int> array)
//{
//	/*for (int i = 0; i < array.size(); i++)
//		cout << array[i] << " ";
//	cout << endl;*/
//	int ret = array[0];
//	int t = 0;
//	for (const int &d : array)
//	{
//		cout << d << " ";
//		if (t + d < 0)
//			t = 0;
//		else
//		{
//			t += d;
//		}
//		ret = max(ret, t);
//	}
//	if (t > 0)//避免出现vector<int>中数据皆为负地情况
//		return ret;
//	//max_element（）返回的是范围内最大值的地址或迭代器
//	return *max_element(array.begin(),array.end());
//}
//
//void test()
//{
//	vector<int> t = { -2, -8, -1, -5, -9 };
//	/*for (int i = 0; i < t.size(); i++)
//		cout << t[i] << " ";
//	cout << endl;*/
//	int x = FindGreatestSumOfSubArray(t);
//	cout << "max val = " << x << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*  电话号码的字母组合  该题可结合调试领悟其优秀之处！！！！！！！！！！！！！！！！
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

 示例 1：
	输入：digits = "23"
	输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

 示例 2：
	输入：digits = ""
	输出：[]
	   
 示例 3：
	输入：digits = "2"
	输出：["a","b","c"]
  
  提示：
  0 <= digits.length <= 4
  digits[i] 是范围 ['2', '9'] 的一个数字。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//vector<string> ans;
//string t;
//const string lettersMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//void backtrack(string &digits, int index)
//{
//	if (index == digits.size())
//	{
//		ans.push_back(t);
//		return;
//	}
//	int data = digits[index] - '0';
//	string s = lettersMap[data];
//	for (int i = 0; i < s.size(); i++)
//	{
//		t.push_back(s[i]);
//		backtrack(digits, index + 1);
//		t.pop_back();//用于回溯，t的值每赋进ans后，退出递归就需为其当前层尾删并退回至上一层
//	}
//}
//vector<string> letterCombinations(string digits) 
//{
//	//采用迭代的算法
//	ans.clear();
//	t.clear();
//	if (digits == "")
//		return ans;
//	backtrack(digits, 0);
//	return ans;
//}
//
//void test()
//{
//	string dig = "32";
//	vector<string> anwser = letterCombinations(dig);
//	for (const string& str : anwser)
//		cout << str << " ";
//	cout << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/* 数组中出现次数超过一半的数字
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。1<=数组长度<=50000
示例1
	输入
		[1,2,3,2,2,2,5,4,2]
	返回值
		2
示例2
	输入
		[3,3,3,3,2,2,2]
	返回值
		3
示例3
	输入
		[1]
	返回值
		1
https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey
*/
//int MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	assert(1 <= numbers.size() && numbers.size() <= 50000);
//	cout << numbers.size() / 2 << endl;
//	/* 利用数组，有bug */
//	/*if (numbers.size() == 1)
//		return numbers[0];
//	int arr[256] = { 0 };
//	for (const int &n : numbers)
//	{
//		arr[n]++;
//	}
//	for (const int &i : numbers)
//	{
//		if (arr[i] > (numbers.size() / 2))
//			return i;
//	}
//	return -1;*/
//
//	/* 利用map */
//	//map<int, int> allval;
//	////map<int, int>::iterator iter;
//	//for (const int &n : numbers)
//	//{
//	//	allval[n]++;//此程序可以实现insert功能
//	//	//iter = allval.find(n);
//	//	//if (iter == allval.end())//没找到该元素
//	//	//{
//	//	//	allval.insert(map<int, int>::value_type(n, 1));
//	//	//}
//	//	//else
//	//	//{
//	//	//	allval[n]++;
//	//	//}
//	//	
//	//}
//	//for (const int &n : numbers)
//	//{
//	//	if (allval[n] > numbers.size() / 2)
//	//		return n;
//	//}
//	//return -1;
//
//	/* 利用 unordered_map */
//	unordered_map<int, int> allval;
//	for (const int& n : numbers)
//		allval[n]++;
//	for (const int& n : numbers)
//	{
//		if (allval[n] > numbers.size() / 2)
//			return n;
//	}
//	return -1;
//}
//
//void test()
//{
//	vector<int> nums = { 3, 2, 3, 2, 2, 2, 5, 8, 2 };
//	/*vector<int> nums = { 1 };*/
//	int data = MoreThanHalfNum_Solution(nums);
//	cout << data << endl;
//	//map<int, int> try1;
//	//try1.insert(map<int, int>::value_type (1, 250));
//	//try1.insert(map<int, int>::value_type(2, 666));
//	//try1.insert(map<int, int>::value_type(6, 777));
//	///*try1.insert(1, 1);
//	//try1.insert(2, 28);*/
//	///*map<int, int>::iterator iter;
//	//for (iter = try1.begin(); iter != try1.end(); iter++)
//	//{
//	//	cout << iter->first << ' ' << iter->second << endl;
//	//	if (iter->first == 2 && iter->second != 0)
//	//		try1.insert(map<int, int>::value_type(iter->first, 100));
//	//	cout << iter->first << ' ' << iter->second << endl;
//	//}*/
//	//cout << try1.size() << endl;
//	//for (int i = 1; i <= try1.size(); i++)
//	//{
//	//	try1[i] = 123;
//	//	cout << try1[i] << " ";
//	//}
//	//	
//	//cout << endl;
//	//map<int, int>::iterator iter;
//	//iter = try1.find(3);
//	//if (iter != try1.end())
//	//	try1[3] = 888;
//	//cout << try1[3] << " ";
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/* 只出现一次的数字 III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

  示例 1：
	 输入：nums = [1,2,1,3,2,5]
	 输出：[3,5]
	 解释：[5, 3] 也是有效的答案。

  示例 2：
	输入：nums = [-1,0]
	输出：[-1,0]

  示例 3：
	  输入：nums = [0,1]
	  输出：[1,0]

  提示：
	 2 <= nums.length <= 3 * 104
	  -231 <= nums[i] <= 231 - 1
  除两个只出现一次的整数外，nums 中的其他数字都出现两次

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/single-number-iii
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//vector<int> singleNumber(vector<int>& nums)
//{
//	/*if (nums.size() == 2)
//		return nums;
//	map<int, int> val;
//	vector<int> res;
//	for (const int &n : nums)
//		val[n]++;
//	for (const int &n : nums)
//	{
//		if (val[n] == 1)
//			res.push_back(n);
//	}
//	return res;*/
//	
//	int ret = 0;
//	for (int n : nums)
//		ret ^= n;
//	int div = 1;
//	while ((div & ret) == 0)
//		div <<= 1;
//	int a = 0, b = 0;
//	for (int n : nums)
//		if (div & n)
//			a ^= n;
//		else
//			b ^= n;
//	return vector < int > {a, b};
//	
//}
//void test()
//{
//	vector<int> nums = { 1, 2, 1, 3, 2, 5 };
//	for (const int &n : nums)
//		cout << n << " ";
//	cout << endl;
//	vector<int> data = singleNumber(nums);
//	for (const int &n : data)
//		cout << n << " ";
//	cout << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/* 只出现一次的数字 II
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 示例 1：
	输入：nums = [2,2,3,2]
	输出：3
 示例 2：
	 输入：nums = [0,1,0,1,0,1,99]
	 输出：99
  
  提示：
  1 <= nums.length <= 3 * 104
  -231 <= nums[i] <= 231 - 1

  nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/single-number-ii
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//int singleNumber(vector<int>& nums) 
//{
//	/* 哈希表 */
//	map<int, int> val;  // unordered_map 亦可
//	int res;
//	for (const int &n : nums)
//		val[n]++;
//	for (const int &n : nums)
//	{
//		if (val[n] == 1)
//			res = n;
//	}
//	return res;
//
//}
//void test()
//{
//	vector<int> nums = { 2,2,3,2 };
//	for (const int &n : nums)
//		cout << n << " ";
//	cout << endl;
//	int data = singleNumber(nums);
//	cout << data << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*  只出现一次的数字 I
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int singleNumber(vector<int>& nums) 
{
	int res = 0;
	for (const int &n : nums)
		res ^= n;
	return res;

}
void test()
{
	vector<int> nums = { 4, 1, 2, 1, 2 };
	int res = singleNumber(nums);
	cout << res << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}

/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成

 说明:
 为什么返回数值是整数，但输出的答案是数组呢?
 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 你可以想象内部操作如下:
 // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 int len = removeDuplicates(nums);
 // 在函数里修改输入数组对于调用者是可见的。
 // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
 for (int i = 0; i < len; i++) {
     print(nums[i]);
	 }
	  
	示例 1：
	  输入：nums = [1,1,2]
	  输出：2, nums = [1,2]
	  解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

	示例 2：
	  输入：nums = [0,0,1,1,1,2,2,3,3,4]
	  输出：5, nums = [0,1,2,3,4]
	  解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。

	提示：
	   0 <= nums.length <= 3 * 104
	   -104 <= nums[i] <= 104
	   nums 已按升序排列
	    

		来源：力扣（LeetCode）
		链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
		著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//int removeDuplicates(vector<int>& nums) 
//{
//	auto it = nums.begin();
//	while (it != nums.end() - 1)
//	{
//		if (*it == *(it + 1))
//			it = nums.erase(it);
//		else
//			++it;
//	}
//	return nums.size();
//}
//void test()
//{
//	vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	/*for (const int &n : nums)
//		cout << n << " ";*/
//	//for (int i = 0; i < nums.size(); i++)
//	//	cout << nums[i] << " ";
//	int len = removeDuplicates(nums);
//	cout << "len = " << len << endl;
//	for (const int &n : nums)
//		cout << n << " ";
//	/*vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}*/
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

/*  杨辉三角
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//vector<vector<int>> generate(int numRows) 
//{
//	vector<vector<int>> res;
//	res.resize(numRows);
//	for (size_t i = 0; i < numRows; i++)
//	{
//		res[i].resize(i + 1, 0);
//		res[i][0] = 1;
//		res[i][i] = 1;
//	}
//	for (size_t i = 0; i < res.size(); i++)
//	{
//		for (size_t j = 0; j < res[i].size(); j++)
//		{
//			if (res[i][j] == 0)
//			{
//				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
//			}
//		}
//	}
//	return res;
//}
//void test()
//{
//	int n = 5;
//	vector<vector<int>> data = generate(n);
//	for (const vector<int> &d : data)
//	{
//		for (const int &m : d)
//			cout << m << " ";
//		cout << endl;
//	}
//
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}