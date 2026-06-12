
extern zend_class_entry *phalcon_db_dialect_postgresql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Postgresql);

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addCheck);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createMaterializedView);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropCheck);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropMaterializedView);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, refreshMaterializedView);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, returning);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, sharedLock);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, truncateTable);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, castDefault);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getTableOptions);
zend_object *zephir_init_properties_Phalcon_Db_Dialect_Postgresql(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addcolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addcheck, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, check, Phalcon\\Db\\CheckInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addforeignkey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addindex, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addprimarykey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_createtable, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_creatematerializedview, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_createview, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describecolumns, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describeindexes, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describereferences, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropcolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, columnName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropcheck, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, checkName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropforeignkey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropindex, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, indexName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropprimarykey, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_droptable, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ifExists, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropmaterializedview, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ifExists, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropview, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ifExists, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_refreshmaterializedview, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, concurrent, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_getcolumndefinition, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_listtables, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_listviews, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_modifycolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, currentColumn, Phalcon\\Db\\ColumnInterface, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_returning, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_sharedlock, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, modifier, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_tableexists, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_tableoptions, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_truncatetable, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_viewexists, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_castdefault, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_dialect_postgresql_gettableoptions, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_zephir_init_properties_phalcon_db_dialect_postgresql, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_postgresql_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addColumn, arginfo_phalcon_db_dialect_postgresql_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addCheck, arginfo_phalcon_db_dialect_postgresql_addcheck, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addForeignKey, arginfo_phalcon_db_dialect_postgresql_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addIndex, arginfo_phalcon_db_dialect_postgresql_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addPrimaryKey, arginfo_phalcon_db_dialect_postgresql_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, createTable, arginfo_phalcon_db_dialect_postgresql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, createMaterializedView, arginfo_phalcon_db_dialect_postgresql_creatematerializedview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, createView, arginfo_phalcon_db_dialect_postgresql_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeColumns, arginfo_phalcon_db_dialect_postgresql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeIndexes, arginfo_phalcon_db_dialect_postgresql_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeReferences, arginfo_phalcon_db_dialect_postgresql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropColumn, arginfo_phalcon_db_dialect_postgresql_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropCheck, arginfo_phalcon_db_dialect_postgresql_dropcheck, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropForeignKey, arginfo_phalcon_db_dialect_postgresql_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropIndex, arginfo_phalcon_db_dialect_postgresql_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey, arginfo_phalcon_db_dialect_postgresql_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropTable, arginfo_phalcon_db_dialect_postgresql_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropMaterializedView, arginfo_phalcon_db_dialect_postgresql_dropmaterializedview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropView, arginfo_phalcon_db_dialect_postgresql_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, refreshMaterializedView, arginfo_phalcon_db_dialect_postgresql_refreshmaterializedview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, getColumnDefinition, arginfo_phalcon_db_dialect_postgresql_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, listTables, arginfo_phalcon_db_dialect_postgresql_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, listViews, arginfo_phalcon_db_dialect_postgresql_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, modifyColumn, arginfo_phalcon_db_dialect_postgresql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, returning, arginfo_phalcon_db_dialect_postgresql_returning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, sharedLock, arginfo_phalcon_db_dialect_postgresql_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, tableExists, arginfo_phalcon_db_dialect_postgresql_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, tableOptions, arginfo_phalcon_db_dialect_postgresql_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, truncateTable, arginfo_phalcon_db_dialect_postgresql_truncatetable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, viewExists, arginfo_phalcon_db_dialect_postgresql_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, castDefault, arginfo_phalcon_db_dialect_postgresql_castdefault, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, getTableOptions, arginfo_phalcon_db_dialect_postgresql_gettableoptions, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
