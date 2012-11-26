// Dlg1.cpp : 实现文件 ————【借还管理属性页】
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg1.h"
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


// CDlg1 对话框

IMPLEMENT_DYNAMIC(CDlg1, CPropertyPage)

CDlg1::CDlg1()
	: CPropertyPage(CDlg1::IDD)
{

}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg1, CPropertyPage)
	
END_MESSAGE_MAP()


// CDlg1 消息处理程序


BOOL CDlg1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//说明1.下面这一串，用来消掉propertypage父窗口的几个button
	HWND hwnd,subhwnd;
    hwnd=::GetParent(m_hWnd); //开头就是两个冒号用于引用全局变量 
	subhwnd=::GetDlgItem(hwnd,IDOK);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,IDCANCEL);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,ID_APPLY_NOW);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,IDHELP);
	::DestroyWindow(subhwnd);
	//说明1.结束


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


