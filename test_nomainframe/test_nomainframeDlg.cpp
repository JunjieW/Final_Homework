
// test_nomainframeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "test_nomainframeDlg.h"
#include "afxdialogex.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"
#include "Dlg6.h"
#include "UserLogin.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest_nomainframeDlg 对话框




Ctest_nomainframeDlg::Ctest_nomainframeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest_nomainframeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest_nomainframeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest_nomainframeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &Ctest_nomainframeDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest_nomainframeDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest_nomainframeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &Ctest_nomainframeDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Ctest_nomainframeDlg 消息处理程序

BOOL Ctest_nomainframeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest_nomainframeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest_nomainframeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest_nomainframeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/////////////////////下面是添加的消息响应函数（这句话是自己加的）


void Ctest_nomainframeDlg::OnBnClickedButton4()//这个按钮是管理员登陆
{
	// TODO: 在此添加控件通知处理程序代码
	//CPropertySheet m_sheet;
	//CDlg1 page1;
	//CDlg2 page2;
	//CDlg3 page3;
	//CDlg6 page6;
	//AfxGetMainWnd()->PostMessage(WM_CLOSE,0,0);//关闭主窗口
	//
	//m_sheet.AddPage(&page1);//插入属性页
 //   m_sheet.AddPage(&page2);
	//m_sheet.AddPage(&page3);
	//m_sheet.AddPage(&page6);	

	//m_sheet.DoModal();
	EndDialog(1);
}


void Ctest_nomainframeDlg::OnBnClickedButton3()//这个按钮是用户登陆
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	//The following line send a WM_CLOSE message 
	//   to the Application's main window. This will cause the
	//   Application to exit.  这是帮助文档里说的，所以，这个行不通，主程序都关闭了
	//AfxGetMainWnd()->PostMessage(WM_CLOSE,0,0);//隐藏主窗口
	//AfxGetMainWnd()->CloseWindow();//只是最小化了
	
	//CUserLogin userLogin;
	//userLogin.DoModal();
	*/
	EndDialog(1);
}


void Ctest_nomainframeDlg::OnBnClickedButton2()//这个是退出程序的按钮的消息响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(2);
}


void Ctest_nomainframeDlg::OnBnClickedButton5()//测试用调试按钮消息响应函数
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(3);
}
