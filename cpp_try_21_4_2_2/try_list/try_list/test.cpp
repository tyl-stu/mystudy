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

/*  list �Ĺ��캯��
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

/* ��������ʹ�� */
//void test()
//{
//	string s = "12345";
//	list<char> lst(s.begin(), s.end());
//
//	list<char>::iterator it = lst.begin();
//	while (it != lst.end())  // �ɶ���д
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
//	//��Χfor
//	for (auto& e : lst2)
//	{
//		cout << e << " ";
//		e = 'c';
//	}cout << endl;
//
//}

/* ���ֲ����ʹ�� */
//void test()
//{
//	//insert , emplace �������
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
//	/* ���ֲ��룬�����ǵ���
//	 void insert (iterator position, InputIterator first, InputIterator last);
//	*/
//	list<int> copy = lst;
//	lst.insert(lst.end(), copy.begin(), copy.end());//β����lstԭ������
//
//	for (auto& e : lst)
//		cout << e << " ";
//	cout << endl;
//
//	//���벻�ᵼ�µ�������ʧЧ,������itָ������ݸ��ģ�������ָ�����ݲ��ᷢ���仯
//	cout << *it << endl;
//	*it = 5;
//	cout << *it << endl;
//
//	//ɾ����������ʧЧ����Ϊ������ָ��Ŀռ���ʧЧ
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
//	// splice(a,b) -- ��b������ƴ�ӵ�a�ϣ���b������Ҳ���ÿ�
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
//	//lst.sort(); //�Զ������ݽ�������,Ĭ�ϴ�С����
//	lst.sort(compareList);//ʹ���Ϊ�Ӵ�С
//	printList(lst);
//	lst.unique(); // �������ݱ������򣬷���ú������ñȽ�С
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
//	lst2.merge(lst);//����������붼���򣬸������ᱨ��,������ϲ����ϲ��󣬱��ϲ��Ķ������ݻ��ÿ�
//	printList(lst2);
//}

/* reverse��a,b�� - �� a �� b ǰ������Ԫ�����ã�����a,��������b�� */
void test()
{
	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar + n);
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
	// reverse��a,b�� - �� a �� b ǰ������Ԫ�����ã�����a,��������b��
	reverse(mylist.begin(), pos);//4 3 2 1 0 5 6 7 8 9
	reverse(pos, mylist.end());//4 3 2 1 0 9 8 7 6 5
	list<int>::const_reverse_iterator crit = mylist.crbegin();//���������
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