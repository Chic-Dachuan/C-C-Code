#include<iostream>
#include<stack>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

stack<int> sorting(stack<int>);

int main()
{
	stack<int> stc;
	int temp;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 20; i++)
	{
		temp = rand() % 100;
		cout << temp << "  ";
		stc.push(temp);
	}
	cout << endl;
	stc = sorting(stc);
	vector<int> answer;
	while (!stc.empty())
	{
		answer.insert(answer.begin(), stc.top());
		// answer.push_back(stc.top());
		stc.pop();
	}
	/*for (vector<int>::reverse_iterator it = answer.rbegin(); it != answer.rend(); ++it)
	{
		cout << *it << "  ";
	}*/
	for (vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
	{
		cout << *it << "  ";
	}
	/*for (int i = 0; i < 20; i++)
	{
		cout << "%2d" << stc.top() << "  ";
		stc.pop();
	}*/
	cout << endl;
	system("pause");
	return 0;
}

stack<int> sorting(stack<int> MyStack)
{
	stack<int> result;
	if (MyStack.empty())
	{
		return result;
	}
	int temp = MyStack.top();
	MyStack.pop();
	while (!MyStack.empty() || ((!result.empty()) && (result.top() > temp)))
	{
		if (result.empty() || result.top() <= temp)
		{
			result.push(temp);
			temp = MyStack.top();
			MyStack.pop();
		}
		else
		{
			MyStack.push(result.top());
			result.pop();
		}
	}
	result.push(temp);
	return result;
}
