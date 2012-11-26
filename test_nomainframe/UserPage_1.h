#pragma once


// CUserPage_1 对话框

class CUserPage_1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CUserPage_1)

public:
	CUserPage_1();
	virtual ~CUserPage_1();

// 对话框数据
	enum { IDD = IDD_USERDLG_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
