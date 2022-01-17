
// 学生成绩管理系统Dlg.h: 头文件
//

#pragma once
#include<vector>
#include<algorithm>
#include<list>
#include<fstream>
// C学生成绩管理系统Dlg 对话框
class C学生成绩管理系统Dlg : public CDialogEx
{
// 构造
public:
	C学生成绩管理系统Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void WriteMessage();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton5();
	CButton Add_Button;
	CButton Import_Button;
	CButton Mod_Button;
	CButton Del_Button;
	CButton Clean_Button;
};
