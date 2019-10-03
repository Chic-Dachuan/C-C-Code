#include<Windows.h>  // 底层窗口头文件
#include<stdlib.h>


// 6. 窗口处理过程
// CALLBACK 代表 __stdcall 参数传递顺序 从右往左 依次入栈 并且在函数返回前自动清空 堆栈内容
LRESULT CALLBACK WindowsProc(
	HWND hwnd,  // 消息所属窗口句柄
	UINT uMsg,  // 消息的具体名称
	WPARAM wParam, // 键盘附加消息
	LPARAM lParam  // 鼠标附加消息
) {
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);  // 仅仅是关闭窗口 但是程序没有销毁  这会儿触发一个消息 WM_DESTROY 销毁窗口
		/*
		当触发消息中  XXXWindows消息  不会放到消息队列中，而是直接执行
		*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);  // 发送退出的消息
		break;
	case WM_LBUTTONDOWN:  // 鼠标左键按下
	{
		int xPos;
		int yPos;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		// 打印通知 通常同MessageBox
		TCHAR buff[1024];
		wsprintf(buff, TEXT("X = %d, y = %d"), xPos, yPos);
		MessageBox(hwnd, buff, TEXT("鼠标按下"), MB_OK);
		/*
			所属窗口  显示内容  标题内容  关联按键类型
		*/
	}
		break;
	case WM_KEYDOWN: // 键盘消息
		MessageBox(hwnd, TEXT("键盘按下"), TEXT("按键消息"), MB_OK);
		break;
	case WM_PAINT:  // 绘图消息
	{
		PAINTSTRUCT ps;  // 绘图结构体
		HDC hdc = BeginPaint(hwnd, &ps);  // 开始绘图 返回hdc
										  // 绘制一个文字
		TextOut(hdc, 100, 100, TEXT("hello world"), strlen("hello world"));
		EndPaint(hwnd, &ps);
	}
		break;
	default:
		break;
	}
	// 默认方式处理
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
 }


// winmain 函数人口  返回值是int
// WINAPI 代表 __stdcall 参数传递的顺序  从右往左依次入栈 并且在函数返回前 清空堆栈内容
int WINAPI WinMain(
					HINSTANCE hInstance,  // 应用程序实例句柄
					HINSTANCE hPrevInstance, // 前一个应用程序实例句柄  在win32环境下， 基本值NULL 不起作用
					LPSTR lpCmdLine,  // char * argv[] 命令行参数 
					int nShowCmd) { // 窗口显示风格  最大化还是最小化
	// 实现底层窗口 通常需要6步

	// 1. 设计窗口类
	WNDCLASS wc;
	wc.cbClsExtra = 0; // 类额外的内存  通常为0 
	wc.cbWndExtra = 0;  // 窗口额外的内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // 设置背景颜色
	wc.hCursor = LoadCursor(NULL, IDC_HAND);  // 设置光标  第一参数为NULL 表示使用系统默认的光标
	wc.hIcon = LoadIcon(NULL, IDI_WARNING); // 设置图标  第一参数为NULL 表示使用系统默认的图标
	wc.hInstance = hInstance; // 当前实例句柄
	wc.lpfnWndProc = WindowsProc; // 窗口过程 函数  也就是回调函数
	wc.lpszClassName = TEXT("WINDOW"); // 指定窗口类名
	wc.lpszMenuName = NULL;  // 菜单名 没有填NULL
	wc.style = 0;  // 0代表默认风格


	// 2. 注册窗口类
	RegisterClass(&wc);

	// 3. 创建窗口类
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("TEXT WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	/*
		lpClassName 类名
		lpWindowName 窗口名
		dwStyle  显示风格   WS_OVERLAPPEDWINDOW
		x, y 创建窗口的起始坐标   默认值 CW_USEDEFAULT
		nWidth, nHeight  窗口宽高
		hWindParent  父窗口
		hMenu 菜单
		hInstance  实例句柄
		lpParam 其他参数
	*/

	// 4. 显示和更新窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	// 5. 通过循环取消息
	/*
	 HWND hwnd  主窗口
	 UINT message  // 消息名称 WM_XXXX(WINDOW MESSAGE)
	 WPARAM wParam   // 附加消息 键盘
	 LPARAM lParam   // 附加消息 鼠标
	 DWORD  time  // 消息产生时间
	 POINT  pt   //  附件消息  鼠标 点到 x, y
	*/
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		/*
			_Out_LPMSG lpmsg 消息结构体
			_In_opt_HWND hWnd  为 NULL 表示捕获所有窗口消息
			_In_UINT wMsgFilterMin  过滤最小消息数量
			_In_UINt wMsgFilterMax  过滤最大消息数量  都写0  0代表捕获所有消息
		*/
		/*if (GetMessage(&msg, NULL, 0, 0)== FALSE) {
			break;
		}*/

		// 翻译消息
		TranslateMessage(&msg);

		// 分发消息
		DispatchMessage(&msg);
	}

	// 6. 处理消息（窗口过程）
	
	return 0;
}
