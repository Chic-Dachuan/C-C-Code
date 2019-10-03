#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
#include<functional>

/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
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
		cout << "没找到" << endl;
	}
}


/*
find_if算法 条件查找
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return bool 查找返回true 否则false
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
// 利用find查找自定义数据类型

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
	// 重载关系运算符
	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos != v.end())
	{
		cout << (*pos).m_Name << "  " << (*pos).m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
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
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
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
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/

// bool binary_search(iterator beg, iterator end, value);


/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
// count(iterator beg, iterator end, value);  按照值去查找


/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
// count_if(iterator beg, iterator end, _callback);  按照条件去查找
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

