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
//			//1.可用（传统版深拷贝）
//			char* ptr = new char[strlen(str.m_pData) + 1];//1.先申请，有异常会抛异常，后面不会进行，原来的实例没有改，保证了异常安全性
//			strcpy(ptr, str.m_pData);
//			delete[] m_pData;//2.再释放自己之前的
//			m_pData = NULL;
//			m_pData = ptr;
//
//			//2.不建议这样先释放，如果申请空间失败，那m_pData会是一个空指针，可能会导致程序崩溃
//			//delete[] m_pData;
//			//m_pData = nullptr;
//			//m_pData = new char[strlen(str.m_pData) + 1];
//			//strcpy(m_pData, str.m_pData);
//
//			////3.可用 （现代版深拷贝）
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