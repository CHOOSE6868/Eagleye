#pragma once

#include "afxsock.h"
//#include "EntityClass.h"
// CSessionSocket ����Ŀ��

class CSessionSocket : public CSocket
{
public:
	//CMonitoredPC &m_PC;
	int m_PC;//���޸�
public:
	CSessionSocket();
	virtual ~CSessionSocket();
	virtual void OnReceive(int nErrorCode);
};


