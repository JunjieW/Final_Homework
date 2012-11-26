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
							    ��ֵ����ת��
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
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
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
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
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
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
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
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
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
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
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
	case VT_BSTR://�ַ���
	case VT_LPSTR://�ַ���
	case VT_LPWSTR://�ַ���
		value = _tstol((LPCTSTR)(_bstr_t)var);
		break;
	case VT_NULL:
	case VT_EMPTY:
		value = 0;
		break;
	default:
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
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
	case VT_BSTR://�ַ���
	case VT_LPSTR://�ַ���
	case VT_LPWSTR://�ַ���
		value = _tstof((LPCTSTR)(_bstr_t)var);
		break;
	case VT_NULL:
	case VT_EMPTY:
		value = 0;
		break;
	default:
		value = 0;
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	}
	return value;
}

CString ConvertHelp::ConvertToCString(const _variant_t &var)
{
	CString strValue;
	
	switch (var.vt)
	{
	case VT_BSTR://�ַ���
	case VT_LPSTR://�ַ���
	case VT_LPWSTR://�ַ���
		strValue = (LPCTSTR)(_bstr_t)var;
		break;
	case VT_I1:
	case VT_UI1:
		strValue.Format(_T("%d"), var.bVal);
		break;
	case VT_I2://������
		strValue.Format(_T("%d"), var.iVal);
		break;
	case VT_UI2://�޷��Ŷ�����
		strValue.Format(_T("%d"), var.uiVal);
		break;
	case VT_INT://����
		strValue.Format(_T("%d"), var.intVal);
		break;
	case VT_I4: //����
		strValue.Format(_T("%d"), var.lVal);
		break;
	case VT_I8: //������
		strValue.Format(_T("%d"), var.lVal);
		break;
	case VT_UINT://�޷�������
		strValue.Format(_T("%d"), var.uintVal);
		break;
	case VT_UI4: //�޷�������
		strValue.Format(_T("%d"), var.ulVal);
		break;
	case VT_UI8: //�޷��ų�����
		strValue.Format(_T("%d"), var.ulVal);
		break;
	case VT_VOID:
		strValue.Format(_T("%8x"), (long)(var.byref));
		break;
	case VT_R4://������
		strValue.Format(_T("%.4f"), var.fltVal);
		break;
	case VT_R8://˫������
		strValue.Format(_T("%.8f"), var.dblVal);
		break;
	case VT_DECIMAL: //С��
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
	case VT_BOOL://������

		strValue = var.boolVal ? "TRUE" : "FALSE";
		break;
	case VT_DATE: //������
		{
			DATE dt = var.date;
			COleDateTime da = COleDateTime(dt); 
			strValue = da.Format(_T("%Y-%m-%d %H:%M:%S"));
		}
		break;
	case VT_NULL://NULLֵ
		strValue = _T("");
		break;
	case VT_EMPTY://��
		strValue = _T("");
		break;
	case VT_UNKNOWN://δ֪����
	default:
		strValue = _T("UN_KNOW");
		break;
	}
	return strValue;
}

/*########################################################################
			 ------------------------------------------------
					CAdoConnection class ����/��������
			 ------------------------------------------------
  ########################################################################*/

CAdoConnection::CAdoConnection()
{
	//���� Connection ����---------------------------

	//2012-11-26ע��by-JJ��ע�⣬�������ȫ�ֱ�������ע�͵�������仰��
	//������App::InitInstance()�Ŀ�ʼ���ô˺���������COM���
	CoInitialize(NULL);///////////��������������ļ�����û�У��ᵼ�������_ConnectionPtr����m_p_connection����ʧ��
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_p_connection.CreateInstance("ADODB.Connection");
	
	#ifdef _DEBUG
	if (m_p_connection == NULL)
	{
		AfxMessageBox(_T("Connection ���󴴽�ʧ��! ��ȷ���Ƿ��ʼ����COM����\r\n"));
		TRACE("Connection ���󴴽�ʧ��! ��ȷ���Ƿ��ʼ����COM����\r\n");
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
	//2012-11-26ע��by-JJ��ע�⣬�������ȫ�ֱ�������ע�͵�������仰��
	//������App::InitInstance()�������ô˺������ͷ�COM���
	::CoUninitialize();////�ŵ������Ȼ��������ڴ���ʳ�ͻ�ˣ�
					   ///������˵��CoInitialize(NULL);��CoUninitialize();�������ͬһ�߳���
					   ///�������ڲ�֪����ȫ�ֱ���������ָ�룬��ʲô��App::InitInstance()��
					   ///������ͻ�����ڴ���ʳ�ͻ
}

/*========================================================================
	Name:		���ӵ�����Դ.
	-----------------------------------------------------
	Params:		[lpszConnect]: �����ַ���, ����������Ϣ.
				[lOptions]:	��ѡ. �����÷�������ͬ�������첽�ķ�ʽ��������
						Դ. ����������ĳ������:
		[����]					[˵��] 
		----------------------------------
		adConnectUnspecified	(Ĭ��)ͬ����ʽ������. 
		adAsyncConnect			�첽��ʽ������. Ado�� ConnectComplete ��
						����֪ͨ�Ѿ��������. 
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
		// �������ݿ� ---------------------------------------------
		AfxMessageBox(_T("���ӳɹ�"));//�Լ���ӵģ�һ��Ҫɾ��
		return (m_p_connection->Open(_bstr_t(/*LPCTSTR*/(m_strConnect)), (""), (""), lOptions) == S_OK);
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: �������ݿⷢ���쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		TRACE(_T("%s\r\n"), GetLastErrorText());
		return FALSE;
	} 
	catch (...)
	{
		TRACE(_T("Warning: �������ݿ�ʱ����δ֪����:"));
	}
	return FALSE;
}

/*========================================================================
	Name:	���� SQL SERVER ���ݿ�. 
	-----------------------------------------------------
	Params:		[dbsrc]:	SQL SERVER ��������.
				[dbname]:	Ĭ�ϵ����ݿ���.
				[user]:		�û���.
				[pass]:		����.
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
	Name:	���� Access ���ݿ�. 
	-----------------------------------------------------
	Params:		[dbpath]:
				
				[pass]:		��������.
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
	Name:	���� Oracle ���ݿ�. 
	-----------------------------------------------------
	Params:		[server]:	��������.
				[name]:		�����û���.
				[password]:		��������.
===========================================================================*/
BOOL CAdoConnection::ConnectToOracle(CString server, CString name, CString password, long lOptions)
{
	//Oracle �����ӣ�
	//MSDAORA������ʽ���Ӳ��ϣ�Oracle�Դ���������� /*OraOLEDB.Oracle.1*/
	CString strConnection = _T("Provider=OraOLEDB.Oracle.1;Data Source=") + server +
		_T(";User ID=") + name + _T("; Password=") + password;
	return Open((_bstr_t)strConnection,lOptions);
}

/*========================================================================
	Name:	����Զ��Oracle ���ݿ�. 
	-----------------------------------------------------
	Params:		[server]:	��������.
				[name]:		�����û���.
				[password]:		��������.
				[ip]:		ip��ַ
				[port]:		�˿�
===========================================================================*/
BOOL CAdoConnection::ConnectToRemoteOracle(CString ip,CString port, CString service_name,
										   CString server, CString name, CString password, long lOptions)
{
	//Oracle �����ӣ�
	//MSDAORA������ʽ���Ӳ��ϣ�Oracle�Դ���������� /*OraOLEDB.Oracle.1*/
	CString DataSource = _T("(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=")+ ip +_T(")") + 
		CString("(PORT=") + port + _T("))") + _T("(CONNECT_DATA=(SERVICE_NAME=") + service_name +_T(")))");
	CString strConnection = _T("Provider=OraOLEDB.Oracle.1;Data Source=") + DataSource +
		_T(";User ID=") + name + _T("; Password=") + password;
	return Open((_bstr_t)strConnection,lOptions);
}
/*========================================================================
	Name:	ͨ�� udl �ļ��������ݿ�. 
	-----------------------------------------------------
	Params:		[strFileName]:	UDL ���ݿ������ļ�·����.
==========================================================================*/
BOOL CAdoConnection::OpenUDLFile(LPCTSTR strFileName, long lOptions)
{
	CString strConnect = _T("File Name=");
	strConnect += strFileName;
	return Open(LPCTSTR(strConnect), lOptions);
}

/*========================================================================
	Name:	�ر�������Դ������.
	-----------------------------------------------------
	Remarks: ʹ�� Close �����ɹر� Connection �����Ա��ͷ����й�����ϵͳ��Դ. 
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
		TRACE(_T("Warning: �ر����ݿⷢ���쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
	} 
}

/*========================================================================
	Name:	�ر����Ӳ��ͷŶ���.
	-----------------------------------------------------
	Remarks: �ر����Ӳ��ͷ�connection����.
==========================================================================*/
void CAdoConnection::Release()
{
	if (IsOpen()) Close();
	m_p_connection.Release();
}

/*========================================================================
	Name:		ִ��ָ���Ĳ�ѯ��SQL ��䡢�洢���̵�.
    ----------------------------------------------------------
	Remarks:	��ο� CAdoRecordSet ���Open����. ���ص� Recordset ����ʼ
			��Ϊֻ��������ǰ���α�.
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
		TRACE(_T("Warning: Execute ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*========================================================================
	Remarks:	��ο� CAdoRecordSet �� Cancel ����.
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
		TRACE(_T("Warning: Cancel ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:	ȡ��������Ĵ�����Ϣ.
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
		TRACE(_T("Warning: GetLastError ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return strErrors;
	} 
#ifdef _DEBUG
		return strErrors;
#else
		return "���ݲ�������";
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
		TRACE(_T("Warning: GetErrors ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
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
		TRACE(_T("Warning: GetError ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*========================================================================
	Name:		ȡ������ʱ��.
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
		TRACE(_T("Warning: GetConnectTimeOut ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*========================================================================
	Name:		��������ʱ��.
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
		TRACE(_T("Warning: SetConnectTimeOut ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
}

/*========================================================================
	Name:		ȡ��Ĭ�����ݿ������.
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
		TRACE(_T("Warning: GetDefaultDatabase ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return CString(_T(""));
	} 
}

/*========================================================================
	Name:		ȡ�� Connection �����ṩ�ߵ�����.
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
		TRACE(_T("Warning: GetProviderName ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return CString(_T(""));
	} 
}

/*========================================================================
	Name:		ȡ�� ADO �İ汾��
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
		TRACE(_T("Warning: GetVersion ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return CString(_T(""));
	} 
}

/*========================================================================
	Name:		ȡ�ö����״̬(ͬ Recordset ����� GetState ����).
	-----------------------------------------------------
	returns:	�������г���֮һ�ĳ�����ֵ.
		[����]				[˵��] 
		----------------------------------
		adStateClosed		ָʾ�����ǹرյ�. 
		adStateOpen			ָʾ�����Ǵ򿪵�. 
	-----------------------------------------------------
	Remarks:		������ʱʹ�� State ����ȡ��ָ������ĵ�ǰ״̬.
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
		TRACE(_T("Warning: GetState �����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*========================================================================
	Name:	������Ӷ����Ƿ�Ϊ��״̬.
==========================================================================*/
BOOL CAdoConnection::IsOpen()
{
	try
	{
		return (m_p_connection != NULL && (m_p_connection->State & adStateOpen));
	}
	catch (_com_error e)
	{
		TRACE(_T("Warning: IsOpen ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
	Name:		ȡ���� Connection �������޸����ݵĿ���Ȩ��.
    ----------------------------------------------------------
	returns:	��������ĳ�� ConnectModeEnum ��ֵ.
		[����]				 [˵��] 
		----------------------------------
		adModeUnknown		 Ĭ��ֵ. ����Ȩ����δ���û��޷�ȷ��. 
		adModeRead			 ����Ȩ��Ϊֻ��. 
		adModeWrite			 ����Ȩ��Ϊֻд. 
		adModeReadWrite		 ����Ȩ��Ϊ��/д. 
		adModeShareDenyRead  ��ֹ�����û�ʹ�ö�Ȩ�޴�����. 
		adModeShareDenyWrite ��ֹ�����û�ʹ��дȨ�޴�����. 
		adModeShareExclusive ��ֹ�����û�������. 
		adModeShareDenyNone  ��ֹ�����û�ʹ���κ�Ȩ�޴�����.
    ----------------------------------------------------------
	Remarks: ʹ�� Mode ���Կ����û򷵻ص�ǰ�������ṩ������ʹ�õķ���Ȩ��.
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
		TRACE(_T("Warning: GetMode �����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return adModeUnknown;
	} 
	return adModeUnknown;
}

/*========================================================================
	Name:		������ Connection ���޸����ݵĿ���Ȩ��. ��ο� GetMode ����.
    ----------------------------------------------------------
	Remarks:	ֻ���ڹر� Connection ����ʱ�������� Mode ����.
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
		TRACE(_T("Warning: SetMode �����쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return TRUE;
}

/*========================================================================
    Name:		������Դ��ȡ���ݿ���Ϣ.
	-----------------------------------------------------
	Params:		QueryType  ��Ҫ���е�ģʽ��ѯ����,����Ϊ�������ⳣ��.
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
	adSchemaProviderSpecific	 �μ�˵�� 
	adSchemaProviderTypes		DATA_TYPE
								BEST_MATCH 
	adSchemaReferentialConstraints CONSTRAINT_CATALOG
								CONSTRAINT_SCHEMA
								CONSTRAINT_NAME 
	adSchemaSchemata			CATALOG_NAME
								SCHEMA_NAME
								SCHEMA_OWNER 
	adSchemaSQLLanguages		<��> 
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
	returns:	���ذ������ݿ���Ϣ�� Recordset ����. Recordset ����ֻ������̬
			�α��.
	-----------------------------------------------------
	Remarks:	OpenSchema��������������Դ�йص���Ϣ��������ڷ������ϵı�
			�Լ����е��е���Ϣ, �������ݽ����ο�, �Ӿ��������Դ���ܻ��в�ͬ��
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
		TRACE(_T("Warning: OpenSchema���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return NULL;
	} 
	return NULL;
}

/*########################################################################
			  ------------------------------------------------
									������
			  ------------------------------------------------
  ########################################################################*/

/*========================================================================
    Name:		��ʼ������.
	-----------------------------------------------------
	returns:	����֧��Ƕ����������ݿ���˵, ���Ѵ򿪵������е��� BeginTrans 
	��������ʼ�µ�Ƕ������. ����ֵ��ָʾǶ�ײ��: ����ֵΪ 1 ��ʾ�Ѵ򿪶���
	���� (�����񲻱���һ��������Ƕ��), ����ֵΪ 2 ��ʾ�Ѵ򿪵ڶ�������(Ƕ��
	�ڶ��������е�����), ��������.
	-----------------------------------------------------
	Remarks:	һ�������� BeginTrans ����, �ڵ��� CommitTrans �� RollbackTrans
	��������֮ǰ, ���ݿ⽫���������ύ�������κθ���.
		
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
		TRACE(_T("Warning: BeginTrans ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return -1;
	} 
	return -1;
}

/*########################################################################
			  ------------------------------------------------
									������
			  ------------------------------------------------
	BeginTrans		- ��ʼ������
	CommitTrans		- �����κθ��Ĳ�������ǰ������Ҳ��������������
	RollbackTrans	- ȡ����ǰ�������������κθ��Ĳ�����������Ҳ��������
					������

		һ�������� BeginTrans �������ڵ��� CommitTrans �� RollbackTrans ��
	������֮ǰ�����ݿ⽫���������ύ�������κθ��ġ�
		����֧��Ƕ����������ݿ���˵�����Ѵ򿪵������е��� BeginTrans ����
	����ʼ�µ�Ƕ�����񡣷���ֵ��ָʾǶ�ײ�Σ�����ֵΪ 1 ��ʾ�Ѵ򿪶�������
	(�����񲻱���һ��������Ƕ��)������ֵΪ 2 ��ʾ�Ѵ򿪵ڶ�������(Ƕ��
	�ڶ��������е�����)���������ơ����� CommitTrans �� RollbackTrans ֻӰ
	�����´򿪵������ڴ����κθ��߲�����֮ǰ����رջ�ؾ�ǰ����
		���� CommitTrans ���������������ϴ򿪵������������ĸ��Ĳ���������
	���� RollbackTrans������ԭ�������������ĸ��Ĳ�����������δ������
	ʱ���������κ�һ�ַ���������������
		ȡ���� Connection ����� Attributes ���ԣ����� CommitTrans �� 
	RollbackTrans �����������Զ�������������� Attributes ��������Ϊ 
	adXactCommitRetaining�����ݿ��� CommitTrans ���ú���Զ�����������
	��� Attributes ��������Ϊ adXactAbortRetaining�����ݿ��ڵ��� 
	RollbackTrans ֮���Զ�����������
  ########################################################################*/
/*========================================================================
    Name:		�����κθ��Ĳ�������ǰ����.
	-----------------------------------------------------
	Remarks:	���� CommitTrans �� RollbackTrans ֻӰ�����´򿪵�����; ��
	�����κθ��߲�����֮ǰ����رջ�ؾ�ǰ����.
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
		TRACE(_T("Warning: CommitTrans ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

/*========================================================================
    Name:		ȡ����ǰ�������������κθ��Ĳ���������.
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
		TRACE(_T("Warning: RollbackTrans ���������쳣. ������Ϣ: %s; �ļ�: %s; ��: %d\n"), e.ErrorMessage(), __FILE__, __LINE__);
		return FALSE;
	} 
	return FALSE;
}

