#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
#include<functional>

/*
find�㷨 ����Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return ���ز���Ԫ�ص�λ��
*/
// find(iterator beg, iterator end, value)
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}


/*
find_if�㷨 ��������
@param beg ������ʼ������
@param end ��������������
@param  callback �ص���������ν��(����bool���͵ĺ�������)
@return bool ���ҷ���true ����false
*/
// find_if(iterator beg, iterator end, _callback);
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
	bool operator == (const Person & p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		return false;
	}
};
// ����find�����Զ�����������

void test2()
{
	vector<Person> v;
	Person p1("aa", 40);
	Person p2("bb", 10);
	Person p3("dd", 30);
	Person p4("cc", 20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	// ���ع�ϵ�����
	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos != v.end())
	{
		cout << (*pos).m_Name << "  " << (*pos).m_Age << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
class MyCompare:public binary_function<Person *, Person *, bool>
{
public:
	bool operator ()(Person * p1, Person * p2)const
	{
		if ((p1->m_Name == p2->m_Name) && (p1->m_Age = p2->m_Age))
		{
			return true;
		}
		return false;
	}
};
void test3()
{
	vector<Person * > v;
	Person p1("aa", 40);
	Person p2("bb", 10);
	Person p3("dd", 30);
	Person p4("cc", 20);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	Person * p = new Person("bbb", 10);
	vector<Person * >::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare(), p));
}

/*
adjacent_find�㷨 ���������ظ�Ԫ��
@param beg ������ʼ������
@param end ��������������
@param  _callback �ص���������ν��(����bool���͵ĺ�������)
@return ��������Ԫ�صĵ�һ��λ�õĵ�����
*/
// adjacent_find(iterator beg, iterator end, _callback);

void test4()
{
	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}

	// vector<int>::iterator pos = adjacent_find(v.begin(), v.end(), 5);

}

/*
binary_search�㷨 ���ֲ��ҷ�
ע��: �����������в�����
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return bool ���ҷ���true ����false
*/

// bool binary_search(iterator beg, iterator end, value);


/*
count�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  value�ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
*/
// count(iterator beg, iterator end, value);  ����ֵȥ����


/*
count�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  callback �ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
*/
// count_if(iterator beg, iterator end, _callback);  ��������ȥ����
class Compare_count
{
public:
	bool operator()(int v)
	{
		return v >= 5;
	}
};

void test()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.push_back(4);
	v.push_back(5);
	v.push_back(8);
	v.push_back(5);
	v.push_back(6);
	v.push_back(5);
	int num = 0;
	num = count_if(v.begin(), v.end(), Compare_count());
	cout << num << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}

