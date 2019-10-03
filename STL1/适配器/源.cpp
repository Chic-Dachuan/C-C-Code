#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;

class MyPrint: public binary_function<int, int, void>
{
	public:
		void operator()(int val, int start) const  // ������ �����޸������ֵ
		{
			cout << val + start << endl;
		} 
};

void test1() {
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	int num;
	cin >> num;
	// for_each(v.begin(), v.end(), bind2nd(MyPrint(), num)); // �󶨵ڶ�������
	for_each(v.begin(), v.end(), bind1st(MyPrint(), num));  // �󶨵�һ������
}
// ��һ�������� bind2nd 
// �̳���  binary_function  < ��������1�� ��������2�� ����ֵ����>
// ��const ���� 



// ȡ��������
class Greater:public unary_function<int, bool>
{
public:
	bool operator()(int v)  const
	{
		return v > 5;
	}
};
void test2() {
	// һԪȡ��
	vector<int>vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	// ���Ҵ���5������
	// �����Ϊ��С��5����  ��һ��ȡ����������
	// vector<int>::iterator pos = find_if(vec.begin(), vec.end(), not1(Greater())); // not1() ȡ�������� not2��Ԫȡ��
	vector<int>::iterator pos = find_if(vec.begin(), vec.end(), not1 (bind2nd(greater<int>(), 5)));
	
	if (pos != vec.end()) {
		cout << "����5������Ϊ�� " << *pos << endl;
	}
	else
	{
		cout << "û���ҵ�����5����" << endl;
	}
}

// ����ָ�� ������
void doPrint(int v)   // ��ͨ�ص�����
{
	cout << v << endl;
}

void test3() {
	vector<int>vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	// ������ָ������Ϊ ��������
	// ptr_fun
	for_each(vec.begin(), vec.end(), bind2nd(ptr_fun(doPrint), 100));
}


// ��Ա����������
class Person
{
public:
	Person(string Name, int Age)
	{
		this->m_Name = Name;
		this->m_Age = Age;
	}
	string m_Name;
	int m_Age;
	void showPerson()
	{
		cout << this->m_Name << "  " << this->m_Age << endl;
	}
	void PlusAge()
	{
		this->m_Age = this->m_Age + 100;
	}
};
void PrintPerson(Person & p)
{
	cout << "���� " << p.m_Name << "\n ���� " << p.m_Age << endl;
}


void test() {
	vector<Person> vec;
	Person p1("Ƥ����", 10);
	Person p2("ϲ����", 10);
	Person p3("������", 10);
	Person p4("������", 10);
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);
	// ��Ա������������
	// mem_fun_ref
	for_each(vec.begin(), vec.end(), mem_fun_ref(&Person::showPerson));
	for_each(vec.begin(), vec.end(), mem_fun_ref(&Person::PlusAge));
	for_each(vec.begin(), vec.end(), mem_fun_ref(&Person::showPerson));
}

int main() {

	test();
	system("pause");
	return 0;
}
