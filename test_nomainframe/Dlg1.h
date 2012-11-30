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


	//CString m_bookname;
	CEdit m_bookname;
//	CEdit m_barcode;
	CEdit m_searchbarcode;
	CEdit m_barcodeinfo;
	CEdit m_searchbookname;
//	CListCtrl m_list_readerinfo;
	CListCtrl m_list_readerinfo;
	CListCtrl m_list_bookinfo;
//	CEdit m_ISBN;
//	CEdit m_bookname;
	CEdit m_isbn;
	CEdit m_publish;
	CEdit m_publishtime;
	CEdit m_writter;
	CEdit m_importtime;
	CEdit m_availiable;
	CEdit m_position;

	afx_msg void OnBnClickedButton7();
};
