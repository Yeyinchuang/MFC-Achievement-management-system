#pragma once


// CDlgstatistics �Ի���

class CDlgstatistics : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgstatistics)

public:
	CDlgstatistics(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgstatistics();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
