#pragma once


// CDldadd �Ի���

class CDldadd : public CDialogEx
{
	DECLARE_DYNAMIC(CDldadd)

public:
	CDldadd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDldadd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_id;
	CString m_name;
	int m_math;
	int m_physics;
	int m_english;
};
