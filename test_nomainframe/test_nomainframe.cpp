
// test_nomainframe.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "test_nomainframeDlg.h"

////自己加的
#include "AdoCommand.h"     ///*****
#include "AdoConnection.h"  ///引用所有的ADO类，
#include "AdoRecordSet.h"   ///*****

#include "UserLogin.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"
#include "Dlg6.h"

///////////////////////


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest_nomainframeApp

BEGIN_MESSAGE_MAP(Ctest_nomainframeApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Ctest_nomainframeApp 构造

Ctest_nomainframeApp::Ctest_nomainframeApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}




/////////////////////////////////////////////////////////
/////自己添加的设置数据库登陆的全局变量,还有记录用户名和密码的全局变量（可能用不上）
CAdoConnection adoConnect;
CAdoCommand adoCommand;
CAdoRecordSet adoRecSet;
CString username,password;//记录当前用户名，密码,不知道用不用得上

//CReport report;//这个是书上的，不知道什么意思，注释掉
/////////////////////////////////////////////////////////


// 唯一的一个 Ctest_nomainframeApp 对象

Ctest_nomainframeApp theApp;


// Ctest_nomainframeApp 初始化

BOOL Ctest_nomainframeApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	


	///按道理，这个COM组件的初始化放在这里应该没有问题的，但是好像因为
	///声明的_ConnectionPtr对象是全局变量，又好像因为m_pMainWnd一直没有被赋值的缘故
	///搞得非得放在CAdoConnection::CAdoConnection() 的函数体里面。
	///网上看了看，有些人的_ConnectionPtr对象是局部变量（在initialdialog函数里面调用_ConnectionPtr.InitInstance（））
	///CoInitialize(NULL)就可以放到App的这个地方
	/////CoInitialize(NULL);

	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));


	Ctest_nomainframeDlg dlg;
	//m_pMainWnd = &dlg;	//这个是原来有的，我注释掉了
	INT_PTR nResponse = dlg.DoModal();

	/*if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}*///这个if elseif 是正宗的下面那个是我改的

	if (nResponse == 1)//进入登陆窗口分支
	{
	 /* CPropertySheet sheet;
		
		CDlg1 page1;
		CDlg2 page2;
		CDlg3 page3;
		CDlg6 page6;
		
		sheet.AddPage(&page1);//插入属性页
		sheet.AddPage(&page2);
		sheet.AddPage(&page3);
		sheet.AddPage(&page6);	
		
		m_pMainWnd = &sheet;//这句一定要在所有的属性页创建忘之后才写，估计是在创建完之后，才能确定这个线程分配多少内存
		sheet.DoModal();	
	 */
		CUserLogin loginDlg;
		m_pMainWnd = &loginDlg;
		nResponse = loginDlg.DoModal();
	}
	else if (nResponse == 2)//推出程序分支
	{
		//返回2，是点击退出按钮，也是返回IDCANCLE（当然我们程序里没有）,好像也是右上角X按钮的返回值

	}
	else if(nResponse == 3)//测试用按钮分支
	{
		CPropertySheet sheet;
		
		CDlg1 page1;
		CDlg2 page2;
		CDlg3 page3;
		CDlg6 page6;
		
		sheet.AddPage(&page1);//插入属性页
		sheet.AddPage(&page2);
		sheet.AddPage(&page3);
		sheet.AddPage(&page6);	

		m_pMainWnd = &sheet;//这句一定要在所有的属性页创建忘之后才写，估计是在创建完之后，才能确定这个线程分配多少内存
		sheet.DoModal();
	}

	

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	
	return FALSE;
}

