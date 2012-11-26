#pragma once


// CUserLogin 对话框

class CUserLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CUserLogin)

public:
	CUserLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLogin();
	CEdit m_Username;
	CEdit m_Password;

	afx_msg void OnBnClickedCancle();
};
