
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


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
/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Interface for Phalcon\Db adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, AdapterInterface, phalcon, db_adapterinterface, phalcon_db_adapterinterface_method_entry);


	return SUCCESS;

}

/**
 * Constructor for Phalcon\Db\Adapter
 *
 * @param array descriptor
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, __construct);

/**
 * Returns the first row in a SQL query result
 *
 * @param string sqlQuery
 * @param int fetchMode
 * @param int placeholders
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, fetchOne);

/**
 * Dumps the complete result of a query into an array
 *
 * @param string sqlQuery
 * @param int fetchMode
 * @param int placeholders
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, fetchAll);

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * @param 	string table
 * @param 	array values
 * @param 	array fields
 * @param 	array dataTypes
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, insert);

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * @param 	string table
 * @param 	array fields
 * @param 	array values
 * @param 	string whereCondition
 * @param 	array dataTypes
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, update);

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * @param  string table
 * @param  string whereCondition
 * @param  array placeholders
 * @param  array dataTypes
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, delete);

/**
 * Gets a list of columns
 *
 * @param	array columnList
 * @return	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getColumnList);

/**
 * Appends a LIMIT clause to sqlQuery argument
 *
 * @param  	string sqlQuery
 * @param 	int number
 * @return 	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, limit);

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * @param string tableName
 * @param string schemaName
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, tableExists);

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string viewName
 * @param string schemaName
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, viewExists);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param	string sqlQuery
 * @return	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param	string sqlQuery
 * @return	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, sharedLock);

/**
 * Creates a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	array definition
 * @return	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, createTable);

/**
 * Drops a table from a schema/database
 *
 * @param	string tableName
 * @param   string schemaName
 * @param	boolean ifExists
 * @return	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropTable);

/**
 * Creates a view
 *
 * @param	string tableName
 * @param	array definition
 * @param	string schemaName
 * @return	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, createView);

/**
 * Drops a view
 *
 * @param	string viewName
 * @param   string schemaName
 * @param	boolean ifExists
 * @return	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropView);

/**
 * Adds a column to a table
 *
 * @param	string tableName
 * @param 	string schemaName
 * @param	Phalcon\Db\ColumnInterface column
 * @return	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addColumn);

/**
 * Modifies a table column based on a definition
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ColumnInterface column
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, modifyColumn);

/**
 * Drops a column from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string columnName
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropColumn);

/**
 * Adds an index to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\IndexInterface index
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addIndex);

/**
 * Drop an index from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string indexName
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropIndex);

/**
 * Adds a primary key to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\IndexInterface index
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addPrimaryKey);

/**
 * Drops primary key from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropPrimaryKey);

/**
 * Adds a foreign key to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ReferenceInterface reference
 * @return	boolean true
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addForeignKey);

/**
 * Drops a foreign key from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string referenceName
 * @return	boolean true
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropForeignKey);

/**
 * Returns the SQL column definition from a column
 *
 * @param	Phalcon\Db\ColumnInterface column
 * @return	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getColumnDefinition);

/**
 * List all tables on a database
 *
 * @param string schemaName
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, listTables);

/**
 * List all views on a database
 *
 * @param string schemaName
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, listViews);

/**
 * Return descriptor used to connect to the active database
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getDescriptor);

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getConnectionId);

/**
 * Active SQL statement in the object
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLStatement);

/**
 * Active SQL statement in the object without replace bound paramters
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getRealSQLStatement);

/**
 * Active SQL statement in the object
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLVariables);

/**
 * Active SQL statement in the object
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLBindTypes);

/**
 * Returns type of database system the adapter is used for
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getType);

/**
 * Returns the name of the dialect used
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getDialectType);

/**
 * Returns internal dialect instance
 *
 * @return Phalcon\Db\DialectInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getDialect);

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection
 *
 * @param 	array descriptor
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, connect);

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server return rows
 *
 * @param  string sqlStatement
 * @param  array placeholders
 * @param  array dataTypes
 * @return Phalcon\Db\ResultInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, query);

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server don't return any row
 *
 * @param  string sqlStatement
 * @param  array placeholders
 * @param  array dataTypes
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, execute);

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, affectedRows);

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, close);

/**
 * Escapes a column/table/schema name
 *
 * @param string identifier
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, escapeIdentifier);

/**
 * Escapes a value to avoid SQL injections
 *
 * @param string str
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, escapeString);

/**
 * Converts bound params like :name: or ?1 into ? bind params
 *
 * @param string sqlStatement
 * @param array params
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, convertBoundParams);

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string sequenceName
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, lastInsertId);

/**
 * Starts a transaction in the connection
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, begin);

/**
 * Rollbacks the active transaction in the connection
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, rollback);

/**
 * Commits the active transaction in the connection
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, commit);

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, isUnderTransaction);

/**
 * Return internal PDO handler
 *
 * @return \PDO
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getInternalHandler);

/**
 * Lists table indexes
 *
 * @param	string table
 * @param	string schema
 * @return	Phalcon\Db\IndexInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, describeIndexes);

/**
 * Lists table references
 *
 * @param	string table
 * @param	string schema
 * @return	Phalcon\Db\ReferenceInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, describeReferences);

/**
 * Gets creation options from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @return	array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, tableOptions);

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, useExplicitIdValue);

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Phalcon\Db\RawValue
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getDefaultIdValue);

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, supportSequences);

/**
 * Creates a new savepoint
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, createSavepoint);

/**
 * Releases given savepoint
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, releaseSavepoint);

/**
 * Rollbacks given savepoint
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, rollbackSavepoint);

/**
 * Set if nested transactions should use savepoints
 *
 * @param boolean nestedTransactionsWithSavepoints
 * @return Phalcon\Db\AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, setNestedTransactionsWithSavepoints);

/**
 * Returns if nested transactions should use savepoints
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, isNestedTransactionsWithSavepoints);

/**
 * Returns the savepoint name to use for nested transactions
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getNestedTransactionSavepointName);

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * @param string table
 * @param string schema
 * @return Phalcon\Db\ColumnInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, describeColumns);

