#pragma once


// CUserPage_2 �Ի���

class CUserPage_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CUserPage_2)

public:
	CUserPage_2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserPage_2();

// �Ի�������
	enum { IDD = IDD_USERDLG_2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
