#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<string>

template<class T>
void printList(const list<T>& lst)
{
	for (const auto& e : lst)
		cout << e << " ";
	cout << endl;
}

/*  list 的构造函数
default (1)
explicit list (const allocator_type& alloc = allocator_type());
fill (2)
explicit list (size_type n, const value_type& val = value_type(),
const allocator_type& alloc = allocator_type());
range (3)
template <class InputIterator>
list (InputIterator first, InputIterator last,
const allocator_type& alloc = allocator_type());
copy (4)
list (const list& x);
*/
//void test()
//{
//	list<int> lst;
//	list<char> lst2;
//
//	list<int> lst3(3, 6);
//
//	string s = "hello";
//	list<char> lst4(s.begin(), s.end());
//	char arr[] = "abcde";
//	list<char> lst5(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	vector<char> v(s.begin(), s.end());
//	list<char> lst6(v.begin(), v.end());
//
//	list<char> lst7(lst4);
//}

/* 迭代器的使用 */
//void test()
//{
//	string s = "12345";
//	list<char> lst(s.begin(), s.end());
//
//	list<char>::iterator it = lst.begin();
//	while (it != lst.end())  // 可读可写
//	{
//		cout << *it << " ";
//		*it = 'a';
//		it++;
//	}cout << endl;
//
//	list<char>::const_iterator cit = lst.cbegin();
//	while (cit != lst.cend())
//	{
//		cout << *cit << " ";
//		cit++;
//	}cout << endl;
//
//	list<char> lst2(s.begin(), s.end());
//	list<char>::reverse_iterator rit = lst2.rbegin();
//	while (rit != lst2.rend())
//	{
//		cout << *rit << " ";
//		*rit = 'b';
//		rit++;
//	}cout << endl;
//
//	list<char> lst3(s.begin(), s.end());
//	list<char>::reverse_iterator rit2 = lst3.rend();
//	rit2--;
//	while (rit2 != lst3.rbegin())
//	{
//		cout << *rit2 << " ";
//		*rit2 = 'b';
//		rit2--;
//	}
//	cout << *rit2 <<endl;
//
//	//范围for
//	for (auto& e : lst2)
//	{
//		cout << e << " ";
//		e = 'c';
//	}cout << endl;
//
//}

/* 各种插入的使用 */
//void test()
//{
//	//insert , emplace 插入操作
//	list<int> lst;
//	lst.push_back(1);
//	list<int>::iterator it = lst.begin();
//	cout << *it << endl;
//	lst.push_front(2);
//	lst.insert(lst.end(), 6);
//	lst.insert(lst.begin(), 8);
//	lst.emplace(lst.begin(), -1);
//	lst.emplace_back(9);
//	lst.emplace_front(-2);
//
//	/* 这种插入，不能是倒序
//	 void insert (iterator position, InputIterator first, InputIterator last);
//	*/
//	list<int> copy = lst;
//	lst.insert(lst.end(), copy.begin(), copy.end());//尾插了lst原有数据
//
//	for (auto& e : lst)
//		cout << e << " ";
//	cout << endl;
//
//	//插入不会导致迭代器的失效,若不对it指向的内容更改，则其所指的内容不会发生变化
//	cout << *it << endl;
//	*it = 5;
//	cout << *it << endl;
//
//	//删除迭代器会失效，因为迭代器指向的空间已失效
//	lst.erase(it);
//	cout << *it << endl;
//}

bool compareList(const int& a, const int& b)
{
	return a > b;
}

/* splice ,remove ,sort ,unique.... */
//void test()
//{
//	string s = "123";
//	string s2 = "abc";
//	list<char> lst(s.begin(), s.end());
//	list<char> lst2(s2.begin(), s2.end());
//
//	// splice(a,b) -- 将b的内容拼接到a上，但b的内容也会置空
//	printList(lst);
//	lst.splice(lst.begin(), lst2, ++lst2.begin(),lst2.end());
//	printList(lst);
//	printList(lst2);
//	lst.remove('b');
//	printList(lst);
//
//	list<char> copy = lst;
//	lst.insert(lst.end(), copy.begin(), copy.end());
//	printList(lst);
//	//lst.sort(); //对对象内容进行排序,默认从小到大
//	lst.sort(compareList);//使其变为从大到小
//	printList(lst);
//	lst.unique(); // 对象内容必须有序，否则该函数作用比较小
//	printList(lst);
//}

/* sort ,merge */
//void test()
//{
//	int arr[] = { 5, 9 ,6 ,12};
//	int arr2[] = { 8, 10, 15, 21 };
//	list<int> lst(arr, arr + 4);
//	list<int> lst2(arr2, arr2 + 4);
//	lst.sort();
//	lst2.merge(lst);//两个对象必须都有序，负责程序会报错,有序则合并，合并后，被合并的对象内容会置空
//	printList(lst2);
//}

/* reverse（a,b） - 将 a 到 b 前的所有元素逆置（包括a,但不包括b） */
void test()
{
	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar + n);
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
	// reverse（a,b） - 将 a 到 b 前的所有元素逆置（包括a,但不包括b）
	reverse(mylist.begin(), pos);//4 3 2 1 0 5 6 7 8 9
	reverse(pos, mylist.end());//4 3 2 1 0 9 8 7 6 5
	list<int>::const_reverse_iterator crit = mylist.crbegin();//逆向迭代器
	while (crit != mylist.crend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}