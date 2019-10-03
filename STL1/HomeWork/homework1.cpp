#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
class Player {
public:
	Player(string name, float socre) {
		this->m_Socre = socre;
		this->name = name;
	}
	string name;  // 人名
	float m_Socre; // 平均分分数
};
void createPerson(vector<Player> & v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "先手";
		name += nameSeed[i];

		float score = 0.0;
		Player p(name, score);
		v.push_back(p);
	}
}

void SetScore(vector<Player> & v) {
	for (vector<Player>::iterator it = v.begin(); it != v.end(); ++it) {
		// 对五个人打分
		deque<int> d;
		for (int i = 0; i < 10; i++){
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		// 先看一下打分
		/*for (deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit) {
			cout << *dit << " ";
		}
		cout << endl;*/
		// 排序
		sort(d.begin(), d.end());  // 默认是从小到大

		// 去处最高和最低分
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit) {
			sum += *dit;
		}
		float avg = (float)sum / d.size();
		it->m_Socre = avg;
	}
}

void showScore(vector<Player> & v) {
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++){
		cout << "姓名：" << (*it).name << "  平均分数：" << (*it).m_Socre << endl;
	}
}

int main() {

	// 创建容器 存放人名
	vector<Player> v;
	createPerson(v);
	SetScore(v);
	// 打分

	/*for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).name << "  分数：" << (*it).m_Socre << endl;
	}*/
	// 展示平均分
	showScore(v);

	system("pause");
	return EXIT_SUCCESS;
}

