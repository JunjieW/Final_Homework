#pragma once


// CDlg1 对话框

class CDlg1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1();
	virtual ~CDlg1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

};
