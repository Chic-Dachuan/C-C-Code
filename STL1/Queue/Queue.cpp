#include<iostream>
using namespace std;
#include<queue>
/*
Queue��һ���Ƚ��ȳ�(First In First Out,FIFO)�����ݽṹ��
�����������ڣ�queue���������һ������Ԫ�أ�����һ���Ƴ�Ԫ�ء�
Queue����Ԫ�صĽ�����������ϡ��Ƚ��ȳ�����������ֻ��queue�Ķ���Ԫ�أ�
���л��ᱻ���ȡ�á�Queue���ṩ�������ܣ�Ҳ���ṩ��������
*/

void test() {
	// ���캯��
	queue<int>q;
	q.push(10);  // ����β���Ԫ��
	q.push(30);
	q.push(20);
	q.push(50);

	while (!q.empty())
	{
		cout << "��ͷԪ��" << q.front() << endl;
		cout << "��βԪ��" << q.back() << endl;
		q.pop();  // ������ͷԪ��
	}
	cout << "size" << q.size() << endl;
}

int main() {
	test();
	system("pause");
	return EXIT_SUCCESS;
}