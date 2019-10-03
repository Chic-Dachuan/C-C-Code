#include"mfc.h"

MyApp app;  // Ӧ�ó������  ����ֻ��һ��

BOOL MyApp::InitInstance()
{
	// ����һ������
	MyFrame * frame = new MyFrame();

	// ��ʾ�͸���
	frame->ShowWindow(SW_SHOWNORMAL);  
	frame->UpdateWindow();
	
	m_pMainWnd = frame;  // ����ָ��Ӧ�ó���������ڵ�ָ��

	return TRUE;  // ����������ʼ��
}

// ��Ϣӳ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd) // ��һ��������Ϣӳ��������  �ڶ������� ������Ļ���
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()   // ���̺�
	ON_WM_PAINT()  // ��ͼ��
END_MESSAGE_MAP();

// ���ڿ�ܵ�Ĭ�Ϲ��캯��
MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC WINDOW"));
}

// ���������µ�ʵ��
/*
������ nFlags ָ���˲�ͬ��������Ƿ񱻰��¡������������������ֵ֮һ��
�� MK_CONTROL ���CTRL�������£������ô�λ��
�� MK_LBUTTON ��������������£������ô�λ��
�� MK_MBUTTON �������м������£������ô�λ��
�� MK_RBUTTON �������Ҽ������£������ô�λ��
�� MK_SHIFT ���SHIFT�������£������ô�λ��
point ָ���˹���x��y�����ꡣ��Щ����ͨ��������ڴ��ڵ����Ͻǵġ�
*/
void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	TCHAR buff[1024];
	wsprintf(buff, TEXT("x=%d, y=%d"), point.x, point.y);   // ��ȡ���λ��
	// MessageBox(buff);  // ��ӡ��Ϣ

	CString str;   //mfc��ʹ�õ��ַ���
	str.Format(TEXT(":::::x=%d, y=%d"), point.x, point.y);
	MessageBox(str);
}

// ����ʵ��
void MyFrame::OnChar(UINT key, UINT, UINT)
{
	/*
		��һ������ͳ�ư��µ�ʲô��
	*/
	TCHAR buff[1024];
	wsprintf(buff, TEXT("����%c"), key);
	MessageBox(buff);

	CString str;
	str.Format(TEXT("������%c"), key);
	MessageBox(str);

	// ͳ�ƿ��ֽ��ַ�������
	const wchar_t * p = L"aaaa";
	int n = wcslen(p);
}

// ��ͼʵ��
void MyFrame::OnPaint()
{
	CPaintDC dc(this);  // ����  ������ǰ�Ĵ�����
	// ������
	dc.TextOutW(100, 100, TEXT("Ϊ����"));


	// ��ͼ��
	dc.Ellipse(10, 5, 100, 200);
}
