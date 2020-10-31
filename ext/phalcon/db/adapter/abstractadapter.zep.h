
extern zend_class_entry *phalcon_db_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDialectType);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getSqlVariables);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getType);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addColumn);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addForeignKey);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addIndex);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createSavepoint);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createTable);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, createView);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, delete);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, describeReferences);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropColumn);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropForeignKey);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropIndex);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropTable);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, dropView);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, escapeIdentifier);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, fetchAll);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, fetchColumn);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, fetchOne);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, forUpdate);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getColumnList);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getConnectionId);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDefaultValue);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDescriptor);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getDialect);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getEventsManager);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getNestedTransactionSavepointName);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getRealSQLStatement);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getSQLBindTypes);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, getSQLStatement);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, insert);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, insertAsDict);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, isNestedTransactionsWithSavepoints);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, limit);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, listTables);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, listViews);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, modifyColumn);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, releaseSavepoint);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, rollbackSavepoint);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setEventsManager);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setDialect);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, setNestedTransactionsWithSavepoints);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, sharedLock);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, supportSequences);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, tableExists);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, tableOptions);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, update);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, updateAsDict);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, useExplicitIdValue);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, supportsDefaultValue);
PHP_METHOD(Phalcon_Db_Adapter_AbstractAdapter, viewExists);
zend_object *zephir_init_properties_Phalcon_Db_Adapter_AbstractAdapter(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdialecttype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdialecttype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getsqlvariables, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getsqlvariables, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_gettype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_gettype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addcolumn, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addcolumn, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addforeignkey, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addforeignkey, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addindex, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addindex, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addprimarykey, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_addprimarykey, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_createsavepoint, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_createsavepoint, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_createtable, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_createtable, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_createview, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_createview, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, viewName)
#endif
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_describeindexes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_describeindexes, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schema)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_describereferences, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_describereferences, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schema)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropcolumn, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropcolumn, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, columnName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, columnName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropforeignkey, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropforeignkey, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, referenceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, referenceName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropindex, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropindex, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropprimarykey, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropprimarykey, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_droptable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_droptable, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ifExists, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, ifExists)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropview, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_dropview, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, viewName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ifExists, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, ifExists)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_escapeidentifier, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_escapeidentifier, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_fetchall, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_fetchall, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlQuery)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, fetchMode)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_fetchcolumn, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlQuery)
#endif
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_fetchone, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_fetchone, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlQuery)
#endif
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_forupdate, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_forupdate, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlQuery)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getcolumndefinition, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getcolumndefinition, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getcolumnlist, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getcolumnlist, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getconnectionid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getconnectionid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdefaultidvalue, 0, 0, Phalcon\\Db\\RawValue, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdefaultidvalue, 0, 0, IS_OBJECT, "Phalcon\\Db\\RawValue", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdefaultvalue, 0, 0, Phalcon\\Db\\RawValue, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdefaultvalue, 0, 0, IS_OBJECT, "Phalcon\\Db\\RawValue", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdescriptor, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdescriptor, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdialect, 0, 0, Phalcon\\Db\\DialectInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getdialect, 0, 0, IS_OBJECT, "Phalcon\\Db\\DialectInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getnestedtransactionsavepointname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getnestedtransactionsavepointname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getrealsqlstatement, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getrealsqlstatement, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getsqlbindtypes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getsqlbindtypes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getsqlstatement, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_getsqlstatement, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_insert, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_insert, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_insertasdict, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_insertasdict, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_isnestedtransactionswithsavepoints, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_isnestedtransactionswithsavepoints, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_limit, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_limit, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlQuery)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, number)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_listtables, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_listtables, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_listviews, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_listviews, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_modifycolumn, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_modifycolumn, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_releasesavepoint, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_releasesavepoint, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_rollbacksavepoint, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_rollbacksavepoint, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_seteventsmanager, 0, 0, 1)
#define arginfo_phalcon_db_adapter_abstractadapter_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_setdialect, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dialect, Phalcon\\Db\\DialectInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_setnestedtransactionswithsavepoints, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_setnestedtransactionswithsavepoints, 0, 1, IS_OBJECT, "Phalcon\\Db\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, nestedTransactionsWithSavepoints, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_sharedlock, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_sharedlock, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlQuery)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_supportsequences, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_supportsequences, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_tableexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_tableexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_tableoptions, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_tableoptions, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tableName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_update, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_update, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_updateasdict, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_updateasdict, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, table)
#endif
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_useexplicitidvalue, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_useexplicitidvalue, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_supportsdefaultvalue, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_supportsdefaultvalue, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_viewexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_abstractadapter_viewexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, viewName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, schemaName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getDialectType, arginfo_phalcon_db_adapter_abstractadapter_getdialecttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getSqlVariables, arginfo_phalcon_db_adapter_abstractadapter_getsqlvariables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getType, arginfo_phalcon_db_adapter_abstractadapter_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, __construct, arginfo_phalcon_db_adapter_abstractadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, addColumn, arginfo_phalcon_db_adapter_abstractadapter_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, addForeignKey, arginfo_phalcon_db_adapter_abstractadapter_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, addIndex, arginfo_phalcon_db_adapter_abstractadapter_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, addPrimaryKey, arginfo_phalcon_db_adapter_abstractadapter_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, createSavepoint, arginfo_phalcon_db_adapter_abstractadapter_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, createTable, arginfo_phalcon_db_adapter_abstractadapter_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, createView, arginfo_phalcon_db_adapter_abstractadapter_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, delete, arginfo_phalcon_db_adapter_abstractadapter_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, describeIndexes, arginfo_phalcon_db_adapter_abstractadapter_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, describeReferences, arginfo_phalcon_db_adapter_abstractadapter_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, dropColumn, arginfo_phalcon_db_adapter_abstractadapter_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, dropForeignKey, arginfo_phalcon_db_adapter_abstractadapter_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, dropIndex, arginfo_phalcon_db_adapter_abstractadapter_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, dropPrimaryKey, arginfo_phalcon_db_adapter_abstractadapter_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, dropTable, arginfo_phalcon_db_adapter_abstractadapter_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, dropView, arginfo_phalcon_db_adapter_abstractadapter_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, escapeIdentifier, arginfo_phalcon_db_adapter_abstractadapter_escapeidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, fetchAll, arginfo_phalcon_db_adapter_abstractadapter_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, fetchColumn, arginfo_phalcon_db_adapter_abstractadapter_fetchcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, fetchOne, arginfo_phalcon_db_adapter_abstractadapter_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, forUpdate, arginfo_phalcon_db_adapter_abstractadapter_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getColumnDefinition, arginfo_phalcon_db_adapter_abstractadapter_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getColumnList, arginfo_phalcon_db_adapter_abstractadapter_getcolumnlist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getConnectionId, arginfo_phalcon_db_adapter_abstractadapter_getconnectionid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getDefaultIdValue, arginfo_phalcon_db_adapter_abstractadapter_getdefaultidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getDefaultValue, arginfo_phalcon_db_adapter_abstractadapter_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getDescriptor, arginfo_phalcon_db_adapter_abstractadapter_getdescriptor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getDialect, arginfo_phalcon_db_adapter_abstractadapter_getdialect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getEventsManager, arginfo_phalcon_db_adapter_abstractadapter_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getNestedTransactionSavepointName, arginfo_phalcon_db_adapter_abstractadapter_getnestedtransactionsavepointname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getRealSQLStatement, arginfo_phalcon_db_adapter_abstractadapter_getrealsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getSQLBindTypes, arginfo_phalcon_db_adapter_abstractadapter_getsqlbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, getSQLStatement, arginfo_phalcon_db_adapter_abstractadapter_getsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, insert, arginfo_phalcon_db_adapter_abstractadapter_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, insertAsDict, arginfo_phalcon_db_adapter_abstractadapter_insertasdict, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, isNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapter_abstractadapter_isnestedtransactionswithsavepoints, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, limit, arginfo_phalcon_db_adapter_abstractadapter_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, listTables, arginfo_phalcon_db_adapter_abstractadapter_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, listViews, arginfo_phalcon_db_adapter_abstractadapter_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, modifyColumn, arginfo_phalcon_db_adapter_abstractadapter_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, releaseSavepoint, arginfo_phalcon_db_adapter_abstractadapter_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, rollbackSavepoint, arginfo_phalcon_db_adapter_abstractadapter_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, setEventsManager, arginfo_phalcon_db_adapter_abstractadapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, setDialect, arginfo_phalcon_db_adapter_abstractadapter_setdialect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapter_abstractadapter_setnestedtransactionswithsavepoints, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, sharedLock, arginfo_phalcon_db_adapter_abstractadapter_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, supportSequences, arginfo_phalcon_db_adapter_abstractadapter_supportsequences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, tableExists, arginfo_phalcon_db_adapter_abstractadapter_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, tableOptions, arginfo_phalcon_db_adapter_abstractadapter_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, update, arginfo_phalcon_db_adapter_abstractadapter_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, updateAsDict, arginfo_phalcon_db_adapter_abstractadapter_updateasdict, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, useExplicitIdValue, arginfo_phalcon_db_adapter_abstractadapter_useexplicitidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, supportsDefaultValue, arginfo_phalcon_db_adapter_abstractadapter_supportsdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_AbstractAdapter, viewExists, arginfo_phalcon_db_adapter_abstractadapter_viewexists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
