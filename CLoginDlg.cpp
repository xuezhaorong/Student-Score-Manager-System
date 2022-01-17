// CLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"
#include "CResiderDlg.h"
#include "InfoFile.h"
// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CResiderDlg dlg;
	dlg.DoModal();
}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE); //更新控件的数据到对应的变量

    CInfoFile file; //创建操作文件类对象，需要头文件#include "InfoFile.h" 

    //读取配置文件，获取用户名密码，参数为引用传递

    if (m_user.IsEmpty() || m_pwd.IsEmpty())
    {
        MessageBox(_T("输入信息不能为空"));
        m_user.Empty();
        m_pwd.Empty();
        UpdateData(FALSE);
    }
    else
    {
        if (file.ReadLogin(m_user, m_pwd))
        {
            MessageBox(_T("登录成功"));
            CDialogEx::OnOK();
        }
        else
        {
            MessageBox(_T("登录失败"));
            m_pwd.Empty();
            UpdateData(FALSE);
        }
    }
}
