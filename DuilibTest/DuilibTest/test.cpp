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
}；
#endif
//上面比较麻烦
//直接用WinWnd继承 ，WindowImpIBase里有上面实现的
class DuiWinWnd : public WindowImplBase //WindowImpIBase,把CwindowWnd 和NotiUI继承了
{
protected: 
	//写Base里的虚函数
	virtual CDuiString GetSkinFolder()//获取文件所在的目录
	{
		return _T("");
	}    
	virtual CDuiString GetSkinFile() //获取xml文件的名字         
	{
		return _T("duilib.xml"); 
	}    
	virtual LPCTSTR GetWindowClassName(void) const //当前窗口类的名字
	{
		return _T("GIFMakeWnd");
	}
	virtual void Notify(TNotifyUI& msg)//duilib所维护的控件（按钮）
	{
		CDuiString strName = msg.pSender->GetName(); //(对象)  获取控件的名字
		if (msg.sType == _T("click"))//单击  对关注的消息进行拦截
		{
			if (strName == _T("btn_close"))
			{
				Close();
			}
			else if (strName == _T("btn_min"))
			{
				MessageBox(NULL, _T("最小化"), _T("test"), IDOK);//弹框
			}
			else if (strName == _T("btn_load"))
			{
				LoadFile();
			}
			else if (strName == _T("btn_cut"))
			{
				CutView();
			}
			else if (strName == _T("btn_get_srt"))//提取srt文件
			{
				GetSRTFile();
				LoadSRT();
			}
			else if (strName == _T("btn_commit"))//编辑内容
			{
				CEditUI* pEdit = (CEditUI*)m_PaintManager.FindControl(_T("edit_word"));//获取edit控件,(内容添加到edit中)
				CDuiString strWord = pEdit->GetText();//获取文本
				
				//将该文本写回到List中
				//获取list控件
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
				//获取这行文本内容   通过GetItemAt将选中行的下标传进来,
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());//   pList->GetCurSel()当前选中的是哪一行,
				pListItemp->SetText(1,strWord);
			}
			else if (strName == _T("btn_write_srt"))//将编辑好的字幕文件写回srt文件中
			{
				WriteSRT();
			}
			else if (strName == _T("btn_generate"))//通过按钮对图片或视频进行响应
			{//根据CComboBox控件的name拿到该控件
				//             (CComboBoxUI*)从基类转到子类（向下转型）   // ContralUI是所有控件的基类
				CComboBoxUI* pCombo = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
				if (pCombo->GetCurSel()==0)//获取当前选中的
				{
					GenerateGifWithPic();//用照片生成gif
				}
				else
				{
					GenerateGifWithView();//用照片生成gif
				}
				
			}
		}
		//在窗口初始化期间需要做的事情
		else if (msg.sType == _T("windowinit"))//拦截窗口初始化的消息
		{
			SetControlEnable(false);//窗口初始化期间也要让它变成无效
		}
		else if (msg.sType==_T("itemselect"))//改变选择的视频或图片（这个就不是单击了）但是也是在处理消息改变哦
		{
		//	MessageBox(NULL, _T("Combo"), _T("test"), IDOK);//Combo控件
			//通过名字找控件，才能知道选择的是哪个         //通过paintmanager管理器获取，里面有findcontrol的方法   
			if (strName == _T("list_srt"))
			{
				//获取list控件
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
				//通过GetItemAt将选中行的下标传进来,获取这行文本内容
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());//   pList->GetCurSel()当前选中的是哪一行,
				//将list选中行中的对应文本信息增加到当前edit中
				CEditUI* pEdit = (CEditUI*)m_PaintManager.FindControl(_T("edit_word"));//获取edit控件,(内容添加到edit中)
				pEdit->SetText(pListItemp->GetText(1));//通过edit设置文本，从第一个开始才是文本，第0个是时间轴
			}
			if (strName == _T("combo_select"))
			{
				//选择图片的方式生成，让以下控件无效
				CComboBoxUI* pComboUI = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
				if (0 == pComboUI->GetCurSel())//获取当前选中
				{
					SetControlEnable(false);//让选择的控件无效
				}
				else
				{//让选择的控件有效
					SetControlEnable(true);
				}
			}
		}
	}
	void SetControlEnable(bool IsValid)//设置控件的有效型
	{

		((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->SetEnabled(IsValid);
		((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_cut")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_generate")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_get_srt")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_view")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_bron")))->SetEnabled(IsValid);
	}
	//发送消息
	void SendMessage(CDuiString strCMD)//把CMD的命令通过参数的方式传进来
	{
		//1.发命令前先调（diao）控制台(CMD)
		SHELLEXECUTEINFO strSEInfo;//先创建结构体
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));//把结构体中所有字段置0，把关心的字段再设置
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);	//设置size
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;//掩码
		strSEInfo.lpFile = _T("C:\\Windows\\System32\\cmd");////命令行工具所在的位置
		strSEInfo.lpParameters = strCMD;//让CMD执行什么命令
		//控制台窗口显示的方式：SW_HI显示出来  SW_HIDE隐藏的方式
		strSEInfo.nShow = SW_HIDE;//隐藏的方式  

		//2.给命令行发送消息  通过界面发 duilib所维护的控件的消息(比如，最小化，最大化等)
		ShellExecuteEx(&strSEInfo);//调用命令行窗口，执行用户的命令，
		//在该函数中自己会创建一个进程来负责调用命令行窗口，来执行命令（给控制台发命令，ShellExecuteEx(&str)执行，传结构体，把命令窗口打开）
		//ShellExecuteEx执行cmd命令时，命令行参数要假如/c来让命令行执行完后关闭，否则命令行进程会一直存在，WaitForSingleObject会一直等待
		
		//等待命令响应完成，然后显示框
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);//INFINITE  无限等待

		MessageBox(NULL, _T("命令操作完成"), _T("DuilibTest"), IDOK);//命令执行完弹框
	}
	void GenerateGifWithPic()//用照片生成gif
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();//获取工程目录(获取实例的路径)
		strPath += _T("ffmpeg\\");//只要发消息，都要加这个路径

		//1.构造命令   //考虑路径
		//CDuiString strCMD(_T("ffmpeg\\ffmpeg -r 3 -i .\\Picture\\%d.jpg output.gif -y"));//  \\两个，	
		CDuiString strCMD;//定义字符串
		strCMD += _T("/c ");//通过-c后面就是要执行的命令（接构造ffmpeg的命令）
		strCMD += strPath;//路径
		strCMD += _T("ffmpeg -r 3 -i ");//再加字符串  注意该工具所在的路径必须填充完整
		strCMD += strPath;//图片所在的路径
		strCMD += _T(".\\Picture\\%d.jpg ");
		strCMD += strPath;//生成动态图的路径 （因为生成动态图要放到一个位置）
		strCMD += _T("output.gif -y");//-y 如果存在该图片，覆盖掉该图片
		//2.发送命令
		SendMessage(strCMD);
		MessageBox(NULL, _T("命令操作完成"), _T("DuilibTest"), IDOK);
	}

	//用视频生成
	//一、截取视频片段
	void CutView()//
	{
		//CDuiString strCMD(_T("ffmpeg -i input.mkv -vcodec copy -acodec copy -ss 00:40:07 -to 00:40:28 11.mkv -y"));	
		//1.构造命令
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		CDuiString strViewPath = ((CEditUI*)m_PaintManager.FindControl(_T("edit_path")))->GetText();

		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		//视频的路径
		//优先：通过界面方式加载
		//如果界面没有配置，再到ffmpeg目录下获取默认的文件
		if (!strViewPath.IsEmpty())
		{
			strCMD += strViewPath;
		}
		else
		{
			strCMD += strPath;//视频路径
			strCMD += _T("input.mkv ");
		}
		strCMD += _T("-vcodec copy -acodec copy -ss ");

		//获取起始、结尾时间
		CDuiString strStartTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->GetText(); //ContralUI是所有控件的基类  GetText() 返回字符串
		if (!IsValidTime(strStartTime))
		{
			MessageBox(NULL, _T("起始时间有误"), _T("DuilibTest"), IDOK);
			return;
		}
		CDuiString strEndTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->GetText(); 
		if (!IsValidTime(strEndTime))
		{
			MessageBox(NULL, _T("终止时间有误"), _T("DuilibTest"), IDOK);
			return;
		}
		strCMD += strStartTime;
		strCMD += _T(" -to ");
		strCMD += strEndTime;
		//输出文件的路径
		strCMD += _T(" ");
		strCMD += strPath;
		strCMD += _T("11.mkv -y");
		//2.执行命令（给CMD发送命令）
		SendMessage(strCMD);
	}
	void LoadFile()//设置加载的控件
	{
		OPENFILENAME ofn;
		memset(&ofn, 0, sizeof(OPENFILENAME));//不用的设置为0

		TCHAR strPath[MAX_PATH] = { 0 };//宽字符
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFile = strPath;
		ofn.nMaxFile = sizeof(strPath);
		ofn.lpstrFilter = _T("All(*.*)\0 *.*\0mkv(*.mkv)\0 *.mkv\0");
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
		if (GetOpenFileName(&ofn))
		{
			//将文件的路径设置到edit
			((CEditUI*)m_PaintManager.FindControl(_T("edit_path")))->SetText();
			MessageBox(NULL, _T("test"), _T("gif"), IDOK);
		}
	}
	//二、从视频中提取srt字幕文件
	void GetSRTFile()
	{
		//构造命令
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		//1.构造命令  ffmpeg -i 11.kmv input.srt -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//视频路径
		strCMD += _T("11.kmv ");
		strCMD += strPath;
		strCMD += _T("input.srt -y");
		//2.执行命令（给CMD发送命令）
		SendMessage(strCMD);
	}
	//三、对提取的字幕流进行重新编辑成我们想要的
	void LoadSRT()
	{
		//将srt格式的字幕文件，加载到界面中的list控件
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpage\\input.srt");
		std::ifstream fIn(strPath.GetData()); //ifsteam 读取（有getline,直接读取一行） GetData()获取字符串
		
		char strSRTCon[512] = { 0 };//读取多少个
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
		pList->RemoveAll();//先把之前的清空，否则会重复显示
		while (!fIn.eof())//检查指针是否在结尾，读取内容
		{
			fIn.getline(strSRTCon, 512);//读取字幕序号  在strSRTCon字符串中读取512个
			CListTextElementUI* pListItem = new CListTextElementUI;
			pList->Add(pListItem);//通过Add函数给list中加载的文本内容

			fIn.getline(strSRTCon, 512);//读取时间轴
			pListItem->SetText(0, UTF8ToUnicode(strSRTCon));//给每项设置内容   1.编号 2.读取的文本内容 (转成Unicode)
			
			fIn.getline(strSRTCon, 512);//读取字幕，最后显示到list控件中
			pListItem->SetText(1, UTF8ToUnicode(strSRTCon));//设置第二行的

			fIn.getline(strSRTCon, 512);//读取空行
		}
		fIn.close();
	}
	//四、将编辑好的字幕文件写回到srt文件中
	void WriteSRT()
	{
		//先获取SRT文件的路径
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpage\\input.srt");
		std::ofstream fOut(strPath.GetData());

		//1.从list控件中获取文本内容
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
		int szCount = pList->GetCount();//获取行数
		for (int i = 0; i < szCount; i++)
		{
			CListTextElementUI* pListItem = (CListTextElementUI*)pList->GetItemAt(i);
			//序号
			CDuiString strNo;
			strNo.Format(_T("%d"), i + 1);//格式化  i从0开始，但标号从1 开始
			//时间轴
			CDuiString strTime = pListItem->GetText(0);

			//文本内容
			CDuiString strWord = pListItem->GetText(1);

			//2.将获取的内容写回到srt文件中
			string strNewLine = Unicode2ANSI(_T("\n"));//换行
			//写行号
			string itemNo = Unicode2ANSI(strNo);
			fOut.write(itemNo.c_str(), itemNo.size());//宽字符转多字符
			fOut.write(strNewLine.c_str(), strNewLine.size());
			
			//写时间轴
			string itemTime = Unicode2ANSI(strTime);
			fOut.write(itemTime.c_str(), itemTime.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			
			//写文本
			string itemWord = Unicode2ANSI(strWord);
			fOut.write(itemWord.c_str(), itemWord.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			
			//字幕和字幕之间都有个换行
			fOut.write(strNewLine.c_str(), strNewLine.size());
		}
		
		fOut.close();
	}

	//五、提取视频裸流 
	void GenerateView()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		//1.构造命令  ffmpeg -i 11.mkv -vcodec copy -an -sn 22.mkv -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//视频路径
		strCMD += _T("11.mkv -vcodec copy -an -sn ");
		strCMD += strPath;
		strCMD += _T("22.mkv -y");

		SendMessage(strCMD);
	}
	//五.烧录（将修改的小段视频内嵌到裸流视频中）
	void BornSRT2View()
	{
		//构造命令
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		//1.构造命令  ffmpeg - i 22.mkv -vf subtitles=11.srt 33.mkv -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//视频路径
		strCMD += _T("22.mkv -vf subtitles=11.srt ");
		strCMD += strPath;
		strCMD += _T("33.mkv -y");

		SendMessage(strCMD);
	}
	//六、生成动态图
	void GenerateGifWithView()
	{
		
		//构造命令
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		//1.构造命令//ffmpeg -i 33.mkv -vf scale=iw/2:ih/2 -f gif output.gif -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//视频路径
		strCMD += _T("33.mkv -vf scale=iw/2:ih/2 -f gif ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");

		SendMessage(strCMD);
	}
	//转Unicode
	CDuiString UTF8ToUnicode(const char* str)  
	{
	     //第一次调用：获取转化之后的目标的长度:需要多少自己存储内容
		int szLen= ::MultiByteToWideChar(CP_UTF8,0,str,strlen(str),NULL,0);//把字符集转化成所需要的格式
		wchar_t* pContent = new wchar_t[szLen + 1];//开辟空间
		
		//第二次调用：真正的转化
		::MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), pContent, szLen);
		pContent[szLen] = '\0';
		CDuiString s(pContent);
		delete[] pContent;
		return s;
	}
	//截取视频时，检测时间是否有效
	bool IsValidTime(CDuiString strTime)
	{
		//"00:40:30"   //8个字符
		if (strTime.GetLength() != 8)
		{
			return false;
		}
		for (int i = 0; i < strTime.GetLength(); i++)
		{
			if (strTime[i] == ':')
				continue;
			if(!(strTime[i] >= '0'&&strTime[i] <= '9'))
			{
				return false;
			}
		}
		return true;
	}
	//Unicode转ASCII
	string Unicode2ANSI(CDuiString str)//  多字符集到宽字符集
	{
		//获取有多少个字节
		int szLen = ::WideCharToMultiByte(CP_ACP, 0, str.GetData(), -1, NULL, 0,NULL,FALSE);
		char* pBuff = new char[szLen + 1];
		::WideCharToMultiByte(CP_ACP, 0, str.GetData(), str.GetLength(), pBuff, szLen, NULL, FALSE);
		pBuff[szLen] = '\0';
		string s(pBuff);
		delete[] pBuff;
		return s;
	}

};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//CPaintManagerUI::SetInstance(hInstance);
	//// 设置资源的默认路径（此处设置为和exe在同一目录） 要不然运行就崩溃了
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

