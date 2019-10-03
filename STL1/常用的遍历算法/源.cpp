#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<functional>

//void Print(int v)
//{
//	cout << v << " ";
//}

struct Print 
{
	void operator() (int v)
	{
		cout << v << endl;
	}
};

void test1()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	for_each(vec.begin(), vec.end(), Print());
}

// for_each  �����ڲ���¼
struct Print2
{
	void operator() (int v)
	{
		cout << v << endl;
		m_Count++;
	}
	int m_Count = 0;
};

void test2()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	Print2 print2 = for_each(vec.begin(), vec.end(), Print2());  // ���طº�������
	// forz-each �з���ֵ
	cout << print2.m_Count << endl;
}

// for_each �󶨲������
struct Print3:public binary_function<int, int, void>
{
	void operator ()(int v, int start)const
	{
		cout << v + start << endl;
	}

};

void test3()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	for_each(vec.begin(), vec.end(), bind2nd(Print3(), 1000));
}

// transform  �㷨 ��ָ�������Ԫ�ذ��˵���һ�ռ�  ע���ȷ���ռ�

class TransForm
{
public:
	int operator()(int v)
	{
		return v;
	}

};


void test4()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	vector<int>vec2;  // Ŀ������
	// �����ڴ� Ԥ��
	vec2.resize(vec.size());
	transform(vec.begin(), vec.end(), vec2.begin(), TransForm());
	for_each(vec2.begin(), vec2.end(), [](int val) {cout << val << endl; });

}
// transform �������������˵�һ��������
class TransForm2
{
public:

	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	vector<int> v;
	v.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), v.begin(), TransForm2());
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
int main()
{
	test();
	system("pause");
	return 0;
}
