// UserPage_1.cpp : 实现文件
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "UserPage_1.h"
#include "afxdialogex.h"


// CUserPage_1 对话框

IMPLEMENT_DYNAMIC(CUserPage_1, CPropertyPage)

CUserPage_1::CUserPage_1()
	: CPropertyPage(CUserPage_1::IDD)
{

}

CUserPage_1::~CUserPage_1()
{
}

void CUserPage_1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserPage_1, CPropertyPage)
END_MESSAGE_MAP()


// CUserPage_1 消息处理程序
