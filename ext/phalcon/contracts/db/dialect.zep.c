
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Canonical contract for Phalcon\Db dialects.
 *
 * @phpstan-import-type db_bind_counts from DbTypes
 * @phpstan-import-type db_column_list from DbTypes
 * @phpstan-import-type db_column_names from DbTypes
 * @phpstan-import-type db_custom_functions from DbTypes
 * @phpstan-import-type db_expression from DbTypes
 * @phpstan-import-type db_limit_number from DbTypes
 * @phpstan-import-type db_select_definition from DbTypes
 * @phpstan-import-type db_table_definition from DbTypes
 * @phpstan-import-type db_view_definition from DbTypes
 *
 * @todo v7 - these will become required interface members. They are
 *            omitted from the v5 line to avoid breaking third-party
 *            implementors:
 *              - addCheck()                : string
 *              - createMaterializedView()  : string
 *              - dropCheck()               : string
 *              - dropMaterializedView()    : string
 *              - escape()                  : string
 *              - escapeSchema()            : string
 *              - listViews()               : string
 *              - onConflictUpdate()        : string
 *              - refreshMaterializedView() : string
 *              - returning()               : string
 *
 * The adapters call the members above on the interface. They join the
 * interface in the next major; until then the tags below record what all
 * implementations provide.
 *
 * @method string addCheck(string $tableName, string $schemaName, \Phalcon\Db\CheckInterface $check)
 * @method string createMaterializedView(string $view, db_view_definition $definition, string|null $schema = null)
 * @method string dropCheck(string $tableName, string $schemaName, string $checkName)
 * @method string dropMaterializedView(string $viewName, string|null $schemaName = null, bool $ifExists = true)
 * @method string escape(string $input, string $escapeChar = '')
 * @method string escapeSchema(string $input, string $escapeChar = '')
 * @method string listViews(string|null $schemaName = null)
 * @method string onConflictUpdate(string $sqlQuery, db_column_names $conflictColumns, db_column_names $updateColumns)
 * @method string refreshMaterializedView(string $viewName, string|null $schemaName = null, bool $concurrent = false)
 * @method string returning(string $sqlQuery, db_column_names $columns)
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Dialect)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db, Dialect, phalcon, contracts_db_dialect, phalcon_contracts_db_dialect_method_entry);

	/**
	 * No row-lock modifier - the default behavior for `forUpdate()`.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_db_dialect_ce, SL("LOCK_NONE"), "");

	/**
	 * Append `NOWAIT` to the `FOR UPDATE` clause - the query fails immediately
	 * if a row it needs is locked instead of blocking. MySQL 8.0+ and
	 * PostgreSQL 9.5+ recognize this. SQLite has no row-level locking and
	 * silently ignores the modifier.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_db_dialect_ce, SL("LOCK_NOWAIT"), "NOWAIT");

	/**
	 * Append `SKIP LOCKED` to the `FOR UPDATE` clause - the query returns
	 * rows that are not currently locked and silently skips ones that are.
	 * MySQL 8.0+ and PostgreSQL 9.5+ recognize this. SQLite ignores it.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_db_dialect_ce, SL("LOCK_SKIP_LOCKED"), "SKIP LOCKED");

	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, addColumn);
/**
 * Generates SQL to add an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, addForeignKey);
/**
 * Generates SQL to add an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, addIndex);
/**
 * Generates SQL to add the primary key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, addPrimaryKey);
/**
 * Generate SQL to create a new savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, createSavepoint);
/**
 * Generates SQL to create a table
 *
 * @phpstan-param db_table_definition $definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, createTable);
/**
 * Generates SQL to create a view
 *
 * @phpstan-param db_view_definition $definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, createView);
/**
 * Generates SQL to describe a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, describeColumns);
/**
 * Generates SQL to query indexes on a table.
 *
 * The base adapter consumes the result as `FETCH_NUM` rows by position:
 * column index 2 must be the index key name and column index 4 the indexed
 * column name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, describeIndexes);
/**
 * Generates SQL to query foreign keys on a table.
 *
 * The base adapter consumes the result as `FETCH_NUM` rows by position:
 * index 1 the local column, index 2 the constraint name, index 3 the
 * referenced schema, index 4 the referenced table, and index 5 the
 * referenced column.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, describeReferences);
/**
 * Generates SQL to delete a column from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, dropColumn);
/**
 * Generates SQL to delete a foreign key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, dropForeignKey);
/**
 * Generates SQL to delete an index from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, dropIndex);
/**
 * Generates SQL to delete primary key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, dropPrimaryKey);
/**
 * Generates SQL to drop a table. Every bundled dialect widens
 * `schemaName` to `string|null` and defaults it to null; widening the
 * contract itself is a next major change.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, dropTable);
/**
 * Generates SQL to drop a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, dropView);
/**
 * Returns a SQL modified with a FOR UPDATE clause. The optional `modifier`
 * appends a row-lock disposition keyword - pass `Dialect::LOCK_NOWAIT`
 * or `Dialect::LOCK_SKIP_LOCKED` (or leave as `Dialect::LOCK_NONE`).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, forUpdate);
/**
 * Gets the column name in RDBMS
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, getColumnDefinition);
/**
 * Gets a list of columns
 *
 * @phpstan-param db_column_list $columnList
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, getColumnList);
/**
 * Returns registered functions
 *
 * @phpstan-return db_custom_functions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, getCustomFunctions);
/**
 * Transforms an intermediate representation for an expression into a
 * database system valid expression
 *
 * @phpstan-param db_expression   $expression
 * @phpstan-param db_bind_counts  $bindCounts
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, getSqlExpression);
/**
 * Generates the SQL for LIMIT clause
 *
 * @phpstan-param db_limit_number $number
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, limit);
/**
 * List all tables in database
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, listTables);
/**
 * Generates SQL to modify a column in a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, modifyColumn);
/**
 * Registers custom SQL functions
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, registerCustomFunction);
/**
 * Generate SQL to release a savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, releaseSavepoint);
/**
 * Generate SQL to rollback a savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, rollbackSavepoint);
/**
 * Builds a SELECT statement
 *
 * @phpstan-param db_select_definition $definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, select);
/**
 * Returns a SQL modified with a shared-lock clause. MySQL emits
 * `LOCK IN SHARE MODE`; PostgreSQL emits `FOR SHARE`; SQLite returns the
 * original query unchanged. The optional `modifier` appends a row-lock
 * disposition keyword (`Dialect::LOCK_NOWAIT` / `Dialect::LOCK_SKIP_LOCKED`)
 * for PostgreSQL - MySQL's legacy `LOCK IN SHARE MODE` does not support
 * modifiers, so non-empty values are silently ignored on MySQL.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, sharedLock);
/**
 * Checks whether the platform supports releasing savepoints.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, supportsReleaseSavepoints);
/**
 * Checks whether the platform supports savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, supportsSavepoints);
/**
 * Generates SQL checking for the existence of a schema.table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, tableExists);
/**
 * Generates the SQL to describe the table creation options
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, tableOptions);
/**
 * Generates SQL checking for the existence of a schema.view
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Dialect, viewExists);
