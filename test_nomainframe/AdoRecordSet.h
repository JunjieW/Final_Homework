
#if !defined(_ANYOU_COOL_ADORECORDSET_H)
#define _ANYOU_COOL_ADORECORDSET_H
#include "AdoConnection.h"
/*########################################################################
			 ------------------------------------------------
						  CAdoRecordSet class
			 ------------------------------------------------
  ########################################################################*/


class CAdoRecordSet 
{
// 构建/折构 --------------------------------------------
public:
	CAdoRecordSet();
	CAdoRecordSet(CAdoConnection *pConnection);

	virtual ~CAdoRecordSet();
	//flag form end to first
	BOOL SeekToFieldValue(int fieldIndex, const CString & Value ,BOOL flag);
protected:
	void Release();
	
// 属性 ------------------------------------------------	
public:
	// 当前编辑状态 ----------------------------
	EditModeEnum GetEditMode();
	
	// 当前状态 --------------------------------
	BOOL IsEOF();
	BOOL IsBOF();
	BOOL IsOpen();
	long GetState();
	long GetStatus();

	// 充许返回的最大记录数 --------------------
	long GetMaxRecordCount();
	BOOL SetMaxRecordCount(long count);
	
	// 光标位置 --------------------------------
	CursorLocationEnum GetCursorLocation();
	BOOL SetCursorLocation(CursorLocationEnum CursorLocation = adUseClient);
	
	// 光标类型 --------------------------------
	CursorTypeEnum GetCursorType();
	BOOL SetCursorType(CursorTypeEnum CursorType = adOpenStatic);
	
	// 书签 --------------------------------
	_variant_t GetBookmark();
	BOOL SetBookmark(_variant_t varBookMark = _variant_t((long)adBookmarkFirst));
	
	// 当前记录位置 ------------------------
	long GetAbsolutePosition();
	BOOL SetAbsolutePosition(int nPosition);

	long GetAbsolutePage();
	BOOL SetAbsolutePage(int nPage);

	// 每页的记录数 ------------------------
	long GetPageSize();
	BOOL SetCacheSize(const long& lCacheSize);	

	// 页数 --------------------------------
	long GetPageCount();

	// 记录数及字段数 ----------------------
	long GetRecordCount();
	long GetFieldsCount();

	// 字段值在记录集合中的位置 --------------------------	
	int GetFieldIndex(CString filedName);

	// 光标的位置 --------------------------	
	long GetCursorPos();

	// 查询字符串 --------------------------
	CString GetSQLText() {return m_strSQL;}
	void SetSQLText(LPCTSTR strSQL) {m_strSQL = strSQL;}
	
	// 连接对象 ----------------------------
	CAdoConnection* GetConnection() {return m_p_connection;}
	void SetAdoConnection(CAdoConnection *pConnection);

	// 记录集对象 --------------------------
	_RecordsetPtr& GetRecordset();

	CString GetLastError();

// 字段属性 ----------------------------------------------
public:
	// 字段集 -------------------------------
	FieldsPtr GetFields();

	// 字段对象 -----------------------------
	FieldPtr  GetField(long lIndex);
	FieldPtr  GetField(LPCTSTR lpszFieldName);
	
	// 字段名 -------------------------------
	CString GetFieldName(long lIndex);
	
	// 字段数据类型 -------------------------
	DataTypeEnum GetFieldType(long lIndex);
	DataTypeEnum GetFieldType(LPCTSTR lpszFieldName);

	// 字段属性 -----------------------------
	long  GetFieldAttributes(long lIndex);
	long  GetFieldAttributes(LPCTSTR lpszFieldName);

	// 字段定义长度 -------------------------
	long  GetFieldDefineSize(long lIndex);
	long  GetFieldDefineSize(LPCTSTR lpszFieldName);

	// 字段实际长度 -------------------------
	long  GetFieldActualSize(long lIndex);
	long  GetFieldActualSize(LPCTSTR lpszFieldName);

	// 字段是否为NULL -----------------------
	BOOL  IsFieldNull(long index);
	BOOL  IsFieldNull(LPCTSTR lpFieldName);

// 记录更改 --------------------------------------------
public:
	BOOL AddNew();
	BOOL Update();
	BOOL UpdateBatch(AffectEnum AffectRecords = adAffectAll); 
	BOOL CancelUpdate();
	BOOL CancelBatch(AffectEnum AffectRecords = adAffectAll);
	BOOL Delete(AffectEnum AffectRecords = adAffectCurrent);
	
	// 刷新记录集中的数据 ------------------
	BOOL Requery(long Options = adConnectUnspecified);
	BOOL Resync(AffectEnum AffectRecords = adAffectAll, ResyncEnum ResyncValues = adResyncAllValues);   

	BOOL RecordBinding(CADORecordBinding &pAdoRecordBinding);
	BOOL AddNew(CADORecordBinding &pAdoRecordBinding);
	
// 记录集导航操作 --------------------------------------
public:
	BOOL MoveFirst();
	BOOL MovePrevious();
	BOOL MoveNext();
	BOOL MoveLast();
	BOOL Move(long lRecords, _variant_t Start = _variant_t((long)adBookmarkFirst));
	
	// 查找指定的记录 ----------------------
	BOOL Find(LPCTSTR lpszFind, SearchDirectionEnum SearchDirection = adSearchForward);
	BOOL FindNext();

// 查询 ------------------------------------------------
public:
	BOOL Open(LPCTSTR strSQL, long lOption = adCmdText, CursorTypeEnum CursorType = adOpenStatic, LockTypeEnum LockType = adLockOptimistic);
	BOOL Cancel();
	void Close();

	// 保存/载入持久性文件 -----------------
	BOOL Save(LPCTSTR strFileName = _T(""), PersistFormatEnum PersistFormat = adPersistXML);
	BOOL Load(LPCTSTR strFileName);
	
// 字段存取 --------------------------------------------
public:
	BOOL PutCollect(long index, const _variant_t &value);
	BOOL PutCollect(long index, const CString &value);
	BOOL PutCollect(long index, const double &value);
	BOOL PutCollect(long index, const float  &value);
	BOOL PutCollect(long index, const long   &value);
	BOOL PutCollect(long index, const DWORD  &value);
	BOOL PutCollect(long index, const int    &value);
	BOOL PutCollect(long index, const short  &value);
	BOOL PutCollect(long index, const BYTE   &value);
	BOOL PutCollect(long index, const bool   &value);
	BOOL PutCollect(long index, const COleDateTime &value);
	BOOL PutCollect(long index, const COleCurrency &value);

	BOOL PutCollect(LPCTSTR strFieldName, const _variant_t &value);
	BOOL PutCollect(LPCTSTR strFieldName, const CString &value);
	BOOL PutCollect(LPCTSTR strFieldName, const double &value);
	BOOL PutCollect(LPCTSTR strFieldName, const float  &value);
	BOOL PutCollect(LPCTSTR strFieldName, const long   &value);
	BOOL PutCollect(LPCTSTR strFieldName, const DWORD  &value);
	BOOL PutCollect(LPCTSTR strFieldName, const int    &value);
	BOOL PutCollect(LPCTSTR strFieldName, const short  &value);
	BOOL PutCollect(LPCTSTR strFieldName, const BYTE   &value);
	BOOL PutCollect(LPCTSTR strFieldName, const bool   &value);
	BOOL PutCollect(LPCTSTR strFieldName, const COleDateTime &value);
	BOOL PutCollect(LPCTSTR strFieldName, const COleCurrency &value);

	// ---------------------------------------------------------

	BOOL GetCollect(long index, CString &value);
	BOOL GetCollect(long index, double  &value);
	BOOL GetCollect(long index, float   &value);
	BOOL GetCollect(long index, long    &value);
	BOOL GetCollect(long index, DWORD   &value);
	BOOL GetCollect(long index, int     &value);
	BOOL GetCollect(long index, short   &value);
	BOOL GetCollect(long index, BYTE    &value);
	BOOL GetCollect(long index, bool   &value);
	BOOL GetCollect(long index, COleDateTime &value);
	BOOL GetCollect(long index, COleCurrency &value);

	BOOL GetCollect(LPCTSTR strFieldName, CString &strValue);
	BOOL GetCollect(LPCTSTR strFieldName, double &value);
	BOOL GetCollect(LPCTSTR strFieldName, float  &value);
	BOOL GetCollect(LPCTSTR strFieldName, long   &value);
	BOOL GetCollect(LPCTSTR strFieldName, DWORD  &value);
	BOOL GetCollect(LPCTSTR strFieldName, int    &value);
	BOOL GetCollect(LPCTSTR strFieldName, short  &value);
	BOOL GetCollect(LPCTSTR strFieldName, BYTE   &value);
	BOOL GetCollect(LPCTSTR strFieldName, bool   &value);
	BOOL GetCollect(LPCTSTR strFieldName, COleDateTime &value);
	BOOL GetCollect(LPCTSTR strFieldName, COleCurrency &value);

	// 群组获取记录集合值 ------------------------------------------
	BOOL GetFieldValues(CStringArray *array, CString fieldName,BOOL lockCursorPos = FALSE,int maxRows = 100);
	BOOL GetFieldValues(CStringArray *array, int index ,BOOL lockCursorPos = FALSE,int maxRows = 100);

	int GetFieldValues(double *Array, int size, int index, BOOL lockCursorPos = FALSE, int maxRows = 100);
	int GetFieldValues(double *Array, int size, CString fieldName, BOOL lockCursorPos = FALSE, int maxRows = 100);

	int GetFieldValues(COleDateTime *Array, int size, int index, BOOL lockCursorPos = FALSE, int maxRows = 100);
	int GetFieldValues(COleDateTime *Array, int size, CString fieldName, BOOL lockCursorPos = FALSE, int maxRows = 100);

	int GetFieldValues(int * Array,int size , int index,BOOL lockCursorPos = FALSE,int maxRows =100);
	int GetFieldValues(int * Array,int size , CString fieldName,BOOL lockCursorPos = FALSE,int maxRows =100);

	// BLOB 数据存取 ------------------------------------------
	// BLOB 是指二进制的大对象，如图片，声音，视频，由于它们的尺寸，必须使用特殊的方式来处理
	BOOL LoadOLEDataFromDB(CString CreateFileName ,CString feildName);
	
	BOOL AppendChunk(FieldPtr pField, LPVOID lpData, UINT nBytes);
	BOOL AppendChunk(long index, LPVOID lpData, UINT nBytes);
	BOOL AppendChunk(LPCTSTR strFieldName, LPVOID lpData, UINT nBytes);
	BOOL AppendChunk(long index, LPCTSTR lpszFileName);
	BOOL AppendChunk(LPCTSTR strFieldName, LPCTSTR lpszFileName);

	BOOL GetChunk(FieldPtr pField, LPVOID lpData);
	BOOL GetChunk(long index, LPVOID lpData);
	BOOL GetChunk(LPCTSTR strFieldName, LPVOID lpData);
	BOOL GetChunk(long index, CBitmap &bitmap);
	BOOL GetChunk(LPCTSTR strFieldName, CBitmap &bitmap);

// 其他方法 --------------------------------------------
public:
	// 过滤记录 ---------------------------------
	BOOL SetFilter(LPCTSTR lpszFilter);

	// 排序 -------------------------------------
	BOOL SetSort(LPCTSTR lpszCriteria);

	// 测试是否支持某方法 -----------------------
	BOOL Supports(CursorOptionEnum CursorOptions = adAddNew);

	// 克隆 -------------------------------------
	BOOL Clone(CAdoRecordSet &pRecordSet);
	_RecordsetPtr operator = (_RecordsetPtr &pRecordSet);
	
	// 格式化 _variant_t 类型值 -----------------
	
//成员变量 --------------------------------------------
protected:
	CAdoConnection     *m_p_connection;
	_RecordsetPtr		m_p_record_set;
	CString				m_strSQL;
	CString				m_strFind;
	CString				m_strFileName;
	IADORecordBinding	*m_pAdoRecordBinding;
	SearchDirectionEnum m_SearchDirection;
public:
	
	_variant_t			m_varBookmark;
};
//________________________________________________________________________

#endif //_ANYOU_COOL_ADORECORDSET_H