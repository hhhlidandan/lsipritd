#include <Windows.h>
#include <tchar.h>
#include "resource.h"
//1.注册窗口类
//2.创建窗口
//3.显示窗口
//4.更新窗口
//5.进入消息循环


//消息回调函数（操作系统调用）
//用户自己定义：函数的格式必须按照系统提供的固定格式
POINT start;//点 鼠标开始的起点
POINT end;//点 终点
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//想要处理的消息：参数： 窗口句柄 消息 附加信息 附加信息
{
	switch (message)
	{
	case WM_COMMAND:
	{/*
					   switch (wParam)
					   {
					   case  ID_LINE:

					   }*/
		   MessageBox(NULL, _T("点击菜单"),_T("测试"), IDOK);
		   return 0;
	}
	case WM_LBUTTONDOWN://按左键，（消息响应的话，弹框就可以检测,）（鼠标按下将左键的位置显示出来（通过后LP传进来））
		start.x = LOWORD(lParam) ;//HIWORD系统提供的宏  低字节
		start.y = HIWORD(lParam);//高字节 
		//MessageBox(NULL, _T("LBTNDOWN"),_T("Test"),IDOK);//   内容（左键按下）、窗口标题、
		return 0;
	case WM_LBUTTONUP:
	{
	   end.x = LOWORD(lParam);
	   end.y = HIWORD(lParam);
	   //划线
	   HDC hdc = GetDC(hWnd);//用hdc画，获取系统的设备，用当前的应用程序关联起来
	   //MoveToEx(hdc,start.x,start.y,NULL);//移光标
	   //LineTo(hdc,end.x,end.y);//划线
	   Ellipse(hdc, start.x, start.y, end.x,end.y);//画圆
	   Rectangle(hdc, start.x, start.y, end.x, end.y);//画矩形
	   ReleaseDC(hWnd, hdc);//用完释放
	   
	   return 0;
	}
	//	MessageBox(NULL, _T("LBTNDOWN"), _T("Test"), IDOK);
	case WM_PAINT://拦截重绘的消息
	{
	   HDC hdc = GetDC(hWnd);//用hdc画，获取系统的设备，用当前的应用程序关联起来
	   //MoveToEx(hdc,start.x,start.y,NULL);//移光标
	   //LineTo(hdc,end.x,end.y);//划线   
	   Ellipse(hdc, start.x, start.y, end.x, end.y);//画圆
	   Rectangle(hdc, start.x, start.y, end.x, end.y);
	   ReleaseDC(hWnd, hdc);//用完释放
	   return 0;
	}
	case WM_CLOSE:
		//if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL))
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
//                                                                          命令行
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	MessageBox(NULL,_T("hello Win32"),_T("Win32"),IDOK);//Win32里面编码不是ASCII（ASCII编码有限）默认情况以unicode格式处理，所以加了_T
	//第四个参数不一样，窗口出来的不一样，第二个参数为标题

	//Step1:注册一个窗口类《因为是基于窗口的》
	HWND hwnd; //窗口的句柄

	WNDCLASSEX wc; //窗口类结构
	wc.cbSize = sizeof(WNDCLASSEX);//当前结构体占的字节
	wc.style = CS_VREDRAW | CS_HREDRAW;//窗口刷新的机制（以垂直的方式和水平的方式绘制窗口）
	wc.lpszMenuName = 0;//有无菜单 0就是没有菜单
	wc.lpszClassName = _T("Win32");//怎么标记窗口（相当于取名字），不重复就行

	wc.lpfnWndProc = WinProc; //消息回调函数(处理消息)，如果用户关心，再对消息响应

	wc.hInstance = hInstance;//
	wc.hIcon = NULL;//图标
	wc.hCursor = NULL;//鼠标的光标
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);//背景颜色
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;////上面是注册窗口类的属性信息
	RegisterClassEx(&wc); //注册窗口

	//Step2:创建一个窗口
	hwnd = CreateWindow(
		_T("Win32"), //窗口的类名，也就是上面我们自定义的窗口类的名字
		_T("我的第一个Win32程序"), //窗口的标题
		WS_OVERLAPPEDWINDOW, //窗口style（窗口的功能）
		//窗口的大小
		500, //窗口位置x坐标
		300, //窗口位置y坐标
		800, //窗口宽度
		600, //窗口高度
		NULL, //父窗口句柄（用来标记窗口）
		//NULL, //菜单句柄// 参数：给实例加菜单  菜单名字
		LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1)), //实例句柄 每个程序对应一个进程，用实例来标记
		hInstance,
	    NULL //创建数据    走到这里，不为空窗口创建成功
		);
	if (!hwnd)
	{
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //显示窗口
	UpdateWindow(hwnd); //刷新
	//Step3:消息循环
	MSG msg;//只要产生消息，就会处理
	while (GetMessage(&msg, NULL, 0, 0))//拿消息处理
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}