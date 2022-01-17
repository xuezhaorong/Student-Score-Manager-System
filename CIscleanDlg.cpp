// CIscleanDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CIscleanDlg.h"
#include "InfoFile.h"

// CIscleanDlg 对话框

IMPLEMENT_DYNAMIC(CIscleanDlg, CDialogEx)

CIscleanDlg::CIscleanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_ISCLEAN, pParent)
{

}

CIscleanDlg::~CIscleanDlg()
{
}

void CIscleanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CIscleanDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CIscleanDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CIscleanDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CIscleanDlg 消息处理程序


void CIscleanDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CInfoFile file;
	file.Clear_file();
	MessageBox(_T("清库成功！！！"));
	OnOK();
}


void CIscleanDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
