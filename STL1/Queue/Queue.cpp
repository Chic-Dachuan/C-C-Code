#include<iostream>
using namespace std;
#include<queue>
/*
Queue是一种先进先出(First In First Out,FIFO)的数据结构，
它有两个出口，queue容器允许从一端新增元素，从另一端移除元素。
Queue所有元素的进出都必须符合”先进先出”的条件，只有queue的顶端元素，
才有机会被外界取用。Queue不提供遍历功能，也不提供迭代器。
*/

void test() {
	// 构造函数
	queue<int>q;
	q.push(10);  // 往队尾添加元素
	q.push(30);
	q.push(20);
	q.push(50);

	while (!q.empty())
	{
		cout << "队头元素" << q.front() << endl;
		cout << "队尾元素" << q.back() << endl;
		q.pop();  // 弹出对头元素
	}
	cout << "size" << q.size() << endl;
}

int main() {
	test();
	system("pause");
	return EXIT_SUCCESS;
}