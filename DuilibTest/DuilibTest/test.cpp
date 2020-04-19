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
}��
#endif
//����Ƚ��鷳
//ֱ����WinWnd�̳� ��WindowImpIBase��������ʵ�ֵ�
class DuiWinWnd : public WindowImplBase //WindowImpIBase,��CwindowWnd ��NotiUI�̳���
{
protected: 
	//дBase����麯��
	virtual CDuiString GetSkinFolder()//��ȡ�ļ����ڵ�Ŀ¼
	{
		return _T("");
	}    
	virtual CDuiString GetSkinFile() //��ȡxml�ļ�������         
	{
		return _T("duilib.xml"); 
	}    
	virtual LPCTSTR GetWindowClassName(void) const //��ǰ�����������
	{
		return _T("GIFMakeWnd");
	}
	virtual void Notify(TNotifyUI& msg)//duilib��ά���Ŀؼ�����ť��
	{
		CDuiString strName = msg.pSender->GetName(); //(����)  ��ȡ�ؼ�������
		if (msg.sType == _T("click"))//����  �Թ�ע����Ϣ��������
		{
			if (strName == _T("btn_close"))
			{
				Close();
			}
			else if (strName == _T("btn_min"))
			{
				MessageBox(NULL, _T("��С��"), _T("test"), IDOK);//����
			}
			else if (strName == _T("btn_load"))
			{
				LoadFile();
			}
			else if (strName == _T("btn_cut"))
			{
				CutView();
			}
			else if (strName == _T("btn_get_srt"))//��ȡsrt�ļ�
			{
				GetSRTFile();
				LoadSRT();
			}
			else if (strName == _T("btn_commit"))//�༭����
			{
				CEditUI* pEdit = (CEditUI*)m_PaintManager.FindControl(_T("edit_word"));//��ȡedit�ؼ�,(������ӵ�edit��)
				CDuiString strWord = pEdit->GetText();//��ȡ�ı�
				
				//�����ı�д�ص�List��
				//��ȡlist�ؼ�
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
				//��ȡ�����ı�����   ͨ��GetItemAt��ѡ���е��±괫����,
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());//   pList->GetCurSel()��ǰѡ�е�����һ��,
				pListItemp->SetText(1,strWord);
			}
			else if (strName == _T("btn_write_srt"))//���༭�õ���Ļ�ļ�д��srt�ļ���
			{
				WriteSRT();
			}
			else if (strName == _T("btn_generate"))//ͨ����ť��ͼƬ����Ƶ������Ӧ
			{//����CComboBox�ؼ���name�õ��ÿؼ�
				//             (CComboBoxUI*)�ӻ���ת�����ࣨ����ת�ͣ�   // ContralUI�����пؼ��Ļ���
				CComboBoxUI* pCombo = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
				if (pCombo->GetCurSel()==0)//��ȡ��ǰѡ�е�
				{
					GenerateGifWithPic();//����Ƭ����gif
				}
				else
				{
					GenerateGifWithView();//����Ƭ����gif
				}
				
			}
		}
		//�ڴ��ڳ�ʼ���ڼ���Ҫ��������
		else if (msg.sType == _T("windowinit"))//���ش��ڳ�ʼ������Ϣ
		{
			SetControlEnable(false);//���ڳ�ʼ���ڼ�ҲҪ���������Ч
		}
		else if (msg.sType==_T("itemselect"))//�ı�ѡ�����Ƶ��ͼƬ������Ͳ��ǵ����ˣ�����Ҳ���ڴ�����Ϣ�ı�Ŷ
		{
		//	MessageBox(NULL, _T("Combo"), _T("test"), IDOK);//Combo�ؼ�
			//ͨ�������ҿؼ�������֪��ѡ������ĸ�         //ͨ��paintmanager��������ȡ��������findcontrol�ķ���   
			if (strName == _T("list_srt"))
			{
				//��ȡlist�ؼ�
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
				//ͨ��GetItemAt��ѡ���е��±괫����,��ȡ�����ı�����
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());//   pList->GetCurSel()��ǰѡ�е�����һ��,
				//��listѡ�����еĶ�Ӧ�ı���Ϣ���ӵ���ǰedit��
				CEditUI* pEdit = (CEditUI*)m_PaintManager.FindControl(_T("edit_word"));//��ȡedit�ؼ�,(������ӵ�edit��)
				pEdit->SetText(pListItemp->GetText(1));//ͨ��edit�����ı����ӵ�һ����ʼ�����ı�����0����ʱ����
			}
			if (strName == _T("combo_select"))
			{
				//ѡ��ͼƬ�ķ�ʽ���ɣ������¿ؼ���Ч
				CComboBoxUI* pComboUI = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
				if (0 == pComboUI->GetCurSel())//��ȡ��ǰѡ��
				{
					SetControlEnable(false);//��ѡ��Ŀؼ���Ч
				}
				else
				{//��ѡ��Ŀؼ���Ч
					SetControlEnable(true);
				}
			}
		}
	}
	void SetControlEnable(bool IsValid)//���ÿؼ�����Ч��
	{

		((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->SetEnabled(IsValid);
		((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_cut")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_generate")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_get_srt")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_view")))->SetEnabled(IsValid);
		((CButtonUI*)m_PaintManager.FindControl(_T("btn_bron")))->SetEnabled(IsValid);
	}
	//������Ϣ
	void SendMessage(CDuiString strCMD)//��CMD������ͨ�������ķ�ʽ������
	{
		//1.������ǰ�ȵ���diao������̨(CMD)
		SHELLEXECUTEINFO strSEInfo;//�ȴ����ṹ��
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));//�ѽṹ���������ֶ���0���ѹ��ĵ��ֶ�������
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);	//����size
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;//����
		strSEInfo.lpFile = _T("C:\\Windows\\System32\\cmd");////�����й������ڵ�λ��
		strSEInfo.lpParameters = strCMD;//��CMDִ��ʲô����
		//����̨������ʾ�ķ�ʽ��SW_HI��ʾ����  SW_HIDE���صķ�ʽ
		strSEInfo.nShow = SW_HIDE;//���صķ�ʽ  

		//2.�������з�����Ϣ  ͨ�����淢 duilib��ά���Ŀؼ�����Ϣ(���磬��С������󻯵�)
		ShellExecuteEx(&strSEInfo);//���������д��ڣ�ִ���û������
		//�ڸú������Լ��ᴴ��һ��������������������д��ڣ���ִ�����������̨�����ShellExecuteEx(&str)ִ�У����ṹ�壬������ڴ򿪣�
		//ShellExecuteExִ��cmd����ʱ�������в���Ҫ����/c����������ִ�����رգ����������н��̻�һֱ���ڣ�WaitForSingleObject��һֱ�ȴ�
		
		//�ȴ�������Ӧ��ɣ�Ȼ����ʾ��
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);//INFINITE  ���޵ȴ�

		MessageBox(NULL, _T("����������"), _T("DuilibTest"), IDOK);//����ִ���굯��
	}
	void GenerateGifWithPic()//����Ƭ����gif
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();//��ȡ����Ŀ¼(��ȡʵ����·��)
		strPath += _T("ffmpeg\\");//ֻҪ����Ϣ����Ҫ�����·��

		//1.��������   //����·��
		//CDuiString strCMD(_T("ffmpeg\\ffmpeg -r 3 -i .\\Picture\\%d.jpg output.gif -y"));//  \\������	
		CDuiString strCMD;//�����ַ���
		strCMD += _T("/c ");//ͨ��-c�������Ҫִ�е�����ӹ���ffmpeg�����
		strCMD += strPath;//·��
		strCMD += _T("ffmpeg -r 3 -i ");//�ټ��ַ���  ע��ù������ڵ�·�������������
		strCMD += strPath;//ͼƬ���ڵ�·��
		strCMD += _T(".\\Picture\\%d.jpg ");
		strCMD += strPath;//���ɶ�̬ͼ��·�� ����Ϊ���ɶ�̬ͼҪ�ŵ�һ��λ�ã�
		strCMD += _T("output.gif -y");//-y ������ڸ�ͼƬ�����ǵ���ͼƬ
		//2.��������
		SendMessage(strCMD);
		MessageBox(NULL, _T("����������"), _T("DuilibTest"), IDOK);
	}

	//����Ƶ����
	//һ����ȡ��ƵƬ��
	void CutView()//
	{
		//CDuiString strCMD(_T("ffmpeg -i input.mkv -vcodec copy -acodec copy -ss 00:40:07 -to 00:40:28 11.mkv -y"));	
		//1.��������
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		CDuiString strViewPath = ((CEditUI*)m_PaintManager.FindControl(_T("edit_path")))->GetText();

		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		//��Ƶ��·��
		//���ȣ�ͨ�����淽ʽ����
		//�������û�����ã��ٵ�ffmpegĿ¼�»�ȡĬ�ϵ��ļ�
		if (!strViewPath.IsEmpty())
		{
			strCMD += strViewPath;
		}
		else
		{
			strCMD += strPath;//��Ƶ·��
			strCMD += _T("input.mkv ");
		}
		strCMD += _T("-vcodec copy -acodec copy -ss ");

		//��ȡ��ʼ����βʱ��
		CDuiString strStartTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->GetText(); //ContralUI�����пؼ��Ļ���  GetText() �����ַ���
		if (!IsValidTime(strStartTime))
		{
			MessageBox(NULL, _T("��ʼʱ������"), _T("DuilibTest"), IDOK);
			return;
		}
		CDuiString strEndTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->GetText(); 
		if (!IsValidTime(strEndTime))
		{
			MessageBox(NULL, _T("��ֹʱ������"), _T("DuilibTest"), IDOK);
			return;
		}
		strCMD += strStartTime;
		strCMD += _T(" -to ");
		strCMD += strEndTime;
		//����ļ���·��
		strCMD += _T(" ");
		strCMD += strPath;
		strCMD += _T("11.mkv -y");
		//2.ִ�������CMD�������
		SendMessage(strCMD);
	}
	void LoadFile()//���ü��صĿؼ�
	{
		OPENFILENAME ofn;
		memset(&ofn, 0, sizeof(OPENFILENAME));//���õ�����Ϊ0

		TCHAR strPath[MAX_PATH] = { 0 };//���ַ�
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFile = strPath;
		ofn.nMaxFile = sizeof(strPath);
		ofn.lpstrFilter = _T("All(*.*)\0 *.*\0mkv(*.mkv)\0 *.mkv\0");
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
		if (GetOpenFileName(&ofn))
		{
			//���ļ���·�����õ�edit
			((CEditUI*)m_PaintManager.FindControl(_T("edit_path")))->SetText();
			MessageBox(NULL, _T("test"), _T("gif"), IDOK);
		}
	}
	//��������Ƶ����ȡsrt��Ļ�ļ�
	void GetSRTFile()
	{
		//��������
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		//1.��������  ffmpeg -i 11.kmv input.srt -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//��Ƶ·��
		strCMD += _T("11.kmv ");
		strCMD += strPath;
		strCMD += _T("input.srt -y");
		//2.ִ�������CMD�������
		SendMessage(strCMD);
	}
	//��������ȡ����Ļ���������±༭��������Ҫ��
	void LoadSRT()
	{
		//��srt��ʽ����Ļ�ļ������ص������е�list�ؼ�
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpage\\input.srt");
		std::ifstream fIn(strPath.GetData()); //ifsteam ��ȡ����getline,ֱ�Ӷ�ȡһ�У� GetData()��ȡ�ַ���
		
		char strSRTCon[512] = { 0 };//��ȡ���ٸ�
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
		pList->RemoveAll();//�Ȱ�֮ǰ����գ�������ظ���ʾ
		while (!fIn.eof())//���ָ���Ƿ��ڽ�β����ȡ����
		{
			fIn.getline(strSRTCon, 512);//��ȡ��Ļ���  ��strSRTCon�ַ����ж�ȡ512��
			CListTextElementUI* pListItem = new CListTextElementUI;
			pList->Add(pListItem);//ͨ��Add������list�м��ص��ı�����

			fIn.getline(strSRTCon, 512);//��ȡʱ����
			pListItem->SetText(0, UTF8ToUnicode(strSRTCon));//��ÿ����������   1.��� 2.��ȡ���ı����� (ת��Unicode)
			
			fIn.getline(strSRTCon, 512);//��ȡ��Ļ�������ʾ��list�ؼ���
			pListItem->SetText(1, UTF8ToUnicode(strSRTCon));//���õڶ��е�

			fIn.getline(strSRTCon, 512);//��ȡ����
		}
		fIn.close();
	}
	//�ġ����༭�õ���Ļ�ļ�д�ص�srt�ļ���
	void WriteSRT()
	{
		//�Ȼ�ȡSRT�ļ���·��
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpage\\input.srt");
		std::ofstream fOut(strPath.GetData());

		//1.��list�ؼ��л�ȡ�ı�����
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("list_srt"));
		int szCount = pList->GetCount();//��ȡ����
		for (int i = 0; i < szCount; i++)
		{
			CListTextElementUI* pListItem = (CListTextElementUI*)pList->GetItemAt(i);
			//���
			CDuiString strNo;
			strNo.Format(_T("%d"), i + 1);//��ʽ��  i��0��ʼ������Ŵ�1 ��ʼ
			//ʱ����
			CDuiString strTime = pListItem->GetText(0);

			//�ı�����
			CDuiString strWord = pListItem->GetText(1);

			//2.����ȡ������д�ص�srt�ļ���
			string strNewLine = Unicode2ANSI(_T("\n"));//����
			//д�к�
			string itemNo = Unicode2ANSI(strNo);
			fOut.write(itemNo.c_str(), itemNo.size());//���ַ�ת���ַ�
			fOut.write(strNewLine.c_str(), strNewLine.size());
			
			//дʱ����
			string itemTime = Unicode2ANSI(strTime);
			fOut.write(itemTime.c_str(), itemTime.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			
			//д�ı�
			string itemWord = Unicode2ANSI(strWord);
			fOut.write(itemWord.c_str(), itemWord.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			
			//��Ļ����Ļ֮�䶼�и�����
			fOut.write(strNewLine.c_str(), strNewLine.size());
		}
		
		fOut.close();
	}

	//�塢��ȡ��Ƶ���� 
	void GenerateView()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		//1.��������  ffmpeg -i 11.mkv -vcodec copy -an -sn 22.mkv -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//��Ƶ·��
		strCMD += _T("11.mkv -vcodec copy -an -sn ");
		strCMD += strPath;
		strCMD += _T("22.mkv -y");

		SendMessage(strCMD);
	}
	//��.��¼�����޸ĵ�С����Ƶ��Ƕ��������Ƶ�У�
	void BornSRT2View()
	{
		//��������
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		//1.��������  ffmpeg - i 22.mkv -vf subtitles=11.srt 33.mkv -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//��Ƶ·��
		strCMD += _T("22.mkv -vf subtitles=11.srt ");
		strCMD += strPath;
		strCMD += _T("33.mkv -y");

		SendMessage(strCMD);
	}
	//�������ɶ�̬ͼ
	void GenerateGifWithView()
	{
		
		//��������
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		//1.��������//ffmpeg -i 33.mkv -vf scale=iw/2:ih/2 -f gif output.gif -y
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;//��Ƶ·��
		strCMD += _T("33.mkv -vf scale=iw/2:ih/2 -f gif ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");

		SendMessage(strCMD);
	}
	//תUnicode
	CDuiString UTF8ToUnicode(const char* str)  
	{
	     //��һ�ε��ã���ȡת��֮���Ŀ��ĳ���:��Ҫ�����Լ��洢����
		int szLen= ::MultiByteToWideChar(CP_UTF8,0,str,strlen(str),NULL,0);//���ַ���ת��������Ҫ�ĸ�ʽ
		wchar_t* pContent = new wchar_t[szLen + 1];//���ٿռ�
		
		//�ڶ��ε��ã�������ת��
		::MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), pContent, szLen);
		pContent[szLen] = '\0';
		CDuiString s(pContent);
		delete[] pContent;
		return s;
	}
	//��ȡ��Ƶʱ�����ʱ���Ƿ���Ч
	bool IsValidTime(CDuiString strTime)
	{
		//"00:40:30"   //8���ַ�
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
	//UnicodeתASCII
	string Unicode2ANSI(CDuiString str)//  ���ַ��������ַ���
	{
		//��ȡ�ж��ٸ��ֽ�
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
	//// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼�� Ҫ��Ȼ���оͱ�����
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

