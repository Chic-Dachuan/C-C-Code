#include"mfc.h"

MyApp app;  // 应用程序对象  有且只有一个

BOOL MyApp::InitInstance()
{
	// 创建一个窗口
	MyFrame * frame = new MyFrame();

	// 显示和更新
	frame->ShowWindow(SW_SHOWNORMAL);  
	frame->UpdateWindow();
	
	m_pMainWnd = frame;  // 保存指向应用程序的主窗口的指针

	return TRUE;  // 返回正常初始化
}

// 消息映射
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd) // 第一个参数消息映射所属类  第二个参数 所属类的基类
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()   // 键盘宏
	ON_WM_PAINT()  // 绘图宏
END_MESSAGE_MAP();

// 窗口框架的默认构造函数
MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC WINDOW"));
}

// 鼠标左键按下的实现
/*
参数： nFlags 指定了不同的虚拟键是否被按下。这个参数可以是下列值之一：
· MK_CONTROL 如果CTRL键被按下，则设置此位。
· MK_LBUTTON 如果鼠标左键被按下，则设置此位。
· MK_MBUTTON 如果鼠标中键被按下，则设置此位。
· MK_RBUTTON 如果鼠标右键被按下，则设置此位。
· MK_SHIFT 如果SHIFT键被按下，则设置此位。
point 指定了光标的x和y轴坐标。这些坐标通常是相对于窗口的左上角的。
*/
void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	TCHAR buff[1024];
	wsprintf(buff, TEXT("x=%d, y=%d"), point.x, point.y);   // 获取鼠标位置
	// MessageBox(buff);  // 打印信息

	CString str;   //mfc中使用的字符串
	str.Format(TEXT(":::::x=%d, y=%d"), point.x, point.y);
	MessageBox(str);
}

// 键盘实现
void MyFrame::OnChar(UINT key, UINT, UINT)
{
	/*
		第一个参数统计按下的什么键
	*/
	TCHAR buff[1024];
	wsprintf(buff, TEXT("按下%c"), key);
	MessageBox(buff);

	CString str;
	str.Format(TEXT("按下了%c"), key);
	MessageBox(str);

	// 统计宽字节字符串长度
	const wchar_t * p = L"aaaa";
	int n = wcslen(p);
}

// 绘图实现
void MyFrame::OnPaint()
{
	CPaintDC dc(this);  // 画家  画到当前的窗口中
	// 画文字
	dc.TextOutW(100, 100, TEXT("为了她"));


	// 画图形
	dc.Ellipse(10, 5, 100, 200);
}
