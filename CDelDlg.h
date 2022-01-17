#pragma once
#include "afxdialogex.h"


// CDelDlg 对话框

class CDelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDelDlg)

public:
	CDelDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDelDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_DEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combox;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
