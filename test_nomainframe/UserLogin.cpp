// UserLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "UserLogin.h"
#include "afxdialogex.h"

#include "AdoConnection.h"

////////引用自己添加的全局变量////////////////////
//外部全局变量:ADO对象，用户名，密码，右键可以查看变量定义
extern CAdoConnection adoConnect;
extern CAdoCommand adoCommand;
extern CAdoRecordSet adoRecSet;
extern CString username,password;//记录当前用户名，密码,不知道用不用得上
//////////////////////////////////////////////////


// CUserLogin 对话框

IMPLEMENT_DYNAMIC(CUserLogin, CDialogEx)

CUserLogin::CUserLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserLogin::IDD, pParent)
{

}

CUserLogin::~CUserLogin()
{
	
}

void CUserLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Username);
	DDX_Control(pDX, IDC_EDIT2, m_Password);
}


BEGIN_MESSAGE_MAP(CUserLogin, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &CUserLogin::OnBnClickedLogin)

	ON_BN_CLICKED(IDC_CANCLE, &CUserLogin::OnBnClickedCancle)
END_MESSAGE_MAP()


// CUserLogin 消息处理程序


void CUserLogin::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	//CAdoConnection adosql;
	//adosql.OnInitADOConn();//用全局ADO对象，创建链接
	
	adoConnect.ConnectSQLServer(_T("JJ_VAIO"),_T("LibraryDataBaseTest"),NULL,NULL);

	//下面是抄书照搬的一点，要做一点改动，留在这里做参考
	//m_Username.GetWindowText(c_user);
	//m_Password.GetWindowText(c_password);
	/*if (c_user.IsEmpty() || c_password.IsEmpty())
	{
		MessageBox(_T("用户名称或密码不能为空"),_T("用户登录信息"));
		return;
	}
	*/
}



void CUserLogin::OnBnClickedCancle()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxGetMainWnd()->PostMessage(SW_SHOW); // 如果在初始窗口使用了AfxGetMainWnd()->PostMessage(WM_CLOSE,0,0);就无法用这个再打开了
	//Ctest_nomainframeDlg dlg;
	//dlg.DoModal();
	
	//theApp.InitInstance();
	//PostMessage(WM_CLOSE);
	//AfxGetParents
}
