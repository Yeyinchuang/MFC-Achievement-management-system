#pragma once


// CDlgsearchstudent �Ի���

class CDlgsearchstudent : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgsearchstudent)

public:
	CDlgsearchstudent(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgsearchstudent();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_low;
	int m_high;
};
