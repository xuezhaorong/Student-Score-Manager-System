// CModDlg.cpp: 实现文件
//

#include "pch.h"
#include "学生成绩管理系统.h"
#include "afxdialogex.h"
#include "CModDlg.h"
#include "InfoFile.h"

// CModDlg 对话框

IMPLEMENT_DYNAMIC(CModDlg, CDialogEx)

CModDlg::CModDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_MOD, pParent)
	, m_index(_T(""))
	, m_name(_T(""))
	, m_score1(0)
	, m_score2(0)
	, m_score3(0)
{

}

CModDlg::~CModDlg()
{
}

void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Text(pDX, IDC_EDIT1, m_index);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_score1);
	DDX_Text(pDX, IDC_EDIT6, m_score2);
	DDX_Text(pDX, IDC_EDIT8, m_score3);
}


BEGIN_MESSAGE_MAP(CModDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CModDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CModDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CModDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CModDlg 消息处理程序





BOOL CModDlg::OnInitDialog()
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


void CModDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString text;
	int temp = m_combox.GetCurSel();
	m_combox.GetLBText(temp, text);
	std::string STDStr(CW2A(text.GetString()));
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
		if (tmp.id == it->id && tmp.name == it->name && tmp.sex == it->sex && tmp.score1 == it->score1 && tmp.score2 == it->score2 && tmp.score3 == it->score3)
		{
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
			UpdateData(FALSE); //内容更新到对应的控件
			break;
		}
	}

}


void CModDlg::OnBnClickedButton1()//修改
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	int temp = m_combox.GetCurSel();
	m_combox.GetLBText(temp, text);
	std::string STDStr(CW2A(text.GetString()));
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
	CInfoFile file;
	file.ReadDocline(); //读取学生信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (tmp.id == it->id && tmp.name == it->name && tmp.sex == it->sex && tmp.score1 == it->score1 && tmp.score2 == it->score2 && tmp.score3 == it->score3 && tmp.score_sum == it->score_sum)
		{
			file.ls.erase(it);

			break;
		}
	}
	file.WirteDocline(); //更新文件内容
	UpdateData(TRUE);
	string str;
	CString sex;
	if (((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck())
	{
		str = "男";
	}
	else
	{
		str = "女";
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
	sex = (CString)str.c_str();
	file.Addline(m_index, m_name, sex, m_score1, m_score2, m_score3);
	file.WirteDocline();
	MessageBox(_T("修改成功"));
	file.ls.clear(); //清空list的内容
	UpdateData(FALSE);
	m_combox.ResetContent();
	OnInitDialog();
}


void CModDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_index.Empty();
	m_name.Empty();
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE); //选上
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);//不选上
	m_score1 = 0;
	m_score2 = 0;
	m_score3 = 0;
	UpdateData(FALSE);
}
