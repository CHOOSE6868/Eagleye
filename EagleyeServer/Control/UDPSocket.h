#pragma once
#include "afxsock.h"

// CUDPSocket ����Ŀ��

class CUDPSocket : public CSocket
{
public:
	CUDPSocket();
	virtual ~CUDPSocket();
	virtual void OnReceive(int nErrorCode);
};