#pragma once


// CDlg3 对话框

class CDlg3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg3)

public:
	CDlg3();
	virtual ~CDlg3();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
