#include<iostream>
using namespace std;
#include<string>

/* ��Ƭ��ǿ��ת���Ȼ���֪ʶ����֤ */
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
//	string _name = "peter"; // ���� 28�ֽ�
//private :
//	int _age = 18; // ����
//protected:
//	int _class = 5;
//};
//
//class A  //����Ĵ�С��1�ֽ�
//{};
//
////class ������࣬Ĭ�ϵļ̳з�ʽ��private��˽�У�
//class student :public Person  //�̳���Person�࣬���student�ǿ���Ļ������С���丸��һ��
//{
//public:
//	void print_stu()
//	{
//		cout << "name:" << _name << endl;
//		cout << "class: " << _class << endl;//protected��Ա�����������н��з��� 
//		//cout << "age:" << _age << endl;//˽�г�Ա�޷����������н��з���
//
//	}
//public:
//	int id = 766;
//	
//};
//
//void test()
//{
//	/*cout << sizeof(Person) << endl;
//	cout << sizeof(A) << endl;
//	cout << sizeof(student) << endl;
//	student s;
//	s.print_stu();*/
//
//	student s;//����
//	Person p;//����
//	//��Ƭ������������ã�ָ�븳�������Ӧ�Ķ������á�ָ��
//	p = s;//�������е�ֵ��������
//	Person& rs = s;//���ำ�����������
//	Person* ps = &s;//����ָ����������ַ
//
//	student rs2 = s;
//	student* ps2 = (student*)ps;//������ָ��ǿת��ֵ������ָ��
//	student& rp = (student&)rs;//ǿת�������ø�ֵ���������
//	student* pp = (student*)&p;//������ʱ���з��գ��ͱ������·��� id �ĳ���
//	int ret = pp->id;//���ֲ�������ʵ� id
//	cout << ret << endl;
//}

/* ͬ������֮��֤ */
//class A // 4���ֽ�
//{
//public:
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	} 
//protected:
//	int _a = 1;
//};
//class B :public A  //8���ֽ�
//{
//public:
//	//ͬ�����أ������ǳ�Ա�������ǳ�Ա������ֻҪ��Ա������ͬ���ͻṹ��ͬ������
//	void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//	void printB()
//	{
//		cout << _a << endl;
//		//ͬ�����صĸ����Ա����������ͨ�����ϸ������������з���
//		cout << "�����Ա��"<< A::_a << endl;
//	}
//
//private:
//	int _a = 100;//ͬ���̳г�Ա������
//};
//
//void test()
//{
//	A a;
//	B b;
//	b.printB();
//	//ͬ�����������أ�����ø����е�ͬ����������Ҫ���ϸ������ҵ��
//	b.fun();
//}

/* ����ĳ�ʼ�������ֹ��� */
//class Person
//{
//public:
//	//Person()//Ĭ�Ϲ���ֻ����һ��������һ��Ĭ�Ϲ��������������������翽������
//	//{	}
//	Person(int id = 1, int age = 2)
//		:_id(id)
//		, _age(age)
//	{
//		cout << "Person(int, int)" << endl;
//	}
//	Person(const Person& p)
//		:_id(p._id)
//		, _age(p._age)
//	{
//		cout << "Person(const Person&)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			_id = p._id; 
//			_age = p._age;
//		}
//		cout << "Person& operator=(const Person&)" << endl;
//		return *this;
//	}
//
//	void printA()
//	{
//		cout << "A::id: " << _id << endl
//			<< "A::age: " << _age << endl;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//public:
//	int _id;
//	int _age;
//};
//class student :public Person
//{
//public:
//	//����ĳ�Ա��Ҫ���ø���Ĺ��캯�����г�ʼ��
//	//���������Ĭ�Ϲ��죬��ʼ���б���Բ�����ʾ���ø���Ĺ��캯�������������Զ����ø����Ĭ�Ϲ���
//	//�������û��Ĭ�Ϲ��캯����������ʾ���ø����һ�����캯��
//	student(int id, int age, int stuid)
//		:Person(id,age)
//		, _stuid(stuid)  //���ַ�������
//	{
//
//	}
//	//student(int id, int age, int stuid)
//	//	:_stuid(stuid)
//	//{
//	//	//Person(id, age); //���ַ���Ҳ����
//	//	_id = id; _age = age; //���ַ�����Ȼ����
//	//}
//	/*student(int id, int age, int stuid)
//		:_stuid(stuid)  
//	{}*/
//
//	//����Ŀ�������
//	//��������ĳ�ʼ���б��п��Ե�����ͨ�ĸ��๹�캯����Ҳ���Ե��ÿ�������
//	student(const student& stu)
//		:Person(stu)
//		,_stuid(stu._stuid)
//	{
//		cout << "student(const student&)" << endl;
//	}
//
//	//����ĸ�ֵ�������Զ����ø���ĸ�ֵ�����
//	//���Ҫ���ø���ĸ�ֵ���죬����Ҫ��ʽ����
//	student& operator=(const student& stu)
//	{
//		if (this != &stu)
//		{
//			_id = stu._id;
//			_age = stu._age;
//			//�����ͬ�����أ��Ӷ����²����ݹ��������Ҫ���ø���ĸ�ֵ������ϸ��������򼴿�
//			//operator=(stu);
//			//Person::operator=(stu);
//			_stuid = stu._stuid;
//		}
//		cout << "student& operator=(const student&)" << endl;
//		return *this;
//	}
//
//	void printB()
//	{
//		cout << "id: " << _id << endl
//			<< "age: " << _age << endl
//			<< "stuid:" << _stuid << endl;
//	}
//
//	~student()
//	{
//		cout << "~student() " << endl;
//	}
//private:
//	int _stuid;
//};
//
//void test()
//{
//	//�����Ĭ�Ϲ�����Զ����ø���Ĺ��캯��
//	student stu(1,18,1604665484);
//	//stu.printB(); 
//	//stu.printA();
//
//	//�����Ĭ�Ͽ��������Զ����ø���Ŀ�������
//	//���������ʽ�����˿������죬����Ŀ���������Զ������Ĭ�Ϲ��죬������û��Ĭ�Ϲ��죬�������
//	student copy(stu);  //copy.printA();copy.printB();
//
//	//��ֵ�������Ĭ�ϸ�ֵ��������Զ����ø���ĸ�ֵ�����
//	student s(1, 2, 3);
//	s = copy;
//
//	//�����Ĭ���������Զ����ø����Ĭ������
//	//�ȵ���������������ٵ��ø��������
//	//���������͸���������ͬ������
//	//���������κ�����¶����Զ����ø��������������Ҫ��ʽ���ø��������������ʽ�����˸������������ܻ������
//	//���Ҫ�����������е��ø������������Ҫ���ϸ���������
//}

/* ���μ̳� */
class Person
{
public:
	string _name; // ����
};
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void test()
{
	//�ֽڵĴ�СӦΪ4��������
	cout << sizeof(Assistant) << endl;//92 = 64 + 28 = 2*32 + 28 = 2*(28 + 4) + 28 -- û������̳еĴ�С
									  //72  -- ����̳к�Ĵ�С
	//���μ̳е����⣺�������ࡢ������
	//����̳п��Խ�����μ̳еĶ����Ժ�������������⡣!!!!!!!!!!!!!!!!!
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	a._name = "peter";
	//// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	//a.Student::_name = "xxx";
	//a.Teacher::_name = "yyy"; 
}

int main()
{
	test();
	system("pause");
	return 0;
}