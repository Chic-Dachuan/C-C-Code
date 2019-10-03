#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define I 20
#define R 340
#include <string.h>
int main()
{
	system("mode con cols=80 lines=35");//设置窗口大小
	system("color 84"); //设置窗口颜色
	system("title 难以抑制的心");//设置标题
	char answer[10];

	printf("输入love,你可以看到我的真心\n");
	scanf("%s", answer);
	float y, x, z, f;
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			z = x * x + y * y - 1;
			f = z * z*z - x * x*y*y*y;
			putchar(f <= 0.0f ? "*********"[(int)(f*-8.0f)] : ' ');
		}
		putchar('\n');
	}
	long time;
	for (;;)
	{
		system("color a");
		for (time = 0; time<99999999; time++);
		system("color b");
		for (time = 0; time<99999999; time++);
		system("color c");
		for (time = 0; time<99999999; time++);
		system("color d");
		for (time = 0; time<99999999; time++);
		system("color e");
		for (time = 0; time<99999999; time++);
		system("color f");
		for (time = 0; time<99999999; time++);
		system("color 0");
		for (time = 0; time<99999999; time++);
		system("color 1");
		for (time = 0; time<99999999; time++);
		system("color 2");
		for (time = 0; time<99999999; time++);
		system("color 3");
		for (time = 0; time<99999999; time++);
		system("color 4");
		for (time = 0; time<99999999; time++);
		system("color 5");
		for (time = 0; time<99999999; time++);
		system("color 6");
		for (time = 0; time<99999999; time++);
		system("color 7");
		for (time = 0; time<99999999; time++);
		system("color 8");
		for (time = 0; time<99999999; time++);
		system("color 9");
	}
	getchar();
	return 0;
}