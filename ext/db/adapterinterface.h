
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_db_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_convertboundparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, __construct, arginfo_phalcon_db_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchOne, arginfo_phalcon_db_adapterinterface_fetchone)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchAll, arginfo_phalcon_db_adapterinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, insert, arginfo_phalcon_db_adapterinterface_insert)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, update, arginfo_phalcon_db_adapterinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, delete, arginfo_phalcon_db_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnList, arginfo_phalcon_db_adapterinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, limit, arginfo_phalcon_db_adapterinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableExists, arginfo_phalcon_db_adapterinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, viewExists, arginfo_phalcon_db_adapterinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, forUpdate, arginfo_phalcon_db_adapterinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, sharedLock, arginfo_phalcon_db_adapterinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createTable, arginfo_phalcon_db_adapterinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropTable, arginfo_phalcon_db_adapterinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addColumn, arginfo_phalcon_db_adapterinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, modifyColumn, arginfo_phalcon_db_adapterinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropColumn, arginfo_phalcon_db_adapterinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addIndex, arginfo_phalcon_db_adapterinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropIndex, arginfo_phalcon_db_adapterinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addPrimaryKey, arginfo_phalcon_db_adapterinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropPrimaryKey, arginfo_phalcon_db_adapterinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addForeignKey, arginfo_phalcon_db_adapterinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropForeignKey, arginfo_phalcon_db_adapterinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnDefinition, arginfo_phalcon_db_adapterinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, listTables, arginfo_phalcon_db_adapterinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDescriptor, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getConnectionId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getRealSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLVariables, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLBindTypes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialectType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialect, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, connect, arginfo_phalcon_db_adapterinterface_connect)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, query, arginfo_phalcon_db_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, execute, arginfo_phalcon_db_adapterinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, affectedRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeIdentifier, arginfo_phalcon_db_adapterinterface_escapeidentifier)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeString, arginfo_phalcon_db_adapterinterface_escapestring)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, convertBoundParams, arginfo_phalcon_db_adapterinterface_convertboundparams)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, lastInsertId, arginfo_phalcon_db_adapterinterface_lastinsertid)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, isUnderTransaction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getInternalHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeIndexes, arginfo_phalcon_db_adapterinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeReferences, arginfo_phalcon_db_adapterinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableOptions, arginfo_phalcon_db_adapterinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, useExplicitIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDefaultIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, supportSequences, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeColumns, arginfo_phalcon_db_adapterinterface_describecolumns)
	PHP_FE_END
};

