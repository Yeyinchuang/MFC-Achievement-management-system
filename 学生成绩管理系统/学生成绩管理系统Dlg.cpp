
// ѧ���ɼ�����ϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include<fstream>
#include "ѧ���ɼ�����ϵͳ.h"
#include "ѧ���ɼ�����ϵͳDlg.h"
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Cѧ���ɼ�����ϵͳDlg �Ի���



Cѧ���ɼ�����ϵͳDlg::Cѧ���ɼ�����ϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cѧ���ɼ�����ϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_SList);
}

BEGIN_MESSAGE_MAP(Cѧ���ɼ�����ϵͳDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &Cѧ���ɼ�����ϵͳDlg::OnClickedOpen)
	ON_BN_CLICKED(IDC_Write, &Cѧ���ɼ�����ϵͳDlg::OnClickedWrite)
	ON_BN_CLICKED(IDC_sort, &Cѧ���ɼ�����ϵͳDlg::OnClickedSort)
	ON_BN_CLICKED(IDC_delete, &Cѧ���ɼ�����ϵͳDlg::OnClickedDelete)
	ON_BN_CLICKED(IDC_clear, &Cѧ���ɼ�����ϵͳDlg::OnClickedClear)
	ON_BN_CLICKED(IDC_searchgrade, &Cѧ���ɼ�����ϵͳDlg::OnClickedSearchgrade)
	ON_BN_CLICKED(IDC_searchstudent, &Cѧ���ɼ�����ϵͳDlg::OnClickedSearchstudent)
	ON_BN_CLICKED(IDC_Statistic, &Cѧ���ɼ�����ϵͳDlg::OnClickedStatistic)
	ON_BN_CLICKED(IDC_Refine, &Cѧ���ɼ�����ϵͳDlg::OnClickedRefine)
	ON_BN_CLICKED(IDC_Add, &Cѧ���ɼ�����ϵͳDlg::OnClickedAdd)
END_MESSAGE_MAP()


// Cѧ���ɼ�����ϵͳDlg ��Ϣ�������

BOOL Cѧ���ɼ�����ϵͳDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	DWORD dwStyle = m_SList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	///////////
	m_SList.SetExtendedStyle(dwStyle);
	m_SList.InsertColumn(0, TEXT("ѧ��"), LVCFMT_LEFT, 100);              //����б��⣡������  �����80,40,90���������еĿ�ȡ�������LVCFMT_LEFT�������ö��뷽ʽ������
	m_SList.InsertColumn(1, TEXT("����"), LVCFMT_LEFT, 80);
	m_SList.InsertColumn(2, TEXT("��ѧ"), LVCFMT_LEFT, 70);
	m_SList.InsertColumn(3, TEXT("����"), LVCFMT_LEFT, 70);
	m_SList.InsertColumn(4, TEXT("Ӣ��"), LVCFMT_LEFT, 70);
	m_SList.InsertColumn(5, TEXT("�ܷ�"), LVCFMT_LEFT, 70);
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cѧ���ɼ�����ϵͳDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cѧ���ɼ�����ϵͳDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cѧ���ɼ�����ϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

float Cѧ���ɼ�����ϵͳDlg::getaveragegrade(string tag)
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

float Cѧ���ɼ�����ϵͳDlg::getaveragegrade()
{
	int n = m_students.size();
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += m_students[i].getnum();
	}
	return sum / n;
}

float Cѧ���ɼ�����ϵͳDlg::getstandarddeviation(string tag)
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

float Cѧ���ɼ�����ϵͳDlg::getacceptancerate(string tag)
{
	int n = m_students.size();
	int count = 0;//�����˺ϸ�
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



void Cѧ���ɼ�����ϵͳDlg::OnClickedOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CString str;
	m_students.clear();
	char a[500];
	string ID;
	string Name;
	int Math;
	int Physical;
	int English;
	ifstream input("�ɼ�ԭ����.txt");
	if (!input) {
		MessageBox(TEXT("���ļ�����"));
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




void Cѧ���ɼ�����ϵͳDlg::open()
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


void Cѧ���ɼ�����ϵͳDlg::OnClickedWrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ofstream output("�ɼ�ԭ����.txt");
	if (!output) {
		MessageBox(_T("δ�ɹ�д��")); return ;
	}
	output << "ѧ��" << '\t' << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "����" << '\t' << "Ӣ��" << endl;
	vector<Student>::iterator pos;
	pos = m_students.begin();
	while (pos != m_students.end()) {
		output << pos->getid() << '\t' << pos->getname() << '\t' << pos->getmath() << '\t' << pos->getphysics() << '\t' << pos->getenglish() << endl;
		pos++;
	}
	MessageBox(_T("д���ļ��ɹ�"));
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedSort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sort(m_students.begin(), m_students.end(), greater);
	open();
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int a = m_SList.GetSelectionMark();
	if (a == -1)
	{
		MessageBox(_T("��ѡ��һ����Ϣ!"), _T("ɾ����Ϣ"));
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
				MessageBox(_T("ɾ���ɹ�!"));
				break;
			}
			pos++;
		}
	}
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_SList.DeleteAllItems();
	m_students.clear();
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedSearchgrade()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			MessageBox(_T("��ѯ����"));
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
			MessageBox(_T("��ѯ����"));
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
	else { MessageBox(_T("��ѯȡ��"));}
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedSearchstudent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDlgsearchstudent dlg;
	if (IDOK == dlg.DoModal()) {
		int n = m_SList.GetItemCount();
		for (int i = 0; i < n; i++) {
			int grade= _ttoi(m_SList.GetItemText(i, 5));//CStringתint
			if(grade<dlg.m_low||grade>dlg.m_high)//������ȥ��
				m_SList.DeleteItem(i);
		}
	}
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedStatistic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void Cѧ���ɼ�����ϵͳDlg::OnClickedRefine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int a = m_SList.GetSelectionMark();
	if (a == -1)
	{
		MessageBox(_T("��ѡ��һ����Ϣ!"), _T("�޸���Ϣ"));
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
			MessageBox(_T("�޸ĳɹ�!"));
			open();
		}
	}
}


void Cѧ���ɼ�����ϵͳDlg::OnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDldadd dlg;
	if (IDOK == dlg.DoModal()) {
		Dlgconfirm dlg1;
		if (IDOK == dlg1.DoModal()) {
			string id = CT2A(dlg.m_id);
			string name = CT2A(dlg.m_name);
			Student stu(id, name, dlg.m_math, dlg.m_physics, dlg.m_english);
			m_students.push_back(stu);
			MessageBox(_T("��ӳɹ�!"));
			open();
		}
	}
}
