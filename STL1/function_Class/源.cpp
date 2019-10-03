#include<iostream>
using namespace std;
/*
���غ������ò��������࣬����󳣳�Ϊ��������function object����
����������Ϊ���ƺ����Ķ���Ҳ�зº���(functor),��ʵ�������ء�()����������ʹ���������������������á�
1.��������(�º���)��һ���࣬����һ��������
2.��������(�º���)�����ˡ�() ��������ʹ������������һ�����á�
  
  һԪ�º�����  ����ֻ��һ������
  ��Ԫ�º�����  ���Ǵ���������

*/

class MyPrint {  // �º���  ���Ǻ�������
public:
	MyPrint() {
		this->count = 0;
	}
	void operator() (int num) {
		cout << "num = " << num << endl;
		count++;
	}
	int count;
};

void test1() {
	MyPrint myprint;
	myprint(111);
}

// �������󳬳�����ͨ�����ĸ�����Ա��溯���ĵ���״̬
void test2() {
	MyPrint myprint;
	myprint(100);
	myprint(100);
	myprint(100);
	myprint(100);
	cout << myprint.count << endl;
}

// ����������Ϊ��������
void doPrint(MyPrint myprint, int num) {
	myprint(num);
}

void test() {
	doPrint(MyPrint(), 20); // ����һ ������������
}

/*

1����������ͨ�������幹�캯�������������������ڹ��������ʱ���ᷢ���κ����⣬�����˺������õ�����ʱ���⡣
2���������󳬳���ͨ�����ĸ����������������Լ���״̬
3������������������룬���ܺá��ú���ָ�뼸��������
4��ģ�溯������ʹ�����������ͨ���ԣ���Ҳ����������֮һ

*/

int main() {

	test();

	system("pause");
	return 0;
}
