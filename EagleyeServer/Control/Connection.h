#pragma once
#include "UDPSocket.h"
#include "SessionSocket.h"
#include "EntityClass.h"

#include <string>
using namespace std;

#define PORT 32767

class CConnection
{
private:
	CUDPSocket m_UDPSokcet;
	//CMonitoredPC *m_pPCArray;
	CServerConfig *m_pServerConfig;
public:
	static CConnection * m_pThis;
	CUIWnd *m_pUI;
	CConnection();
	~CConnection(void);
	
	int InitConnection(CMonitoredPC *pPCArray,CServerConfig *, CUIWnd *);
	static int ReceiveUDPMessage(CUDPSocket &rUDPSocket);//����UDP�㲥
	static int ReceiveMonitoredInfo(CSessionSocket &rSessionSocket);//���ռ����Ϣ
	static int SendConfiguration(CSessionSocket &rSessionSocket);//����������Ϣ
	//static int SendCommand();//����ָ��
	static 	VOID CALLBACK CheckOnLine(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime);//����Ƿ����
};
