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
	string name;  // ����
	float m_Socre; // ƽ���ַ���
};
void createPerson(vector<Player> & v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "����";
		name += nameSeed[i];

		float score = 0.0;
		Player p(name, score);
		v.push_back(p);
	}
}

void SetScore(vector<Player> & v) {
	for (vector<Player>::iterator it = v.begin(); it != v.end(); ++it) {
		// ������˴��
		deque<int> d;
		for (int i = 0; i < 10; i++){
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		// �ȿ�һ�´��
		/*for (deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit) {
			cout << *dit << " ";
		}
		cout << endl;*/
		// ����
		sort(d.begin(), d.end());  // Ĭ���Ǵ�С����

		// ȥ����ߺ���ͷ�
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
		cout << "������" << (*it).name << "  ƽ��������" << (*it).m_Socre << endl;
	}
}

int main() {

	// �������� �������
	vector<Player> v;
	createPerson(v);
	SetScore(v);
	// ���

	/*for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).name << "  ������" << (*it).m_Socre << endl;
	}*/
	// չʾƽ����
	showScore(v);

	system("pause");
	return EXIT_SUCCESS;
}

