#pragma once


// CDlgstatistics 对话框

class CDlgstatistics : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgstatistics)

public:
	CDlgstatistics(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgstatistics();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float m_mathaverage;
	float m_physicsaverage;
	float m_englishaverage;
	float m_mathrate;
	float m_physicsrate;
	float m_englishrate;
	float m_mathbiaozhuncha;
	float m_physicsbiaozhuncha;
	float m_englishbiaozhuncha;
	virtual BOOL OnInitDialog();
	float m_average;
};
