#include<iostream>
using namespace std;
#include<string>
#include<stdexcept> // �쳣��׼ͷ�ļ�


void test() {
	string str = "hello";
	cout << str[5] << endl;  // ������� \0�ַ�
}

/*
дһ�������������ڲ���string�ַ���������Сд��ĸ����Ϊ��д��ĸ
*/
void test9() {
	string s = "aBcDefgHijk";
	for (int i = 0; i < s.size(); ++i) {
		s[i] = toupper(s[i]);
	}
	cout << s << endl;

	for (int i = 0; i < s.size(); ++i) {
		s[i] = tolower(s[i]);
	}
	cout << s << endl;

}

void test8() {
	string s = "abcdef";
	char & a = s[1];
	char & b = s[2];
	a = '1';
	b = '2';
	cout << s << endl;
	cout << (int *)s.c_str() << endl;  // s.c_str()��sת��ΪC-style�µ��ַ���(int*)ת��Ϊ��ַ

	s = "ppppppppppppppppppppp"; // �˴�s�Ѿ�ָ���ĵط�������������һ���ڴ�
	a = '1';  // ����a��b�������õ�ԭsָ��ط�s[1] ��s[2]�����ڴ�λ��
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "ppp"; // �˴�s����ָ��ԭsָ��ĵ�ַ��û�����·����ڴ棬ԭs��6���ַ� ���ֻ��3���ʲ���Ҫ���·����ڴ�
	a = '1';  // ����a��b�������õ�ԭsָ��ط�s[1] ��s[2]�����ڴ�λ��
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;
}

// string �� C-style�ַ���ת��

void func(string s) {
	cout << s << endl;
}

void func2(char * s) {
	cout << s << endl;
}
void test7() {
	string s1 = "hello world";
	// string ת����C-style ��const char*
	const char * p = s1.c_str();

	// C-styleת���� string
	string s2(p);  // ����string�Ĺ��췽��ת��

	func(p);  // const char* ��ʽ����ת��Ϊstring

	// func2(s2);  // string ��������ʽ����ת��Ϊ char*
}


// �ַ������ɾ������
void test6() {
	string s1 = "hello";
	s1.insert(1, "ddd");  // ��1��ʼ���� ddd�ַ�
	cout << s1 << endl;

	// ɾ��
	s1.erase(1, 3);  // ��1��ʼɾ��3���ַ�
	cout << s1 << endl;
}


void test5() {
	string s1 = "abcde";
	string s2 = s1.substr(1, 3);  // ���ش�1��ʼ֮���3���ַ���s2
	cout << s2 << endl;

	// ����һ���Ҽ����û���
	string email = "Zerkerbery@163.com";
	int pos = email.find("@");
	cout << pos << endl;
	string username = email.substr(0, pos);
	cout << username << endl;
}

// �ַ����Ƚ�
void test4() {
	// compare  > ����1  < ���� -1  = ����0
	string s1 = "abcdf";
	string s2 = "abddf";
	if (s1.compare(s2) == 0)
	{
		cout << "s1 = s2" << endl;
	}
	else if (s1.compare(s2) == 1) {
		cout << "s1 > s2" << endl;
	}
	else {
		cout << "s1 < s2" << endl;
	}
}

// �ַ���ƴ������� �滻
void test3() {
	string s1 = "hello";
	string s2 = " world";
	s1 += s2;
	cout << s1 << endl;

	s1.append(" i love you");
	cout << s1 << endl;
	string s = "abcdeg";
	cout << s.find("bc") << endl;  // �����������ַ�����һ�γ��ֵ�λ�� �Ҳ�������-1
	cout << s.rfind("bc") << endl; // ����������� ���ǲ��ҷ�ʽһ��


	// �滻
	string s3 = "hahaha";
	s3.replace(1, 3, "11111"); // ��1��ʼ3���ַ����滻���ַ�1111  ��ʾ3���ַ����滻��11111  ��� h11111ha
	cout << s3 << endl;
}

// string ��ȡ
void test2() {
	string s = "hello world";
	for (int i = 0; i < s.size(); ++i) {
		// cout << s[i] << endl;
		cout << s.at(i) << endl;
		// [] ��at����
		// [] ����Խ�磬 ֱ�ӽ������� �ҵ�  at Խ���ʱ����׳��쳣
	}
	try
	{
		// cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (out_of_range & e) {
		cout << e.what() << endl;
	}
	/*{
		cout << "Խ���쳣" << endl;
	}*/
}

void test1() {
	string str; // Ĭ�Ϲ���
	string str2(str); // ��������
	string str3 = str;  // ��������

	string str4 = "abcd";

	string str5(10, 'c');  // ����10���ַ�c����ʼ���ַ���str5

	cout << str4 << endl;
	cout << str5 << endl;

	// ������ֵ
	str = "hello world";
	str2 = str4;  // �Ⱥ�����

	str3.assign("abcdef", 4);
	cout << str3 << endl;

	string str6;
	str6.assign(str, 2, 4); // ���㿪ʼ���� ��str �� 2 -- 4(����) �ַ���ֵ��str6 
	cout << str6 << endl;
}

int main() {


	test();
	system("pause");
	return EXIT_SUCCESS;
}