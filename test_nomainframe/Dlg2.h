#pragma once


// CDlg2 �Ի���

class CDlg2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CDlg2)

public:
	CDlg2();
	virtual ~CDlg2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	virtual BOOL OnInitDialog();
	afx_msg void OnMcnSelchangeMonthcalendar2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
};
