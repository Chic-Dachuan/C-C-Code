#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void print(const deque<int> & d) {
	for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); ++dit) {  // const_iterator 只读迭代器
		cout << *dit << " ";
	}
	cout << endl;
}

void test1() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	print(d);

	deque<int> d2(d.begin(), d.end());  // 拷贝构造
	d2.push_back(1000);

	// 交换
	d.swap(d2);
	print(d);

	if (d2.empty()) {
		cout << "为空" << endl;
	}
	else {
		cout << "不为空" << "  大小为" << d2.size() << endl;
	}
}


void test2() {
	deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);

	d.push_front(400);
	d.push_front(500);
	print(d);

	// 删除
	d.pop_back();  // 删除尾部
	d.pop_front(); // 删除头部
	print(d);

	cout << "front" << d.front() << endl;
	cout << "back" << d.back() << endl;


	// 插入
	deque<int> d2;
	d2.push_back(666);
	d2.push_back(777);
	d2.push_back(888);

	d2.insert(d2.begin(), d.begin(), d.end());  // 从头部开始插入 把d容器中的内容插入
	print(d2);

	d2.erase(d2.begin()); // 删除头部元素
	d2.erase(d2.end());  // 删除尾部元素

	d2.pop_back(); // 删除最后一个元素
	d2.pop_front(); // 删除第一个元素

}

// 排序规则
bool myCompare(int value1, int value2) {
	return value1 > value2;
}

// 排序算法sort

void test() {
	deque<int> d;
	d.push_back(10);
	d.push_back(4);
	d.push_back(5);
	d.push_back(21);
	d.push_back(17);
	d.push_back(7);
	print(d);

	// 排序
	sort(d.begin(), d.end());
	print(d);

	// 从大到小
	sort(d.begin(), d.end(), myCompare);
	print(d);

}

int main() {
	test();
	system("pause");
	return EXIT_SUCCESS;
}

