
// ѧ���ɼ�����ϵͳDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include<vector>

// Cѧ���ɼ�����ϵͳDlg �Ի���
class Cѧ���ɼ�����ϵͳDlg : public CDialogEx
{
// ����
public:
	Cѧ���ɼ�����ϵͳDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	vector<Student> m_students;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float getaveragegrade(string tag);//���������ʲô�ɼ�
	float getaveragegrade();//���ܷ���ƽ��ֵ
	float getstandarddeviation(string tag);//���׼��
	float getacceptancerate(string tag);//��ϸ���
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
