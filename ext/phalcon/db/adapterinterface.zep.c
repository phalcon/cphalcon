
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, tableExists);

/**
 * Generates SQL checking for the existence of a schema.view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, viewExists);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, sharedLock);

/**
 * Creates a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, createTable);

/**
 * Drops a table from a schema/database
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropTable);

/**
 * Creates a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, createView);

/**
 * Drops a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropView);

/**
 * Adds a column to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addColumn);

/**
 * Modifies a table column based on a definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, modifyColumn);

/**
 * Drops a column from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropColumn);

/**
 * Adds an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addIndex);

/**
 * Drop an index from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropIndex);

/**
 * Adds a primary key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addPrimaryKey);

/**
 * Drops primary key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropPrimaryKey);

/**
 * Adds a foreign key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, addForeignKey);

/**
 * Drops a foreign key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, dropForeignKey);

/**
 * Returns the SQL column definition from a column
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getColumnDefinition);

/**
 * List all tables on a database
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, listTables);

/**
 * List all views on a database
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getSQLStatement);

/**
 * Active SQL statement in the object without replace bound paramters
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, query);

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server doesn't return any rows	 
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, execute);

/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE reported by the database system
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, affectedRows);

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon\Db\Pool
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, escapeString);

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string sequenceName
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, lastInsertId);

/**
 * Starts a transaction in the connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, begin);

/**
 * Rollbacks the active transaction in the connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, rollback);

/**
 * Commits the active transaction in the connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, commit);

/**
 * Checks whether connection is under database transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, isUnderTransaction);

/**
 * Return internal PDO handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getInternalHandler);

/**
 * Lists table indexes
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, describeIndexes);

/**
 * Lists table references
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, describeReferences);

/**
 * Gets creation options from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, tableOptions);

/**
 * Check whether the database system requires an explicit value for identity columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, useExplicitIdValue);

/**
 * Return the default identity value to insert in an identity column
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getDefaultIdValue);

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, supportSequences);

/**
 * Creates a new savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, createSavepoint);

/**
 * Releases given savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, releaseSavepoint);

/**
 * Rollbacks given savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, rollbackSavepoint);

/**
 * Set if nested transactions should use savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, setNestedTransactionsWithSavepoints);

/**
 * Returns if nested transactions should use savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, isNestedTransactionsWithSavepoints);

/**
 * Returns the savepoint name to use for nested transactions
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, getNestedTransactionSavepointName);

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_AdapterInterface, describeColumns);

