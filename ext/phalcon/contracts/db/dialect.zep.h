
extern zend_class_entry *phalcon_contracts_db_dialect_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Dialect);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_addcolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_addforeignkey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_addindex, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_addprimarykey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_createsavepoint, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_createtable, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_createview, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_describecolumns, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_describeindexes, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_describereferences, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_dropcolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, columnName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_dropforeignkey, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, referenceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_dropindex, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, indexName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_dropprimarykey, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_droptable, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ifExists, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_dropview, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ifExists, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_forupdate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, modifier, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_getcolumndefinition, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_getcolumnlist, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, columnList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_getcustomfunctions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_getsqlexpression, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, escapeChar, IS_STRING, 1, "null")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindCounts, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_limit, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_listtables, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_modifycolumn, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, currentColumn, Phalcon\\Db\\ColumnInterface, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_db_dialect_registercustomfunction, 0, 2, Phalcon\\Db\\Dialect, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, customFunction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_releasesavepoint, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_rollbacksavepoint, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_select, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_sharedlock, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sqlQuery, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, modifier, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_supportsreleasesavepoints, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_supportssavepoints, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_tableexists, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_tableoptions, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schema, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_dialect_viewexists, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, schemaName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_db_dialect_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, addColumn, arginfo_phalcon_contracts_db_dialect_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, addForeignKey, arginfo_phalcon_contracts_db_dialect_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, addIndex, arginfo_phalcon_contracts_db_dialect_addindex)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, addPrimaryKey, arginfo_phalcon_contracts_db_dialect_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, createSavepoint, arginfo_phalcon_contracts_db_dialect_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, createTable, arginfo_phalcon_contracts_db_dialect_createtable)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, createView, arginfo_phalcon_contracts_db_dialect_createview)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, describeColumns, arginfo_phalcon_contracts_db_dialect_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, describeIndexes, arginfo_phalcon_contracts_db_dialect_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, describeReferences, arginfo_phalcon_contracts_db_dialect_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, dropColumn, arginfo_phalcon_contracts_db_dialect_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, dropForeignKey, arginfo_phalcon_contracts_db_dialect_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, dropIndex, arginfo_phalcon_contracts_db_dialect_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, dropPrimaryKey, arginfo_phalcon_contracts_db_dialect_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, dropTable, arginfo_phalcon_contracts_db_dialect_droptable)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, dropView, arginfo_phalcon_contracts_db_dialect_dropview)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, forUpdate, arginfo_phalcon_contracts_db_dialect_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, getColumnDefinition, arginfo_phalcon_contracts_db_dialect_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, getColumnList, arginfo_phalcon_contracts_db_dialect_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, getCustomFunctions, arginfo_phalcon_contracts_db_dialect_getcustomfunctions)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, getSqlExpression, arginfo_phalcon_contracts_db_dialect_getsqlexpression)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, limit, arginfo_phalcon_contracts_db_dialect_limit)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, listTables, arginfo_phalcon_contracts_db_dialect_listtables)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, modifyColumn, arginfo_phalcon_contracts_db_dialect_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, registerCustomFunction, arginfo_phalcon_contracts_db_dialect_registercustomfunction)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, releaseSavepoint, arginfo_phalcon_contracts_db_dialect_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, rollbackSavepoint, arginfo_phalcon_contracts_db_dialect_rollbacksavepoint)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, select, arginfo_phalcon_contracts_db_dialect_select)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, sharedLock, arginfo_phalcon_contracts_db_dialect_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, supportsReleaseSavepoints, arginfo_phalcon_contracts_db_dialect_supportsreleasesavepoints)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, supportsSavepoints, arginfo_phalcon_contracts_db_dialect_supportssavepoints)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, tableExists, arginfo_phalcon_contracts_db_dialect_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, tableOptions, arginfo_phalcon_contracts_db_dialect_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Dialect, viewExists, arginfo_phalcon_contracts_db_dialect_viewexists)
	PHP_FE_END
};
