// Dlgconfirm.cpp : 实现文件
//

#include "stdafx.h"
#include "学生成绩管理系统.h"
#include "Dlgconfirm.h"
#include "afxdialogex.h"


// Dlgconfirm 对话框

IMPLEMENT_DYNAMIC(Dlgconfirm, CDialogEx)

Dlgconfirm::Dlgconfirm(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dlgconfirm::~Dlgconfirm()
{
}

void Dlgconfirm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlgconfirm, CDialogEx)
END_MESSAGE_MAP()


// Dlgconfirm 消息处理程序
