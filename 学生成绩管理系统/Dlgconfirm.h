#pragma once


// Dlgconfirm �Ի���

class Dlgconfirm : public CDialogEx
{
	DECLARE_DYNAMIC(Dlgconfirm)

public:
	Dlgconfirm(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlgconfirm();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
