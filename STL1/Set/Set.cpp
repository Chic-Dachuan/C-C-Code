#include<iostream>
using namespace std;
#include<string>
#include<set>  // ����������  set mulset �������ͷ�ļ���
// ���������Զ�����

void printSet(set<int> & sl) {
	for (set<int>::iterator it = sl.begin(); it != sl.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	// ���캯��
	set<int> sl;
	// ֻ�ܲ��벻��push
	sl.insert(5);
	sl.insert(10);
	sl.insert(1);
	sl.insert(3);
	sl.insert(6);
	sl.insert(4);
	sl.insert(2);
	printSet(sl);  // �Զ�����key���� ������Ĭ�ϴ�С���� set����ֻ��keyֵ��value��keyֵͬ

	// �ж��Ƿ�Ϊ��
	if (sl.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "size" << sl.size() << endl;
	}
	/*
		insert(elem);//�������в���Ԫ�ء�
		clear();//�������Ԫ��
		erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
		erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
		erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
	*/

	// erase ɾ��  
	sl.erase(sl.begin());
	sl.erase(1);  
}

// ���Ҳ���
/*
	find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
	count(key);//���Ҽ�key��Ԫ�ظ���
	lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

*/
void test2() {
	set<int> sl;
	sl.insert(5);
	sl.insert(7);
	sl.insert(1);
	sl.insert(3);
	sl.insert(6);
	sl.insert(4);
	sl.insert(2);

	set<int>::iterator pos1 = sl.find(0);  // û���ҵ�����sl.end()

	// �ж��Ƿ��ҵ�
	if (pos1 != sl.end()) {  // �ҵ�
		cout << *pos1 << endl;
	}
	else {
		cout << "û��" << endl;
	}

	int num = sl.count(1);  // ��set���� ����1��0 �о���1û�о���0
	cout << "1�ĸ���Ϊ" << num << endl;

	// lower_bound
	set<int>::iterator pos2 = sl.lower_bound(3);  // ���ص�һ��key>=keyElemԪ�صĵ������� 
	if (pos2 != sl.end()) {  // �ҵ�
		cout << "�ҵ���" << *pos2 << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}

	// upper_bound   ���ص�һ��key>keyElemԪ�صĵ�������
	set<int>::iterator pos3 = sl.upper_bound(3);
	if (pos3 != sl.end()) {  // �ҵ�
		cout << "�ҵ���" << *pos3 << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}
	
	// equal_range(keyElem)   ����������key��keyElem��ȵ������޵�������������  ��������ֵ
	// pair ��ʾ����  pair<key1,key2>  ��ʾ����ֵ
	// �����޾��� lower_bound �� upper_bound
	pair<set<int>::iterator, set<int>::iterator> ret = sl.equal_range(3);

	// ��ȡ pair�е�ֵ
	if (ret.first != sl.end()) {  // ��ȡ��һ��ֵ
		cout << "�ҵ�equal_range�е�lower_boundֵ" << *(ret.first) << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	// ��ȡ�ڶ���ֵ
	if (ret.second != sl.end()) {
		cout << "�ҵ�equal_range�е�upper_boundֵ" << *(ret.second) << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
}
/*
	set��������������ظ���ֵ
*/
void test3() {
	set<int> sl;
	pair<set<int>::iterator, bool> ret = sl.insert(10);
	if (ret.second) {
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	pair<set<int>::iterator, bool> ret1 = sl.insert(10);
	if (ret1.second) {
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	printSet(sl);

}

// set����
// ָ��set�������Ӵ�С   �º���  ��һ����
// �º���
class MyCompare {
public:
	// ����
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};


void test4() {
	// set<int> sl;
	set<int, MyCompare>sl;
	sl.insert(5);
	sl.insert(7);
	sl.insert(1);
	sl.insert(3);
	sl.insert(6);
	sl.insert(4);
	sl.insert(2);
	// printSet(sl);  // ÿ�����������Լ�ר��������
	// �Ӵ�С����
	// ֻ���ڲ���֮ǰָ���������   set��������֮����������ı�����
	// ����ı�setԪ��ֵ���������ƻ�set��֯�����仰˵��set��iterator��һ��const_iterator.
	for (set<int, MyCompare>::iterator it = sl.begin(); it != sl.end(); ++it) {
		cout << *it << endl;
	}
		
}

// �Զ�����������

class Person {
public:
	Person(string name, int age) {
		this->Name = name;
		this->Age = age;
	}
	string Name;
	int Age;
};

class myCompare {  // �º���
public:
	bool operator()(const Person & p1, const Person & p2) {  // �������м���const�޶���ֹ�޸�
		return p1.Age > p2.Age;
	}
};

void test() {
	set<Person, myCompare> sl;

	Person p1("����", 20);
	Person p2("�ͽ�����", 22);
	Person p3("������", 40);
	Person p4("��ħС��ʦ", 12);
	Person p5("Сѧ��֮��", 35);
	Person p6("������", 35);
	Person p7("����ki", 40);
	Person p8("����", 34);

	// �����Զ����������ͣ� ������ǰָ���������
	sl.insert(p1);
	sl.insert(p2);
	sl.insert(p3);
	sl.insert(p4);
	sl.insert(p5);
	for (set<Person, myCompare>::iterator it = sl.begin(); it != sl.end(); ++it) {
		cout << "����  " << it->Name << "  ����  " << it->Age << endl;
	}
}

//  mulset ��������ظ���ֵ
int main() {

	test();
	system("pause");
	return EXIT_SUCCESS;
}

