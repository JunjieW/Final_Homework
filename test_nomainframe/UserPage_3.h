#pragma once


// CUserPage_3 对话框

class CUserPage_3 : public CDialogEx
{
	DECLARE_DYNAMIC(CUserPage_3)

public:
	CUserPage_3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserPage_3();

// 对话框数据
	enum { IDD = IDD_USERDLG_3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
