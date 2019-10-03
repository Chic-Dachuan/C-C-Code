#include<iostream>
using namespace std;
#include<string>

void test() {
	// 创建对组
	pair<string, int> p(string("Tom"), 100);
	// 取值
	cout << "姓名: " << p.first << endl;  // 取第一个值
	cout << "分数: " << p.second << endl; // 取第二个值

	// 第二种创建方式
	pair<string, int> p2 = make_pair("Jerry", 90);
	cout << "姓名: " << p2.first << endl;  // 取第一个值
	cout << "分数: " << p2.second << endl; // 取第二个值
}

int main() {

	test();
	system("pause");
	return EXIT_SUCCESS;
}
