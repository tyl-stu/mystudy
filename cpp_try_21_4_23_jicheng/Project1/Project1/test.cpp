#include<iostream>
using namespace std;
#include<string>

/* 切片、强制转换等基础知识的验证 */
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
//	string _name = "peter"; // 姓名 28字节
//private :
//	int _age = 18; // 年龄
//protected:
//	int _class = 5;
//};
//
//class A  //空类的大小是1字节
//{};
//
////class 定义的类，默认的继承方式是private（私有）
//class student :public Person  //继承了Person类，如果student是空类的话，其大小与其父类一致
//{
//public:
//	void print_stu()
//	{
//		cout << "name:" << _name << endl;
//		cout << "class: " << _class << endl;//protected成员可在派生类中进行访问 
//		//cout << "age:" << _age << endl;//私有成员无法在派生类中进行访问
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
//	student s;//子类
//	Person p;//父类
//	//切片：子类对象，引用，指针赋给父类对应的对象、引用、指针
//	p = s;//将子类中的值赋给父类
//	Person& rs = s;//子类赋给父类的引用
//	Person* ps = &s;//父类指针接收子类地址
//
//	student rs2 = s;
//	student* ps2 = (student*)ps;//将父类指针强转赋值给子类指针
//	student& rp = (student&)rs;//强转父类引用赋值给子类对象
//	student* pp = (student*)&p;//这种有时会有风险，就比如以下访问 id 的程序
//	int ret = pp->id;//这种并不会访问到 id
//	cout << ret << endl;
//}

/* 同名隐藏之验证 */
//class A // 4个字节
//{
//public:
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	} 
//protected:
//	int _a = 1;
//};
//class B :public A  //8个字节
//{
//public:
//	//同名隐藏：无论是成员变量还是成员函数，只要成员名称相同，就会构成同名隐藏
//	void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//	void printB()
//	{
//		cout << _a << endl;
//		//同名隐藏的父类成员变量：可以通过加上父类的作用域进行访问
//		cout << "父类成员："<< A::_a << endl;
//	}
//
//private:
//	int _a = 100;//同名继承成员的隐藏
//};
//
//void test()
//{
//	A a;
//	B b;
//	b.printB();
//	//同名函数的隐藏，想调用父类中的同名函数，需要加上父类的作业域
//	b.fun();
//}

/* 子类的初始化，各种构造 */
//class Person
//{
//public:
//	//Person()//默认构函只能有一个，可有一个默认构函，和其他构函，比如拷贝构函
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
//	//父类的成员需要调用父类的构造函数进行初始化
//	//如果父类有默认构造，初始化列表可以不用显示调用父类的构造函数，编译器会自动调用父类的默认构造
//	//如果父类没有默认构造函数，必须显示调用父类的一个构造函数
//	student(int id, int age, int stuid)
//		:Person(id,age)
//		, _stuid(stuid)  //这种方法可以
//	{
//
//	}
//	//student(int id, int age, int stuid)
//	//	:_stuid(stuid)
//	//{
//	//	//Person(id, age); //这种方法也可以
//	//	_id = id; _age = age; //这种方法依然可以
//	//}
//	/*student(int id, int age, int stuid)
//		:_stuid(stuid)  
//	{}*/
//
//	//子类的拷贝构造
//	//拷贝构造的初始化列表中可以调用普通的父类构造函数，也可以调用拷贝构造
//	student(const student& stu)
//		:Person(stu)
//		,_stuid(stu._stuid)
//	{
//		cout << "student(const student&)" << endl;
//	}
//
//	//子类的赋值，不会自动调用父类的赋值运算符
//	//如果要调用父类的赋值构造，则需要显式调用
//	student& operator=(const student& stu)
//	{
//		if (this != &stu)
//		{
//			_id = stu._id;
//			_age = stu._age;
//			//会产生同名隐藏，从而导致产生递归操作，若要调用父类的赋值，则加上父类作用域即可
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
//	//子类的默认构造会自动调用父类的构造函数
//	student stu(1,18,1604665484);
//	//stu.printB(); 
//	//stu.printA();
//
//	//子类的默认拷贝构造自动调用父类的拷贝构造
//	//如果子类显式定义了拷贝构造，子类的拷贝构造会自动父类的默认构造，若父类没有默认构造，则调不动
//	student copy(stu);  //copy.printA();copy.printB();
//
//	//赋值：子类的默认赋值运算符会自动调用父类的赋值运算符
//	student s(1, 2, 3);
//	s = copy;
//
//	//子类的默认析构会自动调用父类的默认析构
//	//先调用子类的析构，再调用父类的析构
//	//子类析构和父类析构是同名隐藏
//	//编译器在任何情况下都会自动调用父类的析构，不需要显式调用父类析构，如果显式调用了父类析构，可能会出问题
//	//如果要在子类析构中调用父类的析构，需要加上父类作用域
//}

/* 菱形继承 */
class Person
{
public:
	string _name; // 姓名
};
class Student : virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void test()
{
	//字节的大小应为4的整数倍
	cout << sizeof(Assistant) << endl;//92 = 64 + 28 = 2*32 + 28 = 2*(28 + 4) + 28 -- 没用虚拟继承的大小
									  //72  -- 虚拟继承后的大小
	//菱形继承的问题：数据冗余、二义性
	//虚拟继承可以解决菱形继承的二义性和数据冗余的问题。!!!!!!!!!!!!!!!!!
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	a._name = "peter";
	//// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	//a.Student::_name = "xxx";
	//a.Teacher::_name = "yyy"; 
}

int main()
{
	test();
	system("pause");
	return 0;
}