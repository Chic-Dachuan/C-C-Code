#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

// 容器嵌套
void test() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	// 将小容器放入大容器之中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	// 遍历
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
			cout << *vit << "\t";
		}
		cout << endl;
	}
}


// 操作自定义的数据类型
class Person {
	
public:
	Person(string name, int age) {
		this->Age = age;
		this->Name = name;
	}
	string Name;
	int Age;

};
void showInfo(Person p) {
	cout << "姓名:" << p.Name << "\n 年龄:" << p.Age << endl;
}
// 存放自定义数据类型指针
void test04() {
	vector<Person*>v;  // 存放 Person*类型的数据
	Person p1("Jobs", 50);
	Person p2("隔壁老王", 45);
	Person p3("小头爸爸", 40);
	Person p4("大头儿子", 12);
	v.push_back(&p1);  // 应该把地址存放进去
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it) { // it 是一个指向 Person* 类型的指针
		cout << (*it)->Name << (*it)->Age << endl;
	}

}
void test03() {
	vector<Person> vp;
	Person p1("Jobs", 50);
	Person p2("隔壁老王", 45);
	Person p3("小头爸爸", 40);
	Person p4("大头儿子", 12);
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);

	// 遍历
	for_each(vp.begin(), vp.end(), showInfo);
}

void myprint(int v) {
	cout << v << endl;
}

void test02() {
	// 声明一个容器
	vector<int> v; // 声明一个int类型的容器对象v
	v.push_back(1);  // 相容器中加入数据 尾插法
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// 遍历容器中的数据
	// ；利用迭代器
	// ite 和 itb是指针
	vector<int>::iterator itb = v.begin(); // 表示定义一个vector<int>::这种容器作用域下的迭代器对象it； it指向v容器的起始位置begin
	vector<int>::iterator ite = v.end();  // 指向容器最后一个位置的下一个
	/*while (itb != ite)
	{
		cout << *itb << endl;
		itb++;
	}*/
	// 第二种遍历方法
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}*/
	// 第三种利用算法
	for_each(v.begin(), v.end(), myprint);
}


// 迭代器 遍历的功能 用指针解释
// 不同指针也算迭代器
void test01() {
	int array[5] = { 1, 3, 5, 7, 9 };
	int * p = array;  // 指针指向数据首地址 &array[0]

	for (int i = 0; i < 5; ++i) {
		cout << array[i] << endl;
		cout << *p++ << endl;
	}
}

int main() {
	
	test();

	system("pause");
	return EXIT_SUCCESS;
}

