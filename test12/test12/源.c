#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define N 1100

struct edge {
	int y, next;
}e[501 * 501 * 4];
struct link {
	int x, y;
}link[N];

int n, m, component, top, tops, id;
int first[N], dfn[N], low[N], stack[N], strong[N];

void init() {
	tops = -1;
	top = component = id = 0;
	memset(first, -1, sizeof(first));
	memset(dfn, -1, sizeof(dfn));
	memset(strong, 0, sizeof(strong));
}
void add(int x, int y) {
	e[top].y = y;
	e[top].next = first[x];
	first[x] = top++;
}
int test_cross(int i, int j) {
	int num = 0, k;
	int x1 = link[i].x;
	int y1 = link[i].y;
	int x2 = link[j].x;
	int y2 = link[j].y;
	for (k = min(x1, y1) + 1; k<max(x1, y1); k++) {//两对点交替排列则num值必为1
		if (k == x2 || k == y2)
			num++;
	}
	return num == 1;
}
void tarjan(int x) {
	int i, y;
	dfn[x] = low[x] = ++id;
	stack[++tops] = x;
	for (i = first[x]; i != -1; i = e[i].next) {
		y = e[i].y;
		if (dfn[y] == -1) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (!strong[y])
			low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		component++;
		do {
			strong[stack[tops]] = component;
		} while (stack[tops--] != x);
	}
}
int main() {
	int i, j;
	// freopen("a.txt", "r", stdin);
	init();
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &link[i].x, &link[i].y);
	}
	for (i = 1; i<m; i++)
	{
		for (j = i + 1; j <= m; j++)
		{
			if (test_cross(i, j)) {
				add(i, j + m); add(j, i + m);
				add(i + m, j); add(j + m, i);
			}
		}	
	}
		
	for (i = 1; i <= 2 * m; i++)
	{
		if (dfn[i] == -1)
			tarjan(i);
	}
	for (i = 1; i <= m; i++)
	{
		if (strong[i] && (strong[i] == strong[i + m]))
			break;
	}
	if (i > m)
	{
		printf("panda is telling the truth...\n");
	}
	else {
		printf("the evil panda is lying again\n");
	}
	system("pause");
	return 0;
}