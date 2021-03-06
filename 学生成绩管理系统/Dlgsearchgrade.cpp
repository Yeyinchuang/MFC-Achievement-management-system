// Dlgsearchgrade.cpp : 实现文件
//

#include "stdafx.h"
#include "学生成绩管理系统.h"
#include "Dlgsearchgrade.h"
#include "afxdialogex.h"


// CDlgsearchgrade 对话框

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


// CDlgsearchgrade 消息处理程序


void CDlgsearchgrade::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	id = m_key;
	tag = 1;
	EndDialog(0);
}


void CDlgsearchgrade::OnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	name = m_key;
	tag = 2;
	EndDialog(0);
}
