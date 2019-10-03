#include<iostream>
using namespace std;
#include<string>
#include<set>  // 关联性容器  set mulset 都在这个头文件中
// 插入数据自动排序

void printSet(set<int> & sl) {
	for (set<int>::iterator it = sl.begin(); it != sl.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	// 构造函数
	set<int> sl;
	// 只能插入不是push
	sl.insert(5);
	sl.insert(10);
	sl.insert(1);
	sl.insert(3);
	sl.insert(6);
	sl.insert(4);
	sl.insert(2);
	printSet(sl);  // 自动根据key排序 规则是默认从小到大 set容器只有key值，value与key同值

	// 判断是否为空
	if (sl.empty()) {
		cout << "空" << endl;
	}
	else {
		cout << "size" << sl.size() << endl;
	}
	/*
		insert(elem);//在容器中插入元素。
		clear();//清除所有元素
		erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(elem);//删除容器中值为elem的元素。
	*/

	// erase 删除  
	sl.erase(sl.begin());
	sl.erase(1);  
}

// 查找操作
/*
	find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
	count(key);//查找键key的元素个数
	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

*/
void test2() {
	set<int> sl;
	sl.insert(5);
	sl.insert(7);
	sl.insert(1);
	sl.insert(3);
	sl.insert(6);
	sl.insert(4);
	sl.insert(2);

	set<int>::iterator pos1 = sl.find(0);  // 没有找到返回sl.end()

	// 判断是否找到
	if (pos1 != sl.end()) {  // 找到
		cout << *pos1 << endl;
	}
	else {
		cout << "没有" << endl;
	}

	int num = sl.count(1);  // 对set而言 返回1或0 有就是1没有就是0
	cout << "1的个数为" << num << endl;

	// lower_bound
	set<int>::iterator pos2 = sl.lower_bound(3);  // 返回第一个key>=keyElem元素的迭代器。 
	if (pos2 != sl.end()) {  // 找到
		cout << "找到了" << *pos2 << endl;
	}
	else {
		cout << "没找到" << endl;
	}

	// upper_bound   返回第一个key>keyElem元素的迭代器。
	set<int>::iterator pos3 = sl.upper_bound(3);
	if (pos3 != sl.end()) {  // 找到
		cout << "找到了" << *pos3 << endl;
	}
	else {
		cout << "没找到" << endl;
	}
	
	// equal_range(keyElem)   返回容器中key与keyElem相等的上下限的两个迭代器。  返回两个值
	// pair 表示对组  pair<key1,key2>  表示两个值
	// 上下限就是 lower_bound 和 upper_bound
	pair<set<int>::iterator, set<int>::iterator> ret = sl.equal_range(3);

	// 获取 pair中的值
	if (ret.first != sl.end()) {  // 获取第一个值
		cout << "找到equal_range中的lower_bound值" << *(ret.first) << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	// 获取第二个值
	if (ret.second != sl.end()) {
		cout << "找到equal_range中的upper_bound值" << *(ret.second) << endl;
	}
	else {
		cout << "未找到" << endl;
	}
}
/*
	set容器不允许插入重复的值
*/
void test3() {
	set<int> sl;
	pair<set<int>::iterator, bool> ret = sl.insert(10);
	if (ret.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}
	pair<set<int>::iterator, bool> ret1 = sl.insert(10);
	if (ret1.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}
	printSet(sl);

}

// set排序
// 指定set排序规则从大到小   仿函数  是一个类
// 仿函数
class MyCompare {
public:
	// 重载
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};


void test4() {
	// set<int> sl;
	set<int, MyCompare>sl;
	sl.insert(5);
	sl.insert(7);
	sl.insert(1);
	sl.insert(3);
	sl.insert(6);
	sl.insert(4);
	sl.insert(2);
	// printSet(sl);  // 每个容器都有自己专属迭代器
	// 从大到小排序
	// 只能在插入之前指定排序规则   set容器插入之后不允许随意改变数据
	// 任意改变set元素值，会严重破坏set组织。换句话说，set的iterator是一种const_iterator.
	for (set<int, MyCompare>::iterator it = sl.begin(); it != sl.end(); ++it) {
		cout << *it << endl;
	}
		
}

// 自定义数据类型

class Person {
public:
	Person(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
	string Name;
	int Age;
};

class myCompare {  // 仿函数
public:
	bool operator()(const Person & p1, const Person & p2) {  // 在排序中加入const限定禁止修改
		return p1.Age > p2.Age;
	}
};

void test() {
	set<Person, myCompare> sl;

	Person p1("盖伦", 20);
	Person p2("赏金猎人", 22);
	Person p3("蛮三刀", 40);
	Person p4("恶魔小法师", 12);
	Person p5("小学生之手", 35);
	Person p6("信三哥", 35);
	Person p7("哈萨ki", 40);
	Person p8("狗蛋", 34);

	// 插入自定义数据类型， 必须提前指定排序规则
	sl.insert(p1);
	sl.insert(p2);
	sl.insert(p3);
	sl.insert(p4);
	sl.insert(p5);
	for (set<Person, myCompare>::iterator it = sl.begin(); it != sl.end(); ++it) {
		cout << "姓名  " << it->Name << "  年龄  " << it->Age << endl;
	}
}

//  mulset 允许插入重复的值
int main() {

	test();
	system("pause");
	return EXIT_SUCCESS;
}

