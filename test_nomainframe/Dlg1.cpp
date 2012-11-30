// Dlg1.cpp : 实现文件 ————【借还管理属性页】
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "Dlg1.h"
#include "afxdialogex.h"


////////include ADO连接，命令，记录集类/////////////
#include "AdoCommand.h"     ///*****
#include "AdoConnection.h"  ///引用所有的ADO类，
#include "AdoRecordSet.h"   ///*****
///////////////////////////////////////////////////

////////引用自己添加的全局变量////////////////////
//外部全局变量:ADO对象，用户名，密码，右键可以查看变量定义
extern CAdoConnection adoConnect;
extern CAdoCommand adoCommand;
extern CAdoRecordSet adoRecSet;
extern CString username,password;//记录当前用户名，密码,不知道用不用得上
//////////////////////////////////////////////////


// CDlg1 对话框

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


// CDlg1 消息处理程序


BOOL CDlg1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();


	// TODO:  在此添加额外的初始化
	
	//说明1.下面这一串，用来消掉propertypage父窗口的几个button
	HWND hwnd,subhwnd;
    hwnd=::GetParent(m_hWnd); //开头就是两个冒号用于引用全局变量 
	subhwnd=::GetDlgItem(hwnd,IDOK);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,IDCANCEL);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,ID_APPLY_NOW);
	::DestroyWindow(subhwnd);
	subhwnd=::GetDlgItem(hwnd,IDHELP);
	::DestroyWindow(subhwnd);
	//说明1.结束

	//测试时使用，在初始化时登陆数据库
	//adoConnect.ConnectSQLServer(_T("JJ_VAIO"),_T("LibraryDataBaseTest"), _T("databasetest"),_T("123"));
	
	//设置表格格式，可以选中整行
	m_list_readerinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT);//|LVS_EX_GRIDLINES|LVS_EX_JUSTIFYCOLUMNS|LVS_EX_LABELTIP);
	m_list_bookinfo.SetExtendedStyle(LVS_EX_FULLROWSELECT);//LVS_EX_GRIDLINES|LVS_EX_JUSTIFYCOLUMNS|LVS_EX_LABELTIP);

	m_list_readerinfo.InsertColumn(0,_T("读者编号"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(1,_T("读者姓名"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(2,_T("读者学号"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(3,_T("性别"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(4,_T("系别"), LVCFMT_LEFT,100,-1);
	m_list_readerinfo.InsertColumn(5,_T("可借阅数"), LVCFMT_LEFT,100,-1);


	m_list_bookinfo.InsertColumn(0,_T("图书条码"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(1,_T("图书ISBN"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(2,_T("图书名称"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(3,_T("出版社"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(4,_T("出版时间"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(5,_T("作者"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(6,_T("入馆时间"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(7,_T("可借状态"), LVCFMT_LEFT,100,-1);
	m_list_bookinfo.InsertColumn(8,_T("书架位置"), LVCFMT_LEFT,100,-1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlg1::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
		CString sql = NULL;//SQL语句
	CString bookID = NULL,readerID = NULL;
	CStringArray col;
	
	//得到输入的信息
	GetDlgItem(IDC_EDIT1)->GetWindowText(readerID);
	GetDlgItem(IDC_EDIT3)->GetWindowText(bookID);

	//bookID.Format(_T("您输入的条码为：%s"),bookID);//不能自己调用自己又添加自己

	//连接，登陆数据库的操作
	adoConnect.ConnectSQLServer(_T("JJ_VAIO"),_T("LibraryDataBaseTest"),_T("testdatabase"),_T("123"));
	CAdoConnection *p = &adoConnect;
	adoRecSet.SetAdoConnection(p);	

	adoCommand.SetCommandText(_T("insert into Users valuse('a','a','a','a','a',5)"));
	adoCommand.Execute();
	//END 连接登陆数据库
		
	//下面这一段没什么用
	/*//下面试试给所有行的首列列添加数据——成功
	for (int insertrow = 0;insertrow <4;insertrow++)
	{
		m_list_bookinfo.InsertItem(insertrow,_T(""));//插入一行
		m_list_bookinfo.SetItemText(insertrow,0,col[insertrow]);//加入一行
	};
	//下面这些是成功的录入的，但是太麻烦了
	for(int i = 0;i <4;i++)	m_list_bookinfo.InsertItem(i,_T(""));//插入一行

	//下面尝试用双循环给所有行所有列录入信息，外循决定列，内循环决定行
	for(int insertcol = 0;insertcol <8;insertcol++)//外循环控制列输出
	{
		//下面这个函数，游标恢复TOP位置的语句被注释掉了，我把它释放了，具体位置看书签
		adoRecSet.GetFieldValues(&col,insertcol,FALSE,4);//从数据库取出第insertcol列
		
		for (int insertrow = 0;insertrow <4;insertrow++)//内循环控制行输出
		{
			m_list_bookinfo.SetItemText(insertrow,insertcol,col[insertrow]);//
		}
	}
	*/
	//下面这一段，实现了查询的功能
	if( bookID.IsEmpty() || readerID.IsEmpty()) 
	{
		MessageBox(_T("请输入读者ID和图书ID"),_T("提示"));
	}
	else 
	{
		MessageBox(_T("输入的读者编号为：")+readerID+_T("\n输入的图书条码为：")+bookID);
	//第一步，查询图书ID，这里是有效代码（或许可以写成一个函数，和下边的合并，不过一次性写对的成功率不大，调试会浪费大部分时间）
		//曾经考虑过溢出问题，但是好像，一般数据规模还不会溢出，只是程序的资源占用很大
		//下面对控件，记录集做初始化
		m_list_bookinfo.DeleteAllItems();//清空ListCtrl里的内容
		adoRecSet.Close();//关闭已经打开的记录集
		//sql.Format(_T("select * from Books where BookID = '%s'"),bookID);
		sql.Format(_T("select * from Books where BookID > 0"));//本句测试当全部输出数据时内存会不会溢出
		adoRecSet.Open(sql,adCmdText);//打开新的记录集
		//下面这个以后可能还要优化，GetFieldValues()第一个参数不同可以针对不同的类型值取value
		for(int insertrow = 0;!adoRecSet.IsEOF();insertrow++)
		{
			m_list_bookinfo.InsertItem(insertrow,_T(""));//控件中插入行

			//这里应该不需要把详细信息都输出，因为还有个书籍详细信息栏。
			for(int insertcol = 0;insertcol < 9;insertcol++)//内循环控制列
			{
				adoRecSet.GetFieldValues(&col,insertcol,FALSE,1);//数据库取出数据
				m_list_bookinfo.SetItemText(insertrow,insertcol,col[0]);
			}
			adoRecSet.MoveNext();
		}
	//END 查询图书ID



	//第二步，查询读者ID，这里是有效代码，或许可以写成一个函数
		//清空ListCtrl里的内容；关闭已经打开的记录集,设置查询语句，再重新打开记录集
		m_list_readerinfo.DeleteAllItems();
		adoRecSet.Close();
		//sql.Format(_T("select * from Users where UserID = '%s'"),readerID);
		sql.Format(_T("select * from Users"));//本句测试当全部输出数据时内存会不会溢出
		adoRecSet.Open(sql,adCmdText);
	
		//下面这个以后可能还要优化，GetFieldValues()第一个参数不同可以针对不同的类型值取value
		for(int insertrow = 0;!adoRecSet.IsEOF();insertrow++)
		{	
			//控件中插入行
			m_list_readerinfo.InsertItem(insertrow,_T(""));
			//内循环控制列
			for(int insertcol = 0;insertcol < 6;insertcol++)
			{
				//数据库取出数据
				adoRecSet.GetFieldValues(&col,insertcol,FALSE,1);
				m_list_readerinfo.SetItemText(insertrow,insertcol,col[0]);
			}
			adoRecSet.MoveNext();
		}
	//END 查询读者ID


	//第三步，填充图书基本信息栏——————
		adoRecSet.Close();//关闭已经打开的记录集
		sql.Format(_T("select * from Books where BookID = '%s'"),bookID);
		adoRecSet.Open(sql,adCmdText);
		for(int insertrow = 0;!adoRecSet.IsEOF();insertrow++)
		{
			for(int insertcol = 0;insertcol < 9;insertcol++)//内循环控制列
			{
				adoRecSet.GetFieldValues(&col,insertcol,FALSE,1);
				switch(insertcol)
				{   //m_barcodeinfo.SetWindowText(_T("小蝌蚪找妈妈"));//用这个语句给图书基本信息组里的框框赋值
					case 0:m_barcodeinfo.SetWindowText(col[0]);break;//用这个语句给图书基本信息组里的框框赋值;
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
//END 填充图书基本信息栏



}
