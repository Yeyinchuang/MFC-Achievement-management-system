#pragma once


// CDlgsearchstudent 对话框

class CDlgsearchstudent : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgsearchstudent)

public:
	CDlgsearchstudent(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgsearchstudent();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_low;
	int m_high;
};
