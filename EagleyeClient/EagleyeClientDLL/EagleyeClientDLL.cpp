// EagleyeClientDLL.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "EagleyeClientDLL.h"
#include "ClassRealise.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CEagleyeClientDLLApp

BEGIN_MESSAGE_MAP(CEagleyeClientDLLApp, CWinApp)
END_MESSAGE_MAP()


// CEagleyeClientDLLApp ����

CEagleyeClientDLLApp::CEagleyeClientDLLApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CEagleyeClientDLLApp ����

CEagleyeClientDLLApp theApp;


// CEagleyeClientDLLApp ��ʼ��

BOOL CEagleyeClientDLLApp::InitInstance()
{

	NetSpeed(m_Connection.m_lastup, m_Connection.m_lastdown);

	CWinApp::InitInstance();
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}
	/*
	CClientInfo ClientInfo;
	CCreateBag::MonitoredInfo(MonitoredInfoXml, lastup, lastdown, Config);
	//Sleep(1000);
	CCreateBag::MonitoredInfo(MonitoredInfoXml, lastup, lastdown, Config);
	CCreateBag::ClientInfo(ClientInfoXml, ClientInfo);
	*/

	while( m_Connection.InitCConnection() );

	return TRUE;
}
