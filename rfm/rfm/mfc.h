#pragma once
#include<afxwin.h>

class MyApp : public CWinApp {  // Ӧ�ó�����
public:
	// �������
	virtual BOOL InitInstance();
};

// ���ڿ����
class MyFrame : public CFrameWnd {
public:
	MyFrame(); // ���ڿ�ܵ�Ĭ�Ϲ��캯��

	// ʹ����Ϣӳ����� ����ʹ����Ϣӳ���
	DECLARE_MESSAGE_MAP();
	afx_msg void OnLButtonDown(UINT, CPoint);  // ��������������
	afx_msg void OnChar(UINT, UINT, UINT);  // ���̺�������
	afx_msg void OnPaint();  // ��ͼ����
};

