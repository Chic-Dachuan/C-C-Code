#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>
#include<string>
#include<algorithm>
/*
链表是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：
一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。
相较于vector的连续线性空间，list就显得负责许多，它的好处是每次插入或者删除一个元素，就是配置或者释放一个元素的空间。
因此，list对于空间的运用有绝对的精准，一点也不浪费。而且，对于任何位置的元素插入或元素的移除，list永远是常数时间。

List容器是一个双向循环链表  是一种不支持随机访问的容器
*/

//void test1() {
//
//	list<int> myList;
//	for (int i = 0; i < 10; i++) {
//		myList.push_back(i);
//	}
//
//	list<int>::_Nodeptr node = myList._Myhead->_Next;
//
//	for (int i = 0; i < myList._Mysize * 2; i++) {
//		cout << "Node:" << node->_Myval << endl;
//		node = node->_Next;
//		if (node == (list<int>::_Nodeptr) myList._Myhead) {
//			node = node->_Next;
//		}
//	}
//}
void printList(list<int> &l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	// 构造函数 
	list<int>l(10, 10);  // 用10个10初始化一个链表
	list<int>l2(l.begin(), l.end());  // 拷贝构造
	printList(l);
	printList(l2);
	l2.push_back(100);
	// 逆序打印
	for (list<int>::reverse_iterator it = l2.rbegin(); it != l2.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// list迭代器不支持随机访问

	/*list<int>::iterator itbegin = l2.begin();
	itbegin += 1;*/

	//插入数据
	list<int>l3;
	l3.push_back(10);
	l3.push_back(30); 
	l3.push_back(20);
	l3.push_front(100);
	l3.push_front(300);
	l3.push_front(200);
	printList(l3);

	// 删除数据
	l3.pop_front(); // 删除头部
	l3.pop_back(); // 删除尾部

	// insert(pos, elem)  or insert(pos, n, elem)  pos 是一个迭代器 表示在迭代器位置插入一个元素或者n个元素
	// insert(pos, beg, end)  表示在pos位置插入 beg 和 end之间所有数据  beg 和 end 也是迭代器

	l3.insert(l3.begin(), 1000);
	// l3.insert(l3.back(), 2000);
	l3.insert(l3.end(), 2000);
	printList(l3);
	l3.push_back(10);
	// remove
	l3.remove(10);  // 删除所有的10
	printList(l3);
}

void test2() {
	list<int>l3;
	l3.push_back(10);
	l3.push_back(30);
	l3.push_back(20);
	l3.push_front(100);
	l3.push_front(300);
	l3.push_front(200);
	cout << "大小" << l3.size() << endl;
	if (l3.empty())
	{
		cout << "l3为空" << endl;
	}
	else
	{
		cout << "l3不为空" << endl;
	}

	// resize修改链表的大小
	l3.resize(10);  // 后面用0填充
	printList(l3);

	l3.resize(5);  // 删除尾部多余的内容
	printList(l3);
	
	list<int> l;
	l.assign(l3.begin(), l3.end());  // 赋值操作

	cout << "front" << l.front() << endl;
	cout << "back" << l.back() << endl; 
}

// 反转排序
// reverse() 反转链表
// sort() 链表排序
bool myCompare(int vl1, int vl2) {
	return vl1 > vl2;
}

void test3() {
	list<int>L;
	L.push_back(20);
	L.push_back(10);
	L.push_back(40);
	L.push_back(30);
	L.push_back(5);
	// 翻转
	L.reverse();
	printList(L);
	// 排序  
	/*
		所有不支持随机访问的迭代器， 不可以用系统提供的算法
		如果不支持系统的算法那么这个类内部会提供方法
	*/
	// sort(L.begin(), L.end());
	L.sort();  // 从小到大排序
	printList(L);

	// 从大到小
	L.sort(myCompare);  // 回调函数
	printList(L);
}

// 自定义数据类型

class Person {
public:
	Person(string name, int age, float height) {
		this->Name = name;
		this->Age = age;
		this->Height = height;
	}
	string Name;
	int Age;
	float Height;

	// 重载 == 让remove可以删除自定义数据类型
	bool operator==(const Person & p) {  // 必须限定为只读类型
		if (this->Name == p.Name && this->Age == p.Age && this->Height == p.Height){
			return true;
		}
		return false;
	}
};
bool MyCompare(Person & p1, Person & p2) {  // Person排序规则 先按照年龄排序 年龄一样按照身高
	if (p1.Age == p2.Age)
	{
		return p1.Height < p2.Height;
	}
	return p1.Age > p2.Age;
}

void test() {
	list<Person> L;
	Person p1("盖伦", 20, 177.0);
	Person p2("赏金猎人", 22, 165.66);
	Person p3("蛮三刀", 40, 180.80);
	Person p4("恶魔小法师", 12, 150.6);
	Person p5("小学生之手", 35, 178.1);
	Person p6("信三哥", 35, 176.2);
	Person p7("哈萨ki", 40, 166.6);
	Person p8("狗蛋", 34, 144.0);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);
	// 按照年龄降序失败
	/*
		对于自定义数据类型必须制定排序规则
	*/
	L.sort(MyCompare);
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
		cout << "名字: " << it->Name << "  年龄: " << it->Age << " 身高: " << it->Height << endl;
	}
	cout << "__________________________" << endl;
	// remove删除自定义数据类型
	L.remove(p8);
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
		cout << "名字: " << it->Name << "  年龄: " << it->Age << " 身高: " << it->Height << endl;
	}
}
int main() {    
	test();
	system("pause");
	return EXIT_SUCCESS;
}
