#pragma once


// CUserLogin �Ի���

class CUserLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CUserLogin)

public:
	CUserLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLogin();
	CEdit m_Username;
	CEdit m_Password;

	afx_msg void OnBnClickedCancle();
};
