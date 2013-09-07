#pragma once

#include "ClientSocket.h"
#include <string>
using namespace std;
class CConnection
{
private:
	CClientSocket m_TCPSocket;
	CClientSocket m_UDPSocket;
	CClientSocket m_SessionSocket;
	
	int m_nUDPTimerID;
	int m_nTCPTimerID;
	static CConnection * m_pThis;	//���ص��������

public:
	CConnection(void);
	~CConnection(void);
	CClientSocket *GetTCPSocket();
	CClientSocket *GetUDPSocket();
	CClientSocket *GetSessionSocket();

	int GetUDPTimerID();
	int GetTCPTimerID();
	int SetUDPTimerID(int nID);
	int SetTCPTimerID(int nID);
	//���þ�ָ̬�룬����̬�ص�����ʹ�ã�ʵ�־�̬�ص������ԷǾ�̬���Ա�ķ���

	void SetStaticPThis();
	int InitCConnection();	//��ʼ����Ϣ

	//���������͹㲥��Ϣ��֪ͨ���������
	static int Broadcast(string &rszInfo);
	//�ͻ��˼��������
	static int ReceiveMessage(CClientSocket &rTCPSocket);
	//�ͻ��˼���������˵���������
	static int EstablishConnection();
	//�ͻ��˷��ͼ����Ϣ
	static int SendMonitoredInfo(string &rInfo);
	//��ʱ���ص����� ���������ܼ����Ϣ
	static  VOID CALLBACK ProcTCPTimer(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime);
	//��ʱ���ص����� �������͹㲥��Ϣ
	static  VOID CALLBACK ProcUDPTimer(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime);

	friend class CCreateBag;
};