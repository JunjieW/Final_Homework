// Dlg3.cpp : ʵ���ļ��������������߹�������ҳ��
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg3.h"
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




// CDlg3 �Ի���

IMPLEMENT_DYNAMIC(CDlg3, CPropertyPage)

CDlg3::CDlg3()
	: CPropertyPage(CDlg3::IDD)
{

}

CDlg3::~CDlg3()
{
}

void CDlg3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg3, CPropertyPage)
END_MESSAGE_MAP()


// CDlg3 ��Ϣ�������
