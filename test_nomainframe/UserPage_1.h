#pragma once


// CUserPage_1 �Ի���

class CUserPage_1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CUserPage_1)

public:
	CUserPage_1();
	virtual ~CUserPage_1();

// �Ի�������
	enum { IDD = IDD_USERDLG_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
