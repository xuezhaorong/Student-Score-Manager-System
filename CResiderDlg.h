#pragma once
#include "afxdialogex.h"


// CResiderDlg 对话框

class CResiderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResiderDlg)

public:
	CResiderDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CResiderDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_RESIDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_user;
	CString m_pwd;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
