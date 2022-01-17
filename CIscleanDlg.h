#pragma once
#include "afxdialogex.h"


// CIscleanDlg 对话框

class CIscleanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIscleanDlg)

public:
	CIscleanDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CIscleanDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_ISCLEAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
