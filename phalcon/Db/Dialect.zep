
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Db\Exceptions\ConflictTargetColumnRequired;
use Phalcon\Db\Exceptions\ConflictUpdateColumnRequired;
use Phalcon\Db\Exceptions\InvalidGroupByExpression;
use Phalcon\Db\Exceptions\InvalidListExpression;
use Phalcon\Db\Exceptions\InvalidOrderByExpression;
use Phalcon\Db\Exceptions\InvalidSqlExpression;
use Phalcon\Db\Exceptions\InvalidSqlExpressionType;
use Phalcon\Db\Exceptions\InvalidUnaryExpression;
use Phalcon\Db\Exceptions\MaterializedViewsNotSupported;
use Phalcon\Db\Exceptions\MissingDefinitionKey;
use Phalcon\Db\Exceptions\ReturningNotSupported;
use Phalcon\Db\Exceptions\UnsupportedOperator;
use Phalcon\Support\Settings;

/**
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBMS related syntax
 */
abstract class Dialect implements DialectInterface
{
    /**
     * @var string
     */
    protected escapeChar;

    /**
     * @var array
     */
    protected customFunctions = [];

    /**
     * Dialect-specific operators that a concrete dialect must opt into
     * via supportedOperators; using one elsewhere throws.
     *
     * @var array
     */
    protected guardedOperators = ["@@", "@>", "<@", "&&", "||", "->", "->>", "#>", "#>>"];

    /**
     * Subset of guardedOperators that this dialect emits. Overridden per
     * dialect.
     *
     * @var array
     */
    protected supportedOperators = [];

    /**
     * Generate SQL to create a new savepoint
     */
    public function createSavepoint(string! name) -> string
    {
        return "SAVEPOINT " . name;
    }

    /**
     * Escape identifiers
     */
    final public function escape(string! str, string escapeChar = null) -> string
    {
        var parts, key, part, newParts;

        if !Settings::get("db.escape_identifiers") {
            return str;
        }

        if empty escapeChar {
            let escapeChar = (string) this->escapeChar;
        }

        if !memstr(str, ".") {
            if escapeChar != "" && str != "*" {
                return escapeChar . str_replace(escapeChar, escapeChar . escapeChar, str) . escapeChar;
            }

            return str;
        }

        let parts = (array) explode(".", trim(str, escapeChar));

        let newParts = parts;

        for key, part in parts {
            if escapeChar == "" || part == "" || part == "*" {
                continue;
            }

            let newParts[key] = escapeChar . str_replace(escapeChar, escapeChar . escapeChar, part) . escapeChar;
        }

        return implode(".", newParts);
    }

    /**
     * Escape Schema
     */
    final public function escapeSchema(string! str, string escapeChar = null) -> string
    {
        if !Settings::get("db.escape_identifiers") {
            return str;
        }

        if escapeChar == "" {
            let escapeChar = (string) this->escapeChar;
        }

        return escapeChar . trim(str, escapeChar) . escapeChar;
    }

    /**
     * Returns a SQL modified with a FOR UPDATE clause. The optional `modifier`
     * appends a row-lock disposition keyword.
     *
     *```php
     * $sql = $dialect->forUpdate("SELECT * FROM robots");
     * echo $sql; // SELECT * FROM robots FOR UPDATE
     *
     * $sql = $dialect->forUpdate(
     *     "SELECT * FROM robots",
     *     Dialect::LOCK_NOWAIT
     * );
     * echo $sql; // SELECT * FROM robots FOR UPDATE NOWAIT
     *
     * $sql = $dialect->forUpdate(
     *     "SELECT * FROM robots",
     *     Dialect::LOCK_SKIP_LOCKED
     * );
     * echo $sql; // SELECT * FROM robots FOR UPDATE SKIP LOCKED
     *```
     */
    public function forUpdate(string! sqlQuery, string modifier = "") -> string
    {
        if modifier !== "" {
            return sqlQuery . " FOR UPDATE " . modifier;
        }

        return sqlQuery . " FOR UPDATE";
    }

    /**
     * Gets a list of columns with escaped identifiers
     *
     * ```php
     * echo $dialect->getColumnList(
     *     [
     *         "column1",
     *         "column",
     *     ]
     * );
     * ```
     */
    final public function getColumnList(array! columnList, string escapeChar = null, array! bindCounts = []) -> string
    {
        var column;
        array columns;

        let columns = [];

        for column in columnList {
            let columns[] = this->getSqlColumn(column, escapeChar, bindCounts);
        }

        return join(", ", columns);
    }

    /**
     * Returns registered functions
     */
    public function getCustomFunctions() -> array
    {
        return this->customFunctions;
    }

    /**
     * Resolve Column expressions
     *
     * @param array|string column
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final public function getSqlColumn(var column, string escapeChar = null, array! bindCounts = []) -> string
    {
        var columnExpression, columnAlias, columnField, columnDomain;

        if typeof column !== "array" {
            return this->prepareQualified(column, null, escapeChar);
        }

        if !isset column["type"] {
            /**
             * The index "0" is the column field
             */
            let columnField = column[0];

            if typeof columnField === "array" {
                let columnExpression = [
                    "type": "scalar",
                    "value": columnField
                ];
            } elseif columnField === "*" {
                let columnExpression = [
                    "type": "all"
                ];
            } else {
                let columnExpression = [
                    "type": "qualified",
                    "name": columnField
                ];
            }

            /**
             * The index "1" is the domain column
             */
            if fetch columnDomain, column[1] && columnDomain !== "" {
                let columnExpression["domain"] = columnDomain;
            }

            /**
             * The index "2" is the column alias
             */
            if fetch columnAlias, column[2] && columnAlias {
                let columnExpression["sqlAlias"] = columnAlias;
            }
        } else {
            let columnExpression = column;
        }

        /**
         * Resolve column expressions
         */
        let column = this->getSqlExpression(
            columnExpression,
            escapeChar,
            bindCounts
        );

        /**
         * Escape alias and concatenate to value SQL
         */
        if fetch columnAlias, columnExpression["sqlAlias"] || fetch columnAlias, columnExpression["alias"] {
            return this->prepareColumnAlias(column, columnAlias, escapeChar);
        }

        return this->prepareColumnAlias(column, null, escapeChar);
    }

    /**
     * Transforms an intermediate representation for an expression into a database system valid expression
     */
    public function getSqlExpression(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        int i;
        var type, times, postTimes, rawValue, value, nestedDefinition;
        array placeholders;

        if unlikely !fetch type, expression["type"] {
            throw new InvalidSqlExpression();
        }

        switch type {
            /**
             * Resolve scalar column expressions
             */
            case "scalar":
                return this->getSqlExpressionScalar(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve object expressions
             */
            case "object":
                return this->getSqlExpressionObject(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve qualified expressions
             */
            case "qualified":
                return this->getSqlExpressionQualified(expression, escapeChar);

            /**
             * Resolve literal OR placeholder expressions
             */
            case "literal":
                return expression["value"];

            case "placeholder":
                if fetch times, expression["times"] {

                    let placeholders = [],
                        rawValue = expression["rawValue"],
                        value = expression["value"];

                    if fetch postTimes, bindCounts[rawValue] {
                        let times = postTimes;
                    }

                    for i in range(1, times) {
                        let placeholders[] = value . (i - 1);
                    }

                    return join(", ", placeholders);
                }

                return expression["value"];

            /**
             * Resolve binary operations expressions
             */
            case "binary-op":
                return this->getSqlExpressionBinaryOperations(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve unary operations expressions
             */
            case "unary-op":
                return this->getSqlExpressionUnaryOperations(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve parentheses
             */
            case "parentheses":
                return "(" . this->getSqlExpression(expression["left"], escapeChar, bindCounts) . ")";

            /**
             * Resolve function calls
             */
            case "functionCall":
                return this->getSqlExpressionFunctionCall(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve lists
             */
            case "list":
                return this->getSqlExpressionList(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve *
             */
            case "all":
                return this->getSqlExpressionAll(expression, escapeChar);

            /**
             * Resolve SELECT
             *
             * Propagate the outer bindCounts into the nested SELECT
             * definition so that array placeholders inside a sub-select
             * are re-expanded against the current bind values instead of
             * the parse-time `times` baked into the cached irPhql. The
             * local copy avoids mutating the cached intermediate. See
             * issue #17004.
             */
            case "select":
                let nestedDefinition = expression["value"];
                if count(bindCounts) {
                    let nestedDefinition["bindCounts"] = bindCounts;
                }
                return "(" . this->select(nestedDefinition) . ")";

            /**
             * Resolve CAST of values
             */
            case "cast":
                return this->getSqlExpressionCastValue(
                    expression,
                    escapeChar,
                    bindCounts
                );

            /**
             * Resolve CONVERT of values encodings
             */
            case "convert":
                return this->getSqlExpressionConvertValue(
                    expression,
                    escapeChar,
                    bindCounts
                );

            case "case":
                return this->getSqlExpressionCase(
                    expression,
                    escapeChar,
                    bindCounts
                );
        }

        /**
         * Expression type wasn't found
         */
        throw new InvalidSqlExpressionType(type);
    }

    /**
     * Transform an intermediate representation of a schema/table into a
     * database system valid expression
     */
    final public function getSqlTable(var table, string escapeChar = null) -> string
    {
        var tableName, schemaName, aliasName;

        if typeof table == "array" {

            /**
             * The index "0" is the table name
             */
            let tableName = table[0];

            /**
             * The index "1" is the schema name
             */
            fetch schemaName, table[1];

            /**
             * The index "2" is the table alias
             */
            fetch aliasName, table[2];

            return this->prepareTable(
                tableName,
                schemaName,
                aliasName,
                escapeChar
            );
        }

        return this->escape(table, escapeChar);
    }

    /**
     * Generates the SQL for LIMIT clause
     *
     * ```php
     * // SELECT * FROM robots LIMIT 10
     * echo $dialect->limit(
     *     "SELECT * FROM robots",
     *     10
     * );
     *
     * // SELECT * FROM robots LIMIT 10 OFFSET 50
     * echo $dialect->limit(
     *     "SELECT * FROM robots",
     *     [10, 50]
     * );
     * ```
     */
    public function limit(string! sqlQuery, var number) -> string
    {
        if typeof number == "array" {
            let sqlQuery .= " LIMIT " . number[0];

            if isset number[1] && strlen(number[1]) {
                let sqlQuery .= " OFFSET " . number[1];
            }

            return sqlQuery;
        }

        return sqlQuery . " LIMIT " . number;
    }

    /**
     * Registers custom SQL functions
     */
    public function registerCustomFunction(string name, callable customFunction) -> <static>
    {
        let this->customFunctions[name] = customFunction;

        return this;
    }

    /**
     * Generates SQL to create a materialized view. Supported by PostgreSQL
     * (`CREATE MATERIALIZED VIEW name AS <sql>`). Other dialects inherit
     * this throw - MySQL and SQLite have no materialized-view concept.
     */
    public function createMaterializedView(string! viewName, array! definition, string schemaName = null) -> string
    {
        throw new MaterializedViewsNotSupported();
    }

    /**
     * Generates SQL to drop a materialized view. Supported by PostgreSQL.
     */
    public function dropMaterializedView(string! viewName, string schemaName = null, bool ifExists = true) -> string
    {
        throw new MaterializedViewsNotSupported();
    }

    /**
     * Generates SQL to refresh a materialized view. Supported by
     * PostgreSQL. Pass `concurrent = true` for `REFRESH MATERIALIZED VIEW
     * CONCURRENTLY ...`, which avoids blocking concurrent SELECTs (requires
     * the view to have a unique index).
     */
    public function refreshMaterializedView(string! viewName, string schemaName = null, bool concurrent = false) -> string
    {
        throw new MaterializedViewsNotSupported();
    }

    /**
     * Appends an `ON CONFLICT (col, ...) DO UPDATE SET col = excluded.col`
     * upsert clause to the supplied INSERT statement. The syntax is the
     * SQL standard form recognized by PostgreSQL (9.5+) and SQLite (3.24+).
     * MySQL overrides this method to throw because its `ON DUPLICATE KEY
     * UPDATE` has a different shape (deferred to parser item #23).
     */
    public function onConflictUpdate(string! sqlQuery, array! conflictColumns, array! updateColumns) -> string
    {
        var col;
        array assignments;

        if unlikely empty conflictColumns {
            throw new ConflictTargetColumnRequired();
        }

        if unlikely empty updateColumns {
            throw new ConflictUpdateColumnRequired();
        }

        let assignments = [];
        for col in updateColumns {
            let assignments[] = this->escape((string) col)
                . " = excluded." . this->escape((string) col);
        }

        return sqlQuery
            . " ON CONFLICT (" . this->getColumnList(conflictColumns) . ")"
            . " DO UPDATE SET " . implode(", ", assignments);
    }

    /**
     * Returns a SQL statement extended with a `RETURNING` clause so the
     * INSERT/UPDATE/DELETE returns rows. Supported by PostgreSQL and
     * SQLite 3.35+. Pass `["*"]` for `RETURNING *`, or a list of column
     * names. The base implementation throws - MySQL inherits it because
     * MySQL has no RETURNING construct.
     */
    public function returning(string! sqlQuery, array! columns) -> string
    {
        throw new ReturningNotSupported();
    }

    /**
     * Generate SQL to release a savepoint
     */
    public function releaseSavepoint(string! name) -> string
    {
        return "RELEASE SAVEPOINT " . name;
    }

    /**
     * Generate SQL to rollback a savepoint
     */
    public function rollbackSavepoint(string! name) -> string
    {
        return "ROLLBACK TO SAVEPOINT " . name;
    }

    /**
     * Builds a SELECT statement
     */
    public function select(array! definition) -> string
    {
        var tables, columns, sql, distinct, joins, where, escapeChar, groupBy,
            having, orderBy, limit, forUpdate, bindCounts;
        array parts;

        if unlikely !fetch tables, definition["tables"] {
            throw new MissingDefinitionKey("tables");
        }

        if unlikely !fetch columns, definition["columns"] {
            throw new MissingDefinitionKey("columns");
        }

        if fetch distinct, definition["distinct"] {
            if distinct {
                let sql = "SELECT DISTINCT";
            } else {
                let sql = "SELECT ALL";
            }
        } else {
            let sql = "SELECT";
        }

        fetch bindCounts, definition["bindCounts"];
        if typeof bindCounts !== "array" {
            let bindCounts = [];
        }

        let escapeChar = this->escapeChar;

        /**
         * Accumulate the top-level clauses in an array and join once.
         * Each segment is appended without a leading space; implode adds
         * the separator. The conditional LIMIT / FOR UPDATE tails are
         * handled after the join because LIMIT wraps the assembled SQL.
         */
        let parts = [
            sql,
            this->getColumnList(columns, escapeChar, bindCounts),
            this->getSqlExpressionFrom(tables, escapeChar)
        ];

        if fetch joins, definition["joins"] && joins {
            let parts[] = this->getSqlExpressionJoins(definition["joins"], escapeChar, bindCounts);
        }

        if fetch where, definition["where"] && where {
            let parts[] = this->getSqlExpressionWhere(where, escapeChar, bindCounts);
        }

        if fetch groupBy, definition["group"] && groupBy {
            let parts[] = this->getSqlExpressionGroupBy(groupBy, escapeChar);
        }

        if fetch having, definition["having"] && having {
            let parts[] = this->getSqlExpressionHaving(having, escapeChar, bindCounts);
        }

        if fetch orderBy, definition["order"] && orderBy {
            let parts[] = this->getSqlExpressionOrderBy(orderBy, escapeChar, bindCounts);
        }

        let sql = implode(" ", parts);

        /**
         * Resolve LIMIT
         */
        if fetch limit, definition["limit"] && limit {
            let sql = this->getSqlExpressionLimit(
                [
                    "sql":   sql,
                    "value": limit
                ],
                escapeChar,
                bindCounts
            );
        }

        /**
         * Resolve FOR UPDATE
         */
        if fetch forUpdate, definition["forUpdate"] && forUpdate {
            let sql .= " FOR UPDATE";
        }

        return sql;
    }

    /**
     * Checks whether the platform supports savepoints
     */
    public function supportsSavepoints() -> bool
    {
        return true;
    }

    /**
     * Checks whether the platform supports releasing savepoints.
     */
    public function supportsReleaseSavepoints() -> bool
    {
        return this->supportsSavePoints();
    }

    /**
     * Checks whether the platform supports the full `ALTER TABLE` matrix:
     * modifying existing columns and adding or dropping foreign keys, primary
     * keys, and check constraints. SQLite returns false - those operations
     * throw a dedicated `Sqlite*NotSupported` exception there (basic
     * `ADD COLUMN` remains available).
     */
    public function supportsAlterTable() -> bool
    {
        return true;
    }

    /**
     * Checks whether the platform supports materialized views. Only PostgreSQL
     * returns true; `createMaterializedView()` throws on the other dialects.
     */
    public function supportsMaterializedViews() -> bool
    {
        return false;
    }

    /**
     * Checks whether the platform supports the `ON CONFLICT (...) DO UPDATE`
     * upsert clause. MySQL returns false; `onConflictUpdate()` throws there.
     */
    public function supportsOnConflictUpdate() -> bool
    {
        return true;
    }

    /**
     * Checks whether the platform supports the `RETURNING` clause. MySQL
     * returns false; `returning()` throws there.
     */
    public function supportsReturning() -> bool
    {
        return false;
    }

    /**
     * Returns the size of the column enclosed in parentheses
     */
    protected function getColumnSize(<ColumnInterface> column) -> string
    {
        return "(" . column->getSize() . ")";
    }

    /**
     * Returns the column size and scale enclosed in parentheses
     */
    protected function getColumnSizeAndScale(<ColumnInterface> column) -> string
    {
        return "(" . column->getSize() . "," . column->getScale() . ")";
    }

    /**
     * Checks the column type and if not string it returns the type reference
     */
    protected function checkColumnType(<ColumnInterface> column) -> string
    {
        if typeof column->getType() == "string" {
            return column->getTypeReference();
        }

        return column->getType();
    }

    /**
     * Checks the column type and returns the updated SQL statement
     */
    protected function checkColumnTypeSql(<ColumnInterface> column) -> string
    {
        if typeof column->getType() != "string" {
            return "";
        }

        return column->getType();
    }

    /**
     * Builds a CHECK constraint clause from a `CheckInterface`, using the
     * provided escape character for the constraint name (so each dialect
     * gets its native quoting). Returns the clause body - the dialect's
     * `createTable()` / `addCheck()` is expected to prefix `ADD` or place
     * the result on its own line as appropriate.
     */
    protected function getCheckClause(<CheckInterface> check, string escapeChar = "`") -> string
    {
        var name;
        string clause;

        let name = check->getName();

        let clause = "";
        if name !== "" {
            let clause = "CONSTRAINT " . escapeChar . name . escapeChar . " ";
        }

        let clause .= "CHECK (" . check->getExpression() . ")";

        return clause;
    }

    /**
     * Builds the per-index parenthesized column list, honoring per-column
     * sort directions when the index declares any. Returns the bare
     * comma-separated `getColumnList()` output when no directions are set,
     * preserving the legacy rendering exactly. When directions are set,
     * each column is followed by ` ASC` or ` DESC`; trailing positions
     * absent from the directions array default to `ASC`.
     */
    protected function getIndexColumnList(<IndexInterface> index, bool wrapExpressions = true) -> string
    {
        var columns, directions, parts, i, column, direction, upper, rendered;
        bool hasExpression;

        let columns       = index->getColumns();
        let directions    = index->getDirections();
        let hasExpression = false;

        for column in columns {
            if typeof column == "object" && column instanceof RawValue {
                let hasExpression = true;
                break;
            }
        }

        /**
         * Fast path: no expressions and no directions - return the legacy
         * `getColumnList()` rendering verbatim so existing tests and call
         * sites see no diff.
         */
        if !hasExpression && empty directions {
            return this->getColumnList(columns);
        }

        let parts = [],
            i     = 0;

        for column in columns {
            if typeof column == "object" && column instanceof RawValue {
                if wrapExpressions {
                    let rendered = "(" . column->getValue() . ")";
                } else {
                    let rendered = column->getValue();
                }
            } else {
                let rendered = this->escape(column);
            }

            if !empty directions {
                if fetch direction, directions[i] {
                    let upper = strtoupper((string) direction);

                    if upper == "DESC" {
                        let rendered .= " DESC";
                    } else {
                        let rendered .= " ASC";
                    }
                } else {
                    let rendered .= " ASC";
                }
            }

            let parts[] = rendered;
            let i      = i + 1;
        }

        return implode(", ", parts);
    }

    /**
     * Builds the `GENERATED ALWAYS AS (<expr>) VIRTUAL|STORED` clause for a
     * generated/computed column. Returns an empty string when the column is
     * not generated. When `forceStored` is `true` the clause is always emitted
     * as `STORED` regardless of the column's `isGenerationStored()` flag -
     * PostgreSQL uses this since it only supports stored generated columns.
     */
    protected function getGeneratedClause(<ColumnInterface> column, bool forceStored = false) -> string
    {
        var expression;
        string storage;

        if !column->isGenerated() {
            return "";
        }

        let expression = column->getGenerationExpression();

        if forceStored || column->isGenerationStored() {
            let storage = "STORED";
        } else {
            let storage = "VIRTUAL";
        }

        return " GENERATED ALWAYS AS (" . expression . ") " . storage;
    }

    /**
     * Resolve *
     */
    final protected function getSqlExpressionAll(array! expression, string escapeChar = null) -> string
    {
        var domain;

        fetch domain, expression["domain"];

        return this->prepareQualified("*", domain, escapeChar);
    }

    /**
     * Resolve binary operations expressions
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionBinaryOperations(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var left, right, operator;

        let operator = expression["op"];

        if in_array(operator, this->guardedOperators) && !in_array(operator, this->supportedOperators) {
            throw new UnsupportedOperator(operator);
        }

        let left  = this->getSqlExpression(
            expression["left"],
            escapeChar,
            bindCounts
        );

        let right = this->getSqlExpression(
            expression["right"],
            escapeChar,
            bindCounts
        );

        return left . " " . operator . " " . right;
    }

    /**
     * Resolve CASE expressions
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionCase(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var whenClause, whenClauses;
        string sql;

        let sql = "CASE " . this->getSqlExpression(expression["expr"], escapeChar, bindCounts);

        let whenClauses = array_values(expression["when-clauses"]);

        for whenClause in whenClauses {
            if whenClause["type"] == "when" {
                let sql .= " WHEN " .
                        this->getSqlExpression(whenClause["expr"], escapeChar, bindCounts) .
                        " THEN " .
                        this->getSqlExpression(whenClause["then"], escapeChar, bindCounts);
            } else {
                let sql .= " ELSE " . this->getSqlExpression(whenClause["expr"], escapeChar, bindCounts);
            }
        }

        return sql . " END";
    }

    /**
     * Resolve CAST of values
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionCastValue(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var left, right;

        let left  = this->getSqlExpression(
            expression["left"],
            escapeChar,
            bindCounts
        );

        let right = this->getSqlExpression(
            expression["right"],
            escapeChar,
            bindCounts
        );

        return "CAST(" . left . " AS " . right . ")";
    }

    /**
     * Resolve CONVERT of values encodings
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionConvertValue(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var left, right;

        let left  = this->getSqlExpression(
            expression["left"],
            escapeChar,
            bindCounts
        );

        let right = this->getSqlExpression(
            expression["right"],
            escapeChar,
            bindCounts
        );

        return "CONVERT(" . left . " USING " . right . ")";
    }

    /**
     * Resolve a FROM clause
     */
    final protected function getSqlExpressionFrom(var expression, string escapeChar = null) -> string
    {
        var table, tables;

        if typeof expression == "array" {
            let tables = [];

            for table in expression {
                let tables[] = this->getSqlTable(table, escapeChar);
            }

            let tables = join(", ", tables);
        } else {
            let tables = expression;
        }

        return "FROM " . tables;
    }

    /**
     * Resolve function calls
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionFunctionCall(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var name, customFunction, arguments;

        let name = expression["name"];

        if fetch customFunction, this->customFunctions[name] {
            return {customFunction}(this, expression, escapeChar);
        }

        if fetch arguments, expression["arguments"] && typeof arguments === "array" {
            let arguments = this->getSqlExpression(
                [
                    "type":        "list",
                    "parentheses": false,
                    "value":       arguments
                ],
                escapeChar,
                bindCounts
            );

            if isset expression["distinct"] && expression["distinct"] {
                return name . "(DISTINCT " . arguments . ")";
            }

            return name . "(" . arguments . ")";
        }

        return name . "()";
    }

    /**
     * Resolve a GROUP BY clause
     *
     * @param array|string expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionGroupBy(var expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var field, fields;

        if typeof expression === "array" {
            let fields = [];

            for field in expression {
                if unlikely typeof field != "array" {
                    throw new InvalidGroupByExpression();
                }

                let fields[] = this->getSqlExpression(
                    field,
                    escapeChar,
                    bindCounts
                );
            }

            let fields = join(", ", fields);
        } else {
            let fields = expression;
        }

        return "GROUP BY " . fields;
    }

    /**
     * Resolve a HAVING clause
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionHaving(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        return "HAVING " . this->getSqlExpression(expression, escapeChar, bindCounts);
    }

    /**
     * Resolve a JOINs clause
     *
     * @param array|string expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionJoins(var expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var condition, join, joinCondition, joinTable, joinType = "",
            joinConditionsArray;
        string sql = "";

        for join in expression {
            /**
             * Check if the join has conditions
             */
            if fetch joinConditionsArray, join["conditions"] && !empty joinConditionsArray {
                if !isset joinConditionsArray[0] {
                    let joinCondition = this->getSqlExpression(
                        joinConditionsArray,
                        escapeChar,
                        bindCounts
                    );
                } else {
                    let joinCondition = [];

                    for condition in joinConditionsArray {
                        let joinCondition[] = this->getSqlExpression(
                            condition,
                            escapeChar,
                            bindCounts
                        );
                    }

                    let joinCondition = join(" AND ", joinCondition);
                }
            } else {
                let joinCondition = 1;
            }

            if fetch joinType, join["type"] && joinType {
                let joinType .= " ";
            }

            let joinTable = this->getSqlTable(join["source"], escapeChar);

            let sql .= " " . joinType . "JOIN " . joinTable . " ON " . joinCondition;
        }

        return sql;
    }

    /**
     * Resolve a LIMIT clause
     *
     * @param array|string expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionLimit(var expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var sql = "", value, limit, offset = null;

        let value = expression["value"];

        if isset expression["sql"] {
            let sql = expression["sql"];
        }

        if typeof value == "array" {
            if typeof value["number"] == "array" {
                let limit = this->getSqlExpression(
                    value["number"],
                    escapeChar,
                    bindCounts
                );
            } else {
                let limit = value["number"];
            }

            /**
             * Check for an OFFSET condition
             */
            if fetch offset, value["offset"] && typeof offset == "array" {
                let offset = this->getSqlExpression(
                    offset,
                    escapeChar,
                    bindCounts
                );
            }

        } else {
            let limit = value;
        }

        return this->limit(sql, [limit, offset]);
    }

    /**
     * Resolve Lists
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionList(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var item, values, separator;
        array items;

        let items = [];
        let separator = ", ";

        if isset expression["separator"] {
            let separator = expression["separator"];
        }

        if (fetch values, expression[0] || fetch values, expression["value"]) && typeof values == "array" {

            for item in values {
                let items[] = this->getSqlExpression(item, escapeChar, bindCounts);
            }

            if isset expression["parentheses"] && expression["parentheses"] === false {
                return join(separator, items);
            }

            return "(" . join(separator, items) . ")";
        }

        throw new InvalidListExpression();
    }

    /**
     * Resolve object expressions
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionObject(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var domain = null, objectExpression;

        let objectExpression = [
            "type": "all"
        ];

        if (fetch domain, expression["column"] || fetch domain, expression["domain"]) && domain != "" {
            let objectExpression["domain"] = domain;
        }

        return this->getSqlExpression(objectExpression, escapeChar, bindCounts);
    }

    /**
     * Resolve an ORDER BY clause
     *
     * @param array|string expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionOrderBy(var expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var field, fields, type, fieldSql = null;

        if typeof expression === "array" {
            let fields = [];

            for field in expression {

                if unlikely typeof field != "array" {
                    throw new InvalidOrderByExpression();
                }

                let fieldSql = this->getSqlExpression(
                    field[0],
                    escapeChar,
                    bindCounts
                );

                /**
                 * In the numeric 1 position could be a ASC/DESC clause
                 */
                if fetch type, field[1] && type != "" {
                    let fieldSql .= " " . type;
                }

                let fields[] = fieldSql;
            }

            let fields = join(", ", fields);
        } else {
            let fields = expression;
        }

        return "ORDER BY " . fields;
    }

    /**
     * Resolve qualified expressions
     */
    final protected function getSqlExpressionQualified(array! expression, string escapeChar = null) -> string
    {
        var column, domain;

        let column = expression["name"];

        /**
         * A domain could be a table/schema
         */
        if !fetch domain, expression["domain"] {
            let domain = null;
        }

        return this->prepareQualified(column, domain, escapeChar);
    }

    /**
     * Resolve Column expressions
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     */
    final protected function getSqlExpressionScalar(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var value;

        if isset expression["column"] {
            return this->getSqlColumn(expression["column"]);
        }

        if unlikely !fetch value, expression["value"] {
            throw new InvalidSqlExpression();
        }

        if typeof value === "array" {
            return this->getSqlExpression(value, escapeChar, bindCounts);
        }

        return value;
    }

    /**
     * Resolve unary operations expressions
     *
     * @param array expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionUnaryOperations(array! expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var left, right;

        /**
         * Some unary operators use the left operand...
         */
        if fetch left, expression["left"] {
            return this->getSqlExpression(left, escapeChar, bindCounts) . " " . expression["op"];
        }

        /**
         * ...Others use the right operand
         */
        if fetch right, expression["right"] {
            return expression["op"] . " " . this->getSqlExpression(right, escapeChar, bindCounts);
        }

        throw new InvalidUnaryExpression();
    }

    /**
     * Resolve a WHERE clause
     *
     * @param array|string expression
     * @param string|null escapeChar
     * @param array bindCounts
     *
     * @return string
     */
    final protected function getSqlExpressionWhere(var expression, string escapeChar = null, array! bindCounts = []) -> string
    {
        var whereSql;

        if typeof expression === "array" {
            let whereSql = this->getSqlExpression(expression, escapeChar, bindCounts);
        } else {
            let whereSql = expression;
        }

        return "WHERE " . whereSql;
    }

    /**
     * Prepares column for this RDBMS
     */
    protected function prepareColumnAlias(string! qualified, string alias = null, string escapeChar = null) -> string
    {
        if alias != "" {
            return qualified . " AS " . this->escape(alias, escapeChar);
        }

        return qualified;
    }

    /**
     * Prepares table for this RDBMS
     */
    protected function prepareTable(string! table, string schema = null, string alias = null, string escapeChar = null) -> string
    {
        let table = this->escape(table, escapeChar);

        /**
         * Schema
         */
        if schema != "" {
            let table = this->escapeSchema(schema, escapeChar) . "." . table;
        }

        /**
         * Alias
         */
        if alias != "" {
            let table = table . " AS " . this->escape(alias, escapeChar);
        }

        return table;
    }

    /**
     * Prepares qualified for this RDBMS
     */
    protected function prepareQualified(string! column, string domain = null, string escapeChar = null) -> string
    {
        if domain != "" {
            return this->escape(domain . "." . column, escapeChar);
        }

        return this->escape(column, escapeChar);
    }
}
