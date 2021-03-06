
// 学生成绩管理系统Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include<vector>

// C学生成绩管理系统Dlg 对话框
class C学生成绩管理系统Dlg : public CDialogEx
{
// 构造
public:
	C学生成绩管理系统Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	vector<Student> m_students;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float getaveragegrade(string tag);//用来标记求什么成绩
	float getaveragegrade();//求总分数平均值
	float getstandarddeviation(string tag);//求标准差
	float getacceptancerate(string tag);//求合格率
	afx_msg void OnClickedOpen();
	CListCtrl m_SList;
	void open();
	afx_msg void OnClickedWrite();
	afx_msg void OnClickedSort();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedClear();
	afx_msg void OnClickedSearchgrade();
	afx_msg void OnClickedSearchstudent();
	afx_msg void OnClickedStatistic();
	afx_msg void OnClickedRefine();
	afx_msg void OnClickedAdd();
};
