#include "UIlib.h"
#include<fstream>

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")//静态库的文件

#if 0
//创建一个Win32窗口
class CDuiFramWnd : public CWindowWnd, public INotifyUI//让CDuiFramWnd继承  TNotifyUI（CWindowWnd和窗口相关的）
{
public:
	// CWindowWnd类的纯虚函数，在该函数中必须返回用户所定义窗口的类名称，注册窗口时需要用到
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}
	//创建按钮，在窗口显示出来时就要看到按钮，所以在创建窗口期间，就要创建按钮，所以把创建窗口的这个消息拦截一下（通过基类看）
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)// 消息类型编号   消息对应的附加参数
	{
		//要处理的消息（拦截一个）
		if (WM_CREATE == uMsg)
		{
			////给画按钮的初始化
			//m_PaintManager.Init(m_hWnd);
			//
			////在窗口创建期间创建一个按钮 (通过库里面所提供的类创建出来的)，     所以要获取消息，就要获取这套类自己定义的消息
			//CControlUI *pBTN = new CButtonUI;
			//pBTN->SetText(_T("hello"));////按钮显示的文本   _T:通过宏将字符串格式转化
			//pBTN->SetBkColor(0xFF00FF00);//按钮的颜色
			////将绘画器与按钮关联起来
			//m_PaintManager.AttachDialog(pBTN);

			////把按钮给的消息增加到消息循环中
			//m_PaintManager.AddNotifier(this);


			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			// duilib.xml需要放到exe目录下    
			CControlUI* pRoot = builder.Create(_T("DuilibTest.xml"), (UINT)0, NULL, &m_PaintManager);       
			m_PaintManager.AttachDialog(pRoot);      
			m_PaintManager.AddNotifier(this); 
			return 0;
		}
		//在这个库里没有区分标题栏和客户去，需要的话得自己绘制，所以需要先把现在程序里的标题栏屏蔽掉,
		else if (uMsg == WM_NCACTIVATE)         
		{
			if (!::IsIconic(m_hWnd))             
			{
				return (wParam == 0) ? TRUE : FALSE; 
			} 
		}
		else if (uMsg == WM_NCCALCSIZE)
		{
			return 0; 
		}
		else if (uMsg == WM_NCPAINT)
		{
			return 0; 
		}

		//拦截与绘画相关的消息
		LRESULT lRes = 0;
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes; 
		}

		//其他消息不关心，基类处理
		return __super::HandleMessage(uMsg, wParam, lParam);
	}


	//所以要获取消息，就要获取这套类自己定义的消息,让CDuiFramWnd继承Notify
	virtual void Notify(TNotifyUI& msg)
	{
		//响应按钮点击消息  （拦截）
		if (msg.sType == _T("click"))//click 点击   不要写反，这个库里sType必须在==左侧
		{
			MessageBox(m_hWnd, _T("按钮点击"), _T("Test"), IDOK);//窗口  窗口里的文本  标题   类型
		}
	}

private:
	CPaintManagerUI m_PaintManager;//窗口的句柄

};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance); 
	// 设置资源的默认路径（此处设置为和exe在同一目录） 
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	//1.环境搭建
	CDuiFramWnd framWnd;//创建窗口类的对象，调create函数

	// 第一个参数：父窗口（当前程序第一个窗口，没有父窗口，那就设置为NULL）
	// 第二个参数：Cashier即在窗口右上角显式的名字
	// 第三个参数：UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，具有标题栏，最大化最小化，关闭功能等
	// 第四个窗口：WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);// 注册 创建 更新 显示将窗口的一系列操作都包含了

	//显示窗口，激活消息循环（放大 放小  最小化等等）
	framWnd.ShowModal();//默认的消息循环自己处理的
	return 0;
}
#endif;



class DuiWinWnd : public WindowImplBase {
protected: 
	//写Base里的虚函数
	virtual CDuiString   GetSkinFolder()
	{
		return _T("");//获取文件所在的目录
	}    
	virtual CDuiString GetSkinFile()                
	{
		return _T("duilib.xml"); //xml文件的名字
	}    
	virtual LPCTSTR GetWindowClassName(void) const
	{
		return _T("GIFMakeWnd"); //当前窗口类的名字
	}
	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))//对关注的消息进行拦截
		{
			CDuiString strName = msg.pSender->GetName(); //(对象)  获取空间的名字
			if (strName == _T("btn_close"))
			{
				Close();
			}
			else if (strName == _T("btn_min"))
			{
				MessageBox(NULL, _T("最小化"), _T("test"), IDOK);
			}
		}
		else if (msg.sType==_T("itemselect"))
		{
			MessageBox(NULL, _T("Combo"), _T("test"), IDOK);
			//通过名字找控件
			CComboBoxUI* pComboSelect = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
			int iSelect = pComboSelect->GetCurSel();
			if (iSelect == 0)
			{
				MessageBox(NULL, _T("选择图片"), _T("Test"), IDOK);
			}
			else
			{
				; 
			}
		}
	}




	//发送消息
	//void SendMessage(CDuiString strCMD)//把CMD的命令通过参数的方式传进来
	//{
	//	//发命令前先调控制台
	//	SHELLEXECUTEINFO strSEInfo;
	//	memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));//把结构体中所有字段置0，把关心的字段再设置
	//	strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);	//设置size
	//	strSEInfo.fMake//掩码
	//	//命令行工具所在的位置	
	//	strSEInfo.lpFile = _T("C:\Windows\System32");////命令行工具所在的位置
	//	strSEInfo.lpParameters = strCMD;//CMD执行什么命令
	//	//控制台窗口显示的方式
	//	strSEInfo.nshow = SW_HIDE;//隐藏的方式     SW_HI显示出来

	//}


	//动态图的生成方式：图片或视频
	//通过按钮对图片或视频进行响应
	//根据CComboBox控件的name拿到该控件
	//CComboxBoxUI* pCombo = (CComboxBoxUI*)m_PaintManager.FindControl(_T(""));//获取的结果是子类，然后转成基类
	//if (0 == pCombo->GetCurSel())
	//{
	//	Gen
	//}

	void LoadSRT()
	{
		//将srt格式的字幕文件，加载到界面中的list控件
		CDuiString strPath = CpaintManagerUI::GetInstance;
		strPath += _T("ffmpage\\input.srt");
		std::ifstream fIn(strPath.GetData());

	}

	CDuiString UTF8ToUnicode(const char* str)
	{
		//第一次调用：获取转化之后的目标传的长度
		//第二次调用：真正的转化
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//CPaintManagerUI::SetInstance(hInstance);
	//// 设置资源的默认路径（此处设置为和exe在同一目录） 
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	////1.环境搭建
	//CDuiFramWnd framWnd;//创建窗口类的对象，调create函数

	//// 第一个参数：父窗口（当前程序第一个窗口，没有父窗口，那就设置为NULL）
	//// 第二个参数：Cashier即在窗口右上角显式的名字
	//// 第三个参数：UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，具有标题栏，最大化最小化，关闭功能等
	//// 第四个窗口：WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	//framWnd.Create(NULL, _T("DuilibTest"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);// 注册 创建 更新 显示将窗口的一系列操作都包含了

	////显示窗口，激活消息循环（放大 放小  最小化等等）
	//framWnd.ShowModal();//默认的消息循环自己处理的
	//##################################################################################
	
	CPaintManagerUI::SetInstance(hInstance);//创建实例路径
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());// 设置资源的默认路径
	DuiWinWnd wnd;//创建对象
	wnd.Create(NULL, _T("DuilibTest"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);//创建窗口
	wnd.CenterWindow();//让窗口居中
	wnd.ShowModal();//显示窗口
	
	return 0;
}

