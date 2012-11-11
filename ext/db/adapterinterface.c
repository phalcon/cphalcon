
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
 * Phalcon\Db\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, AdapterInterface, db_adapterinterface, phalcon_db_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter
 *
 * @param array $descriptor
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, __construct);

/**
 * Returns the first row in a SQL query result
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, fetchOne);

/**
 * Dumps the complete result of a query into an array
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, fetchAll);

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * @param 	string $table
 * @param 	array $values
 * @param 	array $fields
 * @param 	array $dataTypes
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, insert);

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * @param 	string $table
 * @param 	array $fields
 * @param 	array $values
 * @param 	string $whereCondition
 * @param 	array $dataTypes
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, update);

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * @param  string $table
 * @param  string $whereCondition
 * @param  array $placeholders
 * @param  array $dataTypes
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, delete);

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getColumnList);

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * @param  	string $sqlQuery
 * @param 	int $number
 * @return 	string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, limit);

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, tableExists);

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, viewExists);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, sharedLock);

/**
 * Creates a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, createTable);

/**
 * Drops a table from a schema/database
 *
 * @param string $tableName
 * @param   string $schemaName
 * @param boolean $ifExists
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, dropTable);

/**
 * Adds a column to a table
 *
 * @param string $tableName
 * @param 	string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, addColumn);

/**
 * Modifies a table column based on a definition
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, modifyColumn);

/**
 * Drops a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, dropColumn);

/**
 * Adds an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, addIndex);

/**
 * Drop an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, dropIndex);

/**
 * Adds a primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, addPrimaryKey);

/**
 * Drops primary key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, dropPrimaryKey);

/**
 * Adds a foreign key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ReferenceInterface $reference
 * @return boolean true
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, addForeignKey);

/**
 * Drops a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return boolean true
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, dropForeignKey);

/**
 * Returns the SQL column definition from a column
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getColumnDefinition);

/**
 * List all tables on a database
 *
 * <code> print_r($connection->listTables("blog") ?></code>
 *
 * @param string $schemaName
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, listTables);

/**
 * Return descriptor used to connect to the active database
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getDescriptor);

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getConnectionId);

/**
 * Active SQL statement in the object
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLStatement);

/**
 * Active SQL statement in the object without replace bound paramters
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getRealSQLStatement);

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLVariables);

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLBindTypes);

/**
 * Returns type of database system the adapter is used for
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getType);

/**
 * Returns the name of the dialect used
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getDialectType);

/**
 * Returns internal dialect instance
 *
 * @return Phalcon\Db\DialectInterface
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getDialect);

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection
 *
 * @param 	array $descriptor
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, connect);

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server return rows
 *
 * @param  string $sqlStatement
 * @param  array $placeholders
 * @param  array $dataTypes
 * @return Phalcon\Db\ResultInterface
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, query);

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server don't return any row
 *
 * @param  string $sqlStatement
 * @param  array $placeholders
 * @param  array $dataTypes
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, execute);

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, affectedRows);

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, close);

/**
 * Escapes a value to avoid SQL injections
 *
 * @param string $str
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, escapeString);

/**
 * Bind params to a SQL statement
 *
 * @param string $sql
 * @param array $params
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, bindParams);

/**
 * Converts bound params like :name: or ?1 into ? bind params
 *
 * @param string $sql
 * @param array $params
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, convertBoundParams);

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string $sequenceName
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, lastInsertId);

/**
 * Starts a transaction in the connection
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, begin);

/**
 * Rollbacks the active transaction in the connection
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, rollback);

/**
 * Commits the active transaction in the connection
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, commit);

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, isUnderTransaction);

/**
 * Return internal PDO handler
 *
 * @return \PDO
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getInternalHandler);

/**
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\IndexInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, describeIndexes);

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\ReferenceInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, describeReferences);

/**
 * Gets creation options from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, tableOptions);

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Phalcon\Db\RawValue
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, getDefaultIdValue);

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, supportSequences);

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\ColumnInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Db_AdapterInterface, describeColumns);

