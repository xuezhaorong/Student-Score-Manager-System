#pragma once
#include "afxdialogex.h"


// CFindDlg 对话框

class CFindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFindDlg)

public:
	CFindDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFindDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_FIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_index;
	CString m_name;
	int m_score1;
	int m_score2;
	int m_score3;
public:
	afx_msg void OnBnClickedButton1();
private:
	int m_scoresum;
};
