// ClientSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClientSocket.h"
#include "LogicClass.h"


// CClientSocket
CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}
//CClientSocket ��Ա����

void CClientSocket::OnReceive(int nErrorCode) 
{
	CConnection::ReceiveMessage(*this);
	CSocket::OnReceive(nErrorCode);
}

void CClientSocket::OnAccept(int nErrorCode) 
{
	CConnection::EstablishConnection();	
	CSocket::OnAccept(nErrorCode);
}