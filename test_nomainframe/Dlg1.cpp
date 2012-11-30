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
	//  DDX_Text(pDX, IDC_EDIT_BOOKINFO4, m_bookname);
	//  DDX_Control(pDX, IDC_EDIT_BOOKINFO4, m_bookname);
	//  DDX_Control(pDX, IDC_EDIT1, m_barcode);
	DDX_Control(pDX, IDC_EDIT1, m_searchbarcode);
	DDX_Control(pDX, IDC_EDIT3, m_searchbookname);
	//  DDX_Control(pDX, IDC_LIST4, m_list_readerinfo);
	  DDX_Control(pDX, IDC_LIST5, m_list_bookinfo);
	//  DDX_Control(pDX, IDC_EDIT_BOOKINFO5, m_ISBN);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO4, m_barcodeinfo);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO6, m_bookname);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO5, m_isbn);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO7, m_publish);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO8, m_publishtime);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO9, m_writter);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO10, m_importtime);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO11, m_availiable);
	  DDX_Control(pDX, IDC_EDIT_BOOKINFO12, m_position);
	  DDX_Control(pDX, IDC_LIST1, m_list_readerinfo);
}


BEGIN_MESSAGE_MAP(CDlg1, CPropertyPage)
	
	ON_BN_CLICKED(IDC_BUTTON7, &CDlg1::OnBnClickedButton7)
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

	//����ʱʹ�ã��ڳ�ʼ��ʱ��½���ݿ�
	//adoConnect.ConnectSQLServer(_T("JJ_VAIO"),_T("LibraryDataBaseTest"), _T("databasetest"),_T("123"));
	
	//���ñ���ʽ������ѡ������
	m_list_readerinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT);//|LVS_EX_GRIDLINES|LVS_EX_JUSTIFYCOLUMNS|LVS_EX_LABELTIP);
	m_list_bookinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT);//LVS_EX_GRIDLINES|LVS_EX_JUSTIFYCOLUMNS|LVS_EX_LABELTIP);

	m_list_readerinfo.InsertColumn(0,_T("���߱��"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(1,_T("��������"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(2,_T("����ѧ��"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(3,_T("�Ա�"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(4,_T("ϵ��"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(5,_T("�ɽ�����"), LVCFMT_LEFT,100,-1);


	m_list_bookinfo.InsertColumn(0,_T("ͼ������"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(1,_T("ͼ��ISBN"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(2,_T("ͼ������"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(3,_T("������"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(4,_T("����ʱ��"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(5,_T("����"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(6,_T("���ʱ��"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(7,_T("�ɽ�״̬"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(8,_T("���λ��"), LVCFMT_LEFT,100,-1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDlg1::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString sql = NULL;//SQL���
	CString bookID = NULL,readerID = NULL;
	CStringArray col;
	
	//�õ��������Ϣ
	GetDlgItem(IDC_EDIT1)->GetWindowText(readerID);
	GetDlgItem(IDC_EDIT3)->GetWindowText(bookID);

	//bookID.Format(_T("�����������Ϊ��%s"),bookID);//�����Լ������Լ�������Լ�

	//���ӣ���½���ݿ�Ĳ���
	adoConnect.ConnectSQLServer(_T("JJ_VAIO"),_T("LibraryDataBaseTest"),_T("testdatabase"),_T("123"));
	CAdoConnection *p = &adoConnect;
	adoRecSet.SetAdoConnection(p);	

	adoCommand.SetCommandText(_T("insert into Users valuse('a','a','a','a','a',5)"));
	adoCommand.Execute();
	//END ���ӵ�½���ݿ�
		
	//������һ��ûʲô��
	/*//�������Ը������е�������������ݡ����ɹ�
	for (int insertrow = 0;insertrow <4;insertrow++)
	{
		m_list_bookinfo.InsertItem(insertrow,_T(""));//����һ��
		m_list_bookinfo.SetItemText(insertrow,0,col[insertrow]);//����һ��
	};
	//������Щ�ǳɹ���¼��ģ�����̫�鷳��
	for(int i = 0;i <4;i++)	m_list_bookinfo.InsertItem(i,_T(""));//����һ��

	//���波����˫ѭ����������������¼����Ϣ����ѭ�����У���ѭ��������
	for(int insertcol = 0;insertcol <8;insertcol++)//��ѭ�����������
	{
		//��������������α�ָ�TOPλ�õ���䱻ע�͵��ˣ��Ұ����ͷ��ˣ�����λ�ÿ���ǩ
		adoRecSet.GetFieldValues(&col,insertcol,FALSE,4);//�����ݿ�ȡ����insertcol��
		
		for (int insertrow = 0;insertrow <4;insertrow++)//��ѭ�����������
		{
			m_list_bookinfo.SetItemText(insertrow,insertcol,col[insertrow]);//
		}
	}
	*/
	//������һ�Σ�ʵ���˲�ѯ�Ĺ���
	if( bookID.IsEmpty() || readerID.IsEmpty()) 
	{
		MessageBox(_T("���������ID��ͼ��ID"),_T("��ʾ"));
	}
	else 
	{
		MessageBox(_T("����Ķ��߱��Ϊ��")+readerID+_T("\n�����ͼ������Ϊ��")+bookID);
	//��һ������ѯͼ��ID����������Ч���루�������д��һ�����������±ߵĺϲ�������һ����д�Եĳɹ��ʲ��󣬵��Ի��˷Ѵ󲿷�ʱ�䣩
		//�������ǹ�������⣬���Ǻ���һ�����ݹ�ģ�����������ֻ�ǳ������Դռ�úܴ�
		//����Կؼ�����¼������ʼ��
		m_list_bookinfo.DeleteAllItems();//���ListCtrl�������
		adoRecSet.Close();//�ر��Ѿ��򿪵ļ�¼��
		//sql.Format(_T("select * from Books where BookID = '%s'"),bookID);
		sql.Format(_T("select * from Books where BookID > 0"));//������Ե�ȫ���������ʱ�ڴ�᲻�����
		adoRecSet.Open(sql,adCmdText);//���µļ�¼��
		//��������Ժ���ܻ�Ҫ�Ż���GetFieldValues()��һ��������ͬ������Բ�ͬ������ֵȡvalue
		for(int insertrow = 0;!adoRecSet.IsEOF();insertrow++)
		{
			m_list_bookinfo.InsertItem(insertrow,_T(""));//�ؼ��в�����

			//����Ӧ�ò���Ҫ����ϸ��Ϣ���������Ϊ���и��鼮��ϸ��Ϣ����
			for(int insertcol = 0;insertcol < 9;insertcol++)//��ѭ��������
			{
				adoRecSet.GetFieldValues(&col,insertcol,FALSE,1);//���ݿ�ȡ������
				m_list_bookinfo.SetItemText(insertrow,insertcol,col[0]);
			}
			adoRecSet.MoveNext();
		}
	//END ��ѯͼ��ID



	//�ڶ�������ѯ����ID����������Ч���룬�������д��һ������
		//���ListCtrl������ݣ��ر��Ѿ��򿪵ļ�¼��,���ò�ѯ��䣬�����´򿪼�¼��
		m_list_readerinfo.DeleteAllItems();
		adoRecSet.Close();
		//sql.Format(_T("select * from Users where UserID = '%s'"),readerID);
		sql.Format(_T("select * from Users"));//������Ե�ȫ���������ʱ�ڴ�᲻�����
		adoRecSet.Open(sql,adCmdText);
	
		//��������Ժ���ܻ�Ҫ�Ż���GetFieldValues()��һ��������ͬ������Բ�ͬ������ֵȡvalue
		for(int insertrow = 0;!adoRecSet.IsEOF();insertrow++)
		{	
			//�ؼ��в�����
			m_list_readerinfo.InsertItem(insertrow,_T(""));
			//��ѭ��������
			for(int insertcol = 0;insertcol < 6;insertcol++)
			{
				//���ݿ�ȡ������
				adoRecSet.GetFieldValues(&col,insertcol,FALSE,1);
				m_list_readerinfo.SetItemText(insertrow,insertcol,col[0]);
			}
			adoRecSet.MoveNext();
		}
	//END ��ѯ����ID


	//�����������ͼ�������Ϣ��������������
		adoRecSet.Close();//�ر��Ѿ��򿪵ļ�¼��
		sql.Format(_T("select * from Books where BookID = '%s'"),bookID);
		adoRecSet.Open(sql,adCmdText);
		for(int insertrow = 0;!adoRecSet.IsEOF();insertrow++)
		{
			for(int insertcol = 0;insertcol < 9;insertcol++)//��ѭ��������
			{
				adoRecSet.GetFieldValues(&col,insertcol,FALSE,1);
				switch(insertcol)
				{   //m_barcodeinfo.SetWindowText(_T("С���������"));//���������ͼ�������Ϣ����Ŀ��ֵ
					case 0:m_barcodeinfo.SetWindowText(col[0]);break;//���������ͼ�������Ϣ����Ŀ��ֵ;
					case 1:m_isbn.SetWindowText(col[0]);break;
					case 2:m_bookname.SetWindowText(col[0]);break;
					case 3:m_publish.SetWindowText(col[0]);break;
					case 4:m_publishtime.SetWindowText(col[0]);break;
					case 5:m_writter.SetWindowText(col[0]);break;
					case 6:m_importtime.SetWindowText(col[0]);break;
					case 7:m_availiable.SetWindowText(col[0]);break;
					case 8:m_position.SetWindowText(col[0]);break;
					default:break;
				}
			}
			adoRecSet.MoveNext();
		}		
	}	
//END ���ͼ�������Ϣ��



}
