#pragma once


// CDlg1 �Ի���

class CDlg1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1();
	virtual ~CDlg1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

};
