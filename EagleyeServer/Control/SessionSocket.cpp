// SessionSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
//#include "EagleServer.h"
#include "SessionSocket.h"
#include "Connection.h"


// CSessionSocket

CSessionSocket::CSessionSocket()
{
}

CSessionSocket::~CSessionSocket()
{
}


// CSessionSocket ��Ա����
void CSessionSocket::OnReceive(int nErrorCode) 
{
	CConnection::ReceiveMonitoredInfo(*this);
	CSocket::OnReceive(nErrorCode);
}