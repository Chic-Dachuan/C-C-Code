#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL __int64
LL pp(LL xx)
{
	if (xx == 1)
		return 0;
	if (xx == 2)
		return 0;
	if (xx == 3)
		return 0;
	if (xx == 4)
		return 1;
	if (xx == 5)
		return 2;
	else
	{
		return xx / 2 + pp(xx / 2);
	}
}
void solve()
{
	LL n; scanf("%I64d", &n);
	if (n == 2)
	{
		printf("1\n");
		return;
	}
	printf("%I64d\n",n+pp(n));// 内接成形法---
	//二：printf("%d\n",2*n-3);一圈加一点接所有
	//LL kp=max(n+pp(n),2*n-3);
	//方法二是虽有的
	printf("%I64d\n", 2 * n - 3);
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}