#include<iostream>
using namespace std;
#include<string>

//listʵ�֣�˫���ͷ��ѭ������
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

/* ��ʼ iterator �� const iterator �汾 */
///* �� const ������ */
//template<class T>
//struct ListIterator
//{
//	typedef ListNode<T> Node;
//	typedef ListIterator<T> iterator;
//	//��װ�ڵ�
//	Node* _node;
//
//	ListIterator(Node* node)
//		:_node(node)
//	{}
//
//	// ++iterator ǰ��++
//	ListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	// iterator++ ����++
//	ListIterator<T>& operator++(int)
//	{
//		iterator now(_node);//ListIterator now = _node; ���ַ�ʽ�Կ�,�ȺŻ����Ź�����Կ�
//		//Node* now = _node;���ַ�ʽ������Ϊ ListIterator(_node) �Ĺ�������� Node(node)
//		_node = _node->_next;
//		return now;
//	}
//
//	// --iterator ǰ��--
//	ListIterator<T>& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	// iterator-- ����--
//	ListIterator<T>& operator--(int)
//	{
//		iterator now(_node);//ListIterator now = _node; ���ַ�ʽ�Կ�,�ȺŻ����Ź�����Կ�
//		//Node* now = _node;���ַ�ʽ������Ϊ ListIterator(_node) �Ĺ�������� Node(node)
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
//		// it->_node �Ǵ���ĵ���,����ʲ�����Ӧ��_node
//	}
//
//	//it->  ==  T*  -->  ->
//	//������TΪ�Զ������ͣ��Ұ��������Ա
//	//		ͨ�� -> ����ÿһ����Ա
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
///* const ������ */
//template<class T>
//struct ConstListIterator
//{
//	typedef ListNode<T> Node;
//	typedef ConstListIterator<T> iterator;
//	//��װ�ڵ�
//	Node* _node;
//
//	ConstListIterator(Node* node)
//		:_node(node)
//	{}
//
//	// ++iterator ǰ��++
//	ConstListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	// iterator++ ����++
//	ConstListIterator<T>& operator++(int)
//	{
//		iterator now(_node);//ListIterator now = _node; ���ַ�ʽ�Կ�,�ȺŻ����Ź�����Կ�
//		//Node* now = _node;���ַ�ʽ������Ϊ ListIterator(_node) �Ĺ�������� Node(node)
//		_node = _node->_next;
//		return now;
//	}
//
//	// --iterator ǰ��--
//	ConstListIterator<T>& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	// iterator-- ����--
//	ConstListIterator<T>& operator--(int)
//	{
//		iterator now(_node);//ListIterator now = _node; ���ַ�ʽ�Կ�,�ȺŻ����Ź�����Կ�
//		//Node* now = _node;���ַ�ʽ������Ϊ ListIterator(_node) �Ĺ�������� Node(node)
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
//		// it->_node �Ǵ���ĵ���,����ʲ�����Ӧ��_node
//	}
//
//	//it->  ==  T*  -->  ->
//	//������TΪ�Զ������ͣ��Ұ��������Ա
//	//		ͨ�� -> ����ÿһ����Ա
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

//����������
template<class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	typedef Self iterator;
	//��װ�ڵ�
	Node* _node;

	ListIterator(Node* node)
		:_node(node)
	{}

	// ++iterator ǰ��++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	// iterator++ ����++
	Self& operator++(int)
	{
		Self now(_node);
		//iterator now(_node);//ListIterator now = _node; ���ַ�ʽ�Կ�,�ȺŻ����Ź�����Կ�
		//Node* now = _node;���ַ�ʽ������Ϊ ListIterator(_node) �Ĺ�������� Node(node)
		_node = _node->_next;
		return now; 
	}

	// --iterator ǰ��--
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	// iterator-- ����--
	Self& operator--(int)
	{
		Self now(_node);
		//iterator now(_node);//ListIterator now = _node; ���ַ�ʽ�Կ�,�ȺŻ����Ź�����Կ�
		//Node* now = _node;���ַ�ʽ������Ϊ ListIterator(_node) �Ĺ�������� Node(node)
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
		// it->_node �Ǵ���ĵ���,����ʲ�����Ӧ��_node
	}

	//it->  ==  T*  -->  ->
	//������TΪ�Զ������ͣ��Ұ��������Ա
	//		ͨ�� -> ����ÿһ����Ա
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

	// iterator �� const_iterator ���Ͳ�ͬ
	/*typedef ListIterator<T> iterator;
	typedef ConstListIterator<T> const_iterator;*/
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	List()
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_next = _header->_prev = _header;
	}

	// �ù��캯������ע������ƥ�䣬������е� n ���˴��Ƿ��ͣ����Ե���ʱ�����Ƿ��ͣ�����������
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
		//ѭ���ṹ
		_header->_prev = _header->_next = _header;
		/*���*/   //��Ҫ���ԣ�����������������������1
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
		_header->_next = _header->_prev = _header;//���������У����򹹲���ѭ���ṹ
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void pushBack(const T& val) // ˫�������β�����
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

		//Node tmp(val);//�ֲ������˳������ͻ�ֱ�����ٱ�ΪҰָ�� -- ������ 
		Node* tmp = new Node(val); //�ڶ��Ͽ����½ڵ㣬���������������   
		tmp->_prev = prev;
		prev->_next = tmp;

		tmp->_next = cur;
		cur->_prev = tmp;
	}

	//������ָ��Ľڵ��ͷţ�������ʧЧ
	//���µ�����
	//����ֵ��iterator  --> ��ɾ��Ԫ�ص���һ��λ��
	iterator erase(iterator pos)
	{
		//�ж��Ƿ�Ϊ��Чλ��
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

	// begin()��end()���صĶ��ǽڵ㣬���Ե�����it����������Ӧ�Ĺ��캯��
	iterator begin()//��Ϊ_header����һλ����������ݵ���λ�����Ըú�������_header->_next
	{
		//����һ������������node��Աָ��header->_next
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
		//����һ������������node��Աָ��header->_next
		const_iterator cit(_header->_next);
		return cit;
	}
	const_iterator end() const
	{
		return const_iterator(_header);
	}

	~List()
	{
		//Ҫ�ͷ�ÿһ���ռ�
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
	ListNode<T>* _header;//_headerû�����Ա������һλ�����ݵĿ�ʼ
};

template<class T>  //const ��ӡ
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
//	//List(size_t n, const T& val = T()) ��n�������� size_t ����int,���Իᱨ��!!!!!!!!!!!!!!!!!!!!!!!!!1
//	List<int> lst2((size_t)3, 6);
//
//	string s = "12345";
//	List<char> lst3(s.begin(), s.end());//Ҫ���� '\0'���ܷŽ�ȥ
//}

/* ��ʵ��list�ļ򵥵��ù��졢�������� */
//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<int>::iterator it = lst.begin(); //������begin(),it�Ĺ���
//	while (it != lst.end()) // it.operator!=(lst.end())
//	{
//		cout << *it << " "; // it.operator*()
//		*it = 50;
//		//++it; // it.operator++() ǰ��++
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

/* �Զ������͵ĵ��� */
//void test()
//{
//	List<A> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<A>::iterator it = lst.begin(); //������begin(),it�Ĺ���
//	while (it != lst.end()) // it.operator!=(lst.end())
//	{
//		(*it)._b = 2;
//		cout << (*it)._a << " " << it->_b << " = ";  // it.operator*()
//		(*it)._a = 1; // �������ݻ�ָ�����ݿռ�
//
//		//it->_a;	//it.operator->()->_a;//������ʽ
//		//it->_b;	//it.operator->()->_b;
//		cout << it->_a << " " << (*it)._b << " -- ";
//		it++;//++it; // it.operator++() ǰ��++
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
	List<char> lst4(s.begin(), s.end());//Ҫ���� '\0'���ܷŽ�ȥ

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