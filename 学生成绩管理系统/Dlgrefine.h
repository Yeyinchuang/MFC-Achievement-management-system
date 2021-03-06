#pragma once
#include "afxwin.h"


// CDlgrefine 对话框

class CDlgrefine : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgrefine)

public:
	CDlgrefine(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgrefine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_id;
	CString m_id;
	CString m_name;
	int m_math;
	int m_physics;
	int m_english;
};
