// Dlgstatistics.cpp : 实现文件
//

#include "stdafx.h"
#include "学生成绩管理系统.h"
#include "Dlgstatistics.h"
#include "afxdialogex.h"

// CDlgstatistics 对话框

IMPLEMENT_DYNAMIC(CDlgstatistics, CDialogEx)

CDlgstatistics::CDlgstatistics(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_mathaverage(0)
	, m_physicsaverage(0)
	, m_englishaverage(0)
	, m_mathrate(0)
	, m_physicsrate(0)
	, m_englishrate(0)
	, m_mathbiaozhuncha(0)
	, m_physicsbiaozhuncha(0)
	, m_englishbiaozhuncha(0)
	, m_average(0)
{

}

CDlgstatistics::~CDlgstatistics()
{
}

void CDlgstatistics::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_mathaverage);
	DDX_Text(pDX, IDC_EDIT4, m_physicsaverage);
	DDX_Text(pDX, IDC_EDIT6, m_englishaverage);
	DDX_Text(pDX, IDC_EDIT3, m_mathrate);
	DDX_Text(pDX, IDC_EDIT5, m_physicsrate);
	DDX_Text(pDX, IDC_EDIT7, m_englishrate);
	DDX_Text(pDX, IDC_EDIT8, m_mathbiaozhuncha);
	DDX_Text(pDX, IDC_EDIT9, m_physicsbiaozhuncha);
	DDX_Text(pDX, IDC_EDIT10, m_englishbiaozhuncha);
	DDX_Text(pDX, IDC_EDIT11, m_average);
}


BEGIN_MESSAGE_MAP(CDlgstatistics, CDialogEx)
END_MESSAGE_MAP()


// CDlgstatistics 消息处理程序


BOOL CDlgstatistics::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
