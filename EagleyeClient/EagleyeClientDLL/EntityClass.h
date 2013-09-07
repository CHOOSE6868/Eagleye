#pragma once

/************************************************
Class name: CClientInfo
Create by���ִ��� 
CreateDate��2013-08-19
Explain�������ͻ��˻�����Ӳ����Ϣ 
************************************************/ 

#include <string>

using namespace std;

class CClientInfo
{
	private:
		string 	m_csClientIP;		//IP��ַ 
		string 	m_csMAC;			//����MAC��ַ 
	
		string	m_csOS;				//����ϵͳ 
		string 	m_csCPU;			//CPU
		DWORDLONG 	m_nMemory;			//�ڴ�������M�� 
	public:
		CClientInfo();				//���캯������ϵͳ��ȡ��Ϣ 
		friend class CCreateBag;
};

/************************************************
Class name: CClientConfig
Create by���ִ��� 
CreateDate��2013-08-19
Explain�������ͻ���������Ϣ 
************************************************/ 

class CClientConfig
{
	private:
		string	m_csServerIP;		//�����IP 
		int 	m_nFrequency;		//ˢ��Ƶ�ʣ����룩 
	
	public:
		int ReadXML(string &);  	//��ȡXML����ʼ������
		string GetServerIP();		//��ȡ�����IP 
		int GetFrequency();			//��ȡˢ��Ƶ�� 
};

/************************************************
Class name: CCommand
Create by���ִ��� 
CreateDate��2013-08-19
Explain������CMDָ�� 
************************************************/ 

class CCommand
{
	private:
		string	m_csCommand;		//CMDָ�� 
	
	public:
		int RunCommand();		//ִ��CMDָ�� 
		int SetCommand(CString);
};