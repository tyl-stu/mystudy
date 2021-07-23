#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<sstream>


/* ifsteram,ofstream */
//struct Student
//{
//public:
//	Student()
//	{}
//	Student(const int& age, const string& name)
//		:_age(age)
//		, _name(name)
//	{
//
//	}
//	int _age;
//	string _name;
//};
//
//void test()
//{
//	//ofstream：输出文件流
//	//ifstream：输入文件流
//
//	////写文件：文件不存在，创建文件
//	//ofstream fout("test.txt");
//	////fout.open("test.txt");
//	//if (!fout.is_open())
//	//	cout << "file not open" << endl;
//
//	/*写内容*/
//	/*1、文本形式：字符流读写*/
//	//fout << "test.txt" << endl;
//	//fout.put('a');
//	//fout.put('b');
//	//fout.close();
//	////读文件：文件不存在，打开失败
//	//ifstream fin("test.txt");
//	//char arr[100];
//	//fin >> arr;
//	//char ch;
//	//ch = fin.get();//或 fin.get(ch)
//	//fin.get(ch);
//	//fin.get(arr, 100);
//	//cout<< ch << "  " << arr << endl;
//	////正常读写
//	//cout << sizeof(Student) << endl;//32个字节，按照对齐原则
//	////文本形式，如果输入以下内容，其字节数不会是32，而是9
//	//ofstream fout("test.txt");
//	//Student stu;
//	//stu._age = 20;
//	//stu._name = "abc";
//	//fout << stu._age << endl;
//	//fout << stu._name << endl;
//	//fout.close();
//
//	/*2、二进制读写：字节流读写
//	只关注字节数，不关注格式，二进制形式，文件大小是32字节，与结构体Student的大小一致*/
//	//ofstream fout2("test.binary.txt",ofstream::binary);//按照二进制格式读写内容
//	//fout2.write((char*)&stu, sizeof(stu));
//	//fout2.close();
//	//
//	//ifstream fin("test.txt");//如此恢复数据没有问题
//	//ifstream fin("test.binary.txt",ifstream::binary);//如此会造成恢复数据错误
//	//Student stu;
//	///*fin >> stu._age;
//	//fin >> stu._name;
//	//fin.close();
//	//cout << stu._age << "  " << stu._name << endl;*/
//	//fin.read((char*)&stu, sizeof(stu));
//
//}

/* sstream */

void test()
{
	/* 1、atoi  atof */
	int a = 10;
	int b = 010;// 8 
	int c = 0x10;// 16
	char arr[100];
	cout << a << "  " << b << "  " << c << endl;
	cout<< itoa(a, arr, 10) <<endl;//10进制
	cout<< itoa(b, arr, 8) <<endl;//8进制
	cout<< itoa(c, arr, 16) <<endl;//16进制

	//sprintf.
	cout << "sprintf" << endl;
	sprintf(arr, "%d", a);
	float f = 2.3;
	sprintf(arr, "%f", f);
	printf("%d\n", f);

	stringstream ss;
	string str;
	ss << a;
	ss >> str;
	cout << str << endl;
	//做多个转换时，需要使用clear，即清空接口
	//clear(): 下一次转换之前，调用clear接口清空状态位
	ss.clear();
	ss << f;
	ss >> str; cout << str << endl;

	//str(重置内容)：重置stringstream对象中的内容
	ss.str("");
	//str(): 获取stringstream对象中的内容
	str = ss.str(); cout << str << endl;
	ss.clear();
	ss << f;
	str = ss.str(); cout << str << endl;

	/*2、场景：字符串拼接 -- 不常用*/
	ss.str("");
	ss << "123" << "345" << "567";
	str = ss.str(); cout << str << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}