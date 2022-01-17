// CFindDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CFindDlg.h"
#include "InfoFile.h"

// CFindDlg 对话框

IMPLEMENT_DYNAMIC(CFindDlg, CDialogEx)

CFindDlg::CFindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_FIND, pParent)
	, m_index(_T(""))
	, m_name(_T(""))
	, m_score1(0)
	, m_score2(0)
	, m_score3(0)
	, m_scoresum(0)
{

}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_index);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_score1);
	DDX_Text(pDX, IDC_EDIT6, m_score2);
	DDX_Text(pDX, IDC_EDIT8, m_score3);
	DDX_Text(pDX, IDC_EDIT9, m_scoresum);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CFindDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFindDlg 消息处理程序


void CFindDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (m_index == (CString)it->id.c_str() || m_name == (CString)it->name.c_str())
		{
			CString str;
			m_index = (CString)it->id.c_str();
			m_name = (CString)it->name.c_str();
			if (it->sex == "男")
			{
				((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE); //选上
				((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);//不选上
			}
			else
			{
				((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE); //不选上
				((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);//选上
			}
			m_score1 = it->score1;
			m_score2 = it->score2;
			m_score3 = it->score3;
			m_scoresum = it->score_sum;
			UpdateData(FALSE);
			MessageBox(_T("查询成功"));
			return;
		}
	}
	MessageBox(_T("查无此人"));
}
