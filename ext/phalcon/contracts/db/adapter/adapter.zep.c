
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Canonical contract for Phalcon\Db adapters.
 *
 * @todo v7 — these will become required interface members. They are
 *            omitted from the v5 line to avoid breaking third-party
 *            implementors:
 *              - addCheck()                : bool
 *              - createMaterializedView()  : bool
 *              - dropCheck()               : bool
 *              - dropMaterializedView()    : bool
 *              - onConflictUpdate()        : string
 *              - refreshMaterializedView() : bool
 *              - returning()               : string
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Adapter_Adapter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db\\Adapter, Adapter, phalcon, contracts_db_adapter_adapter, phalcon_contracts_db_adapter_adapter_method_entry);

	return SUCCESS;
}

/**
 * Adds a column to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, addColumn);
/**
 * Adds an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, addIndex);
/**
 * Adds a foreign key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, addForeignKey);
/**
 * Adds a primary key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, addPrimaryKey);
/**
 * Returns the number of affected rows by the last INSERT/UPDATE/DELETE
 * reported by the database system
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, affectedRows);
/**
 * Starts a transaction in the connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, begin);
/**
 * Closes active connection returning success. Phalcon automatically closes
 * and destroys active connections within Phalcon\Db\Pool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, close);
/**
 * Commits the active transaction in the connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, commit);
/**
 * This method is automatically called in \Phalcon\Db\Adapter\Pdo
 * constructor. Call it when you need to restore a database connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, connect);
/**
 * Creates a new savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, createSavepoint);
/**
 * Creates a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, createTable);
/**
 * Creates a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, createView);
/**
 * Deletes data from a table using custom RDBMS SQL syntax
 *
 * @param array|string table
 * @param string|null whereCondition
 * @param array placeholders
 * @param array dataTypes
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, delete);
/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, describeColumns);
/**
 * Lists table indexes
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, describeIndexes);
/**
 * Lists table references
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, describeReferences);
/**
 * Drops a column from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, dropColumn);
/**
 * Drops a foreign key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, dropForeignKey);
/**
 * Drop an index from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, dropIndex);
/**
 * Drops primary key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, dropPrimaryKey);
/**
 * Drops a table from a schema/database
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, dropTable);
/**
 * Drops a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, dropView);
/**
 * Escapes a column/table/schema name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, escapeIdentifier);
/**
 * Escapes a value to avoid SQL injections
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, escapeString);
/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server does not
 * return any rows
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, execute);
/**
 * Dumps the complete result of a query into an array
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, fetchAll);
/**
 * Returns the n'th field of first row in a SQL query result
 *
 *```php
 * // Getting count of robots
 * $robotsCount = $connection->fetchColumn("SELECT COUNT(*) FROM robots");
 * print_r($robotsCount);
 *
 * // Getting name of last edited robot
 * $robot = $connection->fetchColumn(
 *     "SELECT id, name FROM robots ORDER BY modified DESC",
 *     1
 * );
 * print_r($robot);
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, fetchColumn);
/**
 * Returns the first row in a SQL query result
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, fetchOne);
/**
 * Returns a SQL modified with a FOR UPDATE clause. The optional `modifier`
 * appends a row-lock disposition keyword — pass `Dialect::LOCK_NOWAIT`
 * or `Dialect::LOCK_SKIP_LOCKED` (or leave as `Dialect::LOCK_NONE`).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, forUpdate);
/**
 * Returns the SQL column definition from a column
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getColumnDefinition);
/**
 * Gets a list of columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getColumnList);
/**
 * Gets the active connection unique identifier
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getConnectionId);
/**
 * Return descriptor used to connect to the active database
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getDescriptor);
/**
 * Returns internal dialect instance
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getDialect);
/**
 * Returns the name of the dialect used
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getDialectType);
/**
 * Return the default identity value to insert in an identity column
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getDefaultIdValue);
/**
 * Returns the default value to make the RBDM use the default value declared
 * in the table definition
 *
 *```php
 * // Inserting a new robot with a valid default value for the column 'year'
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         "Astro Boy",
 *         $connection->getDefaultValue()
 *     ],
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 *```
 *
 * @todo Return NULL if this is not supported by the adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getDefaultValue);
/**
 * Return internal PDO handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getInternalHandler);
/**
 * Returns the savepoint name to use for nested transactions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getNestedTransactionSavepointName);
/**
 * Active SQL statement in the object without replace bound parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getRealSQLStatement);
/**
 * Active SQL statement in the object
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getSQLStatement);
/**
 * Active SQL statement in the object
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getSQLBindTypes);
/**
 * Active SQL statement in the object
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getSQLVariables);
/**
 * Returns type of database system the adapter is used for
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, getType);
/**
 * Inserts data into a table using custom RDBMS SQL syntax
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, insert);
/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * ```php
 * // Inserting a new robot
 * $success = $connection->insertAsDict(
 *     "robots",
 *     [
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * // Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * ```
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, insertAsDict);
/**
 * Returns if nested transactions should use savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, isNestedTransactionsWithSavepoints);
/**
 * Checks whether connection is under database transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, isUnderTransaction);
/**
 * Returns insert id for the auto_increment column inserted in the last SQL
 * statement
 *
 * @param string|null $name Name of the sequence object from which the ID should be returned.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, lastInsertId);
/**
 * Appends a LIMIT clause to sqlQuery argument
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, limit);
/**
 * List all tables on a database
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, listTables);
/**
 * List all views on a database
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, listViews);
/**
 * Modifies a table column based on a definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, modifyColumn);
/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server returns
 * rows
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, query);
/**
 * Releases given savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, releaseSavepoint);
/**
 * Rollbacks the active transaction in the connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, rollback);
/**
 * Rollbacks given savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, rollbackSavepoint);
/**
 * Returns a SQL modified with a shared-lock clause. See the dialect's
 * `sharedLock()` for per-engine semantics. The optional `modifier` is
 * passed straight through (use `Dialect::LOCK_NOWAIT` /
 * `Dialect::LOCK_SKIP_LOCKED` for PostgreSQL).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, sharedLock);
/**
 * Set if nested transactions should use savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, setNestedTransactionsWithSavepoints);
/**
 * Check whether the database system requires a sequence to produce
 * auto-numeric values
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, supportSequences);
/**
 * Generates SQL checking for the existence of a schema.table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, tableExists);
/**
 * Gets creation options from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, tableOptions);
/**
 * Updates data on a table using custom RDBMS SQL syntax
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, update);
/**
 * Updates data on a table using custom RBDM SQL syntax
 * Another, more convenient syntax
 *
 * ```php
 * // Updating existing robot
 * $success = $connection->updateAsDict(
 *     "robots",
 *     [
 *         "name" => "New Astro Boy",
 *     ],
 *     "id = 101"
 * );
 *
 * // Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 * ```
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, updateAsDict);
/**
 * Check whether the database system requires an explicit value for identity
 * columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, useExplicitIdValue);
/**
 * SQLite does not support the DEFAULT keyword
 *
 * @deprecated Will re removed in the next version
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, supportsDefaultValue);
/**
 * Generates SQL checking for the existence of a schema.view
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Adapter_Adapter, viewExists);
