// EagleyeClientDLL.h : EagleyeClientDLL DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "LogicClass.h"


// CEagleyeClientDLLApp
// �йش���ʵ�ֵ���Ϣ������� EagleyeClientDLL.cpp
//

class CEagleyeClientDLLApp : public CWinApp
{
public:
	CEagleyeClientDLLApp();

// ��д
public:
	virtual BOOL InitInstance();
	CConnection m_Connection;

	DECLARE_MESSAGE_MAP()
};
