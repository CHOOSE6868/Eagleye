#pragma once

// CClientSocket ����Ŀ��


class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	//������Ϣ
	virtual void OnReceive(int nErrorCode);
	virtual void OnAccept(int nErrorCode);
};

