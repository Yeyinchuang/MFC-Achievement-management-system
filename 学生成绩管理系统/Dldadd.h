#pragma once


// CDldadd 对话框

class CDldadd : public CDialogEx
{
	DECLARE_DYNAMIC(CDldadd)

public:
	CDldadd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDldadd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_id;
	CString m_name;
	int m_math;
	int m_physics;
	int m_english;
};
