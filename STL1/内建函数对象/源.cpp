#include<iostream>
#include<functional>  // �ڽ�����ͷ�ļ�
#include<vector>
#include<algorithm>
using namespace std;

/*  ����negate��һԪ���㣬�������Ƕ�Ԫ����

template<class T> T plus<T>//�ӷ��º���
template<class T> T minus<T>//�����º���
template<class T> T multiplies<T>//�˷��º���
template<class T> T divides<T>//�����º���
template<class T> T modulus<T>//ȡģ�º���
template<class T> T negate<T>//ȡ���º���

*/

void test1() {
	negate<int> v;  // ȡ��
	cout << v(10) << endl;
	// �ӷ�
	plus<int>p;  // ֻ������ͬ�������
	cout << p(1, 1) << endl;
}

/*
template<class T> bool equal_to<T>//����
template<class T> bool not_equal_to<T>//������
template<class T> bool greater<T>//����
template<class T> bool greater_equal<T>//���ڵ���
template<class T> bool less<T>//С��
template<class T> bool less_equal<T>//С�ڵ���
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