#pragma once
#include "afxcmn.h"
#include "BaseInfoDialog.h"
#include "ProcessDialog.h"

// CDetailDlg �Ի���

class CDetailDlg : public CDialog
{
	DECLARE_DYNAMIC(CDetailDlg)

public:
	CDetailDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetailDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	CBaseInfoDialog m_BaseInfoDlg;
	CProcessDialog  m_ProcessDlg;
	CMonitoredPC *m_pMonitoredPC;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedDownrateStatic();
};
