// CDelDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CDelDlg.h"
#include "InfoFile.h"

// CDelDlg 对话框

IMPLEMENT_DYNAMIC(CDelDlg, CDialogEx)

CDelDlg::CDelDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_DEL, pParent)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
}


BEGIN_MESSAGE_MAP(CDelDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDelDlg 消息处理程序


BOOL CDelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//读取文件，获取学生信息，给组合框添加字符串
	//需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取学生信息
	string str;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		str = it->id;
		str += " ";
		str += it->name;
		str += " ";
		str += it->sex;
		str += " ";
		str += to_string(it->score1);
		str += " ";
		str += to_string(it->score2);
		str += " ";
		str += to_string(it->score3);
		str += " ";
		str += to_string(it->score_sum);
		str += " ";
		m_combox.AddString((CString)str.c_str());
	}
	//将第一个学生信息设为默认选中项
	m_combox.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDelDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);


	CString type;
	//获取当前选中项
	int index = m_combox.GetCurSel();
	//获取组合框当前内容
	m_combox.GetLBText(index, type);
	std::string STDStr(CW2A(type.GetString()));
	char buf[1024] = { 0 };
	for (int i = 0; i < STDStr.size(); i++)
	{
		buf[i] = STDStr[i];
	}
	msg tmp;
	char* ptr = NULL;
	char* sst = strtok_s(buf, " ", &ptr); //以“ ”切割
	tmp.id = sst; //学生学号

	sst = strtok_s(NULL, " ", &ptr);
	tmp.name = sst;	//学生姓名

	sst = strtok_s(NULL, " ", &ptr);
	tmp.sex = sst;	//学生性别

	sst = strtok_s(NULL, " ", &ptr);
	tmp.score1 = atoi(sst);	//学生三门成绩
	sst = strtok_s(NULL, " ", &ptr);
	tmp.score2 = atoi(sst);	//学生三门成绩
	sst = strtok_s(NULL, " ", &ptr);
	tmp.score3 = atoi(sst);	//学生三门成绩
	sst = strtok_s(NULL, " ", &ptr);
	tmp.score_sum = atoi(sst);	//学生三门成绩总分
	//需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取学生信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (tmp.id == it->id && tmp.name == it->name && tmp.sex == it->sex && tmp.score1 == it->score1 && tmp.score2 == it->score2 && tmp.score3 == it->score3 && tmp.score_sum == it->score_sum)
		{
			file.ls.erase(it);
			MessageBox(_T("删除成功"));
			break;
		}
	}
	file.WirteDocline(); //更新文件内容
	UpdateData(FALSE); //更新到对应的控件
	m_combox.ResetContent();
	OnInitDialog();
}


void CDelDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_combox.SetCurSel(0); //选择第0项目
}
