#pragma once

#include <string>
//#include "LogicClass.h"
#include "SessionSocket.h"

using namespace std;

/************************************************
Class name: CClientInfo
Create by���ִ��� 
CreateDate��2013-08-19
Explain�������ͻ��˻�����Ӳ����Ϣ 
************************************************/ 

class CClientInfo
{
	public:
		string 	m_csClientIP;		//IP��ַ 
		string 	m_csMAC;			//����MAC��ַ 
	
		string	m_csOS;				//����ϵͳ 
		string 	m_csCPU;			//CPU
		int 	m_nMemory;			//�ڴ�������M�� 
		
	public:
		string TransFromXML(char *); 		//ת��Ϊ��׼XML��ʼ���� 
		CClientInfo();				//���캯������ϵͳ��ȡ��Ϣ 

};

/************************************************
Class name: CProcess
Create by���ִ��� 
CreateDate��2013-08-19
Explain���������� 
************************************************/ 

class CProcess
{
	public:
		string	m_csName;			//������ 
		int		m_nPID;				//����PID 
	
	public:
		CProcess(string, int);		//���캯�� 
};




/************************************************
Class name: CPolicy
Create by���ִ���
CreateDate��2013-08-19
Explain������ĳһ������� 
************************************************/ 

class CPolicy
{
	private:
		string	m_csName;				//������
	public: 
		vector<string>	m_BlackList;	//�ò��Ժ����� 
		
	CPolicy();					//���캯������������ 
	int SetName(string);			//���ò����� 
	string GetName();			//��ȡ������ 
};

/************************************************
Class name: CMonitoredPC
Create by���ִ���
CreateDate��2013-08-19
Explain����������˼�صĵ�̨PC 
************************************************/ 

class CMonitoredPC
{
	public:
		int			m_nStatus;				//�ͻ���״̬������1������0 
		CClientInfo	m_Info;					//�ͻ�����Ӳ����Ϣ 
		int			m_Group;				//�ͻ���������
		int			m_Uprate[20];
		int			m_Downrate[20];
	public:
		vector<CProcess>	m_ProcessList;	//�ͻ��˽����б�
		CSessionSocket		m_SessionSocket;
		CTime				m_LastTime;
	
	CMonitoredPC();	//���캯��
	CClientInfo GetClientInfo();		//��ÿͻ�����Ӳ����Ϣ
	CPolicy GetPolicy();				//��ò��õĲ��� 
	int GetStatus();					//��ȡ�ͻ���״̬ 
	int SetPolicy(CPolicy &);		//���ò��õĲ���
	int SetStatus(int); 				//���ÿͻ���״̬ 
	void Visualization();			//���ӻ����� 
	void TransFromXML(CString &);
};


/************************************************
Class name: CGroup
Create by���ִ���
CreateDate��2013-08-19
Explain������ĳһ�������
************************************************/ 

class CGroup
{
	public:
		string		m_csName;					//���� 
		CPolicy		*m_Policy;					//����� 
	public: 
		vector<string>	m_MemberList;	//������ 
		
	CGroup();					//���캯��
	int SetPolicy(CPolicy &);			//��������� 
	int SetName(string &);				//��������
	string GetName();					//��ȡ����
	CPolicy GetPolicy();					//��ȡ����� 
};

/************************************************
Class name: CServerConfig
Create by���ִ��� 
CreateDate��2013-08-19
Explain�����������������Ϣ 
************************************************/ 

class CServerConfig
{
	private:
		int		m_nTimeout;				//�ͻ����쳣���߳�ʱʱ�䣨���룩 
		int		m_nFrequency;			//ˢ��Ƶ�ʣ����룩 
	public:
		CGroup	m_GroupList[7];	//�����б� 
		vector<CPolicy>	m_PolicyList;	//�����б� 
	
	CServerConfig();			//���캯�� 
	string ClientConfigXML();	//����ͻ�������XML��Ϣ
	int ReadConfigFile();		//���ļ���ȡ���� 
	int WriteConfigFile();		//�����ô����ļ� 
	int GetTimeout();			//��ȡ��ʱʱ��
	int GetFrequency();			//��ȡˢ��Ƶ��
	int SetTimeout(int);			//���ó�ʱʱ�� 
	int SetFrequency(int);			//����ˢ��Ƶ�� 		
};

