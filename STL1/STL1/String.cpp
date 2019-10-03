#include<iostream>
using namespace std;
#include<string>
#include<stdexcept> // 异常标准头文件


void test() {
	string str = "hello";
	cout << str[5] << endl;  // 输出最后的 \0字符
}

/*
写一个函数，函数内部将string字符串的所有小写字母都变为大写字母
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
	cout << (int *)s.c_str() << endl;  // s.c_str()把s转换为C-style下的字符串(int*)转换为地址

	s = "ppppppppppppppppppppp"; // 此处s已经指向别的地方，重新申请了一块内存
	a = '1';  // 但是a和b还是引用的原s指向地方s[1] 和s[2]两个内存位置
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "ppp"; // 此处s还是指向原s指向的地址，没有重新分配内存，原s有6个字符 这儿只有3个故不需要重新分配内存
	a = '1';  // 但是a和b还是引用的原s指向地方s[1] 和s[2]两个内存位置
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;
}

// string 与 C-style字符串转换

void func(string s) {
	cout << s << endl;
}

void func2(char * s) {
	cout << s << endl;
}
void test7() {
	string s1 = "hello world";
	// string 转换成C-style 的const char*
	const char * p = s1.c_str();

	// C-style转换成 string
	string s2(p);  // 按照string的构造方法转换

	func(p);  // const char* 隐式类型转换为string

	// func2(s2);  // string 不可以隐式类型转换为 char*
}


// 字符插入和删除操作
void test6() {
	string s1 = "hello";
	s1.insert(1, "ddd");  // 从1开始插入 ddd字符
	cout << s1 << endl;

	// 删除
	s1.erase(1, 3);  // 从1开始删除3个字符
	cout << s1 << endl;
}


void test5() {
	string s1 = "abcde";
	string s2 = s1.substr(1, 3);  // 返回从1开始之后的3个字符给s2
	cout << s2 << endl;

	// 查找一个右键的用户名
	string email = "Zerkerbery@163.com";
	int pos = email.find("@");
	cout << pos << endl;
	string username = email.substr(0, pos);
	cout << username << endl;
}

// 字符串比较
void test4() {
	// compare  > 返回1  < 返回 -1  = 返回0
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

// 字符串拼接与查找 替换
void test3() {
	string s1 = "hello";
	string s2 = " world";
	s1 += s2;
	cout << s1 << endl;

	s1.append(" i love you");
	cout << s1 << endl;
	string s = "abcdeg";
	cout << s.find("bc") << endl;  // 返回所查找字符串第一次出现的位置 找不到返回-1
	cout << s.rfind("bc") << endl; // 从右往左查找 但是查找方式一样


	// 替换
	string s3 = "hahaha";
	s3.replace(1, 3, "11111"); // 从1开始3个字符被替换成字符1111  表示3个字符被替换成11111  结果 h11111ha
	cout << s3 << endl;
}

// string 存取
void test2() {
	string s = "hello world";
	for (int i = 0; i < s.size(); ++i) {
		// cout << s[i] << endl;
		cout << s.at(i) << endl;
		// [] 与at区别
		// [] 访问越界， 直接结束程序 挂掉  at 越界的时候会抛出异常
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
		cout << "越界异常" << endl;
	}*/
}

void test1() {
	string str; // 默认构造
	string str2(str); // 拷贝构造
	string str3 = str;  // 拷贝构造

	string str4 = "abcd";

	string str5(10, 'c');  // 采用10个字符c来初始化字符串str5

	cout << str4 << endl;
	cout << str5 << endl;

	// 基本赋值
	str = "hello world";
	str2 = str4;  // 等号重载

	str3.assign("abcdef", 4);
	cout << str3 << endl;

	string str6;
	str6.assign(str, 2, 4); // 从零开始索引 把str 的 2 -- 4(包含) 字符赋值给str6 
	cout << str6 << endl;
}

int main() {


	test();
	system("pause");
	return EXIT_SUCCESS;
}