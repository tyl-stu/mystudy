#include<iostream>
using namespace std;
#include<string>

/*
default (1)	
string();
copy (2)	
string (const string& str);
substring (3)	
string (const string& str, size_t pos, size_t len = npos);
from c-string (4)	
string (const char* s);
from sequence (5)	
string (const char* s, size_t n);
fill (6)	
string (size_t n, char c);
range (7)	
template <class InputIterator>
string  (InputIterator first, InputIterator last);
  */
/*创建对象*/
//void test()
//{
//	string s0("this is a girl!");
//	//创建空的string 对象
//	string s1;
//	string copy(s0);//此时copy为一个string对象
//	string s2("abcde");
//	string substr(s2, 1, 6);//此时substr为一个string对象,越界时会拿到能拿的数据
//	string s3("12345678",5);
//	string s4(10, 'a');//创建对象
//
//	cout << "s0:" << copy << endl << "s1:" << s1 << endl << "s2:" << s2 << endl
//		<< "s3:" << s3 << endl << "s4:" << s4 << endl << "s5:" << substr << endl;
//
//	string s6 = "ahhh";//单参构造的隐式类型转换
//	cout << "s6:" << s6 << endl;
//
//

/*Element access:(访问元素)
operator[]   Get character of string (public member function )
at  Get character in string (public member function )
back  Access last character (public member function )
front Access first character (public member function )*/
//void test()
//{
//	const string str = "12345";
//	string str2 = "12345";
//	//const对象，调用接口 const char& operator[] (size_t pos) const;
//	char ch = str[3];
//	const char & ref = str[3];
//	//str[3] = 'a';//const对象不能修改
//	cout << str << "   " << ch << "   " << ref << endl;
//
//	//非const对象，调用接口 char& operator[] (size_t pos);
//	char ch2 = str2[3];//ch2是赋值，将str2中位置3的内容赋值给ch2 -- 4 
//	char& ch3 = str2[3];//ch3为引用，引用了str2中位置3的字符 -- a
//	str2[3] = 'a';
//	cout << str2 << "   " << ch2 << "    " << ch3 << endl;
//	str2.at(3) = 'b';
//	cout << str2 << "   " << ch2 << "    " << ch3 << endl;
//
//	//[] 越界会报错
//	//char ch3 = str2[10];
//	// at 越界会抛异常
//	//char ch3 = str2.at(10);
//	char c1 = str2.back();
//	char c2 = str2.front();
//	cout << "c1:" << c1 << endl << "c2:" << c2 << endl;
//}

/*
	string的访问方式：
	1、for循环 + operator[]
	2、迭代器
	3、范围for
	这三种方式都可修改string对象的内容
*/

/*正向迭代器*/
//void test()
//{
//	//正向迭代器 类似指针
//
//	string str = "12345";
//	//起始位置的迭代器
//	string::iterator it = str.begin();
//	for (; it != str.end(); ++it)
//	{
//		//迭代器的解引用
//		cout << *it << " ";
//	}
//
//	const string str2 = "abcde";
//	//只读迭代器
//	string::const_iterator it2 = str2.begin();
//	while (it2!=str2.end())
//	{
//		//只读迭代器不能修改内容
//		cout << *it2 << " ";
//		++it2;
//	}
//}

/*反向迭代器*/
//void test()
//{
//	//反向迭代器
//	string str = "12345";
//	//末尾位置的迭代器
//	string::reverse_iterator it = str.rbegin();
//	for (; it != str.rend(); ++it)
//	{
//		//++it -- 反向移动
//		//迭代器的解引用
//		cout << *it << " ";//54321
//	}cout << endl;
//
//	const string str2 = "abcde";
//	//只读迭代器
//	//string::const_reverse_iterator it2 = str2.rbegin();
//	auto it2 = str2.rbegin();
//	while (it2 != str2.rend())
//	{
//		//只读迭代器不能修改内容
//		cout << *it2 << " ";//edcba
//		++it2;
//	}cout << endl;
//
//	string str3 = "12345";
//	//末尾位置的迭代器
//	string::const_iterator cit = str3.cbegin();
//	//auto cit = str3.cbegin();
//	for (; cit != str3.cend(); ++cit)
//	{
//		//++it -- 反向移动
//		//迭代器的解引用
//		cout << *cit << " ";//54321
//	}cout << endl;
//
//	const string str4 = "abcde";
//	//只读迭代器
//	string::const_reverse_iterator it4 = str4.crbegin();
//	//auto it4 = str4.crbegin();
//	while (it4 != str4.crend())
//	{
//		//只读迭代器不能修改内容
//		cout << *it4 << " ";//edcba
//		++it4;
//	}cout << endl;
//}

/*范围for的使用 -- 遍历string对象*/
//void test()
//{
	////范围for:可以遍历范围确定的序列
	//int arr[] = { 1, 2, 3, 4, 5 };
	//for (const auto& e : arr)
	//{
	//	cout << e << " ";
	//}cout << endl;
//
//	string str = "abcde";
//	//范围 for :实际上是通过迭代器实现的，
//	//			支持迭代器访问的自定义类型都可以支持范围for
//	for (auto& ch : str)
//	{
//		cout << ch << " ";
//	}cout << endl;
//}

/*for循环 + operator[]*/
//void test()
//{
//	string str = "abcde";
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		cout << str[i] << " ";
//	}cout << endl;
//}

/*size、resize*/
//void test()
//{
//	string str;
//	cout << str.size() << endl;
//	//reszie:修改有效字符的个数
//	str.resize(10);
//	cout << str.size() << endl;
//	string str2 = "123";
//	cout << str2.size() << endl;
//	//reszie:修改有效字符的个数
//	str2.resize(10);
//	cout << str2.size() << endl;
//	str2.resize(2);//只保留前两个字符
//	cout << str2.size() << endl << str2 << endl;
//	str2.resize(5,'a');//给需要填充的位置，填充a,一般默认填充0
//	cout << str2 << endl;
//}

/*capacity、reserve、clear、shrink_to_fit*/
//void test()
//{
//	string str = "123";
//	//capacity:当前string 中最多可以存放的元素个数
//	//容量不够时，会增容,增容之后的容量为2的整幂次减1
//	int cap = str.capacity();
//	cout << cap << endl;//15
//	str.resize(20);
//	cap = str.capacity();
//	cout << cap << endl;//31
//
//	//reserve:修改容量,只能增加容量，不能减小容量
//	//且不影响size,即对象的长度
//	str.reserve(60);
//	int sz = str.size();
//	cap = str.capacity();
//	cout << sz << "  " << cap << endl;// 20 63
//	str.reserve(10);
//	sz = str.size();
//	cap = str.capacity();
//	cout << sz << "  " << cap << endl;// 20 63
//
//	//clear：清空有效字符
//	str.clear();
//	sz = str.size();
//	cap = str.capacity();
//	cout << sz << "  " << cap << endl;// 0 63
//
//	//shrink_to_fit:将对象的容量缩小至合适的大小
//	str.shrink_to_fit();
//	sz = str.size();
//	cap = str.capacity();
//	cout << sz << "  " << cap << endl;// 0 15
//}

//void test()
//{
//	string str;
//	//提前开好空间，避免频繁的增容，提高代码的效率
//	str.reserve(200);
//	int cap = str.capacity();
//	int sz = str.size();
//	cout << sz << "  " << cap << endl;
//	for (int i = 0; i < 200; ++i)
//	{
//		str.push_back('a');
//		if (cap != str.capacity())
//		{
//			cap = str.capacity();
//			sz = str.size();
//			cout << sz << "  " << cap << endl;
//			cout << str << endl;
//		}
//	}
//}

/*str.operator+=('5')  -- 相当于尾插，与str.append()功能重合*/
//void test()
//{
//	string str;
//	string str2 = "123";
//	str += str2;//123
//	str += "abc";//123abc
//	str += '4';//123abc4
//	str.operator+=('5');//123abc45
//	cout << str << endl;
//
//	string str3 = "hjk";
//	/*string(1)
//		string& append(const string& str);*/
//	str.append(str3);
//	cout << str << endl;//123abc45hjk
//	/*substring(2)
//		string& append(const string& str, size_t subpos, size_t sublen);
//	*/
//	str.append("uio", 1, 1);
//	cout << str << endl;//123abc45hjki
//	/*c - string(3)
//		string& append(const char* s);*/
//	str.append("asd"); 
//	cout << str << endl;//123abc45hjkiasd
//	/*buffer(4)
//		string& append(const char* s, size_t n);*/
//	str.append("369",4);
//	cout << str << endl;//123abc45hjkiasd369
//	/*fill(5)
//		string& append(size_t n, char c);*/
//	str.append(3,'y');
//	cout << str << endl;//123abc45hjkiasd369 yyy
//	/*range(6)
//		template <class InputIterator>
//	string& append(InputIterator first, InputIterator last);
//	*/
//	char arr[] = "abcdefg";
//	//sizeof(arr) / sizeof(arr[0])=8,包含'\0'
//	//strlen(arr) = 7
//	str.append(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	cout << str << endl;//123abc45hjkiasd369 yyyabcdefg
//	str.append(str2.begin(), str2.end());
//	cout << str << endl;//123abc45hjkiasd369 yyyabcdefg 123
//}

/*赋值操作，等号，assign()*/
//void test()
//{
//	string str;
//	string str2 = "123";
//	/*string(1)
//		string& assign(const string& str);*/
//	str.assign(str2);
//	cout << str << endl;//123
//	/*substring(2)
//		string& assign(const string& str, size_t subpos, size_t sublen);
//	*/
//	str.assign(str2,1,1);
//	cout << str << endl;//2
//	/*c - string(3)
//		string& assign(const char* s);*/
//	str.assign("abc");
//	cout << str << endl;//abc
//	/*buffer(4)
//		string& assign(const char* s, size_t n);*/
//	str.assign("abcde",2);
//	cout << str << endl;//ab
//	/*fill(5)
//		string& assign(size_t n, char c);*/
//	str.assign(3,'a');
//	cout << str << endl;//aaa
//	/*range(6)
//		template <class InputIterator>
//	string& assign(InputIterator first, InputIterator last);*/
//	str.assign(++str2.begin(),str2.end());
//	cout << str << endl;//23
//}

/*insert()*/
//void test()
//{
//	string str;
//	string str2 = "123";
//	/*string(1)
//		string& insert(size_t pos, const string& str);*/
//	str.insert(0, "abc");
//	cout << str << endl;//abc
//	/*substring(2)
//		string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
//	*/
//	str.insert(1,str2,1,2);
//	cout << str << endl;//a23bc
//	/*c - string(3)
//		string& insert(size_t pos, const char* s);*/
//	str.insert(1,"54");
//	cout << str << endl;//a5423bc
//	/*buffer(4)
//		string& insert(size_t pos, const char* s, size_t n);*/
//	str.insert(3, "3693",2);
//	cout << str << endl;//a543623bc
//	/*fill(5)
//		string& insert(size_t pos, size_t n, char c);
//	void insert(iterator p, size_t n, char c);*/
//	str.insert(str.begin(), 2, 'c');
//	cout << str << endl;//cca543623bc
//	/*single character(6)
//		iterator insert(iterator p, char c);*/
//	str.insert(++str.begin(), 'b');
//	cout << str << endl;//cbca543623bc
//	/*range(7)
//		template <class InputIterator>
//	void insert(iterator p, InputIterator first, InputIterator last);
//	*/
//	str.insert(str.end(), str2.begin(), --str2.end());
//	cout << str << endl;//cbca543623bc12
//}

/*substr()*/
//void test()
//{
//	//str.substr(a,b):先是将str从位置a处截取，然后再从截取后的字符对象的位置b前的内容，此为最后结果
//	string str = "this is a tripple 802.11";
//	string sub = str.substr(10, 7);
//	cout << "sub : " << sub << endl;
//}

/*find()*/
//void test()
//{
//	//find():正着找目标字符的位置
//	string str = "http://cplusplus.com/reference/string/string/find/";
//	/*string(1)
//		size_t find(const string& str, size_t pos = 0) const;*/
//	size_t pos = str.find("://");//找到满足条件字符的第一个出现位置
//	size_t end = str.find("/", pos+3);//从 :// 后开始找起
//	cout << "pos:" << pos << "end:" << end << endl;
//	string sub = str.substr(pos+3,end-pos-3);
//	cout << sub << endl;
//	/*c - string(2)
//		size_t find(const char* s, size_t pos = 0) const;*/
//	string str2 = "://nihao??//..??hj";
//	pos = str2.find("??", 1);
//	cout << pos << endl;
//	/*buffer(3)//返回s在字符串中第一次出现的位置（从pos开始查找，长度为n）
//		size_t find(const char* s, size_t pos, size_t n) const;*/
//	pos = str2.find("??sds", 10,2);
//	cout << pos << endl;
//	/*character(4)
//		size_t find(char c, size_t pos = 0) const;*/
//	pos = str2.find('j', 1);
//	cout << pos << endl;
//
//	//rfind() -- 倒着找目标字符的位置
//	string str3 = "./so you are awesome!.";
//	cout << "str3.size():" << str3.size() << endl << "str3.length():" << str3.length() << endl;
//	/*string(1)
//		size_t rfind(const string& str, size_t pos = npos) const;*/
//	size_t rpos = str3.rfind(".", 40);
//	cout << "rpos:" << rpos << endl;
//	/*c - string(2)
//		size_t rfind(const char* s, size_t pos = npos) const;*/
//	rpos = str3.rfind("/s", 40);
//	cout << "rpos:" << rpos << endl;
//	/*buffer(3)返回s在字符串中第一次出现的位置（从pos开始查找，从str中找s的前n个字符首次出现的位置）
//		size_t rfind(const char* s, size_t pos, size_t n) const;*/
//	rpos = str3.rfind("/s ni hao", 40 , 2);
//	cout << "rpos:" << rpos << endl;
//	/*character(4)
//		size_t rfind(char c, size_t pos = npos) const;*/
//	rpos = str3.rfind('s', 20);
//	cout << "rpos:" << rpos << endl;
//
//	//find_first_of(str):找到str中任意一个字符第一次出现的位置
//	rpos = str3.find_first_of("abcs");
//	cout << "rpos:" << rpos << endl;
//	//find_last_of(str):找到str中任意一个字符最后一次出现的位置
//	rpos = str3.find_last_of("abcs");
//	cout << "rpos:" << rpos << endl;
//	//find_first_not_of(str):找到不属于str中任意一个字符第一次出现的位置
//	rpos = str3.find_first_not_of("abcs");
//	cout << "rpos:" << rpos << endl;
//	//find_last_not_of(str):找到不属于str中任意一个字符最后一次出现的位置
//	rpos = str3.find_last_not_of("abcs");
//	cout << "rpos:" << rpos << endl;
//}

/*关系运算符，getline*/
//void test()
//{
//	//关系运算符，满足条件返回1（true），不满足返回0(false)
//	string str = "12345";
//	string str2 = "ab";
//	bool ret = str == str2;
//	cout << ret << endl;
//	ret = str > str2;
//	cout << ret << endl;
//	ret = str2 > str;
//	cout << ret << endl;
//
//	cout << str << endl;
//	//cin:遇到空格、换行结束
//	//cin >> str2;
//	cout << str2 << endl;
//	//getline():遇到换行结束,遇到空格不会结束，此为和cin区别
//	getline(cin, str2);
//	cout << str2 << endl;
//}

/*仅仅反转字母  https://leetcode-cn.com/problems/reverse-only-letters/
给定一个字符串 S，返回 “反转后的” 字符串，其中不是
字母的字符都保留在原地，而所有字母的位置发生反转。*/
//class Solution {
//public:
//
//	bool isLetter(const char &ch)
//	{
//		return (ch >= 'A'&& ch <= 'Z') ||
//			(ch >= 'a' && ch <= 'z');
//	}
//
//	string reverseOnlyLetters(string S) {
//		/*两种方法皆可*/
//		/*if (S.empty())
//			return S;
//		string::iterator begin = S.begin();
//		string::iterator end = --S.end();
//		while (begin < end)
//		{
//			while (begin < end && !isLetter(*begin))
//				++begin;
//			while (begin < end && !isLetter(*end))
//				--end;
//			swap(*begin, *end);
//			++begin;
//			--end;
//		}
//		return S;*/
//
//		int start = 0;
//		int end = S.size() - 1;
//		while (start < end)
//		{
//			//找到有效字符
//			while (start < end && !isLetter(S[start]))
//				++start;
//			while (start < end && !isLetter(S[end]))
//				--end;
//			//交换
//			swap(S[start], S[end]);
//			++start;
//			--end;
//		}
//		return S;
//	}
//
//};

/*字符串中的第一个唯一字符  https://leetcode-cn.com/problems/first-unique-character-in-a-string/
给定一个字符串，找到它的第一个不重复的字符，并返回它的索
引。如果不存在，则返回 -1。*/
//class Solution {
//public:
//	int firstUniqChar(string s) {
//
		////计数数组
		//int count[26] = { 0 };
		////统计次数
		//for (const char& ch : s)//范围for的使用
		//	count[ch - 'a']++;
//		for (int i = 0; i<s.size(); i++)
//		{
//			//判断次数是否为1
//			if (count[s[i] - 'a'] == 1)
//				return i;
//		}
//		return -1;
//
//
		 //////计数数组
		 ////int count[128]={0};
		 //////统计次数
		 ////for(const char& ch : s)
		 ////    count[ch]++;
//		// for(int i=0;i<s.size();i++)
//		// {
//		//     //判断次数是否为1
//		//     if(count[s[i]] == 1)
//		//         return i;
//		// }
//		// return -1;
//
//	}
//};

/*计算字符串最后一个单词的长度，单词以空格隔开。https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&rp=5&ru=%2Factivity%2Foj&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tab=answerKey
输入描述:
输入一行，代表要计算的字符串，非空，长度小于5000。
输出描述:
输出一个整数，表示输入字符串最后一个单词的长度。
输入
hello nowcoder
输出
8*/
//void test()
//{
//	string str;
//	getline(cin, str);
//	int pos = str.rfind(' ', str.size());
//	cout << pos << endl;
//	int len = str.size() - 1 - pos;
//	cout << len << endl;
//}

/*验证回文串  https://leetcode-cn.com/problems/valid-palindrome/
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
*/
//bool isValid(const char &ch)
//{
//	//只判断是否为小写字母，数字
//	return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
//}
//bool isPalindrome(string s) {
//	//预处理：吧大写 -> 小写
//	for (char &ch : s)//范围for的使用
//	{
//		if (ch >= 'A' && ch <= 'Z')
//			ch += 32;
//	}
//	int begin = 0;
//	int end = s.size() - 1;
//	while (begin<end)
//	{
//		//遍历，搜索有效的字符
//		while (begin < end && !isValid(s[begin]))
//			++begin;
//		while (begin < end && !isValid(s[end]))
//			--end;
//		if (s[begin] != s[end])
//			return false;
//		begin++;
//		end--;
//	}
//	return true;
//}
//
//void test()
//{
//	string str = "race a car";
//	cout << isPalindrome(str) << endl;
//}


/*字符串相加 https://leetcode-cn.com/problems/add-strings/
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

提示：
num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
*/
void addStrings(string num1, string num2) 
{
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	//进位
	int step = 0;
	//string ret1;//用于方法二
	string ret;
	//判断需要的长度
	int len = end1 > end2 ? end1 + 2 : end2 + 2;
	//增容
	ret.reserve(len);
	while (end1 >= 0 || end2 >= 0)
	{
		int cur = step;
		if (end1 >= 0)
			cur += num1[end1] - '0';
		if (end2 >= 0)
			cur += num2[end2] - '0';
		if (cur >= 10)
		{
			cur -= 10;
			step = 1;
		}
		else
			step = 0;
		//保存当前位的结果  头插
		//ret.insert(0,1,cur + '0'); //o(n*n) -- n平方的操作量
		//尾插  //o(n)  
		//方法一    不需要进行逆置
		/*ret1 = ret;
		ret = to_string(cur);
		ret += ret1;*/
		//方法二    需要逆置
		ret += cur + '0';//此种是逆序，需要逆置
		end1--;
		end2--;
	}
	if (step == 1)
	{
		//ret.insert(0, 1, '1');
		/*//方法一：不需要逆置
		ret1 = ret;
		ret = to_string(1);
		ret += ret1;*/
		ret += '1';//方法二：此种是逆序，需要逆置
	}
	reverse(ret.begin(), ret.end());
	cout << ret;
}

void test()
{
	string n1 = "1934";
	string n2 = "99";
	addStrings(n1, n2);
}

int main()
{
	test();
	//char a1 = '1';
	/*int cur = 9;
	string b = "23";
	string a = to_string(cur);
	a += b;
	cout << a;*/
	system("pause");
	return 0;
}

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