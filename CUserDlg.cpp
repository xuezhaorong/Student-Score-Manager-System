// CUserDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CUserDlg.h"
#include "InfoFile.h"

// CUserDlg 对话框

IMPLEMENT_DYNAMIC(CUserDlg, CDialogEx)

CUserDlg::CUserDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_USER, pParent)
	, m_id(_T(""))
	, m_user(_T(""))
    , m_newpwd(_T(""))
    , m_surepwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT3, m_id);
    DDX_Text(pDX, IDC_EDIT2, m_user);
    DDX_Text(pDX, IDC_EDIT5, m_newpwd);
    DDX_Text(pDX, IDC_EDIT6, m_surepwd);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CUserDlg 消息处理程序


BOOL CUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	 // TODO: 在此添加专用代码和/或调用基类
	CInfoFile file;    //需要头文件#include "InfoFile.h"
	m_id = (CString)file.ReadMessage().id.c_str();
	m_user = (CString)file.ReadMessage().m_user.c_str();
	UpdateData(FALSE); //把数据更新到控件上
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CUserDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);//更新控件内容到对应的变量中

    if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
    {
        MessageBox(TEXT("输入密码不能为空"));
        //输入框内容清空
        m_surepwd.Empty();
        m_newpwd.Empty();
        UpdateData(FALSE); //把数据更新到控件上
        return;
    }

    if (m_newpwd != m_surepwd)
    {
        MessageBox(TEXT("输入密码和确定密码不相等"));
        //输入框内容清空
        m_surepwd.Empty();
        m_newpwd.Empty();
        UpdateData(FALSE); //把数据更新到控件上
        return;
    }

    CInfoFile file;    //需要头文件#include "InfoFile.h"

    if (m_surepwd == (CString)file.ReadMessage().m_pwd.c_str())
    {
        MessageBox(TEXT("输入密码和旧密码相等"));
        //输入框内容清空
        m_surepwd.Empty();
        m_newpwd.Empty();
        UpdateData(FALSE); //把数据更新到控件上
        return;
    }
    string m_user = file.ReadMessage().id;
    string m_name = file.ReadMessage().m_user;
    std::string STDStr(CW2A(m_newpwd.GetString()));//CString 转 string
    string m_pwd = STDStr;
    file.WritePwd(m_user, m_name, m_pwd); //修改密码
    MessageBox(TEXT("密码修改成功"));
    //输入框内容清空
    m_surepwd.Empty();
    m_newpwd.Empty();
    UpdateData(FALSE); //把数据更新到控件上
}
