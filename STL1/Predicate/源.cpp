#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。
如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，
那么叫做二元谓词，谓词可作为一个判断式。
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

	// 查找第一个大于20的数
	vector<int>::iterator pos = find_if(vec.begin(), vec.end(), Find());  //第三个参数仿函数   传入一个函数对象 匿名的对象
	if (pos != vec.end()) {
		cout << "找到大于20的数 " << *pos << endl;
	}
	else
	{
		cout << "没找到大于20的数" <<endl;
	}
}

//二元谓词

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
	// 匿名函数  lamda表达式	[] () {}  []标识符 () 参数 {} 实现体
	for_each(vec.begin(), vec.end(), [](int val) {cout << val << " "; });

}
int main() {
	test();

	system("pause");
	return 0;
}
