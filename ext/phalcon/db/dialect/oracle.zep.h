
extern zend_class_entry *phalcon_db_dialect_oracle_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Oracle);

PHP_METHOD(Phalcon_Db_Dialect_Oracle, limit);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createView);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropView);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, viewExists);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listViews);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsSavepoints);
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_oracle_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Oracle, limit, arginfo_phalcon_db_dialect_oracle_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, getColumnDefinition, arginfo_phalcon_db_dialect_oracle_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addColumn, arginfo_phalcon_db_dialect_oracle_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, modifyColumn, arginfo_phalcon_db_dialect_oracle_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropColumn, arginfo_phalcon_db_dialect_oracle_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addIndex, arginfo_phalcon_db_dialect_oracle_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropIndex, arginfo_phalcon_db_dialect_oracle_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addPrimaryKey, arginfo_phalcon_db_dialect_oracle_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropPrimaryKey, arginfo_phalcon_db_dialect_oracle_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addForeignKey, arginfo_phalcon_db_dialect_oracle_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropForeignKey, arginfo_phalcon_db_dialect_oracle_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, createTable, arginfo_phalcon_db_dialect_oracle_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropTable, arginfo_phalcon_db_dialect_oracle_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, createView, arginfo_phalcon_db_dialect_oracle_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropView, arginfo_phalcon_db_dialect_oracle_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, viewExists, arginfo_phalcon_db_dialect_oracle_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, listViews, arginfo_phalcon_db_dialect_oracle_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, tableExists, arginfo_phalcon_db_dialect_oracle_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeColumns, arginfo_phalcon_db_dialect_oracle_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, listTables, arginfo_phalcon_db_dialect_oracle_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeIndexes, arginfo_phalcon_db_dialect_oracle_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeReferences, arginfo_phalcon_db_dialect_oracle_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, tableOptions, arginfo_phalcon_db_dialect_oracle_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
