// Dlg6.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg6.h"
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




// CDlg6 �Ի���

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


// CDlg6 ��Ϣ�������
