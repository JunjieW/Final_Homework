
// test_nomainframe.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "test_nomainframeDlg.h"

////�Լ��ӵ�
#include "AdoCommand.h"     ///*****
#include "AdoConnection.h"  ///�������е�ADO�࣬
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


// Ctest_nomainframeApp ����

Ctest_nomainframeApp::Ctest_nomainframeApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}




/////////////////////////////////////////////////////////
/////�Լ���ӵ��������ݿ��½��ȫ�ֱ���,���м�¼�û����������ȫ�ֱ����������ò��ϣ�
CAdoConnection adoConnect;
CAdoCommand adoCommand;
CAdoRecordSet adoRecSet;
CString username,password;//��¼��ǰ�û���������,��֪���ò��õ���

//CReport report;//��������ϵģ���֪��ʲô��˼��ע�͵�
/////////////////////////////////////////////////////////


// Ψһ��һ�� Ctest_nomainframeApp ����

Ctest_nomainframeApp theApp;


// Ctest_nomainframeApp ��ʼ��

BOOL Ctest_nomainframeApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	


	///���������COM����ĳ�ʼ����������Ӧ��û������ģ����Ǻ�����Ϊ
	///������_ConnectionPtr������ȫ�ֱ������ֺ�����Ϊm_pMainWndһֱû�б���ֵ��Ե��
	///��÷ǵ÷���CAdoConnection::CAdoConnection() �ĺ��������档
	///���Ͽ��˿�����Щ�˵�_ConnectionPtr�����Ǿֲ���������initialdialog�����������_ConnectionPtr.InitInstance������
	///CoInitialize(NULL)�Ϳ��Էŵ�App������ط�
	/////CoInitialize(NULL);

	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));


	Ctest_nomainframeDlg dlg;
	//m_pMainWnd = &dlg;	//�����ԭ���еģ���ע�͵���
	INT_PTR nResponse = dlg.DoModal();

	/*if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}*///���if elseif �����ڵ������Ǹ����Ҹĵ�

	if (nResponse == 1)//�����½���ڷ�֧
	{
	 /* CPropertySheet sheet;
		
		CDlg1 page1;
		CDlg2 page2;
		CDlg3 page3;
		CDlg6 page6;
		
		sheet.AddPage(&page1);//��������ҳ
		sheet.AddPage(&page2);
		sheet.AddPage(&page3);
		sheet.AddPage(&page6);	
		
		m_pMainWnd = &sheet;//���һ��Ҫ�����е�����ҳ������֮���д���������ڴ�����֮�󣬲���ȷ������̷߳�������ڴ�
		sheet.DoModal();	
	 */
		CUserLogin loginDlg;
		m_pMainWnd = &loginDlg;
		nResponse = loginDlg.DoModal();
	}
	else if (nResponse == 2)//�Ƴ������֧
	{
		//����2���ǵ���˳���ť��Ҳ�Ƿ���IDCANCLE����Ȼ���ǳ�����û�У�,����Ҳ�����Ͻ�X��ť�ķ���ֵ

	}
	else if(nResponse == 3)//�����ð�ť��֧
	{
		CPropertySheet sheet;
		
		CDlg1 page1;
		CDlg2 page2;
		CDlg3 page3;
		CDlg6 page6;
		
		sheet.AddPage(&page1);//��������ҳ
		sheet.AddPage(&page2);
		sheet.AddPage(&page3);
		sheet.AddPage(&page6);	

		m_pMainWnd = &sheet;//���һ��Ҫ�����е�����ҳ������֮���д���������ڴ�����֮�󣬲���ȷ������̷߳�������ڴ�
		sheet.DoModal();
	}

	

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	
	return FALSE;
}

