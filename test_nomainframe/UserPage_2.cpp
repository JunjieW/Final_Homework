// UserPage_2.cpp : 实现文件
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "UserPage_2.h"
#include "afxdialogex.h"


// CUserPage_2 对话框

IMPLEMENT_DYNAMIC(CUserPage_2, CDialogEx)

CUserPage_2::CUserPage_2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserPage_2::IDD, pParent)
{

}

CUserPage_2::~CUserPage_2()
{
}

void CUserPage_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserPage_2, CDialogEx)
END_MESSAGE_MAP()


// CUserPage_2 消息处理程序
