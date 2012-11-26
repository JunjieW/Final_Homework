// Dlg6.cpp : 实现文件
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg6.h"
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




// CDlg6 对话框

IMPLEMENT_DYNAMIC(CDlg6, CPropertyPage)

CDlg6::CDlg6()
	: CPropertyPage(CDlg6::IDD)
{

}

CDlg6::~CDlg6()
{
}

void CDlg6::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg6, CPropertyPage)
END_MESSAGE_MAP()


// CDlg6 消息处理程序
