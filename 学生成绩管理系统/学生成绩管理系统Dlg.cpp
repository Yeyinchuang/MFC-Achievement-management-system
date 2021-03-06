
// 学生成绩管理系统Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include<fstream>
#include "学生成绩管理系统.h"
#include "学生成绩管理系统Dlg.h"
#include"Dlgconfirm.h"
#include"Dlgsearchgrade.h"
#include"Dlgsearchstudent.h"
#include"Dlgstatistics.h"
#include"Dlgrefine.h"
#include"Dldadd.h"
#include<algorithm>
#include "afxdialogex.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C学生成绩管理系统Dlg 对话框



C学生成绩管理系统Dlg::C学生成绩管理系统Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C学生成绩管理系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_SList);
}

BEGIN_MESSAGE_MAP(C学生成绩管理系统Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &C学生成绩管理系统Dlg::OnClickedOpen)
	ON_BN_CLICKED(IDC_Write, &C学生成绩管理系统Dlg::OnClickedWrite)
	ON_BN_CLICKED(IDC_sort, &C学生成绩管理系统Dlg::OnClickedSort)
	ON_BN_CLICKED(IDC_delete, &C学生成绩管理系统Dlg::OnClickedDelete)
	ON_BN_CLICKED(IDC_clear, &C学生成绩管理系统Dlg::OnClickedClear)
	ON_BN_CLICKED(IDC_searchgrade, &C学生成绩管理系统Dlg::OnClickedSearchgrade)
	ON_BN_CLICKED(IDC_searchstudent, &C学生成绩管理系统Dlg::OnClickedSearchstudent)
	ON_BN_CLICKED(IDC_Statistic, &C学生成绩管理系统Dlg::OnClickedStatistic)
	ON_BN_CLICKED(IDC_Refine, &C学生成绩管理系统Dlg::OnClickedRefine)
	ON_BN_CLICKED(IDC_Add, &C学生成绩管理系统Dlg::OnClickedAdd)
END_MESSAGE_MAP()


// C学生成绩管理系统Dlg 消息处理程序

BOOL C学生成绩管理系统Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	DWORD dwStyle = m_SList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	///////////
	m_SList.SetExtendedStyle(dwStyle);
	m_SList.InsertColumn(0, TEXT("学号"), LVCFMT_LEFT, 100);              //添加列标题！！！！  这里的80,40,90用以设置列的宽度。！！！LVCFMT_LEFT用来设置对齐方式！！！
	m_SList.InsertColumn(1, TEXT("姓名"), LVCFMT_LEFT, 80);
	m_SList.InsertColumn(2, TEXT("数学"), LVCFMT_LEFT, 70);
	m_SList.InsertColumn(3, TEXT("物理"), LVCFMT_LEFT, 70);
	m_SList.InsertColumn(4, TEXT("英语"), LVCFMT_LEFT, 70);
	m_SList.InsertColumn(5, TEXT("总分"), LVCFMT_LEFT, 70);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C学生成绩管理系统Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C学生成绩管理系统Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C学生成绩管理系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

float C学生成绩管理系统Dlg::getaveragegrade(string tag)
{
	int n = m_students.size();
	float sum = 0;
	if (tag == "math") {
		for (int i = 0; i < n; i++)
			sum += m_students[i].getmath();
	}
	else if (tag == "physics") {
		for (int i = 0; i < n; i++)
			sum += m_students[i].getphysics();
	}
	else if (tag == "english") {
		for (int i = 0; i < n; i++)
			sum += m_students[i].getenglish();
	}
	else return -1;
	return sum / n;
}

float C学生成绩管理系统Dlg::getaveragegrade()
{
	int n = m_students.size();
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += m_students[i].getnum();
	}
	return sum / n;
}

float C学生成绩管理系统Dlg::getstandarddeviation(string tag)
{
	float average = getaveragegrade(tag);
	if (average == -1) return -1;
	float fangcha = 0;
	int n = m_students.size();
	if (tag == "math") {
		for (int i = 0; i < n; i++)
			fangcha += pow(m_students[i].getmath() - average, 2);
	}
	else if (tag == "physics") {
		for (int i = 0; i < n; i++)
			fangcha += pow(m_students[i].getphysics() - average, 2);
	}
	else if (tag == "english") {
		for (int i = 0; i < n; i++)
			fangcha += pow(m_students[i].getenglish() - average, 2);
	}
	return sqrt(fangcha);
}

float C学生成绩管理系统Dlg::getacceptancerate(string tag)
{
	int n = m_students.size();
	int count = 0;//多少人合格
	if (tag == "math") {
		for (int i = 0; i < n; i++)
			if (m_students[i].getmath() >= 60)
				count++;
	}
	else if (tag == "physics") {
		for (int i = 0; i < n; i++)
			if (m_students[i].getphysics() >= 60)
				count++;
	}
	else if (tag == "english") {
		for (int i = 0; i < n; i++)
			if (m_students[i].getenglish() >= 60)
				count++;
	}
	else return -1;
	return float(count) / n;
}



void C学生成绩管理系统Dlg::OnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
//	CString str;
	m_students.clear();
	char a[500];
	string ID;
	string Name;
	int Math;
	int Physical;
	int English;
	ifstream input("成绩原数据.txt");
	if (!input) {
		MessageBox(TEXT("打开文件出错"));
		return;
	}
	input.getline(a,500);
	while (true) {
		input >> ID >> Name >> Math >> Physical >> English;
		if (!input.eof() == 0) break;
		Student student(ID, Name, Math, Physical, English);
		m_students.push_back(student);
	}
	open();
}




void C学生成绩管理系统Dlg::open()
{
	CString str;
	m_SList.DeleteAllItems();
	int n = m_students.size();
	for (int i = 0; i<n; i++)
	{
		Student stu = m_students[i];
		m_SList.InsertItem(i, _T(""));
		str = stu.getid().c_str();
		m_SList.SetItemText(i, 0, str);

		str = stu.getname().c_str();
		m_SList.SetItemText(i, 1, str);

		str.Empty();
		str.Format(TEXT("%d"), stu.getmath());
		m_SList.SetItemText(i, 2, str);

		str.Format(_T("%d"), stu.getphysics());
		m_SList.SetItemText(i, 3, str);


		//	str.Empty();
		str.Format(_T("%d"), stu.getenglish());
		m_SList.SetItemText(i, 4, str);

		//	str.Empty();
		str.Format(_T("%d"), stu.getnum());
		m_SList.SetItemText(i, 5, str);

		//	str.Empty();
	}
}


void C学生成绩管理系统Dlg::OnClickedWrite()
{
	// TODO: 在此添加控件通知处理程序代码
	ofstream output("成绩原数据.txt");
	if (!output) {
		MessageBox(_T("未成功写入")); return ;
	}
	output << "学号" << '\t' << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "物理" << '\t' << "英语" << endl;
	vector<Student>::iterator pos;
	pos = m_students.begin();
	while (pos != m_students.end()) {
		output << pos->getid() << '\t' << pos->getname() << '\t' << pos->getmath() << '\t' << pos->getphysics() << '\t' << pos->getenglish() << endl;
		pos++;
	}
	MessageBox(_T("写入文件成功"));
}


void C学生成绩管理系统Dlg::OnClickedSort()
{
	// TODO: 在此添加控件通知处理程序代码
	sort(m_students.begin(), m_students.end(), greater);
	open();
}


void C学生成绩管理系统Dlg::OnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int a = m_SList.GetSelectionMark();
	if (a == -1)
	{
		MessageBox(_T("请选中一行信息!"), _T("删除信息"));
		return;
	}
	Dlgconfirm dlg;
	if (IDOK == dlg.DoModal()) {
		m_SList.DeleteItem(a);
		vector<Student>::iterator pos;
		pos = m_students.begin();
		while (pos != m_students.end()) {
			if (pos->getid() == m_students[a].getid()) {
				m_students.erase(pos);
				MessageBox(_T("删除成功!"));
				break;
			}
			pos++;
		}
	}
}


void C学生成绩管理系统Dlg::OnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_SList.DeleteAllItems();
	m_students.clear();
}


void C学生成绩管理系统Dlg::OnClickedSearchgrade()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgsearchgrade dlg;
	dlg.DoModal();
	int n = m_students.size();
	int i;
	if (dlg.tag == 1) {
		string str0;
		str0 = CT2A(dlg.id.GetString());
		for (i = 0; i < n; i++) {
			if (m_students[i].getid() == str0)
				break;
		}
		if (i==n) {
			MessageBox(_T("查询不到"));
			return;
		}
		CString str;
		m_SList.DeleteAllItems();
		m_SList.InsertItem(0, _T(""));
		str = m_students[i].getid().c_str();
		m_SList.SetItemText(0, 0, str);

		str = m_students[i].getname().c_str();
		m_SList.SetItemText(0, 1, str);

		str.Empty();
		str.Format(TEXT("%d"), m_students[i].getmath());
		m_SList.SetItemText(0, 2, str);

		str.Format(_T("%d"), m_students[i].getphysics());
		m_SList.SetItemText(0, 3, str);


		str.Format(_T("%d"), m_students[i].getenglish());
		m_SList.SetItemText(0, 4, str);

		str.Format(_T("%d"), m_students[i].getnum());
		m_SList.SetItemText(0, 5, str);
	}
	else if (dlg.tag == 2) {
		string str0;
		str0 = CT2A(dlg.name.GetString());
		for (i = 0; i < n; i++) {
			if (m_students[i].getname() == str0)
				break;
		}
		if (i==n) {
			MessageBox(_T("查询不到"));
			return;
		}
		CString str;
		m_SList.DeleteAllItems();
		m_SList.InsertItem(0, _T(""));
		str = m_students[i].getid().c_str();
		m_SList.SetItemText(0, 0, str);

		str = m_students[i].getname().c_str();
		m_SList.SetItemText(0, 1, str);

		str.Empty();
		str.Format(TEXT("%d"), m_students[i].getmath());
		m_SList.SetItemText(0, 2, str);

		str.Format(_T("%d"), m_students[i].getphysics());
		m_SList.SetItemText(0, 3, str);


		str.Format(_T("%d"), m_students[i].getenglish());
		m_SList.SetItemText(0, 4, str);

		str.Format(_T("%d"), m_students[i].getnum());
		m_SList.SetItemText(0, 5, str);

	}
	else { MessageBox(_T("查询取消"));}
}


void C学生成绩管理系统Dlg::OnClickedSearchstudent()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgsearchstudent dlg;
	if (IDOK == dlg.DoModal()) {
		int n = m_SList.GetItemCount();
		for (int i = 0; i < n; i++) {
			int grade= _ttoi(m_SList.GetItemText(i, 5));//CString转int
			if(grade<dlg.m_low||grade>dlg.m_high)//不符合去掉
				m_SList.DeleteItem(i);
		}
	}
}


void C学生成绩管理系统Dlg::OnClickedStatistic()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgstatistics dlg;
	dlg.m_mathaverage = getaveragegrade("math");
	dlg.m_physicsaverage = getaveragegrade("physics");
	dlg.m_englishaverage = getaveragegrade("english");
	dlg.m_mathrate = getacceptancerate("math");
	dlg.m_physicsrate = getacceptancerate("physics");
	dlg.m_englishrate = getacceptancerate("english");
	dlg.m_mathbiaozhuncha = getstandarddeviation("math");
	dlg.m_physicsbiaozhuncha = getstandarddeviation("physics");
	dlg.m_englishbiaozhuncha = getstandarddeviation("english");
	dlg.m_average = getaveragegrade();
	dlg.DoModal();
}


void C学生成绩管理系统Dlg::OnClickedRefine()
{
	// TODO: 在此添加控件通知处理程序代码
	int a = m_SList.GetSelectionMark();
	if (a == -1)
	{
		MessageBox(_T("请选中一行信息!"), _T("修改信息"));
		return;
	}
	CDlgrefine dlg;
	string str;
	str = CT2A(m_SList.GetItemText(a, 0));
	dlg.m_id = m_SList.GetItemText(a, 0);
	dlg.m_name = m_SList.GetItemText(a, 1);
	dlg.m_math = _ttoi(m_SList.GetItemText(a, 2));
	dlg.m_physics = _ttoi(m_SList.GetItemText(a, 3));
	dlg.m_english = _ttoi(m_SList.GetItemText(a, 4));
	if (IDOK == dlg.DoModal()) {
		Dlgconfirm dlg1;
		if (IDOK == dlg1.DoModal()) {
			string id = CT2A(dlg.m_id);
			string name = CT2A(dlg.m_name);
			int n = m_students.size();
			int i;
			for (i = 0; i < n; i++) {
				if (m_students[i].getid() == str)
					break;
			}
			m_students[i].refine(id, name, dlg.m_math, dlg.m_physics, dlg.m_english);
			MessageBox(_T("修改成功!"));
			open();
		}
	}
}


void C学生成绩管理系统Dlg::OnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CDldadd dlg;
	if (IDOK == dlg.DoModal()) {
		Dlgconfirm dlg1;
		if (IDOK == dlg1.DoModal()) {
			string id = CT2A(dlg.m_id);
			string name = CT2A(dlg.m_name);
			Student stu(id, name, dlg.m_math, dlg.m_physics, dlg.m_english);
			m_students.push_back(stu);
			MessageBox(_T("添加成功!"));
			open();
		}
	}
}
