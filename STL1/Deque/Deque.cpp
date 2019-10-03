#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void print(const deque<int> & d) {
	for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); ++dit) {  // const_iterator ֻ��������
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

	deque<int> d2(d.begin(), d.end());  // ��������
	d2.push_back(1000);

	// ����
	d.swap(d2);
	print(d);

	if (d2.empty()) {
		cout << "Ϊ��" << endl;
	}
	else {
		cout << "��Ϊ��" << "  ��СΪ" << d2.size() << endl;
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

	// ɾ��
	d.pop_back();  // ɾ��β��
	d.pop_front(); // ɾ��ͷ��
	print(d);

	cout << "front" << d.front() << endl;
	cout << "back" << d.back() << endl;


	// ����
	deque<int> d2;
	d2.push_back(666);
	d2.push_back(777);
	d2.push_back(888);

	d2.insert(d2.begin(), d.begin(), d.end());  // ��ͷ����ʼ���� ��d�����е����ݲ���
	print(d2);

	d2.erase(d2.begin()); // ɾ��ͷ��Ԫ��
	d2.erase(d2.end());  // ɾ��β��Ԫ��

	d2.pop_back(); // ɾ�����һ��Ԫ��
	d2.pop_front(); // ɾ����һ��Ԫ��

}

// �������
bool myCompare(int value1, int value2) {
	return value1 > value2;
}

// �����㷨sort

void test() {
	deque<int> d;
	d.push_back(10);
	d.push_back(4);
	d.push_back(5);
	d.push_back(21);
	d.push_back(17);
	d.push_back(7);
	print(d);

	// ����
	sort(d.begin(), d.end());
	print(d);

	// �Ӵ�С
	sort(d.begin(), d.end(), myCompare);
	print(d);

}

int main() {
	test();
	system("pause");
	return EXIT_SUCCESS;
}

