#pragma once


// CDlg6 �Ի���

class CDlg6 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg6)

public:
	CDlg6();
	virtual ~CDlg6();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
