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
//	//ofstream������ļ���
//	//ifstream�������ļ���
//
//	////д�ļ����ļ������ڣ������ļ�
//	//ofstream fout("test.txt");
//	////fout.open("test.txt");
//	//if (!fout.is_open())
//	//	cout << "file not open" << endl;
//
//	/*д����*/
//	/*1���ı���ʽ���ַ�����д*/
//	//fout << "test.txt" << endl;
//	//fout.put('a');
//	//fout.put('b');
//	//fout.close();
//	////���ļ����ļ������ڣ���ʧ��
//	//ifstream fin("test.txt");
//	//char arr[100];
//	//fin >> arr;
//	//char ch;
//	//ch = fin.get();//�� fin.get(ch)
//	//fin.get(ch);
//	//fin.get(arr, 100);
//	//cout<< ch << "  " << arr << endl;
//	////������д
//	//cout << sizeof(Student) << endl;//32���ֽڣ����ն���ԭ��
//	////�ı���ʽ����������������ݣ����ֽ���������32������9
//	//ofstream fout("test.txt");
//	//Student stu;
//	//stu._age = 20;
//	//stu._name = "abc";
//	//fout << stu._age << endl;
//	//fout << stu._name << endl;
//	//fout.close();
//
//	/*2�������ƶ�д���ֽ�����д
//	ֻ��ע�ֽ���������ע��ʽ����������ʽ���ļ���С��32�ֽڣ���ṹ��Student�Ĵ�Сһ��*/
//	//ofstream fout2("test.binary.txt",ofstream::binary);//���ն����Ƹ�ʽ��д����
//	//fout2.write((char*)&stu, sizeof(stu));
//	//fout2.close();
//	//
//	//ifstream fin("test.txt");//��˻ָ�����û������
//	//ifstream fin("test.binary.txt",ifstream::binary);//��˻���ɻָ����ݴ���
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
	/* 1��atoi  atof */
	int a = 10;
	int b = 010;// 8 
	int c = 0x10;// 16
	char arr[100];
	cout << a << "  " << b << "  " << c << endl;
	cout<< itoa(a, arr, 10) <<endl;//10����
	cout<< itoa(b, arr, 8) <<endl;//8����
	cout<< itoa(c, arr, 16) <<endl;//16����

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
	//�����ת��ʱ����Ҫʹ��clear������սӿ�
	//clear(): ��һ��ת��֮ǰ������clear�ӿ����״̬λ
	ss.clear();
	ss << f;
	ss >> str; cout << str << endl;

	//str(��������)������stringstream�����е�����
	ss.str("");
	//str(): ��ȡstringstream�����е�����
	str = ss.str(); cout << str << endl;
	ss.clear();
	ss << f;
	str = ss.str(); cout << str << endl;

	/*2���������ַ���ƴ�� -- ������*/
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