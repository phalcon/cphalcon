
extern zend_class_entry *phalcon_db_dialect_sqlite_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Sqlite);

PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describeindex, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_sqlite_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Sqlite, getColumnDefinition, arginfo_phalcon_db_dialect_sqlite_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addColumn, arginfo_phalcon_db_dialect_sqlite_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, modifyColumn, arginfo_phalcon_db_dialect_sqlite_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropColumn, arginfo_phalcon_db_dialect_sqlite_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addIndex, arginfo_phalcon_db_dialect_sqlite_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropIndex, arginfo_phalcon_db_dialect_sqlite_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addPrimaryKey, arginfo_phalcon_db_dialect_sqlite_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey, arginfo_phalcon_db_dialect_sqlite_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addForeignKey, arginfo_phalcon_db_dialect_sqlite_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropForeignKey, arginfo_phalcon_db_dialect_sqlite_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, createTable, arginfo_phalcon_db_dialect_sqlite_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropTable, arginfo_phalcon_db_dialect_sqlite_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, createView, arginfo_phalcon_db_dialect_sqlite_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropView, arginfo_phalcon_db_dialect_sqlite_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, tableExists, arginfo_phalcon_db_dialect_sqlite_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, viewExists, arginfo_phalcon_db_dialect_sqlite_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeColumns, arginfo_phalcon_db_dialect_sqlite_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, listTables, arginfo_phalcon_db_dialect_sqlite_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, listViews, arginfo_phalcon_db_dialect_sqlite_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeIndexes, arginfo_phalcon_db_dialect_sqlite_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeIndex, arginfo_phalcon_db_dialect_sqlite_describeindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeReferences, arginfo_phalcon_db_dialect_sqlite_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, tableOptions, arginfo_phalcon_db_dialect_sqlite_tableoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
