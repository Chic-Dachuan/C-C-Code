#include<Windows.h>  // �ײ㴰��ͷ�ļ�
#include<stdlib.h>


// 6. ���ڴ������
// CALLBACK ���� __stdcall ��������˳�� �������� ������ջ �����ں�������ǰ�Զ���� ��ջ����
LRESULT CALLBACK WindowsProc(
	HWND hwnd,  // ��Ϣ�������ھ��
	UINT uMsg,  // ��Ϣ�ľ�������
	WPARAM wParam, // ���̸�����Ϣ
	LPARAM lParam  // ��긽����Ϣ
) {
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);  // �����ǹرմ��� ���ǳ���û������  ��������һ����Ϣ WM_DESTROY ���ٴ���
		/*
		��������Ϣ��  XXXWindows��Ϣ  ����ŵ���Ϣ�����У�����ֱ��ִ��
		*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);  // �����˳�����Ϣ
		break;
	case WM_LBUTTONDOWN:  // ����������
	{
		int xPos;
		int yPos;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		// ��ӡ֪ͨ ͨ��ͬMessageBox
		TCHAR buff[1024];
		wsprintf(buff, TEXT("X = %d, y = %d"), xPos, yPos);
		MessageBox(hwnd, buff, TEXT("��갴��"), MB_OK);
		/*
			��������  ��ʾ����  ��������  ������������
		*/
	}
		break;
	case WM_KEYDOWN: // ������Ϣ
		MessageBox(hwnd, TEXT("���̰���"), TEXT("������Ϣ"), MB_OK);
		break;
	case WM_PAINT:  // ��ͼ��Ϣ
	{
		PAINTSTRUCT ps;  // ��ͼ�ṹ��
		HDC hdc = BeginPaint(hwnd, &ps);  // ��ʼ��ͼ ����hdc
										  // ����һ������
		TextOut(hdc, 100, 100, TEXT("hello world"), strlen("hello world"));
		EndPaint(hwnd, &ps);
	}
		break;
	default:
		break;
	}
	// Ĭ�Ϸ�ʽ����
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
 }


// winmain �����˿�  ����ֵ��int
// WINAPI ���� __stdcall �������ݵ�˳��  ��������������ջ �����ں�������ǰ ��ն�ջ����
int WINAPI WinMain(
					HINSTANCE hInstance,  // Ӧ�ó���ʵ�����
					HINSTANCE hPrevInstance, // ǰһ��Ӧ�ó���ʵ�����  ��win32�����£� ����ֵNULL ��������
					LPSTR lpCmdLine,  // char * argv[] �����в��� 
					int nShowCmd) { // ������ʾ���  ��󻯻�����С��
	// ʵ�ֵײ㴰�� ͨ����Ҫ6��

	// 1. ��ƴ�����
	WNDCLASS wc;
	wc.cbClsExtra = 0; // �������ڴ�  ͨ��Ϊ0 
	wc.cbWndExtra = 0;  // ���ڶ�����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // ���ñ�����ɫ
	wc.hCursor = LoadCursor(NULL, IDC_HAND);  // ���ù��  ��һ����ΪNULL ��ʾʹ��ϵͳĬ�ϵĹ��
	wc.hIcon = LoadIcon(NULL, IDI_WARNING); // ����ͼ��  ��һ����ΪNULL ��ʾʹ��ϵͳĬ�ϵ�ͼ��
	wc.hInstance = hInstance; // ��ǰʵ�����
	wc.lpfnWndProc = WindowsProc; // ���ڹ��� ����  Ҳ���ǻص�����
	wc.lpszClassName = TEXT("WINDOW"); // ָ����������
	wc.lpszMenuName = NULL;  // �˵��� û����NULL
	wc.style = 0;  // 0����Ĭ�Ϸ��


	// 2. ע�ᴰ����
	RegisterClass(&wc);

	// 3. ����������
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("TEXT WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	/*
		lpClassName ����
		lpWindowName ������
		dwStyle  ��ʾ���   WS_OVERLAPPEDWINDOW
		x, y �������ڵ���ʼ����   Ĭ��ֵ CW_USEDEFAULT
		nWidth, nHeight  ���ڿ��
		hWindParent  ������
		hMenu �˵�
		hInstance  ʵ�����
		lpParam ��������
	*/

	// 4. ��ʾ�͸��´���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	// 5. ͨ��ѭ��ȡ��Ϣ
	/*
	 HWND hwnd  ������
	 UINT message  // ��Ϣ���� WM_XXXX(WINDOW MESSAGE)
	 WPARAM wParam   // ������Ϣ ����
	 LPARAM lParam   // ������Ϣ ���
	 DWORD  time  // ��Ϣ����ʱ��
	 POINT  pt   //  ������Ϣ  ��� �㵽 x, y
	*/
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		/*
			_Out_LPMSG lpmsg ��Ϣ�ṹ��
			_In_opt_HWND hWnd  Ϊ NULL ��ʾ�������д�����Ϣ
			_In_UINT wMsgFilterMin  ������С��Ϣ����
			_In_UINt wMsgFilterMax  ���������Ϣ����  ��д0  0������������Ϣ
		*/
		/*if (GetMessage(&msg, NULL, 0, 0)== FALSE) {
			break;
		}*/

		// ������Ϣ
		TranslateMessage(&msg);

		// �ַ���Ϣ
		DispatchMessage(&msg);
	}

	// 6. ������Ϣ�����ڹ��̣�
	
	return 0;
}
