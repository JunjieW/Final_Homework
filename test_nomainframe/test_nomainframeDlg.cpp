
// test_nomainframeDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Ctest_nomainframeDlg �Ի���




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


// Ctest_nomainframeDlg ��Ϣ�������

BOOL Ctest_nomainframeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest_nomainframeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest_nomainframeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/////////////////////��������ӵ���Ϣ��Ӧ��������仰���Լ��ӵģ�


void Ctest_nomainframeDlg::OnBnClickedButton4()//�����ť�ǹ���Ա��½
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CPropertySheet m_sheet;
	//CDlg1 page1;
	//CDlg2 page2;
	//CDlg3 page3;
	//CDlg6 page6;
	//AfxGetMainWnd()->PostMessage(WM_CLOSE,0,0);//�ر�������
	//
	//m_sheet.AddPage(&page1);//��������ҳ
 //   m_sheet.AddPage(&page2);
	//m_sheet.AddPage(&page3);
	//m_sheet.AddPage(&page6);	

	//m_sheet.DoModal();
	EndDialog(1);
}


void Ctest_nomainframeDlg::OnBnClickedButton3()//�����ť���û���½
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*
	//The following line send a WM_CLOSE message 
	//   to the Application's main window. This will cause the
	//   Application to exit.  ���ǰ����ĵ���˵�ģ����ԣ�����в�ͨ�������򶼹ر���
	//AfxGetMainWnd()->PostMessage(WM_CLOSE,0,0);//����������
	//AfxGetMainWnd()->CloseWindow();//ֻ����С����
	
	//CUserLogin userLogin;
	//userLogin.DoModal();
	*/
	EndDialog(1);
}


void Ctest_nomainframeDlg::OnBnClickedButton2()//������˳�����İ�ť����Ϣ��Ӧ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(2);
}


void Ctest_nomainframeDlg::OnBnClickedButton5()//�����õ��԰�ť��Ϣ��Ӧ����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(3);
}
