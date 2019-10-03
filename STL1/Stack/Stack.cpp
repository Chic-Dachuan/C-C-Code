#include<iostream>
using namespace std;
#include<stack>
/*
stack是一种先进后出(First In Last Out,FILO)的数据结构，
它只有一个出口，形式如图所示。stack容器允许新增元素，
移除元素，取得栈顶元素，但是除了最顶端外，
没有任何其他方法可以存取stack的其他元素。
换言之，stack不允许有遍历行为。
故：栈容器没有迭代器
*/
void test() {

	// 构造函数
	stack<int> st;
	// 放入数据
	st.push(10);
	st.push(30);
	st.push(20);
	st.push(50);
	while (st.size() != 0)
	{
		cout << "栈顶数据: " << st.top() << endl;
		// 弹出栈顶元素
		st.pop();
	}
}

int main() {
	test();
	system("pause");
	return	EXIT_SUCCESS;
}