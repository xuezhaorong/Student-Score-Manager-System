// CResiderDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CResiderDlg.h"
#include "InfoFile.h"

// CResiderDlg 对话框

IMPLEMENT_DYNAMIC(CResiderDlg, CDialogEx)

CResiderDlg::CResiderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_RESIDER, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CResiderDlg::~CResiderDlg()
{
}

void CResiderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CResiderDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CResiderDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CResiderDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CResiderDlg 消息处理程序


BOOL CResiderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE); //选上
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//不选上
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CResiderDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    if (m_user.IsEmpty() || m_pwd.IsEmpty())
    {
        MessageBox(_T("信息不能为空"));
        return;
    }
    CString str;
    string id;
    if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
    {
        id = "学生";
    }
    else
    {
        id = "老师";
    }
    str = (CString)id.c_str();
    CInfoFile file;
    if (file.Resider(str, m_user, m_pwd))
    {
        MessageBox(_T("注册成功"));
        OnOK();
    }
    else
    {
        MessageBox(_T("注册失败,用户名重复"));
        m_user.Empty();
        m_pwd.Empty();
        UpdateData(FALSE);
        return;
    }
}


void CResiderDlg::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    m_user.Empty();
    m_pwd.Empty();
    ((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE); //选上
    ((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//不选上
    UpdateData(FALSE);
    OnOK();
}
