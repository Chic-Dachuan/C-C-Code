#include<iostream>
using namespace std;
#include<vector>

void test1() {
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		cout << v.capacity() << endl; // 容量不是按照2两倍这样扩展的 扩容是人家实现了一个算法
	}
}
void printVector(vector<int> & v) {
	for (vector<int>::iterator it = v.begin(); it !=  v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test2() {
	// 默认构造函数
	vector<int> v;

	int arr[] = { 2, 3, 4, 5, 6 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));  //  第一个参数begin 第二个参数 是end 也就是最后一个位置 + 1
	// 利用容器构造容器
	vector<int> v2(v.begin(), v.end());
	printVector(v1);

	vector<int> v3(10, 100); // 表示用10个100初始化一个容器
	
	// 赋值
	vector<int> v4;
	v4.assign(v3.begin(), v3.end());

	v4.assign(11, 100);  // 给容器v4赋值11个100 
	printVector(v4);  
	cout << "v4的容器大小" << v4.size() << endl;
	v4.swap(v1);
	cout << "交换后的v4" << endl;
	printVector(v4);
	cout << "v4的容器大小" << v4.size() << endl;

	if (v4.empty()) // 当大小为0也表示为空
	{
		cout << "v4为空" << endl;
	}
	else
	{
		cout << "v4为不空" << endl;
	}

	// v4 23456
	v4.resize(10); // 后面5个数是0  默认是0可以重载
	printVector(v4);
	v4.resize(10, -1);  // 后面5个数是-1 

	v4.resize(3);
	printVector(v4); 

}
// 巧用swap来收缩空间
void test3() {
	vector<int> v;
	for (int i = 0; i < 100000; ++i) {
		v.push_back(i);
	}
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
	v.resize(3);
	cout << "v的容量：" << v.capacity() << endl;  // 容量不变  
	cout << "v的大小：" << v.size() << endl;  // 大小变为3

	// 巧用swap
	vector<int>(v).swap(v); // 相当于用V大小来构造初始化匿名对象
	cout << "v的容量：" << v.capacity() << endl; // 容量为3 
	cout << "v的大小：" << v.size() << endl;  // 大小为3
}

void test4() {
	vector<int> v;
	v.reserve(100000);  // 如果知道大概有多少个数据 那么可以采用reserve 来预留空间 避免多次开辟空间带来性能降低
	int * p = NULL;
	int  num = 0;
	for (int i = 0; i < 100000; ++i) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	// 填入100000个数据， 开辟多少次空间
}

// 数据存储 插入
void test5() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "v的front:" << v.front() << endl;  // 第一个元素

	cout << "v的back:" << v.back() << endl;  // 第二个元素

	// 插入
	v.insert(v.begin(), 100);  // 第一个参数必须是一个迭代器 v.begin() 就是一个迭代器
	printVector(v);
	v.insert(v.begin(), 3, 100);  // 第一个参数必须是一个迭代器 v.begin() 就是一个迭代器  第二个参数是插入多少个  第三个参数是插入的元素

	v.pop_back(); // 删除最后一个元素 尾删
	printVector(v);

	v.erase(v.begin());  // 删除迭代器指向的元素
	printVector(v);
	v.erase(v.begin(), v.end());
	if (v.size())
	{
		cout << "v为空" << endl;
	}
	v.clear(); // 清空所有数据
}

void test6() {
	// vector容器逆序遍历
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	printVector(v);

	// 需要逆序的迭代器reverse_iterator
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << " ";
	}

	// vector迭代器一个随机访问的迭代器  特点 支持跳跃式访问
	vector<int> ::iterator itb = v.begin();
	itb += 3;  
	// list 容器不支持随机访问

}


void test() {
	vector<int> v1;
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
	}
	vector<int> v2;
	v2.push_back(1000);
	v1.swap(v2);
	printVector(v1);
}

int main(){

	test();
	system("pause");
	return EXIT_SUCCESS;
}