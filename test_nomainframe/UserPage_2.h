#pragma once


// CUserPage_2 对话框

class CUserPage_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CUserPage_2)

public:
	CUserPage_2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserPage_2();

// 对话框数据
	enum { IDD = IDD_USERDLG_2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
