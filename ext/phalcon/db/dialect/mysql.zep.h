
extern zend_class_entry *phalcon_db_dialect_mysql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Mysql);

PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createView);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropView);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getForeignKeyChecks);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listViews);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, sharedLock);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, truncateTable);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, viewExists);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getTableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, checkColumnSizeAndScale);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, checkColumnUnsigned);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_addcolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_addforeignkey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_addindex, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_addprimarykey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_createtable, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_createview, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_describecolumns, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_describeindexes, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_describereferences, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropcolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, columnName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropforeignkey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropindex, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, indexName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropprimarykey, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_droptable, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, ifExists, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropview, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, ifExists, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_getcolumndefinition, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_getforeignkeychecks, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_listtables, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_listviews, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_modifycolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_sharedlock, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableexists, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableoptions, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_truncatetable, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_viewexists, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_gettableoptions, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_checkcolumnsizeandscale, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_mysql_checkcolumnunsigned, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_mysql_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Mysql, addColumn, arginfo_phalcon_db_dialect_mysql_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, addForeignKey, arginfo_phalcon_db_dialect_mysql_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, addIndex, arginfo_phalcon_db_dialect_mysql_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, addPrimaryKey, arginfo_phalcon_db_dialect_mysql_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, createTable, arginfo_phalcon_db_dialect_mysql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, createView, arginfo_phalcon_db_dialect_mysql_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeColumns, arginfo_phalcon_db_dialect_mysql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeIndexes, arginfo_phalcon_db_dialect_mysql_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeReferences, arginfo_phalcon_db_dialect_mysql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropColumn, arginfo_phalcon_db_dialect_mysql_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropForeignKey, arginfo_phalcon_db_dialect_mysql_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropIndex, arginfo_phalcon_db_dialect_mysql_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropPrimaryKey, arginfo_phalcon_db_dialect_mysql_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropTable, arginfo_phalcon_db_dialect_mysql_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropView, arginfo_phalcon_db_dialect_mysql_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, getColumnDefinition, arginfo_phalcon_db_dialect_mysql_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, getForeignKeyChecks, arginfo_phalcon_db_dialect_mysql_getforeignkeychecks, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, listTables, arginfo_phalcon_db_dialect_mysql_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, listViews, arginfo_phalcon_db_dialect_mysql_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, modifyColumn, arginfo_phalcon_db_dialect_mysql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, sharedLock, arginfo_phalcon_db_dialect_mysql_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, tableExists, arginfo_phalcon_db_dialect_mysql_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, tableOptions, arginfo_phalcon_db_dialect_mysql_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, truncateTable, arginfo_phalcon_db_dialect_mysql_truncatetable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, viewExists, arginfo_phalcon_db_dialect_mysql_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Mysql, getTableOptions, arginfo_phalcon_db_dialect_mysql_gettableoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect_Mysql, checkColumnSizeAndScale, arginfo_phalcon_db_dialect_mysql_checkcolumnsizeandscale, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Db_Dialect_Mysql, checkColumnUnsigned, arginfo_phalcon_db_dialect_mysql_checkcolumnunsigned, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
