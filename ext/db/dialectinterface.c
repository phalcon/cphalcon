
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "db/dialectinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_db_dialectinterface_ce;

static const zend_function_entry phalcon_db_dialectinterface_method_entry[] = {
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
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropTable, arginfo_phalcon_db_dialectinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createView, arginfo_phalcon_db_dialectinterface_createview)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropView, arginfo_phalcon_db_dialectinterface_dropview)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableExists, arginfo_phalcon_db_dialectinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, viewExists, arginfo_phalcon_db_dialectinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeColumns, arginfo_phalcon_db_dialectinterface_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, listTables, arginfo_phalcon_db_dialectinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, listViews, arginfo_phalcon_db_dialectinterface_listtables)
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

/**
 * Phalcon\Db\DialectInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_DialectInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, DialectInterface, db_dialectinterface, phalcon_db_dialectinterface_method_entry);

	return SUCCESS;
}

/**
 * Generates the SQL for LIMIT clause
 *
 * @param string $sqlQuery
 * @param int $number
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, limit);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, sharedLock);

/**
 * Builds a SELECT statement
 *
 * @param array $definition
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, select);

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, getColumnList);

/**
 * Gets the column name in MySQL
 *
 * @param Phalcon\Db\ColumnInterface $column
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, getColumnDefinition);

/**
 * Generates SQL to add a column to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, addColumn);

/**
 * Generates SQL to modify a column in a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, modifyColumn);

/**
 * Generates SQL to delete a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return 	string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropColumn);

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, addIndex);

/**
 * Generates SQL to delete an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropIndex);

/**
 * Generates SQL to add the primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, addPrimaryKey);

/**
 * Generates SQL to delete primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropPrimaryKey);

/**
 * Generates SQL to add an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ReferenceInterface $reference
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, addForeignKey);

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropForeignKey);

/**
 * Generates SQL to create a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, createTable);

/**
 * Generates SQL to create a view
 *
 * @param string $viewName
 * @param string $schemaName
 * @param array $definition
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, createView);

/**
 * Generates SQL to drop a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropTable);

/**
 * Generates SQL to drop a view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropView);

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, tableExists);

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, viewExists);

/**
 * Generates SQL to describe a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, describeColumns);

/**
 * List all tables on database
 *
 * @param string $schemaName
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, listTables);

/**
 * List all views on database
 *
 * @param string $schemaName
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, listViews);

/**
 * Generates SQL to query indexes on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, describeIndexes);

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, describeReferences);

/**
 * Generates the SQL to describe the table creation options
 *
 * @param string $table
 * @param string $schema
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, tableOptions);

/**
 * Checks whether the platform supports savepoints
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, supportsSavepoints);

/**
 * Checks whether the platform supports releasing savepoints.
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, supportsReleaseSavepoints);

/**
 * Generate SQL to create a new savepoint
 *
 * @param string $name
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, createSavepoint);

/**
 * Generate SQL to release a savepoint
 *
 * @param string $name
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, releaseSavepoint);

/**
 * Generate SQL to rollback a savepoint
 *
 * @param string $name
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, rollbackSavepoint);
