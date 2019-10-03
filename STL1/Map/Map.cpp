#include<iostream>
using namespace std;
#include<map>
/*
Map的特性是，所有元素都会根据元素的键值自动排序。
Map所有的元素都是pair,同时拥有实值和键值，
pair的第一元素被视为键值，第二元素被视为实值，map不允许两个元素有相同的键值。
*/

void test1() {
	// 构造
	map<int, int> mp;
	// 插入值 有四种方式
	// 第一种
	mp.insert(pair<int, int>(1, 10));
	// 第二种
	mp.insert(make_pair(2, 20));
	// 第三种
	mp.insert(map<int, int>::value_type(3, 30));
	// 第四种
	mp[4] = 40;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		cout << "key=" << it->first << " value=" << it->second << endl;
	}
	cout << mp[5] << endl;  // key为5 value为0
	/*
		size();//返回容器中元素的数目
		empty();//判断容器是否为空
	*/
	if (mp.empty()) {
		cout << "为空" << endl;
	}
	else {
		cout << mp.size() << endl;
	}
}

void test2() {
	map<int, int>mp;
	mp.insert(make_pair(1, 10));
	mp.insert(make_pair(2, 20));
	mp.insert(make_pair(3, 30));
	mp.insert(make_pair(4, 40));
	mp.insert(make_pair(5, 50));
	 /*
		clear();//删除所有元素
		erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(keyElem);//删除容器中key为keyElem的对组。
	 */

	mp.erase(1); //删除key为1的数据

	// 查找
	/*
		find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
		count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
		lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。	
		upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
		equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	*/
	map<int, int>::iterator pos = mp.find(1);
	if (pos != mp.end())
	{
		cout << "找到了" << ", key: " << pos->first << " ， value: " << pos->second << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	int num = mp.count(3);
	
	// lower_bound() 
	map<int, int>::iterator ret = mp.lower_bound(3);
	if (ret != mp.end())
	{
		cout << "找到" << ", key: " << ret->first << " value:" << ret->second << endl;
	}
	// ipper_bound
	map<int, int>::iterator ret2 = mp.upper_bound(3);
	if (ret2 != mp.end())
	{
		cout << "找到" << ", key: " << ret->first << " value:" << ret->second << endl;
	}

	// equal_range
	pair<map<int, int>::iterator, map<int, int>::iterator> ret3 = mp.equal_range(3);
	if (ret3.first != mp.end() ) // lower_bound
	{
		cout << "找到" << "  key:" << ret3.first->first << "   value:" << ret3.first->second << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	if (ret3.second != mp.end()) // upper_bound
	{
		cout << "找到" << "  key:" << ret3.second->first << "   value:" << ret3.second->second << endl;
	}
	else {
		cout << "未找到" << endl;
	}
}


// 排序
class myCompare {  // 仿函数
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
void test() {
	map<int, int, myCompare>mp;
	mp.insert(make_pair(1, 10));
	mp.insert(make_pair(2, 20));
	mp.insert(make_pair(3, 30));
	mp.insert(make_pair(4, 40));
	mp.insert(make_pair(5, 50));
	for (map<int, int, myCompare>::iterator it = mp.begin(); it != mp.end(); ++it) {
		cout << "key=" << it->first << "  value=" << it->second << endl;
	}
}

int main() {

	test();

	system("pause");
	return EXIT_SUCCESS;
}
