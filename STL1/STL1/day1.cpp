#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

// ����Ƕ��
void test() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	// ��С�������������֮��
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	// ����
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
			cout << *vit << "\t";
		}
		cout << endl;
	}
}


// �����Զ������������
class Person {
	
public:
	Person(string name, int age) {
		this->Age = age;
		this->Name = name;
	}
	string Name;
	int Age;

};
void showInfo(Person p) {
	cout << "����:" << p.Name << "\n ����:" << p.Age << endl;
}
// ����Զ�����������ָ��
void test04() {
	vector<Person*>v;  // ��� Person*���͵�����
	Person p1("Jobs", 50);
	Person p2("��������", 45);
	Person p3("Сͷ�ְ�", 40);
	Person p4("��ͷ����", 12);
	v.push_back(&p1);  // Ӧ�ðѵ�ַ��Ž�ȥ
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it) { // it ��һ��ָ�� Person* ���͵�ָ��
		cout << (*it)->Name << (*it)->Age << endl;
	}

}
void test03() {
	vector<Person> vp;
	Person p1("Jobs", 50);
	Person p2("��������", 45);
	Person p3("Сͷ�ְ�", 40);
	Person p4("��ͷ����", 12);
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);

	// ����
	for_each(vp.begin(), vp.end(), showInfo);
}

void myprint(int v) {
	cout << v << endl;
}

void test02() {
	// ����һ������
	vector<int> v; // ����һ��int���͵���������v
	v.push_back(1);  // �������м������� β�巨
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// ���������е�����
	// �����õ�����
	// ite �� itb��ָ��
	vector<int>::iterator itb = v.begin(); // ��ʾ����һ��vector<int>::���������������µĵ���������it�� itָ��v��������ʼλ��begin
	vector<int>::iterator ite = v.end();  // ָ���������һ��λ�õ���һ��
	/*while (itb != ite)
	{
		cout << *itb << endl;
		itb++;
	}*/
	// �ڶ��ֱ�������
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}*/
	// �����������㷨
	for_each(v.begin(), v.end(), myprint);
}


// ������ �����Ĺ��� ��ָ�����
// ��ָͬ��Ҳ�������
void test01() {
	int array[5] = { 1, 3, 5, 7, 9 };
	int * p = array;  // ָ��ָ�������׵�ַ &array[0]

	for (int i = 0; i < 5; ++i) {
		cout << array[i] << endl;
		cout << *p++ << endl;
	}
}

int main() {
	
	test();

	system("pause");
	return EXIT_SUCCESS;
}

