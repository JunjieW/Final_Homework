// UserLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "UserLogin.h"
#include "afxdialogex.h"

#include "AdoConnection.h"

////////�����Լ���ӵ�ȫ�ֱ���////////////////////
//�ⲿȫ�ֱ���:ADO�����û��������룬�Ҽ����Բ鿴��������
extern CAdoConnection adoConnect;
extern CAdoCommand adoCommand;
extern CAdoRecordSet adoRecSet;
extern CString username,password;//��¼��ǰ�û���������,��֪���ò��õ���
//////////////////////////////////////////////////


// CUserLogin �Ի���

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


// CUserLogin ��Ϣ�������


void CUserLogin::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CAdoConnection adosql;
	//adosql.OnInitADOConn();//��ȫ��ADO���󣬴�������
	
	adoConnect.ConnectSQLServer(_T("JJ_VAIO"),_T("LibraryDataBaseTest"),NULL,NULL);

	//�����ǳ����հ��һ�㣬Ҫ��һ��Ķ��������������ο�
	//m_Username.GetWindowText(c_user);
	//m_Password.GetWindowText(c_password);
	/*if (c_user.IsEmpty() || c_password.IsEmpty())
	{
		MessageBox(_T("�û����ƻ����벻��Ϊ��"),_T("�û���¼��Ϣ"));
		return;
	}
	*/
}



void CUserLogin::OnBnClickedCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxGetMainWnd()->PostMessage(SW_SHOW); // ����ڳ�ʼ����ʹ����AfxGetMainWnd()->PostMessage(WM_CLOSE,0,0);���޷�������ٴ���
	//Ctest_nomainframeDlg dlg;
	//dlg.DoModal();
	
	//theApp.InitInstance();
	//PostMessage(WM_CLOSE);
	//AfxGetParents
}
