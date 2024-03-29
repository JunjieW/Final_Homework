#include "stdafx.h"
#include "AdoConnection.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/*########################################################################
			  ------------------------------------------------
							    数值类型转换
			  ------------------------------------------------
  ########################################################################*/
COleDateTime ConvertHelp::ConvertToDate(const _variant_t& var)
{
	COleDateTime value;
	switch (var.vt) 
	{
	case VT_DATE:
		{
			value = var.date;
		}
		break;
	case VT_EMPTY:
	case VT_NULL:
		value.SetStatus(COleDateTime::null);
		break;
	default:
		value.SetStatus(COleDateTime::null);
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}
	return value;
}

COleCurrency ConvertHelp::ConvertToCurrency(const _variant_t& var)
{
	COleCurrency value;
	switch (var.vt) 
	{
	case VT_CY:
		value = (CURRENCY)var.cyVal;
		break;
	case VT_EMPTY:
	case VT_NULL:
		value.m_status = COleCurrency::null;
		break;
	default:
		value.m_status = COleCurrency::null;
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}
	return value;
}

bool ConvertHelp::ConvertToBool(const _variant_t& var)
{
	bool value = false;
	switch (var.vt)
	{
	case VT_BOOL:
		value = var.boolVal ? true : false;
	case VT_EMPTY:
	case VT_NULL:
		break;
	default:
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}
	return value;
}

BYTE ConvertHelp::ConvertToBYTE(const _variant_t& var)
{
	BYTE value = 0;
	switch (var.vt)
	{
	case VT_I1:
	case VT_UI1:
		value = var.bVal;
		break;
	case VT_NULL:
	case VT_EMPTY:
		value = 0;
		break;
	default:
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}	
	return value;
}

short ConvertHelp::ConvertToShort(const _variant_t& var)
{
	short value = 0;
	switch (var.vt)
	{
	case VT_BOOL:
		value = var.boolVal;
		break;
	case VT_UI1:
	case VT_I1:
		value = var.bVal;
		break;
	case VT_I2:
	case VT_UI2:
		value = var.iVal;
		break;
	case VT_NULL:
	case VT_EMPTY:
		value = 0;
		break;
	default:
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}	
	return value;
}

long ConvertHelp::ConvertToLong(const _variant_t& var)
{
	long value = 0;
	switch (var.vt)
	{
	case VT_BOOL:
		value = var.boolVal;
		break;
	case VT_UI1:
	case VT_I1:
		value = var.bVal;
		break;
	case VT_UI2:
	case VT_I2:
		value = var.iVal;
		break;
	case VT_I4:
	case VT_UI4:
		value = var.lVal;
		break;
	case VT_INT:
		value = var.intVal;
		break;
	case VT_R4:
		value = (long)(var.fltVal + 0.5);
		break;
	case VT_R8:
		value = (long)(var.dblVal + 0.5);
		break;
	case VT_DECIMAL:
		value = (long)var;
		break;
	case VT_CY:
		value = (long)var;
		break;
	case VT_BSTR://字符串
	case VT_LPSTR://字符串
	case VT_LPWSTR://字符串
		value = _tstol((LPCTSTR)(_bstr_t)var);
		break;
	case VT_NULL:
	case VT_EMPTY:
		value = 0;
		break;
	default:
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}
	return value;
}

double ConvertHelp::ConvertToFloat(const _variant_t& var)
{
	double value = 0;
	switch (var.vt)
	{
	case VT_R4:
		value = var.fltVal;
		break;
	case VT_R8:
		value = var.dblVal;
		break;
	case VT_DECIMAL:
		value = (double)var;
		break;
	case VT_CY:
		value = (double)var;
		break;
	case VT_BOOL:
		value = var.boolVal;
		break;
	case VT_UI1:
	case VT_I1:
		value = var.bVal;
		break;
	case VT_UI2:
	case VT_I2:
		value = var.iVal;
		break;
	case VT_UI4:
	case VT_I4:
		value = var.lVal;
		break;
	case VT_INT:
		value = var.intVal;
		break;
	case VT_BSTR://字符串
	case VT_LPSTR://字符串
	case VT_LPWSTR://字符串
		value = _tstof((LPCTSTR)(_bstr_t)var);
		break;
	case VT_NULL:
	case VT_EMPTY:
		value = 0;
		break;
	default:
		value = 0;
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}
	return value;
}

CString ConvertHelp::ConvertToCString(const _variant_t &var)
{
	CString strValue;
	
	switch (var.vt)
	{
	case VT_BSTR://字符串
	case VT_LPSTR://字符串
	case VT_LPWSTR://字符串
		strValue = (LPCTSTR)(_bstr_t)var;
		break;
	case VT_I1:
	case VT_UI1:
		strValue.Format(_T("%d"), var.bVal);
		break;
	case VT_I2://短整型
		strValue.Format(_T("%d"), var.iVal);
		break;
	case VT_UI2://无符号短整型
		strValue.Format(_T("%d"), var.uiVal);
		break;
	case VT_INT://整型
		strValue.Format(_T("%d"), var.intVal);
		break;
	case VT_I4: //整型
		strValue.Format(_T("%d"), var.lVal);
		break;
	case VT_I8: //长整型
		strValue.Format(_T("%d"), var.lVal);
		break;
	case VT_UINT://无符号整型
		strValue.Format(_T("%d"), var.uintVal);
		break;
	case VT_UI4: //无符号整型
		strValue.Format(_T("%d"), var.ulVal);
		break;
	case VT_UI8: //无符号长整型
		strValue.Format(_T("%d"), var.ulVal);
		break;
	case VT_VOID:
		strValue.Format(_T("%8x"), (long)(var.byref));
		break;
	case VT_R4://浮点型
		strValue.Format(_T("%.4f"), var.fltVal);
		break;
	case VT_R8://双精度型
		strValue.Format(_T("%.8f"), var.dblVal);
		break;
	case VT_DECIMAL: //小数
		strValue.Format(_T("%.8f"), (double)var);
		break;
	case VT_CY:
		{
			COleCurrency cy = var.cyVal;
			strValue = cy.Format();
		}
		break;
	case VT_BLOB:
	case VT_BLOB_OBJECT:
	case 0x2011:
		strValue = "[BLOB]";
		break;
	case VT_BOOL://布尔型

		strValue = var.boolVal ? "TRUE" : "FALSE";
		break;
	case VT_DATE: //日期型
		{
			DATE dt = var.date;
			COleDateTime da = COleDateTime(dt); 
			strValue = da.Format(_T("%Y-%m-%d %H:%M:%S"));
		}
		break;
	case VT_NULL://NULL值
		strValue = _T("");
		break;
	case VT_EMPTY://空
		strValue = _T("");
		break;
	case VT_UNKNOWN://未知类型
	default:
		strValue = _T("UN_KNOW");
		break;
	}
	return strValue;
}

/*########################################################################
			 ------------------------------------------------
					CAdoConnection class 构造/析构函数
			 ------------------------------------------------
  ########################################################################*/

CAdoConnection::CAdoConnection()
{
	//创建 Connection 对象---------------------------

	//2012-11-26注释by-JJ，注意，如果不是全局变量，请注释掉下面这句话，
	//并在在App::InitInstance()的开始调用此函数，开启COM组件
	CoInitialize(NULL);///////////这句下载下来的文件里面没有，会导致下面对_ConnectionPtr对象m_p_connection创建失败
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_p_connection.CreateInstance("ADODB.Connection");
	
	#ifdef _DEBUG
	if (m_p_connection == NULL)
	{
		AfxMessageBox(_T("Connection 对象创建失败! 请确认是否初始化了COM环境\r\n"));
		TRACE("Connection 对象创建失败! 请确认是否初始化了COM环境\r\n");
	}
	#endif
	ASSERT(m_p_connection != NULL);
}

CAdoConnection::~CAdoConnection()
{
	if (m_p_connection != NULL)
	{
		Release();
	}
	//2012-11-26注释by-JJ，注意，如果不是全局变量，请注释掉下面这句话，
	//并在在App::InitInstance()的最后调用此函数，释放COM组件
	::CoUninitialize();////放到这里居然不会出现内存访问冲突了！
					   ///网上有说，CoInitialize(NULL);和CoUninitialize();必须得在同一线程里
					   ///但我是在不知道，全局变量的链接指针，问什么在App::InitInstance()里
					   ///加这个就会出现内存访问冲突
}

/*========================================================================
	Name:		连接到数据源.
	-----------------------------------------------------
	Params:		[lpszConnect]: 连接字符串, 包含连接信息.
				[lOptions]:	可选. 决定该方法是以同步还是异步的方式连接数据
						源. 可以是如下某个常量:
		[常量]					[说明] 
		----------------------------------
		adConnectUnspecified	(默认)同步方式打开连接. 
		adAsyncConnect			异步方式打开连接. Ado用 ConnectComplete 事
						件来通知已经完成连接. 
==========================================================================*/
BOOL CAdoConnection::Open(LPCTSTR lpszConnect, long lOptions)
{
	ASSERT(m_p_connection != NULL);
	ASSERT(AfxIsValidString(lpszConnect));
	
	if (_tcscmp(lpszConnect, _T("")) != 0)
	{
		m_strConnect = lpszConnect;
	}

	if (m_strConnect.IsEmpty())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (IsOpen()) Close();

	try
	{
		// 连接数据库 ---------------------------------------------
		AfxMessageBox(_T("连接成功"));//自己添加的，一会要删除
		return (m_p_connection->Open(_bstr_t(/*LPCTSTR*/(m_strConnect)), (""), (""), lOptions) == S_OK);
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: 连接数据库发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		TRACE(_T("%s\r\n"), GetLastErrorText());
		return FALSE;
	} 
	catch (...)
	{
		TRACE(_T("Warning: 连接数据库时发生未知错误:"));
	}
	return FALSE;
}

/*========================================================================
	Name:	连接 SQL SERVER 数据库. 
	-----------------------------------------------------
	Params:		[dbsrc]:	SQL SERVER 服务器名.
				[dbname]:	默认的数据库名.
				[user]:		用户名.
				[pass]:		密码.
==========================================================================*/
BOOL CAdoConnection::ConnectSQLServer(CString dbsrc, CString dbname, CString user, CString pass, long lOptions)
{
	CString strConnect = _T("Provider=SQLOLEDB.1; Data Source=") + dbsrc + 
						 _T("; Initial Catalog=") + dbname  +
						 _T("; User ID=") + user + 
						 _T("; PWD=") + pass;
	return Open(LPCTSTR(strConnect), lOptions);
}

/*========================================================================
	Name:	连接 Access 数据库. 
	-----------------------------------------------------
	Params:		[dbpath]:
				
				[pass]:		访问密码.
===========================================================================*/
BOOL CAdoConnection::ConnectAccess(CString dbpath, CString pass, long lOptions)
{
	CString strConnect = _T("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=") + dbpath;
	if (pass != _T("")) 
	{
		strConnect += _T("Jet OLEDB:Database Password=") + pass + _T(";");
	}
	return Open(LPCTSTR(strConnect), lOptions);
}


/*========================================================================
	Name:	连接 Oracle 数据库. 
	-----------------------------------------------------
	Params:		[server]:	服务器名.
				[name]:		访问用户名.
				[password]:		访问密码.
===========================================================================*/
BOOL CAdoConnection::ConnectToOracle(CString server, CString name, CString password, long lOptions)
{
	//Oracle 的连接：
	//MSDAORA驱动方式连接不上，Oracle自带驱动则可以 /*OraOLEDB.Oracle.1*/
	CString strConnection = _T("Provider=OraOLEDB.Oracle.1;Data Source=") + server +
		_T(";User ID=") + name + _T("; Password=") + password;
	return Open((_bstr_t)strConnection,lOptions);
}

/*========================================================================
	Name:	连接远程Oracle 数据库. 
	-----------------------------------------------------
	Params:		[server]:	服务器名.
				[name]:		访问用户名.
				[password]:		访问密码.
				[ip]:		ip地址
				[port]:		端口
===========================================================================*/
BOOL CAdoConnection::ConnectToRemoteOracle(CString ip,CString port, CString service_name,
										   CString server, CString name, CString password, long lOptions)
{
	//Oracle 的连接：
	//MSDAORA驱动方式连接不上，Oracle自带驱动则可以 /*OraOLEDB.Oracle.1*/
	CString DataSource = _T("(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=")+ ip +_T(")") + 
		CString("(PORT=") + port + _T("))") + _T("(CONNECT_DATA=(SERVICE_NAME=") + service_name +_T(")))");
	CString strConnection = _T("Provider=OraOLEDB.Oracle.1;Data Source=") + DataSource +
		_T(";User ID=") + name + _T("; Password=") + password;
	return Open((_bstr_t)strConnection,lOptions);
}
/*========================================================================
	Name:	通过 udl 文件连接数据库. 
	-----------------------------------------------------
	Params:		[strFileName]:	UDL 数据库连接文件路径名.
==========================================================================*/
BOOL CAdoConnection::OpenUDLFile(LPCTSTR strFileName, long lOptions)
{
	CString strConnect = _T("File Name=");
	strConnect += strFileName;
	return Open(LPCTSTR(strConnect), lOptions);
}

/*========================================================================
	Name:	关闭与数据源的连接.
	-----------------------------------------------------
	Remarks: 使用 Close 方法可关闭 Connection 对象以便释放所有关联的系统资源. 
==========================================================================*/
void CAdoConnection::Close()
{
	try
	{
		if (m_p_connection != NULL && IsOpen()) 
		{
			m_p_connection->Close();
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: 关闭数据库发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	} 
}

/*========================================================================
	Name:	关闭连接并释放对象.
	-----------------------------------------------------
	Remarks: 关闭连接并释放connection对象.
==========================================================================*/
void CAdoConnection::Release()
{
	if (IsOpen()) Close();
	m_p_connection.Release();
}

/*========================================================================
	Name:		执行指定的查询、SQL 语句、存储过程等.
    ----------------------------------------------------------
	Remarks:	请参考 CAdoRecordSet 类的Open方法. 返回的 Recordset 对象始
			终为只读、仅向前的游标.
==========================================================================*/
_RecordsetPtr CAdoConnection::Execute(LPCTSTR lpszSQL, long lOptions)
{
	ASSERT(m_p_connection != NULL);
	ASSERT(AfxIsValidString(lpszSQL));

	try
	{
		return m_p_connection->Execute(_bstr_t(lpszSQL), NULL, lOptions);
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Execute 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*========================================================================
	Remarks:	请参考 CAdoRecordSet 类 Cancel 方法.
==========================================================================*/
BOOL CAdoConnection::Cancel()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return SUCCEEDED(m_p_connection->Cancel());
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: Cancel 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:	取得最后发生的错误信息.
==========================================================================*/
CString CAdoConnection::GetLastErrorText()
{
	ASSERT(m_p_connection != NULL);
	CString strErrors = _T("");
	try
	{
		if (m_p_connection != NULL)
		{
			ErrorsPtr pErrors = m_p_connection->Errors;
			CString strError;
			for (long n = 0; n < pErrors->Count; n++)
			{
				ErrorPtr pError = pErrors->GetItem(n);
				strError.Format(_T("Description: %s\r\nState: %s, Native: %d, Source: %s\r\n"),
								(LPCTSTR)pError->Description,
								(LPCTSTR)pError->SQLState,
										 pError->NativeError,
								(LPCTSTR)pError->Source);
				strErrors += strError;
			}
		}
		return strErrors;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetLastError 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return strErrors;
	} 
#ifdef _DEBUG
		return strErrors;
#else
		return "数据操作错误";
#endif

}

ErrorsPtr CAdoConnection::GetErrors()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		if (m_p_connection != NULL)
		{
			return m_p_connection->Errors;
		}
		return NULL;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetErrors 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

ErrorPtr CAdoConnection::GetError(long index)
{
	ASSERT(m_p_connection != NULL);
	try
	{
		if (m_p_connection != NULL)
		{
			ErrorsPtr pErrors =  m_p_connection->Errors;
			if (index >= 0 && index < pErrors->Count)
			{
				return pErrors->GetItem(_variant_t(index));
			}
		}
		return NULL;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetError 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*========================================================================
	Name:		取得连接时间.
==========================================================================*/
long CAdoConnection::GetConnectTimeOut()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return m_p_connection->GetConnectionTimeout();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetConnectTimeOut 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*========================================================================
	Name:		设置连接时间.
==========================================================================*/
BOOL CAdoConnection::SetConnectTimeOut(long lTime)
{
	ASSERT(m_p_connection != NULL);
	try
	{
		m_p_connection->PutConnectionTimeout(lTime);
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: SetConnectTimeOut 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
}

/*========================================================================
	Name:		取得默认数据库的名称.
==========================================================================*/
CString CAdoConnection::GetDefaultDatabase()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return CString(LPCTSTR(_bstr_t(m_p_connection->GetDefaultDatabase())));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetDefaultDatabase 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return CString(_T(""));
	} 
}

/*========================================================================
	Name:		取得 Connection 对象提供者的名称.
==========================================================================*/
CString CAdoConnection::GetProviderName()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return CString(LPCTSTR(_bstr_t(m_p_connection->GetProvider())));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetProviderName 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return CString(_T(""));
	} 
}

/*========================================================================
	Name:		取得 ADO 的版本号
==========================================================================*/
CString CAdoConnection::GetVersion()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return CString(LPCTSTR(_bstr_t(m_p_connection->GetVersion())));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetVersion 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return CString(_T(""));
	} 
}

/*========================================================================
	Name:		取得对象的状态(同 Recordset 对象的 GetState 方法).
	-----------------------------------------------------
	returns:	返回下列常量之一的长整型值.
		[常量]				[说明] 
		----------------------------------
		adStateClosed		指示对象是关闭的. 
		adStateOpen			指示对象是打开的. 
	-----------------------------------------------------
	Remarks:		可以随时使用 State 属性取得指定对象的当前状态.
==========================================================================*/
long CAdoConnection::GetState()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return m_p_connection->GetState();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetState 发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*========================================================================
	Name:	检测连接对象是否为打开状态.
==========================================================================*/
BOOL CAdoConnection::IsOpen()
{
	try
	{
		return (m_p_connection != NULL && (m_p_connection->State & adStateOpen));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: IsOpen 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:		取得在 Connection 对象中修改数据的可用权限.
    ----------------------------------------------------------
	returns:	返回以下某个 ConnectModeEnum 的值.
		[常量]				 [说明] 
		----------------------------------
		adModeUnknown		 默认值. 表明权限尚未设置或无法确定. 
		adModeRead			 表明权限为只读. 
		adModeWrite			 表明权限为只写. 
		adModeReadWrite		 表明权限为读/写. 
		adModeShareDenyRead  防止其他用户使用读权限打开连接. 
		adModeShareDenyWrite 防止其他用户使用写权限打开连接. 
		adModeShareExclusive 防止其他用户打开连接. 
		adModeShareDenyNone  防止其他用户使用任何权限打开连接.
    ----------------------------------------------------------
	Remarks: 使用 Mode 属性可设置或返回当前连接上提供者正在使用的访问权限.
==========================================================================*/
ConnectModeEnum CAdoConnection::GetMode()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return m_p_connection->GetMode();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: GetMode 发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adModeUnknown;
	} 
	return adModeUnknown;
}

/*========================================================================
	Name:		设置在 Connection 中修改数据的可用权限. 请参考 GetMode 方法.
    ----------------------------------------------------------
	Remarks:	只能在关闭 Connection 对象时方可设置 Mode 属性.
==========================================================================*/
BOOL CAdoConnection::SetMode(ConnectModeEnum mode)
{
	ASSERT(m_p_connection != NULL);
	ASSERT(!IsOpen());

	try
	{
		m_p_connection->PutMode(mode);
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: SetMode 发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return TRUE;
}

/*========================================================================
    Name:		从数据源获取数据库信息.
	-----------------------------------------------------
	Params:		QueryType  所要运行的模式查询类型,可以为下列任意常量.
	adSchemaAsserts				CONSTRAINT_CATALOG
								CONSTRAINT_SCHEMA
								CONSTRAINT_NAME 
	adSchemaCatalogs			CATALOG_NAME 
	adSchemaCharacterSets		CHARACTER_SET_CATALOG
								CHARACTER_SET_SCHEMA
								CHARACTER_SET_NAME 
	adSchemaCheckConstraints	CONSTRAINT_CATALOG
								CONSTRAINT_SCHEMA
								CONSTRAINT_NAME 
	adSchemaCollations			 COLLATION_CATALOG
								COLLATION_SCHEMA
								COLLATION_NAME 
	adSchemaColumnDomainUsage	DOMAIN_CATALOG
								DOMAIN_SCHEMA
								DOMAIN_NAME
								COLUMN_NAME 
	adSchemaColumnPrivileges	TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								COLUMN_NAME
								GRANTOR
								GRANTEE 
	adSchemaColumns				TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								COLUMN_NAME 
	adSchemaConstraintColumnUsage TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								COLUMN_NAME 
	adSchemaConstraintTableUsage TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME 
	adSchemaForeignKeys			PK_TABLE_CATALOG
								PK_TABLE_SCHEMA
								PK_TABLE_NAME
								FK_TABLE_CATALOG
								FK_TABLE_SCHEMA
								FK_TABLE_NAME 
	adSchemaIndexes				TABLE_CATALOG
								TABLE_SCHEMA
								INDEX_NAME
								TYPE
								TABLE_NAME 
	adSchemaKeyColumnUsage		CONSTRAINT_CATALOG
								CONSTRAINT_SCHEMA
								CONSTRAINT_NAME
								TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								COLUMN_NAME 
	adSchemaPrimaryKeys			PK_TABLE_CATALOG
								PK_TABLE_SCHEMA
								PK_TABLE_NAME 
	adSchemaProcedureColumns	PROCEDURE_CATALOG
								PROCEDURE_SCHEMA
								PROCEDURE_NAME
								COLUMN_NAME 
	adSchemaProcedureParameters PROCEDURE_CATALOG
								PROCEDURE_SCHEMA
								PROCEDURE_NAME
								PARAMTER_NAME 
	adSchemaProcedures			PROCEDURE_CATALOG
								PROCEDURE_SCHEMA
								PROCEDURE_NAME
								PROCEDURE_TYPE 
	adSchemaProviderSpecific	 参见说明 
	adSchemaProviderTypes		DATA_TYPE
								BEST_MATCH 
	adSchemaReferentialConstraints CONSTRAINT_CATALOG
								CONSTRAINT_SCHEMA
								CONSTRAINT_NAME 
	adSchemaSchemata			CATALOG_NAME
								SCHEMA_NAME
								SCHEMA_OWNER 
	adSchemaSQLLanguages		<无> 
	adSchemaStatistics			TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME 
	adSchemaTableConstraints	CONSTRAINT_CATALOG
								CONSTRAINT_SCHEMA
								CONSTRAINT_NAME
								TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								CONSTRAINT_TYPE 
	adSchemaTablePrivileges		TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								GRANTOR
								GRANTEE 
	adSchemaTables				TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME
								TABLE_TYPE 
	adSchemaTranslations		TRANSLATION_CATALOG
								TRANSLATION_SCHEMA
								TRANSLATION_NAME 
	adSchemaUsagePrivileges		OBJECT_CATALOG
								OBJECT_SCHEMA
								OBJECT_NAME
								OBJECT_TYPE
								GRANTOR
								GRANTEE 
	adSchemaViewColumnUsage		VIEW_CATALOG
								VIEW_SCHEMA
								VIEW_NAME 
	adSchemaViewTableUsage		VIEW_CATALOG
								VIEW_SCHEMA
								VIEW_NAME 
	adSchemaViews				TABLE_CATALOG
								TABLE_SCHEMA
								TABLE_NAME 
	-----------------------------------------------------
	returns:	返回包含数据库信息的 Recordset 对象. Recordset 将以只读、静态
			游标打开.
	-----------------------------------------------------
	Remarks:	OpenSchema方法返回与数据源有关的信息，例如关于服务器上的表
			以及表中的列等信息, 上述数据仅供参考, 视具体的数据源可能会有不同。
==========================================================================*/
_RecordsetPtr CAdoConnection::OpenSchema(SchemaEnum QueryType)
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return m_p_connection->OpenSchema(QueryType, vtMissing, vtMissing);
	}
	catch(_com_error e)
	{
		TRACE(_T("Warning: OpenSchema方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*########################################################################
			  ------------------------------------------------
									事务处理
			  ------------------------------------------------
  ########################################################################*/

/*========================================================================
    Name:		开始新事务.
	-----------------------------------------------------
	returns:	对于支持嵌套事务的数据库来说, 在已打开的事务中调用 BeginTrans 
	方法将开始新的嵌套事务. 返回值将指示嵌套层次: 返回值为 1 表示已打开顶层
	事务 (即事务不被另一个事务所嵌套), 返回值为 2 表示已打开第二层事务(嵌套
	在顶层事务中的事务), 依次类推.
	-----------------------------------------------------
	Remarks:	一旦调用了 BeginTrans 方法, 在调用 CommitTrans 或 RollbackTrans
	结束事务之前, 数据库将不再立即提交所作的任何更改.
		
==========================================================================*/
long CAdoConnection::BeginTrans()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return m_p_connection->BeginTrans();
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: BeginTrans 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*########################################################################
			  ------------------------------------------------
									事务处理
			  ------------------------------------------------
	BeginTrans		- 开始新事务。
	CommitTrans		- 保存任何更改并结束当前事务。它也可能启动新事务。
	RollbackTrans	- 取消当前事务中所作的任何更改并结束事务。它也可能启动
					新事务。

		一旦调用了 BeginTrans 方法，在调用 CommitTrans 或 RollbackTrans 结
	束事务之前，数据库将不再立即提交所作的任何更改。
		对于支持嵌套事务的数据库来说，在已打开的事务中调用 BeginTrans 方法
	将开始新的嵌套事务。返回值将指示嵌套层次：返回值为 1 表示已打开顶层事务
	(即事务不被另一个事务所嵌套)，返回值为 2 表示已打开第二层事务(嵌套
	在顶层事务中的事务)，依次类推。调用 CommitTrans 或 RollbackTrans 只影
	响最新打开的事务；在处理任何更高层事务之前必须关闭或回卷当前事务。
		调用 CommitTrans 方法将保存连接上打开的事务中所做的更改并结束事务。
	调用 RollbackTrans方法还原打开事务中所做的更改并结束事务。在未打开事务
	时调用其中任何一种方法都将引发错误。
		取决于 Connection 对象的 Attributes 属性，调用 CommitTrans 或 
	RollbackTrans 方法都可以自动启动新事务。如果 Attributes 属性设置为 
	adXactCommitRetaining，数据库在 CommitTrans 调用后会自动启动新事务。
	如果 Attributes 属性设置为 adXactAbortRetaining，数据库在调用 
	RollbackTrans 之后将自动启动新事务。
  ########################################################################*/
/*========================================================================
    Name:		保存任何更改并结束当前事务.
	-----------------------------------------------------
	Remarks:	调用 CommitTrans 或 RollbackTrans 只影响最新打开的事务; 在
	处理任何更高层事务之前必须关闭或回卷当前事务.
==========================================================================*/
BOOL CAdoConnection::CommitTrans()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return SUCCEEDED(m_p_connection->CommitTrans());
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: CommitTrans 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
    Name:		取消当前事务中所作的任何更改并结束事务.
==========================================================================*/
BOOL CAdoConnection::RollbackTrans()
{
	ASSERT(m_p_connection != NULL);
	try
	{
		return SUCCEEDED(m_p_connection->RollbackTrans());
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: RollbackTrans 方法发生异常. 错误信息: %s; 文件: %s; 行: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

