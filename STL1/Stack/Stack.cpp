#include<iostream>
using namespace std;
#include<stack>
/*
stack��һ���Ƚ����(First In Last Out,FILO)�����ݽṹ��
��ֻ��һ�����ڣ���ʽ��ͼ��ʾ��stack������������Ԫ�أ�
�Ƴ�Ԫ�أ�ȡ��ջ��Ԫ�أ����ǳ�������⣬
û���κ������������Դ�ȡstack������Ԫ�ء�
����֮��stack�������б�����Ϊ��
�ʣ�ջ����û�е�����
*/
void test() {

	// ���캯��
	stack<int> st;
	// ��������
	st.push(10);
	st.push(30);
	st.push(20);
	st.push(50);
	while (st.size() != 0)
	{
		cout << "ջ������: " << st.top() << endl;
		// ����ջ��Ԫ��
		st.pop();
	}
}

int main() {
	test();
	system("pause");
	return	EXIT_SUCCESS;
}