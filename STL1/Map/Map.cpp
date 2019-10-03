#include<iostream>
using namespace std;
#include<map>
/*
Map�������ǣ�����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
Map���е�Ԫ�ض���pair,ͬʱӵ��ʵֵ�ͼ�ֵ��
pair�ĵ�һԪ�ر���Ϊ��ֵ���ڶ�Ԫ�ر���Ϊʵֵ��map����������Ԫ������ͬ�ļ�ֵ��
*/

void test1() {
	// ����
	map<int, int> mp;
	// ����ֵ �����ַ�ʽ
	// ��һ��
	mp.insert(pair<int, int>(1, 10));
	// �ڶ���
	mp.insert(make_pair(2, 20));
	// ������
	mp.insert(map<int, int>::value_type(3, 30));
	// ������
	mp[4] = 40;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		cout << "key=" << it->first << " value=" << it->second << endl;
	}
	cout << mp[5] << endl;  // keyΪ5 valueΪ0
	/*
		size();//����������Ԫ�ص���Ŀ
		empty();//�ж������Ƿ�Ϊ��
	*/
	if (mp.empty()) {
		cout << "Ϊ��" << endl;
	}
	else {
		cout << mp.size() << endl;
	}
}

void test2() {
	map<int, int>mp;
	mp.insert(make_pair(1, 10));
	mp.insert(make_pair(2, 20));
	mp.insert(make_pair(3, 30));
	mp.insert(make_pair(4, 40));
	mp.insert(make_pair(5, 50));
	 /*
		clear();//ɾ������Ԫ��
		erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
		erase(beg,end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
		erase(keyElem);//ɾ��������keyΪkeyElem�Ķ��顣
	 */

	mp.erase(1); //ɾ��keyΪ1������

	// ����
	/*
		find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
		count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
		lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������	
		upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
		equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	*/
	map<int, int>::iterator pos = mp.find(1);
	if (pos != mp.end())
	{
		cout << "�ҵ���" << ", key: " << pos->first << " �� value: " << pos->second << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	int num = mp.count(3);
	
	// lower_bound() 
	map<int, int>::iterator ret = mp.lower_bound(3);
	if (ret != mp.end())
	{
		cout << "�ҵ�" << ", key: " << ret->first << " value:" << ret->second << endl;
	}
	// ipper_bound
	map<int, int>::iterator ret2 = mp.upper_bound(3);
	if (ret2 != mp.end())
	{
		cout << "�ҵ�" << ", key: " << ret->first << " value:" << ret->second << endl;
	}

	// equal_range
	pair<map<int, int>::iterator, map<int, int>::iterator> ret3 = mp.equal_range(3);
	if (ret3.first != mp.end() ) // lower_bound
	{
		cout << "�ҵ�" << "  key:" << ret3.first->first << "   value:" << ret3.first->second << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	if (ret3.second != mp.end()) // upper_bound
	{
		cout << "�ҵ�" << "  key:" << ret3.second->first << "   value:" << ret3.second->second << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
}


// ����
class myCompare {  // �º���
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
void test() {
	map<int, int, myCompare>mp;
	mp.insert(make_pair(1, 10));
	mp.insert(make_pair(2, 20));
	mp.insert(make_pair(3, 30));
	mp.insert(make_pair(4, 40));
	mp.insert(make_pair(5, 50));
	for (map<int, int, myCompare>::iterator it = mp.begin(); it != mp.end(); ++it) {
		cout << "key=" << it->first << "  value=" << it->second << endl;
	}
}

int main() {

	test();

	system("pause");
	return EXIT_SUCCESS;
}
