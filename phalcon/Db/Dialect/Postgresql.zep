
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Dialect;

use Phalcon\Db\CheckInterface;
use Phalcon\Db\Column;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\Dialect;
use Phalcon\Db\DialectInterface;
use Phalcon\Db\Exception;
use Phalcon\Db\Exceptions\MissingDefinitionKey;
use Phalcon\Db\Exceptions\ReturningRequiresColumn;
use Phalcon\Db\Exceptions\UnrecognizedDataType;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\RawValue;
use Phalcon\Db\ReferenceInterface;

/**
 * Generates database specific SQL for the PostgreSQL RDBMS
 */
class Postgresql extends Dialect
{
    /**
     * @var string
     */
    protected escapeChar = "\"";

    /**
     * Generates SQL to add a column to a table
     */
    public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> string
    {
        var columnDefinition;
        string sql;

        let columnDefinition = this->getColumnDefinition(column)
            . this->getGeneratedClause(column, true);

        let sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD COLUMN ";
        let sql .= "\"" . column->getName() . "\" " . columnDefinition;

        if !column->isGenerated() && column->hasDefault() {
            let sql .= " DEFAULT " . this->castDefault(column);
        }

        if column->isNotNull() {
            let sql .= " NOT NULL";
        } else {
            let sql .= " NULL";
        }

        return sql;
    }

    /**
     * Generates SQL to add a CHECK constraint to an existing table.
     */
    public function addCheck(string! tableName, string! schemaName, <CheckInterface> check) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName)
            . " ADD " . this->getCheckClause(check, "\"");
    }

    /**
     * Generates SQL to add an index to a table
     */
    public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string
    {
        var onDelete, onUpdate;
        string sql;

        let sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD";

        if reference->getName() {
            let sql .= " CONSTRAINT \"" . reference->getName() . "\"";
        }

        let sql .= " FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ")"
                 . " REFERENCES \"" . reference->getReferencedTable() . "\" (" . this->getColumnList(reference->getReferencedColumns()) . ")";

        let onDelete = reference->getOnDelete();
        if !empty onDelete {
            let sql .= " ON DELETE " . onDelete;
        }

        let onUpdate = reference->getOnUpdate();
        if !empty onUpdate {
            let sql .= " ON UPDATE " . onUpdate;
        }

        return sql;
    }

    /**
     * Generates SQL to add an index to a table
     */
    public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string
    {
        var indexType;
        string sql;

        if index->getName() === "PRIMARY" {
            return this->addPrimaryKey(tableName, schemaName, index);
        }

        let sql = "CREATE";

        let indexType = index->getType();
        if !empty indexType {
            let sql .= " " . indexType;
        }
        let sql .= " INDEX";

        if index->isConcurrent() {
            let sql .= " CONCURRENTLY";
        }

        let sql .= " \"" . index->getName() . "\" ON " . this->prepareTable(tableName, schemaName);

        let sql .= " (" . this->getIndexColumnList(index) . ")";

        if index->getWhere() !== "" {
            let sql .= " WHERE " . index->getWhere();
        }

        return sql;
    }

    /**
     * Generates SQL to add the primary key to a table
     */
    public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD CONSTRAINT \"" . tableName . "_PRIMARY\" PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
    }

    /**
     * Generates SQL to create a table
     */
    public function createTable(string! tableName, string! schemaName, array! definition) -> string
    {
        var temporary, options, table, columns, column, indexes, index,
            reference, references, indexName, indexType, onDelete, onUpdate,
            columnDefinition, checks, check;
        array createLines, primaryColumns;
        string indexSql, indexSqlAfterCreate, columnLine, referenceSql, sql;

        if unlikely !fetch columns, definition["columns"] {
            throw new MissingDefinitionKey("columns");
        }

        let table = this->prepareTable(tableName, schemaName);

        let temporary = false;
        if fetch options, definition["options"] {
            fetch temporary, options["temporary"];
        }

        /**
         * Create a temporary or normal table
         */
        if temporary {
            let sql = "CREATE TEMPORARY TABLE " . table . " (\n\t";
        } else {
            let sql = "CREATE TABLE " . table . " (\n\t";
        }

        /**
         * Create related indexes
         */
        let indexSqlAfterCreate = "";

        let createLines = [];
        let primaryColumns = [];

        for column in columns {
            let columnDefinition = this->getColumnDefinition(column)
                . this->getGeneratedClause(column, true);
            let columnLine = "\"" . column->getName() . "\" " . columnDefinition;

            /**
             * Add a Default clause (skipped for generated columns)
             */
            if !column->isGenerated() && column->hasDefault() {
                let columnLine .= " DEFAULT " . this->castDefault(column);
            }

            /**
             * Add a NOT NULL clause
             */
            if column->isNotNull() {
                let columnLine .= " NOT NULL";
            } else {
                let columnLine .= " NULL";
            }

            /**
             * Mark the column as primary key
             */
            if column->isPrimary() {
                let primaryColumns[] = column->getName() ;
            }

            let createLines[] = columnLine;

            /**
            * Add a COMMENT clause
            */
            if column->getComment() {
                let indexSqlAfterCreate .= " COMMENT ON COLUMN " . table . ".\"" . column->getName()."\" IS '".column->getComment()."';";
            }
        }

        if !empty primaryColumns {
            let createLines[] = "PRIMARY KEY (" . this->getColumnList(primaryColumns) . ")";
        }

        if fetch indexes, definition["indexes"] {
            for index in indexes {
                let indexName = index->getName();
                let indexType = index->getType();
                let indexSql = "";

                /**
                 * If the index name is primary we add a primary key
                 */
                if indexName == "PRIMARY" {
                    let indexSql = "CONSTRAINT \"PRIMARY\" PRIMARY KEY (" . this->getIndexColumnList(index) . ")";
                } else {
                    if !empty indexType {
                        let indexSql = "CONSTRAINT \"" . indexName . "\" "
                            . indexType . " ("
                            . this->getIndexColumnList(index) . ")";
                    } else {
                        let indexSqlAfterCreate .= "CREATE INDEX \"" . index->getName() . "\" ON " . this->prepareTable(tableName, schemaName);

                        let indexSqlAfterCreate .= " (" . this->getIndexColumnList(index) . ");";
                    }
                }

                if !empty indexSql {
                    let createLines[] = indexSql;
                }
            }
        }

        /**
         * Create related references
         */
        if fetch references, definition["references"] {
            for reference in references {
                let referenceSql = "CONSTRAINT \"" . reference->getName() . "\" FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ") REFERENCES ";

                let referenceSql .= this->prepareTable(
                    reference->getReferencedTable(),
                    schemaName
                );

                let referenceSql .= " (" . this->getColumnList(reference->getReferencedColumns()) . ")";

                let onDelete = reference->getOnDelete();
                if !empty onDelete {
                    let referenceSql .= " ON DELETE " . onDelete;
                }

                let onUpdate = reference->getOnUpdate();
                if !empty onUpdate {
                    let referenceSql .= " ON UPDATE " . onUpdate;
                }

                let createLines[] = referenceSql;
            }
        }

        /**
         * Create CHECK constraints
         */
        if fetch checks, definition["checks"] {
            for check in checks {
                let createLines[] = this->getCheckClause(check, "\"");
            }
        }

        let sql .= join(",\n\t", createLines) . "\n)";
        if isset definition["options"] {
            let sql .= " " . this->getTableOptions(definition);
        }
        let sql .= ";" . indexSqlAfterCreate;

        return sql;
    }

    /**
     * Generates SQL to create a materialized view.
     */
    public function createMaterializedView(string! viewName, array! definition, string schemaName = null) -> string
    {
        var viewSql;

        if unlikely !fetch viewSql, definition["sql"] {
            throw new MissingDefinitionKey("sql");
        }

        return "CREATE MATERIALIZED VIEW "
            . this->prepareTable(viewName, schemaName)
            . " AS " . viewSql;
    }

    /**
     * Generates SQL to create a view
     */
    public function createView(string! viewName, array! definition, string schemaName = null) -> string
    {
        var viewSql;

        if unlikely !fetch viewSql, definition["sql"] {
            throw new MissingDefinitionKey("sql");
        }

        return "CREATE VIEW " . this->prepareTable(viewName, schemaName) . " AS " . viewSql;
    }

    /**
     * Generates SQL describing a table
     *
     * ```php
     * print_r(
     *     $dialect->describeColumns("posts")
     * );
     * ```
     */
    public function describeColumns(string! table, string schema = null) -> string
    {
        if schema === null {
            let schema = "public";
        }

        /**
         * Adapter loop reads by ordinal index:
         *   0:Field, 1:Type, 2:Size, 3:NumericSize, 4:NumericScale, 5:Null,
         *   6:Key, 7:Extra, 8:Position, 9:column_default, 10:description
         *
         * Positions 11 (IsGenerated) and 12 (GenerationExpression) are
         * appended for the generated column round-trip
         * (cphalcon issue [#14719] umbrella). `is_generated` is 'ALWAYS' for
         * stored generated columns in PostgreSQL 12+, 'NEVER' otherwise.
         * PostgreSQL only supports STORED generated columns.
         */
        return "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, "
            . "c.character_maximum_length AS Size, "
            . "c.numeric_precision AS NumericSize, "
            . "c.numeric_scale AS NumericScale, c.is_nullable AS Null, "
            . "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, "
            . "CASE WHEN c.data_type LIKE '%int%' AND "
            . "c.column_default LIKE '%nextval%' THEN 'auto_increment' "
            . "ELSE '' END AS Extra, c.ordinal_position AS Position, "
            . "c.column_default, des.description, "
            . "c.is_generated AS IsGenerated, "
            . "c.generation_expression AS GenerationExpression "
            . "FROM information_schema.columns c "
            . "LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, "
            . "kcu.table_schema FROM information_schema.table_constraints tc "
            . "INNER JOIN information_schema.key_column_usage kcu on "
            . "(kcu.constraint_name = tc.constraint_name and "
            . "kcu.table_name=tc.table_name and "
            . "kcu.table_schema=tc.table_schema) "
            . "WHERE tc.constraint_type='PRIMARY KEY') pkc "
            . "ON (c.column_name=pkc.column_name AND "
            . "c.table_schema = pkc.table_schema AND "
            . "c.table_name=pkc.table_name) "
            . "LEFT JOIN ( SELECT objsubid, description, relname, nspname "
            . "FROM pg_description "
            . "JOIN pg_class ON pg_description.objoid = pg_class.oid "
            . "JOIN pg_namespace ON pg_class.relnamespace = pg_namespace.oid "
            . ") des ON ( des.objsubid = C.ordinal_position "
            . "AND C.table_schema = des.nspname "
            . "AND C.TABLE_NAME = des.relname ) "
            . "WHERE c.table_schema='" . schema . "' "
            . "AND c.table_name='" . table . "' "
            . "ORDER BY c.ordinal_position";
    }

    /**
     * Generates SQL to query indexes on a table
     */
    public function describeIndexes(string! table, string schema = null) -> string
    {
        return "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '" . table . "' ORDER BY t.relname, i.relname;";
    }

    /**
     * Generates SQL to query foreign keys on a table
     */
    public function describeReferences(string! table, string schema = null) -> string
    {
        if schema === null {
            let schema = "public";
        }

        return "SELECT DISTINCT tc.table_name AS TABLE_NAME, kcu.column_name AS COLUMN_NAME, tc.constraint_name AS CONSTRAINT_NAME, tc.table_catalog AS REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME, rc.update_rule AS UPDATE_RULE, rc.delete_rule AS DELETE_RULE FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name JOIN information_schema.referential_constraints rc ON tc.constraint_catalog = rc.constraint_catalog AND tc.constraint_schema = rc.constraint_schema AND tc.constraint_name = rc.constraint_name AND tc.constraint_type = 'FOREIGN KEY' WHERE constraint_type = 'FOREIGN KEY' AND tc.table_schema = '" . schema . "' AND tc.table_name='" . table . "'";
    }

    /**
     * Generates SQL to delete a column from a table
     */
    public function dropColumn(string! tableName, string! schemaName, string! columnName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP COLUMN \"" . columnName . "\"";
    }

    /**
     * Generates SQL to delete a CHECK constraint from a table
     */
    public function dropCheck(string! tableName, string! schemaName, string! checkName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName)
            . " DROP CONSTRAINT \"" . checkName . "\"";
    }

    /**
     * Generates SQL to delete a foreign key from a table
     */
    public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP CONSTRAINT \"" . referenceName . "\"";
    }

    /**
     * Generates SQL to delete an index from a table
     */
    public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
    {
        return "DROP INDEX \"" . indexName . "\"";
    }

    /**
     * Generates SQL to delete primary key from a table
     */
    public function dropPrimaryKey(string! tableName, string! schemaName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP CONSTRAINT \"" . tableName . "_PRIMARY\"";
    }

    /**
     * Generates SQL to drop a table
     */
    public function dropTable(string! tableName, string schemaName = null, bool! ifExists = true) -> string
    {
        var table;

        let table = this->prepareTable(tableName, schemaName);

        if ifExists {
            return "DROP TABLE IF EXISTS " . table;
        }

        return "DROP TABLE " . table;
    }

    /**
     * Generates SQL to drop a materialized view.
     */
    public function dropMaterializedView(string! viewName, string schemaName = null, bool ifExists = true) -> string
    {
        var view;

        let view = this->prepareTable(viewName, schemaName);

        if ifExists {
            return "DROP MATERIALIZED VIEW IF EXISTS " . view;
        }

        return "DROP MATERIALIZED VIEW " . view;
    }

    /**
     * Generates SQL to drop a view
     */
    public function dropView(string! viewName, string schemaName = null, bool! ifExists = true) -> string
    {
        var view;

        let view = this->prepareTable(viewName, schemaName);

        if ifExists {
            return "DROP VIEW IF EXISTS " . view;
        }

        return "DROP VIEW " . view;
    }

    /**
     * Generates SQL to refresh a materialized view. When `concurrent` is
     * true, emits `REFRESH MATERIALIZED VIEW CONCURRENTLY ...` (avoids
     * blocking concurrent SELECTs; requires a unique index on the view).
     */
    public function refreshMaterializedView(string! viewName, string schemaName = null, bool concurrent = false) -> string
    {
        var view;

        let view = this->prepareTable(viewName, schemaName);

        if concurrent {
            return "REFRESH MATERIALIZED VIEW CONCURRENTLY " . view;
        }

        return "REFRESH MATERIALIZED VIEW " . view;
    }

    /**
     * Gets the column name in PostgreSQL
     */
    public function getColumnDefinition(<ColumnInterface> column) -> string
    {
        var columnType, columnSql, typeValues;

        let columnSql  = this->checkColumnTypeSql(column);
        let columnType = this->checkColumnType(column);

        switch columnType {

            case Column::TYPE_BIGINTEGER:
                if empty columnSql {
                    if column->isAutoIncrement() {
                        let columnSql .= "BIGSERIAL";
                    } else {
                        let columnSql .= "BIGINT";
                    }
                }

                break;

            case Column::TYPE_BOOLEAN:
                if empty columnSql {
                    let columnSql .= "BOOLEAN";
                }

                break;

            case Column::TYPE_CHAR:
                if empty columnSql {
                    let columnSql .= "CHARACTER";
                }

                let columnSql .= this->getColumnSize(column);

                break;

            case Column::TYPE_DATE:
                if empty columnSql {
                    let columnSql .= "DATE";
                }

                break;

            case Column::TYPE_DATETIME:
                if empty columnSql {
                    let columnSql .= "TIMESTAMP";
                }
                break;

            case Column::TYPE_DECIMAL:
                if empty columnSql {
                    let columnSql .= "NUMERIC";
                }

                let columnSql .= this->getColumnSizeAndScale(column);

                break;

            case Column::TYPE_FLOAT:
                if empty columnSql {
                    let columnSql .= "FLOAT";
                }

                break;

            case Column::TYPE_INTEGER:
                if empty columnSql {
                    if column->isAutoIncrement() {
                        let columnSql .= "SERIAL";
                    } else {
                        let columnSql .= "INT";
                    }
                }

                break;

            case Column::TYPE_SMALLINTEGER:
                if empty columnSql {
                    let columnSql .= "SMALLINT";
                }

                break;

            case Column::TYPE_JSON:
                if empty columnSql {
                    let columnSql .= "JSON";
                }

                break;

            case Column::TYPE_JSONB:
                if empty columnSql {
                    let columnSql .= "JSONB";
                }

                break;

            case Column::TYPE_TIMESTAMP:
                if empty columnSql {
                    let columnSql .= "TIMESTAMP";
                }

                break;

            case Column::TYPE_TEXT:
                if empty columnSql {
                    let columnSql .= "TEXT";
                }

                break;

            case Column::TYPE_UUID:
                if empty columnSql {
                    let columnSql .= "UUID";
                }

                break;

            case Column::TYPE_VARCHAR:
                if empty columnSql {
                    let columnSql .= "CHARACTER VARYING";
                }

                let columnSql .= this->getColumnSize(column);

                break;

            case Column::TYPE_BYTEA:
                if empty columnSql {
                    let columnSql .= "BYTEA";
                }

                break;

            case Column::TYPE_INET:
                if empty columnSql {
                    let columnSql .= "INET";
                }

                break;

            case Column::TYPE_CIDR:
                if empty columnSql {
                    let columnSql .= "CIDR";
                }

                break;

            case Column::TYPE_MACADDR:
                if empty columnSql {
                    let columnSql .= "MACADDR";
                }

                break;

            case Column::TYPE_INT4RANGE:
                if empty columnSql {
                    let columnSql .= "INT4RANGE";
                }

                break;

            case Column::TYPE_INT8RANGE:
                if empty columnSql {
                    let columnSql .= "INT8RANGE";
                }

                break;

            case Column::TYPE_NUMRANGE:
                if empty columnSql {
                    let columnSql .= "NUMRANGE";
                }

                break;

            case Column::TYPE_TSRANGE:
                if empty columnSql {
                    let columnSql .= "TSRANGE";
                }

                break;

            case Column::TYPE_TSTZRANGE:
                if empty columnSql {
                    let columnSql .= "TSTZRANGE";
                }

                break;

            case Column::TYPE_DATERANGE:
                if empty columnSql {
                    let columnSql .= "DATERANGE";
                }

                break;

            case Column::TYPE_GEOMETRY:
                if empty columnSql {
                    let columnSql .= "GEOMETRY";
                }

                break;

            case Column::TYPE_POINT:
                if empty columnSql {
                    let columnSql .= "POINT";
                }

                break;

            case Column::TYPE_LINESTRING:
                if empty columnSql {
                    let columnSql .= "LINESTRING";
                }

                break;

            case Column::TYPE_POLYGON:
                if empty columnSql {
                    let columnSql .= "POLYGON";
                }

                break;

            case Column::TYPE_MULTIPOINT:
                if empty columnSql {
                    let columnSql .= "MULTIPOINT";
                }

                break;

            case Column::TYPE_MULTILINESTRING:
                if empty columnSql {
                    let columnSql .= "MULTILINESTRING";
                }

                break;

            case Column::TYPE_MULTIPOLYGON:
                if empty columnSql {
                    let columnSql .= "MULTIPOLYGON";
                }

                break;

            case Column::TYPE_GEOMETRYCOLLECTION:
                if empty columnSql {
                    let columnSql .= "GEOMETRYCOLLECTION";
                }

                break;

            default:
                if unlikely empty columnSql {
                    throw new UnrecognizedDataType("PostgreSQL", column->getName());
                }

                let typeValues = column->getTypeValues();
                if !empty typeValues {
                    if typeof typeValues == "array" {
                        var value;
                        string valueSql;

                        let valueSql = "";

                        for value in typeValues {
                            let valueSql .= "'" . addcslashes(value, "\'") . "', ";
                        }

                        let columnSql .= "(" . substr(valueSql, 0, -2) . ")";
                    } else {
                        let columnSql .= "('" . addcslashes(typeValues, "\'") . "')";
                    }
                }
        }

        if column->isArray() {
            let columnSql .= "[]";
        }

        return columnSql;
    }

    /**
     * List all tables in database
     *
     * ```php
     * print_r(
     *     $dialect->listTables("blog")
     * );
     * ```
     */
    public function listTables(string schemaName = null) -> string
    {
        if schemaName === null {
            let schemaName = "public";
        }

        return "SELECT table_name FROM information_schema.tables WHERE table_schema = '" . schemaName . "' ORDER BY table_name";
    }

    /**
     * Generates the SQL to list all views of a schema or user
     */
    public function listViews(string schemaName = null) -> string
    {
        if schemaName === null {
            let schemaName = "public";
        }

        return "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '" . schemaName . "' ORDER BY view_name";
    }

    /**
     * Generates SQL to modify a column in a table
     */
    public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
    {
        var defaultValue, columnDefinition;
        string sql = "", sqlAlterTable;

        let columnDefinition = this->getColumnDefinition(column),
            sqlAlterTable = "ALTER TABLE " . this->prepareTable(tableName, schemaName);

        if typeof currentColumn != "object" {
            let currentColumn = column;
        }

        // Rename
        if column->getName() !== currentColumn->getName() {
            let sql .= sqlAlterTable . " RENAME COLUMN \"" . currentColumn->getName() . "\" TO \"" . column->getName() . "\";";
        }

        // Change type
        if column->getType() !== currentColumn->getType() {
            let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" TYPE " . columnDefinition . ";";
        }

        // NULL
        if column->isNotNull() !== currentColumn->isNotNull() {
            if column->isNotNull() {
                let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" SET NOT NULL;";
            } else {
                let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" DROP NOT NULL;";
            }
        }

        /**
         * Add a COMMENT clause
         */
         if column->getComment() {
            let sql .= "COMMENT ON COLUMN " . this->prepareTable(tableName, schemaName) . ".\"" .column->getName()."\" IS '" . column->getComment() . "';";
        }

        // DEFAULT
        if column->getDefault() !== currentColumn->getDefault() {
            if !column->hasDefault() && currentColumn->hasDefault() {
                let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" DROP DEFAULT;";
            }

            if column->hasDefault() {
                let defaultValue = this->castDefault(column);
                let sql .= sqlAlterTable . " ALTER COLUMN \"" . column->getName() . "\" SET DEFAULT " . defaultValue;
            }
        }

        return sql;
    }

    /**
     * Appends a `RETURNING` clause to the supplied INSERT/UPDATE/DELETE
     * statement. Pass `["*"]` for `RETURNING *`, or a list of column names.
     */
    public function returning(string! sqlQuery, array! columns) -> string
    {
        var first;

        if unlikely empty columns {
            throw new ReturningRequiresColumn();
        }

        if count(columns) == 1 {
            let first = (string) columns[0];

            if first == "*" {
                return sqlQuery . " RETURNING *";
            }
        }

        return sqlQuery . " RETURNING " . this->getColumnList(columns);
    }

    /**
     * Returns a SQL modified with a `FOR SHARE` clause — PostgreSQL's
     * equivalent of MySQL's `LOCK IN SHARE MODE`. The optional `modifier`
     * appends a row-lock disposition keyword (pass `Dialect::LOCK_NOWAIT`
     * or `Dialect::LOCK_SKIP_LOCKED`).
     *
     *```php
     * echo $dialect->sharedLock("SELECT * FROM robots");
     * // SELECT * FROM robots FOR SHARE
     *
     * echo $dialect->sharedLock(
     *     "SELECT * FROM robots",
     *     Dialect::LOCK_NOWAIT
     * );
     * // SELECT * FROM robots FOR SHARE NOWAIT
     *```
     */
    public function sharedLock(string! sqlQuery, string modifier = "") -> string
    {
        if modifier !== "" {
            return sqlQuery . " FOR SHARE " . modifier;
        }

        return sqlQuery . " FOR SHARE";
    }

    /**
     * Generates SQL checking for the existence of a schema.table
     *
     * ```php
     * echo $dialect->tableExists("posts", "blog");
     *
     * echo $dialect->tableExists("posts");
     * ```
     */
    public function tableExists(string! tableName, string schemaName = null) -> string
    {
        if schemaName === null {
            let schemaName = "public";
        }

        return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '" . schemaName . "' AND table_name='" . tableName . "'";
    }

    /**
     * Generates the SQL to describe the table creation options
     */
    public function tableOptions(string! table, string schema = null) -> string
    {
        return "";
    }

    /**
     * Generates SQL to truncate a table
     */
    public function truncateTable(string! tableName, string! schemaName) -> string
    {
        var table;

        if schemaName {
            let table = this->prepareTable(tableName, schemaName);
        } else {
            let table = this->prepareTable(tableName);
        }

        return "TRUNCATE TABLE " . table;
    }

    /**
     * Generates SQL checking for the existence of a schema.view
     */
    public function viewExists(string! viewName, string schemaName = null) -> string
    {
        if schemaName === null {
            let schemaName = "public";
        }

        return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='" . viewName . "' AND schemaname='" . schemaName . "'";
    }

    protected function castDefault(<ColumnInterface> column) -> string
    {
        var defaultValue, columnDefinition, columnType;
        string  preparedValue;

        let defaultValue = column->getDefault();

        /**
         * RawValue defaults are emitted verbatim — this is how the caller
         * signals an SQL expression (e.g. `nextval('seq')`, `gen_random_uuid()`,
         * a function call, or any other dialect-specific expression).
         */
        if typeof defaultValue == "object" && defaultValue instanceof RawValue {
            return defaultValue->getValue();
        }

        let columnDefinition = this->getColumnDefinition(column),
            columnType = column->getType();

        if memstr(strtoupper(columnDefinition), "BOOLEAN") {
            var boolStr;
            let boolStr = strtolower((string) defaultValue);
            return (boolStr == "false" || boolStr == "0" || boolStr == "") ? "false" : "true";
        }

        if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
            return "CURRENT_TIMESTAMP";
        }

        if columnType === Column::TYPE_INTEGER ||
            columnType === Column::TYPE_BIGINTEGER ||
            columnType === Column::TYPE_DECIMAL ||
            columnType === Column::TYPE_FLOAT ||
            columnType === Column::TYPE_DOUBLE {
            let preparedValue = (string) defaultValue;
        } else {
            let preparedValue = "'" . addcslashes(defaultValue, "\'") . "'";
        }

        return preparedValue;
    }

    protected function getTableOptions(array! definition) -> string
    {
        return "";
    }
}
