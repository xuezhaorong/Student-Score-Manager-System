
// 学生成绩管理系统Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "学生成绩管理系统.h"
#include "学生成绩管理系统Dlg.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"
#include "InfoFile.h"
#include "CUserDlg.h"
#include "CAddDlg.h"
#include "CIscleanDlg.h"
#include "CDelDlg.h"
#include "CModDlg.h"
#include "CFindDlg.h"
#include "CImportDlg.h"
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



C学生成绩管理系统Dlg::C学生成绩管理系统Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C学生成绩管理系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_BUTTON2, Add_Button);
	DDX_Control(pDX, IDC_BUTTON5, Import_Button);
	DDX_Control(pDX, IDC_BUTTON8, Mod_Button);
	DDX_Control(pDX, IDC_BUTTON10, Del_Button);
	DDX_Control(pDX, IDC_BUTTON11, Clean_Button);
}

BEGIN_MESSAGE_MAP(C学生成绩管理系统Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C学生成绩管理系统Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C学生成绩管理系统Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &C学生成绩管理系统Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C学生成绩管理系统Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON12, &C学生成绩管理系统Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &C学生成绩管理系统Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &C学生成绩管理系统Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON8, &C学生成绩管理系统Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &C学生成绩管理系统Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON5, &C学生成绩管理系统Dlg::OnBnClickedButton5)
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
	if (pSysMenu != nullptr)
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
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_WIN);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设置窗口的位置和大小：CWnd::MoveWindow
	//0, 0, 起点坐标x和y
	//800, 500, 窗口宽度和高度
	MoveWindow(0, 0, 840, 500);
	//将窗口移动到屏幕中央，CWnd::CenterWindow
	CenterWindow();
	m_list.ModifyStyle(0, LVS_REPORT);
	// 设置扩展风格
   //LVS_EX_FULLROWSELECT选中整行，LVS_EX_GRIDLINES网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//写入信息
	WriteMessage();
	ifstream ifs;
	ifs.open(_F_MESSA, ios::in);
	char buf[1024] = { 0 };
	char* ptr = NULL;
	ifs.getline(buf, sizeof(buf));
	char* sst = strtok_s(buf, " ", &ptr);
	message mes;
	mes.id = sst;//身份
	sst = strtok_s(NULL, " ", &ptr);
	mes.m_user = sst;
	sst = strtok_s(NULL, " ", &ptr);
	mes.m_pwd = sst;
	ifs.close();
	if(mes.id == "学生")
	{
		Add_Button.EnableWindow(0);
		Clean_Button.EnableWindow(0);
		Del_Button.EnableWindow(0);
		Import_Button.EnableWindow(0);
		Mod_Button.EnableWindow(0);
	}
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



void C学生成绩管理系统Dlg::OnBnClickedButton1()//个人信息
{
	// TODO: 在此添加控件通知处理程序代码
	CUserDlg dlg;
	dlg.DoModal();
}


void C学生成绩管理系统Dlg::OnBnClickedButton2()//添加学生信息
{
	// TODO: 在此添加控件通知处理程序代码
	CAddDlg dlg;
	dlg.DoModal();
	WriteMessage();
}




void C学生成绩管理系统Dlg::WriteMessage()
{
	// 初始化表头
	m_list.DeleteAllItems();
	CString field[] = { _T("学生学号"),_T("学生姓名"), _T("性别"), _T("第一门成绩"),_T("第二门成绩"), _T("第三门成绩"), _T("总分") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}
	// 需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取学生信息

	//添加数据
	int i = 0;
	CString str;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{

		m_list.InsertItem(i, (CString)it->id.c_str());
		int column = 1;
		m_list.SetItemText(i, column++, (CString)it->name.c_str());
		m_list.SetItemText(i, column++, (CString)it->sex.c_str());
		str.Format(_T("%d"), it->score1);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%d"), it->score2);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%d"), it->score3);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%d"), it->score_sum);
		m_list.SetItemText(i, column++, str);
		i++;
	}
}

//重载sort规则
bool Compare1(const msg& msg1, const msg& msg2)//学号
{
	return atoi(msg1.id.c_str()) < atoi(msg2.id.c_str());
}
bool Compare2(const msg& msg1, const msg& msg2)//成绩
{
	return msg1.score_sum < msg2.score_sum;
}

void C学生成绩管理系统Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CInfoFile file;
	file.ReadDocline();
	vector<msg> vc;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		vc.push_back(*it);
	}
	sort(vc.begin(), vc.end(), Compare2);
	file.ls.clear();
	for (vector<msg>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		file.ls.push_back(*it);
	}
	file.WirteDocline();
	WriteMessage();
	MessageBox(_T("排序成功"));
}



void C学生成绩管理系统Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CInfoFile file;
	file.ReadDocline();
	vector<msg> vc;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		vc.push_back(*it);
	}
	sort(vc.begin(), vc.end(), Compare1);
	file.ls.clear();
	for (vector<msg>::iterator it = vc.begin(); it != vc.end(); it++)
	{
		file.ls.push_back(*it);
	}
	file.WirteDocline();
	WriteMessage();
	MessageBox(_T("排序成功"));
}


void C学生成绩管理系统Dlg::OnBnClickedButton12()//退出程序
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("欢迎下次使用"));
	exit(0);
	OnOK();
}


void C学生成绩管理系统Dlg::OnBnClickedButton11()//清空学生信息
{
	// TODO: 在此添加控件通知处理程序代码
	CIscleanDlg dlg;
	dlg.DoModal(); //以模态方式运行
	WriteMessage();
}


void C学生成绩管理系统Dlg::OnBnClickedButton10()//删除学生信息
{
	// TODO: 在此添加控件通知处理程序代码
	CDelDlg dlg;
	dlg.DoModal();
	WriteMessage();
}


void C学生成绩管理系统Dlg::OnBnClickedButton8()//修改学生信息
{
	// TODO: 在此添加控件通知处理程序代码
	CModDlg dlg;
	dlg.DoModal();
	WriteMessage();
}


void C学生成绩管理系统Dlg::OnBnClickedButton9()//查询学生信息
{
	// TODO: 在此添加控件通知处理程序代码
	CFindDlg dlg;
	dlg.DoModal();
}


void C学生成绩管理系统Dlg::OnBnClickedButton5()//导入学生信息
{
	// TODO: 在此添加控件通知处理程序代码
	CImportDlg dlg;
	dlg.DoModal();
	WriteMessage();
}
