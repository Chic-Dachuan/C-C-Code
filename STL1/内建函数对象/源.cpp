#include<iostream>
#include<functional>  // 内建函数头文件
#include<vector>
#include<algorithm>
using namespace std;

/*  除了negate是一元运算，其他都是二元运算

template<class T> T plus<T>//加法仿函数
template<class T> T minus<T>//减法仿函数
template<class T> T multiplies<T>//乘法仿函数
template<class T> T divides<T>//除法仿函数
template<class T> T modulus<T>//取模仿函数
template<class T> T negate<T>//取反仿函数

*/

void test1() {
	negate<int> v;  // 取反
	cout << v(10) << endl;
	// 加法
	plus<int>p;  // 只允许相同类型相加
	cout << p(1, 1) << endl;
}

/*
template<class T> bool equal_to<T>//等于
template<class T> bool not_equal_to<T>//不等于
template<class T> bool greater<T>//大于
template<class T> bool greater_equal<T>//大于等于
template<class T> bool less<T>//小于
template<class T> bool less_equal<T>//小于等于
*/

void test() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
int main() {

	test();
	system("pause");
	return 0;
}