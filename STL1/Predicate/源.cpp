#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
ν����ָ��ͨ���������ص�operator()����ֵ��bool���͵ĺ�������(�º���)��
���operator����һ����������ô����һԪν��,�����������������
��ô������Ԫν�ʣ�ν�ʿ���Ϊһ���ж�ʽ��
*/

class Find {
public:
	bool operator() (int val) {
		return val > 20;
	}
};
void test1() {
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30); 
	vec.push_back(40); 
	vec.push_back(50);

	// ���ҵ�һ������20����
	vector<int>::iterator pos = find_if(vec.begin(), vec.end(), Find());  //�����������º���   ����һ���������� �����Ķ���
	if (pos != vec.end()) {
		cout << "�ҵ�����20���� " << *pos << endl;
	}
	else
	{
		cout << "û�ҵ�����20����" <<endl;
	}
}

//��Ԫν��

class MyCompare {
public:
	bool operator() (int v1, int v2) {
		return v1 > v2;
	}
};

void test(){
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	
	sort(vec.begin(), vec.end(), MyCompare());
	// ��������  lamda���ʽ	[] () {}  []��ʶ�� () ���� {} ʵ����
	for_each(vec.begin(), vec.end(), [](int val) {cout << val << " "; });

}
int main() {
	test();

	system("pause");
	return 0;
}
