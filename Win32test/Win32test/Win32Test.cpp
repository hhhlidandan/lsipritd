#include <Windows.h>
#include <tchar.h>
#include "resource.h"
//1.ע�ᴰ����
//2.��������
//3.��ʾ����
//4.���´���
//5.������Ϣѭ��


//��Ϣ�ص�����������ϵͳ���ã�
//�û��Լ����壺�����ĸ�ʽ���밴��ϵͳ�ṩ�Ĺ̶���ʽ
POINT start;//�� ��꿪ʼ�����
POINT end;//�� �յ�
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//��Ҫ�������Ϣ�������� ���ھ�� ��Ϣ ������Ϣ ������Ϣ
{
	switch (message)
	{
	case WM_COMMAND:
	{/*
					   switch (wParam)
					   {
					   case  ID_LINE:

					   }*/
		   MessageBox(NULL, _T("����˵�"),_T("����"), IDOK);
		   return 0;
	}
	case WM_LBUTTONDOWN://�����������Ϣ��Ӧ�Ļ�������Ϳ��Լ��,������갴�½������λ����ʾ������ͨ����LP����������
		start.x = LOWORD(lParam) ;//HIWORDϵͳ�ṩ�ĺ�  ���ֽ�
		start.y = HIWORD(lParam);//���ֽ� 
		//MessageBox(NULL, _T("LBTNDOWN"),_T("Test"),IDOK);//   ���ݣ�������£������ڱ��⡢
		return 0;
	case WM_LBUTTONUP:
	{
	   end.x = LOWORD(lParam);
	   end.y = HIWORD(lParam);
	   //����
	   HDC hdc = GetDC(hWnd);//��hdc������ȡϵͳ���豸���õ�ǰ��Ӧ�ó����������
	   //MoveToEx(hdc,start.x,start.y,NULL);//�ƹ��
	   //LineTo(hdc,end.x,end.y);//����
	   Ellipse(hdc, start.x, start.y, end.x,end.y);//��Բ
	   Rectangle(hdc, start.x, start.y, end.x, end.y);//������
	   ReleaseDC(hWnd, hdc);//�����ͷ�
	   
	   return 0;
	}
	//	MessageBox(NULL, _T("LBTNDOWN"), _T("Test"), IDOK);
	case WM_PAINT://�����ػ����Ϣ
	{
	   HDC hdc = GetDC(hWnd);//��hdc������ȡϵͳ���豸���õ�ǰ��Ӧ�ó����������
	   //MoveToEx(hdc,start.x,start.y,NULL);//�ƹ��
	   //LineTo(hdc,end.x,end.y);//����   
	   Ellipse(hdc, start.x, start.y, end.x, end.y);//��Բ
	   Rectangle(hdc, start.x, start.y, end.x, end.y);
	   ReleaseDC(hWnd, hdc);//�����ͷ�
	   return 0;
	}
	case WM_CLOSE:
		//if (IDOK == MessageBox(hWnd, _T("��ȷ���˳���"), _T("�˳�"), MB_OKCANCEL))
		//{
			DestroyWindow(hWnd);
			return 0;
		//}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
//                                                                          ������
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	MessageBox(NULL,_T("hello Win32"),_T("Win32"),IDOK);//Win32������벻��ASCII��ASCII�������ޣ�Ĭ�������unicode��ʽ�������Լ���_T
	//���ĸ�������һ�������ڳ����Ĳ�һ�����ڶ�������Ϊ����

	//Step1:ע��һ�������ࡶ��Ϊ�ǻ��ڴ��ڵġ�
	HWND hwnd; //���ڵľ��

	WNDCLASSEX wc; //������ṹ
	wc.cbSize = sizeof(WNDCLASSEX);//��ǰ�ṹ��ռ���ֽ�
	wc.style = CS_VREDRAW | CS_HREDRAW;//����ˢ�µĻ��ƣ��Դ�ֱ�ķ�ʽ��ˮƽ�ķ�ʽ���ƴ��ڣ�
	wc.lpszMenuName = 0;//���޲˵� 0����û�в˵�
	wc.lpszClassName = _T("Win32");//��ô��Ǵ��ڣ��൱��ȡ���֣������ظ�����

	wc.lpfnWndProc = WinProc; //��Ϣ�ص�����(������Ϣ)������û����ģ��ٶ���Ϣ��Ӧ

	wc.hInstance = hInstance;//
	wc.hIcon = NULL;//ͼ��
	wc.hCursor = NULL;//���Ĺ��
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);//������ɫ
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;////������ע�ᴰ�����������Ϣ
	RegisterClassEx(&wc); //ע�ᴰ��

	//Step2:����һ������
	hwnd = CreateWindow(
		_T("Win32"), //���ڵ�������Ҳ�������������Զ���Ĵ����������
		_T("�ҵĵ�һ��Win32����"), //���ڵı���
		WS_OVERLAPPEDWINDOW, //����style�����ڵĹ��ܣ�
		//���ڵĴ�С
		500, //����λ��x����
		300, //����λ��y����
		800, //���ڿ��
		600, //���ڸ߶�
		NULL, //�����ھ����������Ǵ��ڣ�
		//NULL, //�˵����// ��������ʵ���Ӳ˵�  �˵�����
		LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1)), //ʵ����� ÿ�������Ӧһ�����̣���ʵ�������
		hInstance,
	    NULL //��������    �ߵ������Ϊ�մ��ڴ����ɹ�
		);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //��ʾ����
	UpdateWindow(hwnd); //ˢ��
	//Step3:��Ϣѭ��
	MSG msg;//ֻҪ������Ϣ���ͻᴦ��
	while (GetMessage(&msg, NULL, 0, 0))//����Ϣ����
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}