// UDPSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
//#include "EagleServer.h"
#include "UDPSocket.h"
#include "Connection.h"

// CUDPSocket

CUDPSocket::CUDPSocket()
{
}

CUDPSocket::~CUDPSocket()
{
}


// CUDPSocket ��Ա����
void CUDPSocket::OnReceive(int nErrorCode) 
{
	CConnection::ReceiveUDPMessage(*this);
	CSocket::OnReceive(nErrorCode);
}