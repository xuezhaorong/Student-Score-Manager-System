// CAddDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CAddDlg.h"
#include "InfoFile.h"

// CAddDlg 对话框

IMPLEMENT_DYNAMIC(CAddDlg, CDialogEx)

CAddDlg::CAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_ADD, pParent)
	, m_index(_T(""))
	, m_name(_T(""))
	, m_score1(0)
	, m_score2(0)
	, m_score3(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_index);
	DDX_Text(pDX, IDC_EDIT7, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_score1);
	DDX_Text(pDX, IDC_EDIT2, m_score2);
	DDX_Text(pDX, IDC_EDIT3, m_score3);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON5, &CAddDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CAddDlg 消息处理程序


void CAddDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE); //获取控件内容

    if (m_index.IsEmpty() || m_name.IsEmpty())
    {
        MessageBox(TEXT("输入信息不能为空"));
        return;
    }
    CString str;
    string sex;
    if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
    {
        sex = "男";
    }
    else
    {
        sex = "女";
    }
    bool flag = false;
    if ((m_score1 < 0) || (m_score1 > 150))
    {
        m_score1 = 0;
        UpdateData(FALSE);
        flag = true;
    }
    if ((m_score2 < 0) || (m_score2 > 150))
    {
        m_score2 = 0;
        UpdateData(FALSE);
        flag = true;
    }
    if ((m_score3 < 0) || (m_score3 > 150))
    {
        m_score3 = 0;
        UpdateData(FALSE);
        flag = true;
    }
    if (flag)
    {
        MessageBox(_T("输入成绩不符合条件,请重新输入"));
        return;
    }
    str = (CString)sex.c_str();
    CInfoFile file;
    file.ReadDocline(); //读取学生信息
    file.Addline(m_index, m_name, str, m_score1, m_score2, m_score3); //添加学生信息
    file.WirteDocline(); //写文件
    file.ls.clear(); //清空list的内容
    MessageBox(_T("添加成功"));
    m_index.Empty();
    m_name.Empty();
    ((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE); //选上
    ((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//不选上
    m_score1 = 0;
    m_score2 = 0;
    m_score3 = 0;
    UpdateData(FALSE);
}


BOOL CAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
    ((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE); //选上
    ((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//不选上
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CAddDlg::OnBnClickedButton5()
{
    // TODO: 在此添加控件通知处理程序代码
    m_index.Empty();
    m_name.Empty();
    ((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE); //选上
    ((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//不选上
    m_score1 = 0;
    m_score2 = 0;
    m_score3 = 0;
    UpdateData(FALSE);
}
