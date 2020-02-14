
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Dialect;

use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\Dialect;
use Phalcon\Db\DialectInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;

/**
 * Generates database specific SQL for the SQLite RDBMS
 */
class Sqlite extends Dialect
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
        var defaultValue;
        string sql;

        let sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD COLUMN ";

        let sql .= "\"" . column->getName() . "\" " . this->getColumnDefinition(column);

        if column->hasDefault() {
            let defaultValue = column->getDefault();

            if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
                let sql .= " DEFAULT CURRENT_TIMESTAMP";
            } else {
                let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
            }
        }

        if column->isNotNull() {
            let sql .= " NOT NULL";
        } else {
            let sql .= " NULL";
        }

        if column->isAutoincrement() {
            let sql .= " PRIMARY KEY AUTOINCREMENT";
        }

        return sql;
    }

    /**
     * Generates SQL to add an index to a table
     */
    public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> string
    {
        throw new Exception(
            "Adding a foreign key constraint to an existing table is not supported by SQLite"
        );
    }

    /**
     * Generates SQL to add an index to a table
     */
    public function addIndex(string! tableName, string! schemaName, <IndexInterface> index) -> string
    {
        var indexType;
        string sql;

        let indexType = index->getType();

        if !empty indexType {
            let sql = "CREATE " . indexType . " INDEX ";
        } else {
            let sql = "CREATE INDEX ";
        }

        if schemaName {
            let sql .= "\"" . schemaName . "\".\"" . index->getName() . "\"";
        } else {
            let sql .= "\"" . index->getName() . "\"";
        }

        let sql .= " ON \"" . tableName . "\" (" . this->getColumnList(index->getColumns()) . ")";

        return sql;
    }

    /**
     * Generates SQL to add the primary key to a table
     */
    public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string
    {
        throw new Exception(
            "Adding a primary key after table has been created is not supported by SQLite"
        );
    }

    /**
     * Generates SQL to create a table
     */
    public function createTable(string! tableName, string! schemaName, array! definition) -> string
    {
        var columns, table, temporary, options, createLines, columnLine,
            column, indexes, index, indexName, indexType, references, reference,
            defaultValue, referenceSql, onDelete, onUpdate;
        bool hasPrimary;
        string sql;

        let table = this->prepareTable(tableName, schemaName);

        let temporary = false;
        if fetch options, definition["options"] {
            fetch temporary, options["temporary"];
        }

        if unlikely !fetch columns, definition["columns"] {
            throw new Exception(
                "The index 'columns' is required in the definition array"
            );
        }

        /**
         * Create a temporary or normal table
         */
        if temporary {
            let sql = "CREATE TEMPORARY TABLE " . table;
        } else {
            let sql = "CREATE TABLE " . table;
        }

        let sql .= " (\n\t";

        let hasPrimary = false;
        let createLines = [];

        for column in columns {
            let columnLine = "`" . column->getName() . "` " . this->getColumnDefinition(column);

            /**
             * Mark the column as primary key
             */
            if column->isPrimary() && !hasPrimary {
                let columnLine .= " PRIMARY KEY";
                let hasPrimary = true;
            }

            /**
             * Add an AUTOINCREMENT clause
             */
            if column->isAutoIncrement() && hasPrimary {
                let columnLine .= " AUTOINCREMENT";
            }

            /**
             * Add a Default clause
             */
            if column->hasDefault() {
                let defaultValue = column->getDefault();

                if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
                    let columnLine .= " DEFAULT CURRENT_TIMESTAMP";
                } else {
                    let columnLine .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
                }
            }

            /**
             * Add a NOT NULL clause
             */
            if column->isNotNull() {
                let columnLine .= " NOT NULL";
            } else {
                let columnLine .= " NULL";
            }

            let createLines[] = columnLine;
        }

        /**
         * Create related indexes
         */
        if fetch indexes, definition["indexes"] {
            for index in indexes {
                let indexName = index->getName();
                let indexType = index->getType();

                /**
                 * If the index name is primary we add a primary key
                 */
                if indexName == "PRIMARY" && !hasPrimary {
                    let createLines[] = "PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
                } elseif !empty indexType && memstr(strtoupper(indexType), "UNIQUE") {
                    let createLines[] = "UNIQUE (" . this->getColumnList(index->getColumns()) . ")";
                }
            }
        }

        /**
         * Create related references
         */
        if fetch references, definition["references"] {
            for reference in references {
                let referenceSql = "CONSTRAINT `" . reference->getName() . "` FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ")"
                    . " REFERENCES `" . reference->getReferencedTable() . "`(" . this->getColumnList(reference->getReferencedColumns()) . ")";

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

        let sql .= join(",\n\t", createLines) . "\n)";

        return sql;
    }

    /**
     * Generates SQL to create a view
     */
    public function createView(string! viewName, array! definition, string schemaName = null) -> string
    {
        var viewSql;

        if unlikely !fetch viewSql, definition["sql"] {
            throw new Exception(
                "The index 'sql' is required in the definition array"
            );
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
        return "PRAGMA table_info('" . table . "')";
    }

    /**
     * Generates SQL to query indexes detail on a table
     */
    public function describeIndex(string! index) -> string
    {
        return "PRAGMA index_info('" . index . "')";
    }

    /**
     * Generates SQL to query indexes on a table
     */
    public function describeIndexes(string! table, string schema = null) -> string
    {
        return "PRAGMA index_list('" . table . "')";
    }

    /**
     * Generates SQL to query foreign keys on a table
     */
    public function describeReferences(string! table, string schema = null) -> string
    {
        return "PRAGMA foreign_key_list('" . table . "')";
    }

    /**
     * Generates SQL to delete a column from a table
     */
    public function dropColumn(string! tableName, string! schemaName, string! columnName) -> string
    {
        throw new Exception("Dropping DB column is not supported by SQLite");
    }

    /**
     * Generates SQL to delete a foreign key from a table
     */
    public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string
    {
        throw new Exception(
            "Dropping a foreign key constraint is not supported by SQLite"
        );
    }

    /**
     * Generates SQL to delete an index from a table
     */
    public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
    {
        if schemaName {
            return "DROP INDEX \"" . schemaName . "\".\"" . indexName . "\"";
        }

        return "DROP INDEX \"" . indexName . "\"";
    }

    /**
     * Generates SQL to delete primary key from a table
     */
    public function dropPrimaryKey(string! tableName, string! schemaName) -> string
    {
        throw new Exception(
            "Removing a primary key after table has been created is not supported by SQLite"
        );
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
     * Returns a SQL modified with a FOR UPDATE clause. For SQLite it returns
     * the original query
     */
    public function forUpdate(string! sqlQuery) -> string
    {
        return sqlQuery;
    }

    /**
     * Gets the column name in SQLite
     */
    public function getColumnDefinition(<ColumnInterface> column) -> string
    {
        var columnType, columnSql, typeValues;

        let columnSql  = this->checkColumnTypeSql(column);
        let columnType = this->checkColumnType(column);

        // SQLite has dynamic column typing. The conversion below maximizes
        // compatibility with other DBMS's while following the type affinity
        // rules: http://www.sqlite.org/datatype3.html.
        switch columnType {

            case Column::TYPE_BIGINTEGER:
                if empty columnSql {
                    let columnSql .= "BIGINT";
                }

                if column->isUnsigned() {
                    let columnSql .= " UNSIGNED";
                }

                break;

            case Column::TYPE_BLOB:
                if empty columnSql {
                    let columnSql .= "BLOB";
                }

                break;

            case Column::TYPE_BOOLEAN:
                if empty columnSql {
                    let columnSql .= "TINYINT";
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
                    let columnSql .= "DATETIME";
                }

                break;

            case Column::TYPE_DECIMAL:
                if empty columnSql {
                    let columnSql .= "NUMERIC";
                }

                let columnSql .= this->getColumnSizeAndScale(column);

                break;

            case Column::TYPE_DOUBLE:
                if empty columnSql {
                    let columnSql .= "DOUBLE";
                }

                if column->isUnsigned() {
                    let columnSql .= " UNSIGNED";
                }

                break;

            case Column::TYPE_FLOAT:
                if empty columnSql {
                    let columnSql .= "FLOAT";
                }

                break;

            case Column::TYPE_INTEGER:
                if empty columnSql {
                    let columnSql .= "INTEGER";
                }

                break;

            case Column::TYPE_LONGBLOB:
                if empty columnSql {
                    let columnSql .= "LONGBLOB";
                }

                break;

            case Column::TYPE_MEDIUMBLOB:
                if empty columnSql {
                    let columnSql .= "MEDIUMBLOB";
                }

                break;

            case Column::TYPE_TEXT:
                if empty columnSql {
                    let columnSql .= "TEXT";
                }

                break;

            case Column::TYPE_TIMESTAMP:
                if empty columnSql {
                    let columnSql .= "TIMESTAMP";
                }

                break;

            case Column::TYPE_TINYBLOB:
                if empty columnSql {
                    let columnSql .= "TINYBLOB";
                }

                break;

            case Column::TYPE_VARCHAR:
                if empty columnSql {
                    let columnSql .= "VARCHAR";
                }

                let columnSql .= this->getColumnSize(column);

                break;

            default:
                if empty columnSql {
                    throw new Exception(
                        "Unrecognized SQLite data type at column " . column->getName()
                    );
                }

                let typeValues = column->getTypeValues();
                if !empty typeValues {
                    if typeof typeValues == "array" {
                        var value, valueSql;

                        let valueSql = "";

                        for value in typeValues {
                            let valueSql .= "\"" . addcslashes(value, "\"") . "\", ";
                        }

                        let columnSql .= "(" . substr(valueSql, 0, -2) . ")";
                    } else {
                        let columnSql .= "(\"" . addcslashes(typeValues, "\"") . "\")";
                    }
                }
        }

        return columnSql;
    }

    /**
     * Generates the SQL to get query list of indexes
     *
     * ```php
     * print_r(
     *     $dialect->listIndexesSql("blog")
     * );
     * ```
     */
    public function listIndexesSql(string! table, string schema = null, string keyName = null) -> string
    {
        string sql;

        let sql = "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ". this->escape(table) ." COLLATE NOCASE";

        if keyName {
            let sql .= " AND name = ". this->escape(keyName) ." COLLATE NOCASE";
        }

        return sql;
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
        return "SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name";
    }

    /**
     * Generates the SQL to list all views of a schema or user
     */
    public function listViews(string! schemaName = null) -> string
    {
        return "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name";
    }

    /**
     * Generates SQL to modify a column in a table
     */
    public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
    {
        throw new Exception("Altering a DB column is not supported by SQLite");
    }

    /**
     * Returns a SQL modified a shared lock statement. For now this method
     * returns the original query
     */
    public function sharedLock(string! sqlQuery) -> string
    {
        return sqlQuery;
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
        return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='" . tableName . "'";
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
        string table;

        if schemaName {
            let table = "\"" . schemaName . "\".\"" . tableName . "\"";
        } else {
            let table = "\"" . tableName . "\"";
        }

        return "DELETE FROM " . table;
    }

    /**
     * Generates SQL checking for the existence of a schema.view
     */
    public function viewExists(string! viewName, string schemaName = null) -> string
    {
        return "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='" . viewName . "'";
    }
}
