#pragma once
#include "afxdialogex.h"


// CUserDlg 对话框

class CUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUserDlg)

public:
	CUserDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CUserDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_id;
	CString m_user;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
private:
	CString m_newpwd;
	CString m_surepwd;
};
