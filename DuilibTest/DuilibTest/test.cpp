#include "UIlib.h"
#include<fstream>

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")//��̬����ļ�

#if 0
//����һ��Win32����
class CDuiFramWnd : public CWindowWnd, public INotifyUI//��CDuiFramWnd�̳�  TNotifyUI��CWindowWnd�ʹ�����صģ�
{
public:
	// CWindowWnd��Ĵ��麯�����ڸú����б��뷵���û������崰�ڵ������ƣ�ע�ᴰ��ʱ��Ҫ�õ�
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}
	//������ť���ڴ�����ʾ����ʱ��Ҫ������ť�������ڴ��������ڼ䣬��Ҫ������ť�����԰Ѵ������ڵ������Ϣ����һ�£�ͨ�����࿴��
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)// ��Ϣ���ͱ��   ��Ϣ��Ӧ�ĸ��Ӳ���
	{
		//Ҫ�������Ϣ������һ����
		if (WM_CREATE == uMsg)
		{
			////������ť�ĳ�ʼ��
			//m_PaintManager.Init(m_hWnd);
			//
			////�ڴ��ڴ����ڼ䴴��һ����ť (ͨ�����������ṩ���ഴ��������)��     ����Ҫ��ȡ��Ϣ����Ҫ��ȡ�������Լ��������Ϣ
			//CControlUI *pBTN = new CButtonUI;
			//pBTN->SetText(_T("hello"));////��ť��ʾ���ı�   _T:ͨ���꽫�ַ�����ʽת��
			//pBTN->SetBkColor(0xFF00FF00);//��ť����ɫ
			////���滭���밴ť��������
			//m_PaintManager.AttachDialog(pBTN);

			////�Ѱ�ť������Ϣ���ӵ���Ϣѭ����
			//m_PaintManager.AddNotifier(this);


			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			// duilib.xml��Ҫ�ŵ�exeĿ¼��    
			CControlUI* pRoot = builder.Create(_T("DuilibTest.xml"), (UINT)0, NULL, &m_PaintManager);       
			m_PaintManager.AttachDialog(pRoot);      
			m_PaintManager.AddNotifier(this); 
			return 0;
		}
		//���������û�����ֱ������Ϳͻ�ȥ����Ҫ�Ļ����Լ����ƣ�������Ҫ�Ȱ����ڳ�����ı��������ε�,
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

		//������滭��ص���Ϣ
		LRESULT lRes = 0;
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes; 
		}

		//������Ϣ�����ģ����ദ��
		return __super::HandleMessage(uMsg, wParam, lParam);
	}


	//����Ҫ��ȡ��Ϣ����Ҫ��ȡ�������Լ��������Ϣ,��CDuiFramWnd�̳�Notify
	virtual void Notify(TNotifyUI& msg)
	{
		//��Ӧ��ť�����Ϣ  �����أ�
		if (msg.sType == _T("click"))//click ���   ��Ҫд�����������sType������==���
		{
			MessageBox(m_hWnd, _T("��ť���"), _T("Test"), IDOK);//����  ��������ı�  ����   ����
		}
	}

private:
	CPaintManagerUI m_PaintManager;//���ڵľ��

};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance); 
	// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼�� 
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	//1.�����
	CDuiFramWnd framWnd;//����������Ķ��󣬵�create����

	// ��һ�������������ڣ���ǰ�����һ�����ڣ�û�и����ڣ��Ǿ�����ΪNULL��
	// �ڶ���������Cashier���ڴ������Ͻ���ʽ������
	// ������������UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	// ���ĸ����ڣ�WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);// ע�� ���� ���� ��ʾ�����ڵ�һϵ�в�����������

	//��ʾ���ڣ�������Ϣѭ�����Ŵ� ��С  ��С���ȵȣ�
	framWnd.ShowModal();//Ĭ�ϵ���Ϣѭ���Լ������
	return 0;
}
#endif;



class DuiWinWnd : public WindowImplBase {
protected: 
	//дBase����麯��
	virtual CDuiString   GetSkinFolder()
	{
		return _T("");//��ȡ�ļ����ڵ�Ŀ¼
	}    
	virtual CDuiString GetSkinFile()                
	{
		return _T("duilib.xml"); //xml�ļ�������
	}    
	virtual LPCTSTR GetWindowClassName(void) const
	{
		return _T("GIFMakeWnd"); //��ǰ�����������
	}
	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))//�Թ�ע����Ϣ��������
		{
			CDuiString strName = msg.pSender->GetName(); //(����)  ��ȡ�ռ������
			if (strName == _T("btn_close"))
			{
				Close();
			}
			else if (strName == _T("btn_min"))
			{
				MessageBox(NULL, _T("��С��"), _T("test"), IDOK);
			}
		}
		else if (msg.sType==_T("itemselect"))
		{
			MessageBox(NULL, _T("Combo"), _T("test"), IDOK);
			//ͨ�������ҿؼ�
			CComboBoxUI* pComboSelect = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
			int iSelect = pComboSelect->GetCurSel();
			if (iSelect == 0)
			{
				MessageBox(NULL, _T("ѡ��ͼƬ"), _T("Test"), IDOK);
			}
			else
			{
				; 
			}
		}
	}




	//������Ϣ
	//void SendMessage(CDuiString strCMD)//��CMD������ͨ�������ķ�ʽ������
	//{
	//	//������ǰ�ȵ�����̨
	//	SHELLEXECUTEINFO strSEInfo;
	//	memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));//�ѽṹ���������ֶ���0���ѹ��ĵ��ֶ�������
	//	strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);	//����size
	//	strSEInfo.fMake//����
	//	//�����й������ڵ�λ��	
	//	strSEInfo.lpFile = _T("C:\Windows\System32");////�����й������ڵ�λ��
	//	strSEInfo.lpParameters = strCMD;//CMDִ��ʲô����
	//	//����̨������ʾ�ķ�ʽ
	//	strSEInfo.nshow = SW_HIDE;//���صķ�ʽ     SW_HI��ʾ����

	//}


	//��̬ͼ�����ɷ�ʽ��ͼƬ����Ƶ
	//ͨ����ť��ͼƬ����Ƶ������Ӧ
	//����CComboBox�ؼ���name�õ��ÿؼ�
	//CComboxBoxUI* pCombo = (CComboxBoxUI*)m_PaintManager.FindControl(_T(""));//��ȡ�Ľ�������࣬Ȼ��ת�ɻ���
	//if (0 == pCombo->GetCurSel())
	//{
	//	Gen
	//}

	void LoadSRT()
	{
		//��srt��ʽ����Ļ�ļ������ص������е�list�ؼ�
		CDuiString strPath = CpaintManagerUI::GetInstance;
		strPath += _T("ffmpage\\input.srt");
		std::ifstream fIn(strPath.GetData());

	}

	CDuiString UTF8ToUnicode(const char* str)
	{
		//��һ�ε��ã���ȡת��֮���Ŀ�괫�ĳ���
		//�ڶ��ε��ã�������ת��
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//CPaintManagerUI::SetInstance(hInstance);
	//// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼�� 
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	////1.�����
	//CDuiFramWnd framWnd;//����������Ķ��󣬵�create����

	//// ��һ�������������ڣ���ǰ�����һ�����ڣ�û�и����ڣ��Ǿ�����ΪNULL��
	//// �ڶ���������Cashier���ڴ������Ͻ���ʽ������
	//// ������������UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	//// ���ĸ����ڣ�WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	//framWnd.Create(NULL, _T("DuilibTest"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);// ע�� ���� ���� ��ʾ�����ڵ�һϵ�в�����������

	////��ʾ���ڣ�������Ϣѭ�����Ŵ� ��С  ��С���ȵȣ�
	//framWnd.ShowModal();//Ĭ�ϵ���Ϣѭ���Լ������
	//##################################################################################
	
	CPaintManagerUI::SetInstance(hInstance);//����ʵ��·��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());// ������Դ��Ĭ��·��
	DuiWinWnd wnd;//��������
	wnd.Create(NULL, _T("DuilibTest"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);//��������
	wnd.CenterWindow();//�ô��ھ���
	wnd.ShowModal();//��ʾ����
	
	return 0;
}

