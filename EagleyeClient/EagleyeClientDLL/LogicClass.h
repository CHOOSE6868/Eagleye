#pragma once

#include "EntityClass.h"
#include "ClientSocket.h"
/* ***********************************************
Class name: CConnection
Create by：翁婷婷
CreateDate：2013-08-28
Explain：通信模块
*********************************************** */ 
class CConnection
{
private:
	CClientSocket m_TCPSocket;
	CClientSocket m_UDPSocket;
	CClientSocket m_SessionSocket;

	
	
	int m_nUDPTimerID;
	int m_nTCPTimerID;
	static CConnection * m_pThis;	//供回调函数获得

public:

	long m_lastup;
	long m_lastdown;

	CConnection(void);
	~CConnection(void);

	CClientInfo ClientInfo;
	CClientConfig ClientConfig;

	CClientSocket *GetTCPSocket();
	CClientSocket *GetUDPSocket();
	CClientSocket *GetSessionSocket();

	int GetUDPTimerID();
	int GetTCPTimerID();
	int SetUDPTimerID(int nID);
	int SetTCPTimerID(int nID);
	//设置静态指针，供静态回调函数使用，实现静态回调函数对非静态类成员的访问

	void SetStaticPThis();
	int InitCConnection();	//初始化信息

	//局域网发送广播信息，通知服务端上线
	static int Broadcast(string &rszInfo);
	//客户端监听服务端
	static int ReceiveMessage(CClientSocket &rTCPSocket);
	//客户端监听到服务端的连接请求
	static int EstablishConnection();
	//客户端发送监控信息
	static int SendMonitoredInfo(string &rInfo);
	//定时器回调函数 触发发送受监控信息
	static  VOID CALLBACK ProcTCPTimer(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime);
	//定时器回调函数 触发发送广播信息
	static  VOID CALLBACK ProcUDPTimer(HWND hWnd,UINT uMsg,UINT idEvent,unsigned long dwTime);
};

/************************************************
Class name: CCientMessageHandle
Create by：林达意 
CreateDate：2013-08-22
Explain：客户端消息处理模块
************************************************/ 
class CClientMessageHandle
{
	public:
		static void PrintScreen();								//截屏
		static int RunCommand(CCommand &);						//执行CMD指令
		static void ClientInitial(CClientConfig &, string &);	//客户端初始化
};

/************************************************
Class name: CCreateBag
Create by：林达意 
CreateDate：2013-08-27
Explain：客户端构造包
************************************************/ 
class CCreateBag
{
	public:
		static int MonitoredInfo(string &, long &, long &, CClientConfig &);		//构造监控信息包
		static int ClientInfo(string &, CClientInfo &);		//构造客户端信息包
};

