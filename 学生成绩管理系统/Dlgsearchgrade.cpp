// Dlgsearchgrade.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����ϵͳ.h"
#include "Dlgsearchgrade.h"
#include "afxdialogex.h"


// CDlgsearchgrade �Ի���

IMPLEMENT_DYNAMIC(CDlgsearchgrade, CDialogEx)

CDlgsearchgrade::CDlgsearchgrade(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_key(_T(""))
{

}

CDlgsearchgrade::~CDlgsearchgrade()
{
}

void CDlgsearchgrade::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_key);
}


BEGIN_MESSAGE_MAP(CDlgsearchgrade, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgsearchgrade::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgsearchgrade::OnClickedButton2)
END_MESSAGE_MAP()


// CDlgsearchgrade ��Ϣ�������


void CDlgsearchgrade::OnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	id = m_key;
	tag = 1;
	EndDialog(0);
}


void CDlgsearchgrade::OnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	name = m_key;
	tag = 2;
	EndDialog(0);
}
