
extern zend_class_entry *phalcon_db_dialect_mysql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_MySQL);

PHP_METHOD(Phalcon_Db_Dialect_MySQL, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, createTable);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, createView);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropView);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, viewExists);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, listTables);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, listViews);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableOptions);
PHP_METHOD(Phalcon_Db_Dialect_MySQL, _getTableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql__gettableoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_mysql_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_MySQL, getColumnDefinition, arginfo_phalcon_db_dialect_mysql_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addColumn, arginfo_phalcon_db_dialect_mysql_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, modifyColumn, arginfo_phalcon_db_dialect_mysql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropColumn, arginfo_phalcon_db_dialect_mysql_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addIndex, arginfo_phalcon_db_dialect_mysql_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropIndex, arginfo_phalcon_db_dialect_mysql_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addPrimaryKey, arginfo_phalcon_db_dialect_mysql_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropPrimaryKey, arginfo_phalcon_db_dialect_mysql_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addForeignKey, arginfo_phalcon_db_dialect_mysql_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropForeignKey, arginfo_phalcon_db_dialect_mysql_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, createTable, arginfo_phalcon_db_dialect_mysql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropTable, arginfo_phalcon_db_dialect_mysql_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, createView, arginfo_phalcon_db_dialect_mysql_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropView, arginfo_phalcon_db_dialect_mysql_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, tableExists, arginfo_phalcon_db_dialect_mysql_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, viewExists, arginfo_phalcon_db_dialect_mysql_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, describeColumns, arginfo_phalcon_db_dialect_mysql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, listTables, arginfo_phalcon_db_dialect_mysql_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, listViews, arginfo_phalcon_db_dialect_mysql_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, describeIndexes, arginfo_phalcon_db_dialect_mysql_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, describeReferences, arginfo_phalcon_db_dialect_mysql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, tableOptions, arginfo_phalcon_db_dialect_mysql_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, _getTableOptions, arginfo_phalcon_db_dialect_mysql__gettableoptions, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
