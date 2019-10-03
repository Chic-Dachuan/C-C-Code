#pragma once
#include<afxwin.h>

class MyApp : public CWinApp {  // 应用程序类
public:
	// 程序入口
	virtual BOOL InitInstance();
};

// 窗口框架类
class MyFrame : public CFrameWnd {
public:
	MyFrame(); // 窗口框架的默认构造函数

	// 使用消息映射机制 必须使用消息映射宏
	DECLARE_MESSAGE_MAP();
	afx_msg void OnLButtonDown(UINT, CPoint);  // 鼠标左键按下申明
	afx_msg void OnChar(UINT, UINT, UINT);  // 键盘函数申明
	afx_msg void OnPaint();  // 绘图申明
};

