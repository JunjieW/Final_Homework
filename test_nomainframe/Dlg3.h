#pragma once


// CDlg3 �Ի���

class CDlg3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg3)

public:
	CDlg3();
	virtual ~CDlg3();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
