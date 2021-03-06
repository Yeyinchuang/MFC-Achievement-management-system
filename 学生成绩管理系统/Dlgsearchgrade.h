#pragma once


// CDlgsearchgrade 对话框

class CDlgsearchgrade : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgsearchgrade)

public:
	CDlgsearchgrade(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgsearchgrade();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_key;
	CString name;
	CString id;
	int tag;//标记选择哪个
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
};
