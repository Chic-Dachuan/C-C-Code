#include<iostream>
using namespace std;
/*
重载函数调用操作符的类，其对象常称为函数对象（function object），
即它们是行为类似函数的对象，也叫仿函数(functor),其实就是重载“()”操作符，使得类对象可以像函数那样调用。
1.函数对象(仿函数)是一个类，不是一个函数。
2.函数对象(仿函数)重载了”() ”操作符使得它可以像函数一样调用。
  
  一元仿函数：  就是只传一个参数
  二元仿函数：  就是传两个参数

*/

class MyPrint {  // 仿函数  不是函数是类
public:
	MyPrint() {
		this->count = 0;
	}
	void operator() (int num) {
		cout << "num = " << num << endl;
		count++;
	}
	int count;
};

void test1() {
	MyPrint myprint;
	myprint(111);
}

// 函数对象超出了普通函数的概念，可以保存函数的调用状态
void test2() {
	MyPrint myprint;
	myprint(100);
	myprint(100);
	myprint(100);
	myprint(100);
	cout << myprint.count << endl;
}

// 函数对象作为参数传递
void doPrint(MyPrint myprint, int num) {
	myprint(num);
}

void test() {
	doPrint(MyPrint(), 20); // 参数一 匿名函数对象
}

/*

1、函数对象通常不定义构造函数和析构函数，所以在构造和析构时不会发生任何问题，避免了函数调用的运行时问题。
2、函数对象超出普通函数的概念，函数对象可以有自己的状态
3、函数对象可内联编译，性能好。用函数指针几乎不可能
4、模版函数对象使函数对象具有通用性，这也是它的优势之一

*/

int main() {

	test();

	system("pause");
	return 0;
}
