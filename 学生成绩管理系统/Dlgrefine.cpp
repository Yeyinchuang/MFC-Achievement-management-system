// Dlgrefine.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���ɼ�����ϵͳ.h"
#include "Dlgrefine.h"
#include "afxdialogex.h"


// CDlgrefine �Ի���

IMPLEMENT_DYNAMIC(CDlgrefine, CDialogEx)

CDlgrefine::CDlgrefine(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, m_id(_T(""))
	, m_name(_T(""))
	, m_math(0)
	, m_physics(0)
	, m_english(0)
{

}

CDlgrefine::~CDlgrefine()
{
}

void CDlgrefine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT4, m_math);
	DDX_Text(pDX, IDC_EDIT5, m_physics);
	DDX_Text(pDX, IDC_EDIT6, m_english);
}


BEGIN_MESSAGE_MAP(CDlgrefine, CDialogEx)
END_MESSAGE_MAP()


// CDlgrefine ��Ϣ�������
