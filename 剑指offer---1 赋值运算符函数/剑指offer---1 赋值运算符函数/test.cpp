//#include<iostream>
//using namespace std;
//class CMyString
//{
//public:
//	CMyString(char* pData = NULL);
//	CMyString(const char& str);
//	CMyString& operator=(const CMyString& str)
//	{
//		if (this!=&str)
//		{
//			//1.���ã���ͳ�������
//			char* ptr = new char[strlen(str.m_pData) + 1];//1.�����룬���쳣�����쳣�����治����У�ԭ����ʵ��û�иģ���֤���쳣��ȫ��
//			strcpy(ptr, str.m_pData);
//			delete[] m_pData;//2.���ͷ��Լ�֮ǰ��
//			m_pData = NULL;
//			m_pData = ptr;
//
//			//2.�������������ͷţ��������ռ�ʧ�ܣ���m_pData����һ����ָ�룬���ܻᵼ�³������
//			//delete[] m_pData;
//			//m_pData = nullptr;
//			//m_pData = new char[strlen(str.m_pData) + 1];
//			//strcpy(m_pData, str.m_pData);
//
//			////3.���� ���ִ��������
//			//CMyString temp(str);
//			////swap(m_pData, temp.m_pData);
//			//char* t = temp.m_pData;
//			//temp.m_pData = m_pData;
//			//m_pData = t;
//		}
//		return *this;
//	}
//	~CMyString(void);
//private:
//	char* m_pData;
//};
//int main()
//{
//
//	return 0;
//}