
extern zend_class_entry *phalcon_db_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_AdapterInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_addcolumn, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_addindex, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_addforeignkey, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_addprimarykey, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_affectedrows, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_begin, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_commit, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_connect, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, descriptor, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_createsavepoint, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_createtable, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_createview, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_TYPE_INFO(0, whereCondition, IS_STRING, 1)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dataTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, dataTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_describecolumns, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_describeindexes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_describereferences, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_dropcolumn, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, columnName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_dropforeignkey, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_dropindex, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, indexName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_dropprimarykey, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_droptable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, ifExists, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_dropview, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, ifExists, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_escapeidentifier, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_escapestring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_execute, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_fetchall, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_fetchcolumn, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_fetchone, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_forupdate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getcolumndefinition, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getcolumnlist, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getconnectionid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getdescriptor, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getdialect, 0, 0, Phalcon\\Db\\DialectInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getdialecttype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getdefaultidvalue, 0, 0, Phalcon\\Db\\RawValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getdefaultvalue, 0, 0, Phalcon\\Db\\RawValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getinternalhandler, 0, 0, PDO, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getnestedtransactionsavepointname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getrealsqlstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getsqlstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getsqlbindtypes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_getsqlvariables, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_insert, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_insertasdict, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_isnestedtransactionswithsavepoints, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_isundertransaction, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_limit, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_listtables, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_listviews, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_modifycolumn, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_releasesavepoint, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_rollback, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_rollbacksavepoint, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_sharedlock, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_setnestedtransactionswithsavepoints, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, nestedTransactionsWithSavepoints, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_supportsequences, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_tableexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_tableoptions, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_update, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_updateasdict, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_useexplicitidvalue, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_supportsdefaultvalue, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_adapterinterface_viewexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, addColumn, arginfo_phalcon_db_adapter_adapterinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, addIndex, arginfo_phalcon_db_adapter_adapterinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, addForeignKey, arginfo_phalcon_db_adapter_adapterinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, addPrimaryKey, arginfo_phalcon_db_adapter_adapterinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, affectedRows, arginfo_phalcon_db_adapter_adapterinterface_affectedrows)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, begin, arginfo_phalcon_db_adapter_adapterinterface_begin)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, close, arginfo_phalcon_db_adapter_adapterinterface_close)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, commit, arginfo_phalcon_db_adapter_adapterinterface_commit)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, connect, arginfo_phalcon_db_adapter_adapterinterface_connect)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, createSavepoint, arginfo_phalcon_db_adapter_adapterinterface_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, createTable, arginfo_phalcon_db_adapter_adapterinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, createView, arginfo_phalcon_db_adapter_adapterinterface_createview)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, delete, arginfo_phalcon_db_adapter_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, describeColumns, arginfo_phalcon_db_adapter_adapterinterface_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, describeIndexes, arginfo_phalcon_db_adapter_adapterinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, describeReferences, arginfo_phalcon_db_adapter_adapterinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, dropColumn, arginfo_phalcon_db_adapter_adapterinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, dropForeignKey, arginfo_phalcon_db_adapter_adapterinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, dropIndex, arginfo_phalcon_db_adapter_adapterinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, dropPrimaryKey, arginfo_phalcon_db_adapter_adapterinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, dropTable, arginfo_phalcon_db_adapter_adapterinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, dropView, arginfo_phalcon_db_adapter_adapterinterface_dropview)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, escapeIdentifier, arginfo_phalcon_db_adapter_adapterinterface_escapeidentifier)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, escapeString, arginfo_phalcon_db_adapter_adapterinterface_escapestring)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, execute, arginfo_phalcon_db_adapter_adapterinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, fetchAll, arginfo_phalcon_db_adapter_adapterinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, fetchColumn, arginfo_phalcon_db_adapter_adapterinterface_fetchcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, fetchOne, arginfo_phalcon_db_adapter_adapterinterface_fetchone)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, forUpdate, arginfo_phalcon_db_adapter_adapterinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getColumnDefinition, arginfo_phalcon_db_adapter_adapterinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getColumnList, arginfo_phalcon_db_adapter_adapterinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getConnectionId, arginfo_phalcon_db_adapter_adapterinterface_getconnectionid)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getDescriptor, arginfo_phalcon_db_adapter_adapterinterface_getdescriptor)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getDialect, arginfo_phalcon_db_adapter_adapterinterface_getdialect)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getDialectType, arginfo_phalcon_db_adapter_adapterinterface_getdialecttype)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getDefaultIdValue, arginfo_phalcon_db_adapter_adapterinterface_getdefaultidvalue)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getDefaultValue, arginfo_phalcon_db_adapter_adapterinterface_getdefaultvalue)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getInternalHandler, arginfo_phalcon_db_adapter_adapterinterface_getinternalhandler)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getNestedTransactionSavepointName, arginfo_phalcon_db_adapter_adapterinterface_getnestedtransactionsavepointname)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getRealSQLStatement, arginfo_phalcon_db_adapter_adapterinterface_getrealsqlstatement)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getSQLStatement, arginfo_phalcon_db_adapter_adapterinterface_getsqlstatement)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getSQLBindTypes, arginfo_phalcon_db_adapter_adapterinterface_getsqlbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getSQLVariables, arginfo_phalcon_db_adapter_adapterinterface_getsqlvariables)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, getType, arginfo_phalcon_db_adapter_adapterinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, insert, arginfo_phalcon_db_adapter_adapterinterface_insert)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, insertAsDict, arginfo_phalcon_db_adapter_adapterinterface_insertasdict)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, isNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapter_adapterinterface_isnestedtransactionswithsavepoints)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, isUnderTransaction, arginfo_phalcon_db_adapter_adapterinterface_isundertransaction)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, lastInsertId, arginfo_phalcon_db_adapter_adapterinterface_lastinsertid)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, limit, arginfo_phalcon_db_adapter_adapterinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, listTables, arginfo_phalcon_db_adapter_adapterinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, listViews, arginfo_phalcon_db_adapter_adapterinterface_listviews)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, modifyColumn, arginfo_phalcon_db_adapter_adapterinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, query, arginfo_phalcon_db_adapter_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, releaseSavepoint, arginfo_phalcon_db_adapter_adapterinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, rollback, arginfo_phalcon_db_adapter_adapterinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, rollbackSavepoint, arginfo_phalcon_db_adapter_adapterinterface_rollbacksavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, sharedLock, arginfo_phalcon_db_adapter_adapterinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapter_adapterinterface_setnestedtransactionswithsavepoints)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, supportSequences, arginfo_phalcon_db_adapter_adapterinterface_supportsequences)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, tableExists, arginfo_phalcon_db_adapter_adapterinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, tableOptions, arginfo_phalcon_db_adapter_adapterinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, update, arginfo_phalcon_db_adapter_adapterinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, updateAsDict, arginfo_phalcon_db_adapter_adapterinterface_updateasdict)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, useExplicitIdValue, arginfo_phalcon_db_adapter_adapterinterface_useexplicitidvalue)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, supportsDefaultValue, arginfo_phalcon_db_adapter_adapterinterface_supportsdefaultvalue)
	PHP_ABSTRACT_ME(Phalcon_Db_Adapter_AdapterInterface, viewExists, arginfo_phalcon_db_adapter_adapterinterface_viewexists)
	PHP_FE_END
};
