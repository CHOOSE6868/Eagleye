#pragma once


// CBaseInfoDialog �Ի���
#include "resource.h"
#include "LogicClass.h"
#include "afxwin.h"

class CBaseInfoDialog : public CDialog
{
	DECLARE_DYNAMIC(CBaseInfoDialog)

public:
	CBaseInfoDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBaseInfoDialog();

// �Ի�������
	enum { IDD = IDD_BASEINFO_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMonitoredPC *m_pMonitoredPC;
	afx_msg void OnBnClickedSendcomm();
	afx_msg void OnCbnSelchangeGroup();
	CComboBox m_cbGroup;
};
