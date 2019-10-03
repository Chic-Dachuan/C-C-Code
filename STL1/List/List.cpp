#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>
#include<string>
#include<algorithm>
/*
������һ������洢��Ԫ�Ϸ���������˳��Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ�����Ӵ���ʵ�ֵġ�
������һϵ�н�㣨������ÿһ��Ԫ�س�Ϊ��㣩��ɣ�������������ʱ��̬���ɡ�ÿ���������������֣�
һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
�����vector���������Կռ䣬list���Եø�����࣬���ĺô���ÿ�β������ɾ��һ��Ԫ�أ��������û����ͷ�һ��Ԫ�صĿռ䡣
��ˣ�list���ڿռ�������о��Եľ�׼��һ��Ҳ���˷ѡ����ң������κ�λ�õ�Ԫ�ز����Ԫ�ص��Ƴ���list��Զ�ǳ���ʱ�䡣

List������һ��˫��ѭ������  ��һ�ֲ�֧��������ʵ�����
*/

//void test1() {
//
//	list<int> myList;
//	for (int i = 0; i < 10; i++) {
//		myList.push_back(i);
//	}
//
//	list<int>::_Nodeptr node = myList._Myhead->_Next;
//
//	for (int i = 0; i < myList._Mysize * 2; i++) {
//		cout << "Node:" << node->_Myval << endl;
//		node = node->_Next;
//		if (node == (list<int>::_Nodeptr) myList._Myhead) {
//			node = node->_Next;
//		}
//	}
//}
void printList(list<int> &l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	// ���캯�� 
	list<int>l(10, 10);  // ��10��10��ʼ��һ������
	list<int>l2(l.begin(), l.end());  // ��������
	printList(l);
	printList(l2);
	l2.push_back(100);
	// �����ӡ
	for (list<int>::reverse_iterator it = l2.rbegin(); it != l2.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// list��������֧���������

	/*list<int>::iterator itbegin = l2.begin();
	itbegin += 1;*/

	//��������
	list<int>l3;
	l3.push_back(10);
	l3.push_back(30); 
	l3.push_back(20);
	l3.push_front(100);
	l3.push_front(300);
	l3.push_front(200);
	printList(l3);

	// ɾ������
	l3.pop_front(); // ɾ��ͷ��
	l3.pop_back(); // ɾ��β��

	// insert(pos, elem)  or insert(pos, n, elem)  pos ��һ�������� ��ʾ�ڵ�����λ�ò���һ��Ԫ�ػ���n��Ԫ��
	// insert(pos, beg, end)  ��ʾ��posλ�ò��� beg �� end֮����������  beg �� end Ҳ�ǵ�����

	l3.insert(l3.begin(), 1000);
	// l3.insert(l3.back(), 2000);
	l3.insert(l3.end(), 2000);
	printList(l3);
	l3.push_back(10);
	// remove
	l3.remove(10);  // ɾ�����е�10
	printList(l3);
}

void test2() {
	list<int>l3;
	l3.push_back(10);
	l3.push_back(30);
	l3.push_back(20);
	l3.push_front(100);
	l3.push_front(300);
	l3.push_front(200);
	cout << "��С" << l3.size() << endl;
	if (l3.empty())
	{
		cout << "l3Ϊ��" << endl;
	}
	else
	{
		cout << "l3��Ϊ��" << endl;
	}

	// resize�޸�����Ĵ�С
	l3.resize(10);  // ������0���
	printList(l3);

	l3.resize(5);  // ɾ��β�����������
	printList(l3);
	
	list<int> l;
	l.assign(l3.begin(), l3.end());  // ��ֵ����

	cout << "front" << l.front() << endl;
	cout << "back" << l.back() << endl; 
}

// ��ת����
// reverse() ��ת����
// sort() ��������
bool myCompare(int vl1, int vl2) {
	return vl1 > vl2;
}

void test3() {
	list<int>L;
	L.push_back(20);
	L.push_back(10);
	L.push_back(40);
	L.push_back(30);
	L.push_back(5);
	// ��ת
	L.reverse();
	printList(L);
	// ����  
	/*
		���в�֧��������ʵĵ������� ��������ϵͳ�ṩ���㷨
		�����֧��ϵͳ���㷨��ô������ڲ����ṩ����
	*/
	// sort(L.begin(), L.end());
	L.sort();  // ��С��������
	printList(L);

	// �Ӵ�С
	L.sort(myCompare);  // �ص�����
	printList(L);
}

// �Զ�����������

class Person {
public:
	Person(string name, int age, float height) {
		this->Name = name;
		this->Age = age;
		this->Height = height;
	}
	string Name;
	int Age;
	float Height;

	// ���� == ��remove����ɾ���Զ�����������
	bool operator==(const Person & p) {  // �����޶�Ϊֻ������
		if (this->Name == p.Name && this->Age == p.Age && this->Height == p.Height){
			return true;
		}
		return false;
	}
};
bool MyCompare(Person & p1, Person & p2) {  // Person������� �Ȱ����������� ����һ���������
	if (p1.Age == p2.Age)
	{
		return p1.Height < p2.Height;
	}
	return p1.Age > p2.Age;
}

void test() {
	list<Person> L;
	Person p1("����", 20, 177.0);
	Person p2("�ͽ�����", 22, 165.66);
	Person p3("������", 40, 180.80);
	Person p4("��ħС��ʦ", 12, 150.6);
	Person p5("Сѧ��֮��", 35, 178.1);
	Person p6("������", 35, 176.2);
	Person p7("����ki", 40, 166.6);
	Person p8("����", 34, 144.0);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);
	// �������併��ʧ��
	/*
		�����Զ����������ͱ����ƶ��������
	*/
	L.sort(MyCompare);
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
		cout << "����: " << it->Name << "  ����: " << it->Age << " ���: " << it->Height << endl;
	}
	cout << "__________________________" << endl;
	// removeɾ���Զ�����������
	L.remove(p8);
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
		cout << "����: " << it->Name << "  ����: " << it->Age << " ���: " << it->Height << endl;
	}
}
int main() {    
	test();
	system("pause");
	return EXIT_SUCCESS;
}
