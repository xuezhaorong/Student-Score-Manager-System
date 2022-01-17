// CImportDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CImportDlg.h"
#include "InfoFile.h"

// CImportDlg 对话框

IMPLEMENT_DYNAMIC(CImportDlg, CDialogEx)

CImportDlg::CImportDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_IMPORT, pParent)
{

}

CImportDlg::~CImportDlg()
{
}

void CImportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CImportDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CImportDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CImportDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CImportDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CImportDlg 消息处理程序


void CImportDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString path;
	CFileDialog file(TRUE);
	file.DoModal();
	path = file.GetPathName();
	CInfoFile fl;
	fl.ReadDocline();
	fl.Save_Import(path);
	fl.WirteDocline();
}


void CImportDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString path;
	CFileDialog file(TRUE);
	file.DoModal();
	path = file.GetPathName();
	CInfoFile fl;
	fl.New_Import(path);
	fl.WirteDocline();

}


void CImportDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
