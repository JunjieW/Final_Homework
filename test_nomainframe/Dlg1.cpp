// Dlg1.cpp : ʵ���ļ� �����������軹��������ҳ��
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg1.h"
#include "afxdialogex.h"


////////include ADO���ӣ������¼����/////////////
#include "AdoCommand.h"     ///*****
#include "AdoConnection.h"  ///�������е�ADO�࣬
#include "AdoRecordSet.h"   ///*****
///////////////////////////////////////////////////

////////�����Լ���ӵ�ȫ�ֱ���////////////////////
//�ⲿȫ�ֱ���:ADO�����û��������룬�Ҽ����Բ鿴��������
extern CAdoConnection adoConnect;
extern CAdoCommand adoCommand;
extern CAdoRecordSet adoRecSet;
extern CString username,password;//��¼��ǰ�û���������,��֪���ò��õ���
//////////////////////////////////////////////////


// CDlg1 �Ի���

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


// CDlg1 ��Ϣ�������


BOOL CDlg1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	//˵��1.������һ������������propertypage�����ڵļ���button
	HWND hwnd,subhwnd;
    hwnd=::GetParent(m_hWnd); //��ͷ��������ð����������ȫ�ֱ��� 
	subhwnd=::GetDlgItem(hwnd,IDOK);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,IDCANCEL);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,ID_APPLY_NOW);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,IDHELP);
	::DestroyWindow(subhwnd);
	//˵��1.����


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


