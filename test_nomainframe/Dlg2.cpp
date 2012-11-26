// Dlg2.cpp : 实现文件————【图书管理属性页】
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg2.h"
#include "afxdialogex.h"



////////include ADO连接，命令，记录集类/////////////
#include "AdoCommand.h"     ///*****
#include "AdoConnection.h"  ///引用所有的ADO类，
#include "AdoRecordSet.h"   ///*****
///////////////////////////////////////////////////

////////引用自己添加的全局变量////////////////////
//外部全局变量:ADO对象，用户名，密码，右键可以查看变量定义
extern CAdoConnection adoConnect;
extern CAdoCommand adoCommand;
extern CAdoRecordSet adoRecSet;
extern CString username,password;//记录当前用户名，密码,不知道用不用得上
//////////////////////////////////////////////////


// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CPropertyPage)

CDlg2::CDlg2()
	: CPropertyPage(CDlg2::IDD)
{

}

CDlg2::~CDlg2()
{
}

void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_List);

}


BEGIN_MESSAGE_MAP(CDlg2, CPropertyPage)
	////ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CDlg2::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// CDlg2 消息处理程序


BOOL CDlg2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_JUSTIFYCOLUMNS|LVS_EX_LABELTIP);

	m_List.InsertColumn(0,_T("书籍条码"),LVCFMT_LEFT,150);//添加表头,注意参数个数、顺序、意义
	m_List.InsertColumn(1,_T("书籍名称"),LVCFMT_LEFT,150);
	m_List.InsertColumn(2,_T("ISBN号"),LVCFMT_LEFT,150);
	m_List.InsertColumn(3,_T("副本数"),LVCFMT_LEFT,150);
	m_List.InsertColumn(4,_T("书籍位置"),LVCFMT_LEFT,150);

	m_List.InsertItem(0,_T(""));
	m_List.InsertItem(1,_T(""));
	m_List.InsertItem(2,_T(""));
	m_List.InsertItem(3,_T(""));

	m_List.SetItemText(0,0,_T("1"));
	m_List.SetItemText(0,1,_T("a"));
	m_List.SetItemText(0,2,_T("01"));
	m_List.SetItemText(0,3,_T("a1"));
	m_List.SetItemText(0,4,_T("aaa"));

	m_List.SetItemText(1,0,_T("2"));
	m_List.SetItemText(1,1,_T("b"));
	m_List.SetItemText(1,2,_T("02"));
	m_List.SetItemText(1,3,_T("b2"));
	m_List.SetItemText(1,4,_T("bbb"));

	m_List.SetItemText(2,0,_T("3"));
	m_List.SetItemText(2,1,_T("c"));
	m_List.SetItemText(2,2,_T("03"));
	m_List.SetItemText(2,3,_T("c3"));
	m_List.SetItemText(2,4,_T("ccc"));

	m_List.SetItemText(3,0,_T("4"));
	m_List.SetItemText(3,1,_T("d"));
	m_List.SetItemText(3,2,_T("04"));
	m_List.SetItemText(3,3,_T("d2"));
	m_List.SetItemText(3,4,_T("ddd"));

	/*m_List.SetColumnWidth(0,100);//设置每列初始宽度
	m_List.SetColumnWidth(1,100);
	m_List.SetColumnWidth(2,100);
	m_List.SetColumnWidth(3,100);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



