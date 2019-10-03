#include<iostream>
using namespace std;
#include<vector>

void test1() {
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		cout << v.capacity() << endl; // �������ǰ���2����������չ�� �������˼�ʵ����һ���㷨
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
	// Ĭ�Ϲ��캯��
	vector<int> v;

	int arr[] = { 2, 3, 4, 5, 6 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));  //  ��һ������begin �ڶ������� ��end Ҳ�������һ��λ�� + 1
	// ����������������
	vector<int> v2(v.begin(), v.end());
	printVector(v1);

	vector<int> v3(10, 100); // ��ʾ��10��100��ʼ��һ������
	
	// ��ֵ
	vector<int> v4;
	v4.assign(v3.begin(), v3.end());

	v4.assign(11, 100);  // ������v4��ֵ11��100 
	printVector(v4);  
	cout << "v4��������С" << v4.size() << endl;
	v4.swap(v1);
	cout << "�������v4" << endl;
	printVector(v4);
	cout << "v4��������С" << v4.size() << endl;

	if (v4.empty()) // ����СΪ0Ҳ��ʾΪ��
	{
		cout << "v4Ϊ��" << endl;
	}
	else
	{
		cout << "v4Ϊ����" << endl;
	}

	// v4 23456
	v4.resize(10); // ����5������0  Ĭ����0��������
	printVector(v4);
	v4.resize(10, -1);  // ����5������-1 

	v4.resize(3);
	printVector(v4); 

}
// ����swap�������ռ�
void test3() {
	vector<int> v;
	for (int i = 0; i < 100000; ++i) {
		v.push_back(i);
	}
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl;
	v.resize(3);
	cout << "v��������" << v.capacity() << endl;  // ��������  
	cout << "v�Ĵ�С��" << v.size() << endl;  // ��С��Ϊ3

	// ����swap
	vector<int>(v).swap(v); // �൱����V��С�������ʼ����������
	cout << "v��������" << v.capacity() << endl; // ����Ϊ3 
	cout << "v�Ĵ�С��" << v.size() << endl;  // ��СΪ3
}

void test4() {
	vector<int> v;
	v.reserve(100000);  // ���֪������ж��ٸ����� ��ô���Բ���reserve ��Ԥ���ռ� �����ο��ٿռ�������ܽ���
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
	// ����100000�����ݣ� ���ٶ��ٴοռ�
}

// ���ݴ洢 ����
void test5() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "v��front:" << v.front() << endl;  // ��һ��Ԫ��

	cout << "v��back:" << v.back() << endl;  // �ڶ���Ԫ��

	// ����
	v.insert(v.begin(), 100);  // ��һ������������һ�������� v.begin() ����һ��������
	printVector(v);
	v.insert(v.begin(), 3, 100);  // ��һ������������һ�������� v.begin() ����һ��������  �ڶ��������ǲ�����ٸ�  �����������ǲ����Ԫ��

	v.pop_back(); // ɾ�����һ��Ԫ�� βɾ
	printVector(v);

	v.erase(v.begin());  // ɾ��������ָ���Ԫ��
	printVector(v);
	v.erase(v.begin(), v.end());
	if (v.size())
	{
		cout << "vΪ��" << endl;
	}
	v.clear(); // �����������
}

void test6() {
	// vector�����������
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	printVector(v);

	// ��Ҫ����ĵ�����reverse_iterator
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << " ";
	}

	// vector������һ��������ʵĵ�����  �ص� ֧����Ծʽ����
	vector<int> ::iterator itb = v.begin();
	itb += 3;  
	// list ������֧���������

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