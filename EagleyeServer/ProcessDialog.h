#pragma once


// CProcessDialog �Ի���
#include "resource.h"
#include "EntityClass.h"
#include "afxcmn.h"

class CProcessDialog : public CDialog
{
	DECLARE_DYNAMIC(CProcessDialog)

public:
	CProcessDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProcessDialog();
	CListCtrl *m_pProcess;

// �Ի�������
	enum { IDD = IDD_PROCESS_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMonitoredPC *m_pMonitoredPC;
	afx_msg void OnBnClickedButtonKill();
	afx_msg void OnBnClickedButtonAddbl();
};
