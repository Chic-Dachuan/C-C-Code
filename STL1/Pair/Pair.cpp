#include<iostream>
using namespace std;
#include<string>

void test() {
	// ��������
	pair<string, int> p(string("Tom"), 100);
	// ȡֵ
	cout << "����: " << p.first << endl;  // ȡ��һ��ֵ
	cout << "����: " << p.second << endl; // ȡ�ڶ���ֵ

	// �ڶ��ִ�����ʽ
	pair<string, int> p2 = make_pair("Jerry", 90);
	cout << "����: " << p2.first << endl;  // ȡ��һ��ֵ
	cout << "����: " << p2.second << endl; // ȡ�ڶ���ֵ
}

int main() {

	test();
	system("pause");
	return EXIT_SUCCESS;
}
