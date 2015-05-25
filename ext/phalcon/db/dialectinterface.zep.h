
extern zend_class_entry *phalcon_db_dialectinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_DialectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_select, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, columnList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialectinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, limit, arginfo_phalcon_db_dialectinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, forUpdate, arginfo_phalcon_db_dialectinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, sharedLock, arginfo_phalcon_db_dialectinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, select, arginfo_phalcon_db_dialectinterface_select)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnList, arginfo_phalcon_db_dialectinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnDefinition, arginfo_phalcon_db_dialectinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addColumn, arginfo_phalcon_db_dialectinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, modifyColumn, arginfo_phalcon_db_dialectinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropColumn, arginfo_phalcon_db_dialectinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addIndex, arginfo_phalcon_db_dialectinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropIndex, arginfo_phalcon_db_dialectinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addPrimaryKey, arginfo_phalcon_db_dialectinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropPrimaryKey, arginfo_phalcon_db_dialectinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addForeignKey, arginfo_phalcon_db_dialectinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropForeignKey, arginfo_phalcon_db_dialectinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createTable, arginfo_phalcon_db_dialectinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createView, arginfo_phalcon_db_dialectinterface_createview)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropTable, arginfo_phalcon_db_dialectinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropView, arginfo_phalcon_db_dialectinterface_dropview)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableExists, arginfo_phalcon_db_dialectinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, viewExists, arginfo_phalcon_db_dialectinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeColumns, arginfo_phalcon_db_dialectinterface_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, listTables, arginfo_phalcon_db_dialectinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeIndexes, arginfo_phalcon_db_dialectinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeReferences, arginfo_phalcon_db_dialectinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableOptions, arginfo_phalcon_db_dialectinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, supportsSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, supportsReleaseSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createSavepoint, arginfo_phalcon_db_dialectinterface_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, releaseSavepoint, arginfo_phalcon_db_dialectinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, rollbackSavepoint, arginfo_phalcon_db_dialectinterface_rollbacksavepoint)
	PHP_FE_END
};
