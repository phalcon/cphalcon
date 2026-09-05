
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Db;

use Phalcon\Db\ColumnInterface;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\ReferenceInterface;

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
interface Dialect
{
    /**
     * No row-lock modifier - the default behavior for `forUpdate()`.
     *
     * @var string
     */
    const LOCK_NONE = "";

    /**
     * Append `NOWAIT` to the `FOR UPDATE` clause - the query fails immediately
     * if a row it needs is locked instead of blocking. MySQL 8.0+ and
     * PostgreSQL 9.5+ recognize this. SQLite has no row-level locking and
     * silently ignores the modifier.
     *
     * @var string
     */
    const LOCK_NOWAIT = "NOWAIT";

    /**
     * Append `SKIP LOCKED` to the `FOR UPDATE` clause - the query returns
     * rows that are not currently locked and silently skips ones that are.
     * MySQL 8.0+ and PostgreSQL 9.5+ recognize this. SQLite ignores it.
     *
     * @var string
     */
    const LOCK_SKIP_LOCKED = "SKIP LOCKED";

    /**
     * Generates SQL to add a column to a table
     */
    public function addColumn(string tableName,  string schemaName, <ColumnInterface> column) -> string;

    /**
     * Generates SQL to add an index to a table
     */
    public function addForeignKey(string tableName,  string schemaName, <ReferenceInterface> reference) -> string;

    /**
     * Generates SQL to add an index to a table
     */
    public function addIndex(string tableName,  string schemaName, <IndexInterface> index) -> string;

    /**
     * Generates SQL to add the primary key to a table
     */
    public function addPrimaryKey(string tableName,  string schemaName, <IndexInterface> index) -> string;

    /**
     * Generate SQL to create a new savepoint
     */
    public function createSavepoint(string name) -> string;

    /**
     * Generates SQL to create a table
     *
     * @phpstan-param db_table_definition $definition
     */
    public function createTable(string tableName,  string schemaName,  array definition) -> string;

    /**
     * Generates SQL to create a view
     *
     * @phpstan-param db_view_definition $definition
     */
    public function createView(string viewName,  array definition, string schemaName = null) -> string;

    /**
     * Generates SQL to describe a table
     */
    public function describeColumns(string table, string schema = null) -> string;

    /**
     * Generates SQL to query indexes on a table.
     *
     * The base adapter consumes the result as `FETCH_NUM` rows by position:
     * column index 2 must be the index key name and column index 4 the indexed
     * column name.
     */
    public function describeIndexes(string table, string schema = null) -> string;

    /**
     * Generates SQL to query foreign keys on a table.
     *
     * The base adapter consumes the result as `FETCH_NUM` rows by position:
     * index 1 the local column, index 2 the constraint name, index 3 the
     * referenced schema, index 4 the referenced table, and index 5 the
     * referenced column.
     */
    public function describeReferences(string table, string schema = null) -> string;

    /**
     * Generates SQL to delete a column from a table
     */
    public function dropColumn(string tableName,  string schemaName,  string columnName) -> string;

    /**
     * Generates SQL to delete a foreign key from a table
     */
    public function dropForeignKey(string tableName,  string schemaName,  string referenceName) -> string;

    /**
      * Generates SQL to delete an index from a table
     */
    public function dropIndex(string tableName,  string schemaName,  string indexName) -> string;

    /**
     * Generates SQL to delete primary key from a table
     */
    public function dropPrimaryKey(string tableName,  string schemaName) -> string;

    /**
     * Generates SQL to drop a table. Every bundled dialect widens
     * `schemaName` to `string|null` and defaults it to null; widening the
     * contract itself is a next major change.
     */
    public function dropTable(string tableName,  string schemaName, bool ifExists = true) -> string;

    /**
     * Generates SQL to drop a view
     */
    public function dropView(string viewName, string schemaName = null,  bool ifExists = true) -> string;

    /**
     * Returns a SQL modified with a FOR UPDATE clause. The optional `modifier`
     * appends a row-lock disposition keyword - pass `Dialect::LOCK_NOWAIT`
     * or `Dialect::LOCK_SKIP_LOCKED` (or leave as `Dialect::LOCK_NONE`).
     */
    public function forUpdate(string sqlQuery, string modifier = "") -> string;

    /**
     * Gets the column name in RDBMS
     */
    public function getColumnDefinition(<ColumnInterface> column) -> string;

    /**
     * Gets a list of columns
     *
     * @phpstan-param db_column_list $columnList
     */
    public function getColumnList(array columnList) -> string;

    /**
     * Returns registered functions
     *
     * @phpstan-return db_custom_functions
     */
    public function getCustomFunctions() -> array;

    /**
     * Transforms an intermediate representation for an expression into a
     * database system valid expression
     *
     * @phpstan-param db_expression   $expression
     * @phpstan-param db_bind_counts  $bindCounts
     */
    public function getSqlExpression(array expression, string escapeChar = null,  array bindCounts = []) -> string;

    /**
     * Generates the SQL for LIMIT clause
     *
     * @phpstan-param db_limit_number $number
     */
    public function limit(string sqlQuery, var number) -> string;

    /**
     * List all tables in database
     */
    public function listTables(string schemaName = null) -> string;

    /**
     * Generates SQL to modify a column in a table
     */
    public function modifyColumn(
         string tableName,
         string schemaName,
        <ColumnInterface> column,
        <ColumnInterface> currentColumn = null
    ) -> string;

    /**
     * Registers custom SQL functions
     */
    public function registerCustomFunction(string name, callable customFunction) -> <\Phalcon\Db\Dialect>;

    /**
     * Generate SQL to release a savepoint
     */
    public function releaseSavepoint(string name) -> string;

    /**
     * Generate SQL to rollback a savepoint
     */
    public function rollbackSavepoint(string name) -> string;

    /**
     * Builds a SELECT statement
     *
     * @phpstan-param db_select_definition $definition
     */
    public function select(array definition) -> string;

    /**
     * Returns a SQL modified with a shared-lock clause. MySQL emits
     * `LOCK IN SHARE MODE`; PostgreSQL emits `FOR SHARE`; SQLite returns the
     * original query unchanged. The optional `modifier` appends a row-lock
     * disposition keyword (`Dialect::LOCK_NOWAIT` / `Dialect::LOCK_SKIP_LOCKED`)
     * for PostgreSQL - MySQL's legacy `LOCK IN SHARE MODE` does not support
     * modifiers, so non-empty values are silently ignored on MySQL.
     */
    public function sharedLock(string sqlQuery, string modifier = "") -> string;

    /**
     * Checks whether the platform supports releasing savepoints.
     */
    public function supportsReleaseSavepoints() -> bool;

    /**
     * Checks whether the platform supports savepoints
     */
    public function supportsSavepoints() -> bool;

    /**
     * Generates SQL checking for the existence of a schema.table
     */
    public function tableExists(string tableName, string schemaName = null) -> string;

    /**
     * Generates the SQL to describe the table creation options
     */
    public function tableOptions(string table, string schema = null) -> string;

    /**
     * Generates SQL checking for the existence of a schema.view
     */
    public function viewExists(string viewName, string schemaName = null) -> string;
}
