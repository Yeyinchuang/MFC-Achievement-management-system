// Dlgsearchstudent.cpp : 实现文件
//

#include "stdafx.h"
#include "学生成绩管理系统.h"
#include "Dlgsearchstudent.h"
#include "afxdialogex.h"


// CDlgsearchstudent 对话框

IMPLEMENT_DYNAMIC(CDlgsearchstudent, CDialogEx)

CDlgsearchstudent::CDlgsearchstudent(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_low(0)
	, m_high(0)
{

}

CDlgsearchstudent::~CDlgsearchstudent()
{
}

void CDlgsearchstudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_low);
	//  DDX_Text(pDX, IDC_EDIT2, high);
	DDX_Text(pDX, IDC_EDIT2, m_high);
}


BEGIN_MESSAGE_MAP(CDlgsearchstudent, CDialogEx)
END_MESSAGE_MAP()


// CDlgsearchstudent 消息处理程序
