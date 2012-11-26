#pragma once


// CDlg6 对话框

class CDlg6 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg6)

public:
	CDlg6();
	virtual ~CDlg6();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
