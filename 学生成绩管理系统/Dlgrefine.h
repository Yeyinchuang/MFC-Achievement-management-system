#pragma once
#include "afxwin.h"


// CDlgrefine �Ի���

class CDlgrefine : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgrefine)

public:
	CDlgrefine(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgrefine();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_id;
	CString m_id;
	CString m_name;
	int m_math;
	int m_physics;
	int m_english;
};
