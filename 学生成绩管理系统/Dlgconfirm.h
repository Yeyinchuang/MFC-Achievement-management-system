#pragma once


// Dlgconfirm 对话框

class Dlgconfirm : public CDialogEx
{
	DECLARE_DYNAMIC(Dlgconfirm)

public:
	Dlgconfirm(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlgconfirm();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
