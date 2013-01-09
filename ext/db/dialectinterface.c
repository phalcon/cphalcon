
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

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
 * @param 	string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return 	string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, createTable);

/**
 * Generates SQL to drop a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, dropTable);

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, tableExists);

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
 * @param       string $schemaName
 * @return      array
 */
PHALCON_DOC_METHOD(Phalcon_Db_DialectInterface, listTables);

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

