#pragma once

#include "StdAfx.h"
#include "LogicClass.h"
#include "Markup.h"
//#include "ClassRealise.h"
#define PORT 32767

CConnection::CConnection(void)
{
	m_nUDPTimerID = -1;
	m_nTCPTimerID = -1;
}

CConnection::~CConnection(void)
{
}

CClientSocket * CConnection::GetTCPSocket()
{
	return &m_TCPSocket;
}

CClientSocket * CConnection::GetUDPSocket()
{
	return &m_UDPSocket;
}

CClientSocket * CConnection::GetSessionSocket()
{
	return &m_SessionSocket;
}

int CConnection::GetUDPTimerID()
{
	return m_nUDPTimerID;
}

int CConnection::GetTCPTimerID()
{
	return m_nTCPTimerID;
}


int CConnection::SetUDPTimerID(int nID)
{
	m_nUDPTimerID=nID;
	return m_nUDPTimerID;
}

int CConnection::SetTCPTimerID(int nID)
{
	m_nTCPTimerID=nID;
	return  m_nTCPTimerID;
}

CConnection * CConnection::m_pThis=NULL;

void CConnection::SetStaticPThis()
{
	m_pThis=this;
}

int CConnection::InitCConnection()
{
	SetStaticPThis();

	//�˴����ȡϵͳ��Ϣ��Ȼ������״η��͹㲥��Ϣ
	if (  m_TCPSocket.Create(PORT)==NULL )
	{
		return -1;
	};
	m_TCPSocket.Listen ();

	string BroadcastMessage;
	CCreateBag::ClientInfo(BroadcastMessage, ClientInfo);

	//AfxMessageBox(_T("�㲥��һ��"));
	CConnection::Broadcast(BroadcastMessage);
	int nID=::SetTimer(NULL,0,1000,CConnection::ProcUDPTimer);  //���ö�ʱ���͹㲥
	m_pThis->SetUDPTimerID(nID);
	return 0;
}
	
int CConnection::Broadcast(string &rszInfo)
{
	CClientSocket  &rUDPSocket = *( CConnection::m_pThis->GetUDPSocket() );

	if(rUDPSocket == INVALID_SOCKET)//�鿴UDP�Ƿ��Ѿ�����
	{
		if(	!rUDPSocket.Create(0,SOCK_DGRAM) )
			return -1;
	}
	BOOL bCmdOpt = TRUE;//��ʵ������,�������SO_BROADCAST�������ֵ
	rUDPSocket.SetSockOpt(SO_BROADCAST, (void*)&bCmdOpt, 1);	//�����׽���Ϊ�㲥�׽���

	/*//ָ��UDP�㲥��ַ
	SOCKADDR_IN addr;
	//sin_familyָ��Э���壬��socket�����ֻ����AF_INET
	addr.sin_family = AF_INET;
	//sin_addr�洢IP��ַ,s_addr���������ֽ�˳��洢IP��ַ
	addr.sin_addr.S_un.S_addr= INADDR_BROADCAST;
	//sin_port�洢�˿ں�
	addr.sin_port = htons(PORT);*/

	//int count=rUDPSocket.SendTo(rszInfo.c_str(),rszInfo.length() , (SOCKADDR*)&addr, sizeof(addr));
	int count = rUDPSocket.SendTo(rszInfo.c_str(),rszInfo.length(), PORT, TEXT("255.255.255.255"));

	return count;
}

int CConnection::ReceiveMessage(CClientSocket &rTCPSocket)
{
	//AfxMessageBox(_T("�յ���Ϣ��"));
	char * pBuf = new char[5000];
	int nBuflen = 5000;
	int nRecvNum = rTCPSocket.Receive  (pBuf,nBuflen);

	pBuf[nRecvNum] = 0;
	CString m_str(pBuf);
	CString sTem;
	string m_sstr(pBuf);
	
	//AfxMessageBox(m_str);

	CMarkup xml;
	xml.SetDoc(m_str);
	xml.ResetPos();
	xml.FindElem();
	sTem = xml.GetAttrib(TEXT("type"));
	if (sTem == "clientConfig")
	{
		m_pThis->ClientConfig.ReadXML(m_sstr);
		int nID=::SetTimer(NULL,0,m_pThis->ClientConfig.GetFrequency(),ProcTCPTimer);
		CConnection::m_pThis->SetTCPTimerID(nID);
	}
	else if (sTem == "command")
	{
		CCommand command;
		xml.FindChildElem();
		command.SetCommand(xml.GetChildData());
		command.RunCommand();
	}
	
	delete pBuf;
	return 0;
}

int CConnection::EstablishConnection()
{

	CClientSocket &rTCPSocket=*( CConnection::m_pThis->GetTCPSocket() );
	CClientSocket &rSessionSocket=*( CConnection::m_pThis->GetSessionSocket() );
	if( 	!rTCPSocket.Accept(rSessionSocket) )
	{
		return 0;
	}
	else
	{
		//AfxMessageBox(_T("TCP��������"));
		::KillTimer(NULL,(CConnection::m_pThis->GetUDPTimerID()) );//�رն�ʱ����UDP�㲥
		/*int nID=::SetTimer(NULL,0,3000,ProcTCPTimer);
		CConnection::m_pThis->SetTCPTimerID(nID);*/
		return 1;
	}
}

int CConnection::SendMonitoredInfo(string &rInfo)
{
	//AfxMessageBox(_T("������"));
	CClientSocket &rTCPSocket=*(CConnection::m_pThis->GetSessionSocket());

	int nSendNum=rTCPSocket.Send(rInfo.c_str(),rInfo.length());
		if(nSendNum==WSAENOTCONN ||nSendNum==WSAENETDOWN  ||nSendNum==WSAESHUTDOWN ||nSendNum==WSAENETDOWN||nSendNum==WSAENETRESET||nSendNum==WSAECONNABORTED)
	{
		//AfxMessageBox(TEXT("����˹رգ�"));
		::KillTimer(NULL,(CConnection::m_pThis->GetTCPTimerID()) );
		CConnection::m_pThis->InitCConnection();
	}
	return nSendNum;
}

VOID CALLBACK CConnection:: ProcTCPTimer(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime)
{
	//AfxMessageBox(_T("��ʱTCP"));
	string str;
	CCreateBag::MonitoredInfo(str, m_pThis->m_lastup, m_pThis->m_lastdown, m_pThis->ClientConfig);
	CConnection::SendMonitoredInfo(str);	
}

VOID CALLBACK CConnection::  ProcUDPTimer(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime)
{
	//AfxMessageBox(_T("��ʱ�㲥"));
	string str;
	CCreateBag::ClientInfo(str, CConnection::m_pThis->ClientInfo);
	CConnection::Broadcast(str);	
}