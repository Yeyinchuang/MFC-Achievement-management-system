#pragma once


// CDlgsearchgrade �Ի���

class CDlgsearchgrade : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgsearchgrade)

public:
	CDlgsearchgrade(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgsearchgrade();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_key;
	CString name;
	CString id;
	int tag;//���ѡ���ĸ�
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
};
