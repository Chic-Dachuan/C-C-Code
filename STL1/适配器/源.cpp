#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;

class MyPrint: public binary_function<int, int, void>
{
	public:
		void operator()(int val, int start) const  // 常函数 不能修改里面的值
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
	// for_each(v.begin(), v.end(), bind2nd(MyPrint(), num)); // 绑定第二个参数
	for_each(v.begin(), v.end(), bind1st(MyPrint(), num));  // 绑定第一个参数
}
// 第一步绑定数据 bind2nd 
// 继承类  binary_function  < 参数类型1， 参数类型2， 返回值类型>
// 加const 修饰 



// 取反适配器
class Greater:public unary_function<int, bool>
{
public:
	bool operator()(int v)  const
	{
		return v > 5;
	}
};
void test2() {
	// 一元取反
	vector<int>vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	// 查找大于5的数字
	// 需求改为找小于5的数  加一个取反的适配器
	// vector<int>::iterator pos = find_if(vec.begin(), vec.end(), not1(Greater())); // not1() 取反适配器 not2二元取反
	vector<int>::iterator pos = find_if(vec.begin(), vec.end(), not1 (bind2nd(greater<int>(), 5)));
	
	if (pos != vec.end()) {
		cout << "大于5的数字为： " << *pos << endl;
	}
	else
	{
		cout << "没有找到大于5的数" << endl;
	}
}

// 函数指针 适配器
void doPrint(int v)   // 普通回调函数
{
	cout << v << endl;
}

void test3() {
	vector<int>vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	// 将函数指针适配为 函数对象
	// ptr_fun
	for_each(vec.begin(), vec.end(), bind2nd(ptr_fun(doPrint), 100));
}


// 成员函数适配器
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
	cout << "姓名 " << p.m_Name << "\n 年龄 " << p.m_Age << endl;
}


void test() {
	vector<Person> vec;
	Person p1("皮卡丘", 10);
	Person p2("喜洋洋", 10);
	Person p3("懒洋洋", 10);
	Person p4("美洋洋", 10);
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);
	// 成员函数的适配器
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
