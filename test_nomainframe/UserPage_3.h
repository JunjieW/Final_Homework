#pragma once


// CUserPage_3 �Ի���

class CUserPage_3 : public CDialogEx
{
	DECLARE_DYNAMIC(CUserPage_3)

public:
	CUserPage_3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserPage_3();

// �Ի�������
	enum { IDD = IDD_USERDLG_3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
