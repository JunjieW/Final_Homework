// UserPage_3.cpp : 实现文件
//

#include "stdafx.h"
#include "test_nomainframe.h"
#include "UserPage_3.h"
#include "afxdialogex.h"


// CUserPage_3 对话框

IMPLEMENT_DYNAMIC(CUserPage_3, CDialogEx)

CUserPage_3::CUserPage_3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserPage_3::IDD, pParent)
{

}

CUserPage_3::~CUserPage_3()
{
}

void CUserPage_3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserPage_3, CDialogEx)
END_MESSAGE_MAP()


// CUserPage_3 消息处理程序
