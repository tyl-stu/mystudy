#include<iostream>
using namespace std;
#include<string>

//list实现：双向带头的循环链表
template<class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{

	}
};

/* 开始 iterator 和 const iterator 版本 */
///* 非 const 迭代器 */
//template<class T>
//struct ListIterator
//{
//	typedef ListNode<T> Node;
//	typedef ListIterator<T> iterator;
//	//封装节点
//	Node* _node;
//
//	ListIterator(Node* node)
//		:_node(node)
//	{}
//
//	// ++iterator 前置++
//	ListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	// iterator++ 后置++
//	ListIterator<T>& operator++(int)
//	{
//		iterator now(_node);//ListIterator now = _node; 两种方式皆可,等号或括号构造亦皆可
//		//Node* now = _node;这种方式有误，因为 ListIterator(_node) 的构造包含了 Node(node)
//		_node = _node->_next;
//		return now;
//	}
//
//	// --iterator 前置--
//	ListIterator<T>& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	// iterator-- 后置--
//	ListIterator<T>& operator--(int)
//	{
//		iterator now(_node);//ListIterator now = _node; 两种方式皆可,等号或括号构造亦皆可
//		//Node* now = _node;这种方式有误，因为 ListIterator(_node) 的构造包含了 Node(node)
//		_node = _node->_prev;
//		return now;
//	}
//
//	bool operator!=(const ListIterator<T>& it)
//	{
//		return _node != it._node;
//	}
//	bool operator==(const ListIterator<T>& it)
//	{
//		return _node == it._node;
//		// it->_node 是错误的调用,其访问不到对应的_node
//	}
//
//	//it->  ==  T*  -->  ->
//	//场景：T为自定义类型，且包含多个成员
//	//		通过 -> 访问每一个成员
//	T* operator->()
//	{
//		return &_node->_data;
//	}
//	// *iterator
//	T& operator*()
//	{
//		return _node->_data;
//	}
//};
///* const 迭代器 */
//template<class T>
//struct ConstListIterator
//{
//	typedef ListNode<T> Node;
//	typedef ConstListIterator<T> iterator;
//	//封装节点
//	Node* _node;
//
//	ConstListIterator(Node* node)
//		:_node(node)
//	{}
//
//	// ++iterator 前置++
//	ConstListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	// iterator++ 后置++
//	ConstListIterator<T>& operator++(int)
//	{
//		iterator now(_node);//ListIterator now = _node; 两种方式皆可,等号或括号构造亦皆可
//		//Node* now = _node;这种方式有误，因为 ListIterator(_node) 的构造包含了 Node(node)
//		_node = _node->_next;
//		return now;
//	}
//
//	// --iterator 前置--
//	ConstListIterator<T>& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	// iterator-- 后置--
//	ConstListIterator<T>& operator--(int)
//	{
//		iterator now(_node);//ListIterator now = _node; 两种方式皆可,等号或括号构造亦皆可
//		//Node* now = _node;这种方式有误，因为 ListIterator(_node) 的构造包含了 Node(node)
//		_node = _node->_prev;
//		return now;
//	}
//
//	bool operator!=(const ConstListIterator<T>& it)
//	{
//		return _node != it._node;
//	}
//	bool operator==(const ConstListIterator<T>& it)
//	{
//		return _node == it._node;
//		// it->_node 是错误的调用,其访问不到对应的_node
//	}
//
//	//it->  ==  T*  -->  ->
//	//场景：T为自定义类型，且包含多个成员
//	//		通过 -> 访问每一个成员
//	const T* operator->()
//	{
//		return &_node->_data;
//	}
//	// *iterator
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//};

//迭代器类型
template<class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	typedef Self iterator;
	//封装节点
	Node* _node;

	ListIterator(Node* node)
		:_node(node)
	{}

	// ++iterator 前置++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	// iterator++ 后置++
	Self& operator++(int)
	{
		Self now(_node);
		//iterator now(_node);//ListIterator now = _node; 两种方式皆可,等号或括号构造亦皆可
		//Node* now = _node;这种方式有误，因为 ListIterator(_node) 的构造包含了 Node(node)
		_node = _node->_next;
		return now; 
	}

	// --iterator 前置--
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	// iterator-- 后置--
	Self& operator--(int)
	{
		Self now(_node);
		//iterator now(_node);//ListIterator now = _node; 两种方式皆可,等号或括号构造亦皆可
		//Node* now = _node;这种方式有误，因为 ListIterator(_node) 的构造包含了 Node(node)
		_node = _node->_prev;
		return now;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	bool operator==(const Self& it)
	{
		return _node == it._node;
		// it->_node 是错误的调用,其访问不到对应的_node
	}

	//it->  ==  T*  -->  ->
	//场景：T为自定义类型，且包含多个成员
	//		通过 -> 访问每一个成员
	//T* operator->()
	Ptr operator->()
	{
		return &_node->_data;
	}
	// *iterator
	//T& operator*()
	Ref operator*()
	{
		return _node->_data;
	}

};

template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;

	// iterator 和 const_iterator 类型不同
	/*typedef ListIterator<T> iterator;
	typedef ConstListIterator<T> const_iterator;*/
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	List()
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
	}

	// 该构造函数，需注意类型匹配，如参数中的 n ，此处是泛型，所以调用时必须是泛型，不能是其他
	List(size_t n, const T& val = T())
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		for (size_t i = 0; i < n; i++)
		{
			pushBack(val);
		}
	}

	List(const List<T>& lst)
		:_header(new Node())
	{
		//循环结构
		_header->_prev = _header->_next = _header;
		/*深拷贝*/   //需要调试！！！！！！！！！！！！1
		Node* cur = lst._header->_next;
		while (cur != lst._header)
		{
			/*Node* newNode = new Node(cur->_data);
			Node* prev = _header->_prev;

			prev->_next = newNode;
			newNode->_prev = prev;

			newNode->_next = _header;
			_header->_prev = newNode;*/
			pushBack(cur->_data);
			cur = cur->_next;
		}
		/*for (auto& e : lst)
		{
			pushBack(e);
		}*/
	}

	List<T>& operator=(const List<T>& lst)
	{
		_header->_prev = _header->_next = _header;
		for (auto& e : lst)
		{
			pushBack(e);
		}
	}

	template<class inputIterator>
	List(inputIterator first, inputIterator last)
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;//这语句必须有，否则构不成循环结构
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void pushBack(const T& val) // 双向链表的尾插操作
	{
		Node* prev = _header->_prev;
		Node* newNode = new Node(val);

		prev->_next = newNode;
		newNode->_prev = prev;

		newNode->_next = _header;
		_header->_prev = newNode;
		//insert(end(), val);  
	}
	void pushFront(const T& val)
	{
		insert(begin(), val);
	}
	void popBack()
	{
		erase(--end());
	}
	void popFront()
	{
		erase(begin());
	}

	void insert(iterator pos, const T& val)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		//Node* next = cur->_next;

		//Node tmp(val);//局部对象，退出函数就会直接销毁变为野指针 -- 有问题 
		Node* tmp = new Node(val); //在堆上开辟新节点，不会出现上述问题   
		tmp->_prev = prev;
		prev->_next = tmp;

		tmp->_next = cur;
		cur->_prev = tmp;
	}

	//迭代器指向的节点释放，迭代器失效
	//更新迭代器
	//返回值：iterator  --> 被删除元素的下一个位置
	iterator erase(iterator pos)
	{
		//判断是否为有效位置
		if (pos != end())
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;

			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}
		return pos;
	}

	// begin()、end()返回的都是节点，所以迭代器it都会调用其对应的构造函数
	iterator begin()//因为_header的下一位保存的是数据的首位，所以该函数返回_header->_next
	{
		//创建一个迭代器对象：node成员指向header->_next
		iterator it(_header->_next);
		return it;
		//return iterator(_header->_next);
	}
	iterator end()
	{
		return iterator(_header);
	}

	const_iterator begin() const
	{
		//创建一个迭代器对象：node成员指向header->_next
		const_iterator cit(_header->_next);
		return cit;
	}
	const_iterator end() const
	{
		return const_iterator(_header);
	}

	~List()
	{
		//要释放每一个空间
		if (_header)
		{
			Node* node = _header->_next;
			while (node != _header)
			{
				Node* next = node->_next;
				delete node;
				node = next;
			}
			delete _header;
			_header = nullptr;
		}
	}
private:
	ListNode<T>* _header;//_header没保存成员，其下一位是数据的开始
};

template<class T>  //const 打印
void printList(const List<T>& lst)
{
	List<T>::const_iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		it++;
	}cout << endl;
}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	//List(size_t n, const T& val = T()) ，n的类型是 size_t 不是int,所以会报错!!!!!!!!!!!!!!!!!!!!!!!!!1
//	List<int> lst2((size_t)3, 6);
//
//	string s = "12345";
//	List<char> lst3(s.begin(), s.end());//要避免 '\0'不能放进去
//}

/* 自实现list的简单调用构造、迭代器等 */
//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<int>::iterator it = lst.begin(); //调用了begin(),it的构造
//	while (it != lst.end()) // it.operator!=(lst.end())
//	{
//		cout << *it << " "; // it.operator*()
//		*it = 50;
//		//++it; // it.operator++() 前置++
//		it++;
//	}cout << endl;
//	for (auto& n : lst)
//		cout << n << " ";
//	cout << endl;
//}

struct A
{
	A(int a=1)
		:_a(a)
	{}
	int _a;
	int _b;
};

/* 自定义类型的调用 */
//void test()
//{
//	List<A> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<A>::iterator it = lst.begin(); //调用了begin(),it的构造
//	while (it != lst.end()) // it.operator!=(lst.end())
//	{
//		(*it)._b = 2;
//		cout << (*it)._a << " " << it->_b << " = ";  // it.operator*()
//		(*it)._a = 1; // 返回数据或指向数据空间
//
//		//it->_a;	//it.operator->()->_a;//完整形式
//		//it->_b;	//it.operator->()->_b;
//		cout << it->_a << " " << (*it)._b << " -- ";
//		it++;//++it; // it.operator++() 前置++
//	}cout << endl;
//}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	for (auto& e : lst)
//		cout << e << " ";
//	cout << endl;
//	
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		if (*it % 2 == 0)
//			it = lst.erase(it);
//		else
//			++it;
//	}
//	printList(lst);
//
//	lst.insert(lst.begin(), 6);
//	lst.insert(lst.begin(), 7);
//	printList(lst);
//	lst.popBack();
//	// lst.popFront();
//	printList(lst);
//
//	List<int> copy(lst);
//	printList(copy);
//
//	List<int> copy2 = lst;
//	printList(copy2);
//}

void test()
{
	List<int> lst;
	List<char> lst2;
	List<int> lst3((size_t)3, 6);

	string s = "12345";
	List<char> lst4(s.begin(), s.end());//要避免 '\0'不能放进去

	List<int> lst5(lst3);
	List<int> lst6 = lst5;
	printList(lst3);
}

int main()
{
	test();
	system("pause");
	return 0;
}