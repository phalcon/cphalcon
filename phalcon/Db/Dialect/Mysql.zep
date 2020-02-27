
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Dialect;

use Phalcon\Db\Dialect;
use Phalcon\Db\Column;
use Phalcon\Db\Exception;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\ReferenceInterface;
use Phalcon\Db\DialectInterface;

/**
 * Generates database specific SQL for the MySQL RDBMS
 */
class Mysql extends Dialect
{
    /**
     * @var string
     */
    protected escapeChar = "`";

    /**
     * Generates SQL to add a column to a table
     */
    public function addColumn(string! tableName, string! schemaName, <ColumnInterface> column) -> string
    {
        var afterPosition, defaultValue;
        string sql;

        let sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD `" . column->getName() . "` " . this->getColumnDefinition(column);

        if column->hasDefault() {
            let defaultValue = column->getDefault();

            if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
                let sql .= " DEFAULT " . defaultValue;
            } else {
                let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
            }
        }

        if column->isNotNull() {
            let sql .= " NOT NULL";
        } else {
            let sql .= " NULL";
        }

        if column->isAutoIncrement() {
            let sql .= " AUTO_INCREMENT";
        }

        if column->isFirst() {
            let sql .= " FIRST";
        } else {
            let afterPosition = column->getAfterPosition();

            if afterPosition {
                let sql .=  " AFTER `" . afterPosition . "`";
            }
        }

        return sql;
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
            let sql .= " CONSTRAINT `" . reference->getName() . "`";
        }

        let sql .= " FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ") REFERENCES " . this->prepareTable(reference->getReferencedTable(), reference->getReferencedSchema()) . "(" . this->getColumnList(reference->getReferencedColumns()) . ")";

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

        let sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName);

        let indexType = index->getType();

        if !empty indexType {
            let sql .= " ADD " . indexType . " INDEX ";
        } else {
            let sql .= " ADD INDEX ";
        }

        let sql .= "`" . index->getName() . "` (" . this->getColumnList(index->getColumns()) . ")";

        return sql;
    }

    /**
     * Generates SQL to add the primary key to a table
     */
    public function addPrimaryKey(string! tableName, string! schemaName, <IndexInterface> index) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " ADD PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
    }

    /**
     * Generates SQL to create a table
     */
    public function createTable(string! tableName, string! schemaName, array! definition) -> string
    {
        var temporary, options, table, columns, column, indexes, index,
            reference, references, indexName, columnLine, indexType, onDelete,
            onUpdate, defaultValue;
        array createLines;
        string indexSql, referenceSql, sql;

        if unlikely !fetch columns, definition["columns"] {
            throw new Exception(
                "The index 'columns' is required in the definition array"
            );
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

        let createLines = [];

        for column in columns {
            let columnLine = "`" . column->getName() . "` " . this->getColumnDefinition(column);

            /**
             * Add a Default clause
             */
            if column->hasDefault() {
                let defaultValue = column->getDefault();

                if (defaultValue === null) {
                    let columnLine .= " DEFAULT NULL";
                } else {
                    if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
                        let columnLine .= " DEFAULT " . defaultValue;
                    } else {
                        let columnLine .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
                    }
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

            /**
             * Add an AUTO_INCREMENT clause
             */
            if column->isAutoIncrement() {
                let columnLine .= " AUTO_INCREMENT";
            }

            /**
             * Mark the column as primary key
             */
            if column->isPrimary() {
                let columnLine .= " PRIMARY KEY";
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
                if indexName == "PRIMARY" {
                    let indexSql = "PRIMARY KEY (" . this->getColumnList(index->getColumns()) . ")";
                } else {
                    if !empty indexType {
                        let indexSql = indexType . " KEY `" . indexName . "` (" . this->getColumnList(index->getColumns()) . ")";
                    } else {
                        let indexSql = "KEY `" . indexName . "` (" . this->getColumnList(index->getColumns()) . ")";
                    }
                }

                let createLines[] = indexSql;
            }
        }

        /**
         * Create related references
         */
        if fetch references, definition["references"] {
            for reference in references {
                let referenceSql = "CONSTRAINT `" . reference->getName() . "` FOREIGN KEY (" . this->getColumnList(reference->getColumns()) . ")"
                    . " REFERENCES " . this->prepareTable(reference->getReferencedTable(), reference->getReferencedSchema()) . " (" . this->getColumnList(reference->getReferencedColumns()) . ")";

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

        if isset definition["options"] {
            let sql .= " " . this->getTableOptions(definition);
        }

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
        return "DESCRIBE " . this->prepareTable(table, schema);
    }

    /**
     * Generates SQL to query indexes on a table
     */
    public function describeIndexes(string! table, string schema = null) -> string
    {
        return "SHOW INDEXES FROM " . this->prepareTable(table, schema);
    }

    /**
     * Generates SQL to query foreign keys on a table
     */
    public function describeReferences(string! table, string schema = null) -> string
    {
        string sql;

        let sql = "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ";

        if schema {
            let sql .= "KCU.CONSTRAINT_SCHEMA = '" . schema . "' AND KCU.TABLE_NAME = '" . table . "'";
        } else {
            let sql .= "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = '" . table . "'";
        }

        return sql;
    }

    /**
     * Generates SQL to delete a column from a table
     */
    public function dropColumn(string! tableName, string! schemaName, string! columnName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP COLUMN `" . columnName . "`";
    }

    /**
     * Generates SQL to delete a foreign key from a table
     */
    public function dropForeignKey(string! tableName, string! schemaName, string! referenceName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP FOREIGN KEY `" . referenceName . "`";
    }

    /**
     * Generates SQL to delete an index from a table
     */
    public function dropIndex(string! tableName, string! schemaName, string! indexName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP INDEX `" . indexName . "`";
    }

    /**
     * Generates SQL to delete primary key from a table
     */
    public function dropPrimaryKey(string! tableName, string! schemaName) -> string
    {
        return "ALTER TABLE " . this->prepareTable(tableName, schemaName) . " DROP PRIMARY KEY";
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
     * Gets the column name in MySQL
     */
    public function getColumnDefinition(<ColumnInterface> column) -> string
    {
        var columnType, columnSql, typeValues;

        let columnSql  = this->checkColumnTypeSql(column);
        let columnType = this->checkColumnType(column);

        switch columnType {

            case Column::TYPE_BIGINTEGER:
                if empty columnSql {
                    let columnSql .= "BIGINT";
                }

                let columnSql .= this->getColumnSize(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_BIT:
                if empty columnSql {
                    let columnSql .= "BIT";
                }

                let columnSql .= this->getColumnSize(column);

                break;

            case Column::TYPE_BLOB:
                if empty columnSql {
                    let columnSql .= "BLOB";
                }

                break;

            case Column::TYPE_BOOLEAN:
                if empty columnSql {
                    let columnSql .= "TINYINT(1)";
                }

                break;

            case Column::TYPE_CHAR:
                if empty columnSql {
                    let columnSql .= "CHAR";
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
                    let columnSql .= "DECIMAL";
                }

                let columnSql .= this->getColumnSizeAndScale(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_DOUBLE:
                if empty columnSql {
                    let columnSql .= "DOUBLE";
                }

                let columnSql .= this->checkColumnSizeAndScale(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_ENUM:
                if empty columnSql {
                    let columnSql .= "ENUM";
                }

                let columnSql .= this->getColumnSize(column);

                break;

            case Column::TYPE_FLOAT:
                if empty columnSql {
                    let columnSql .= "FLOAT";
                }

                let columnSql .= this->checkColumnSizeAndScale(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_INTEGER:
                if empty columnSql {
                    let columnSql .= "INT";
                }

                let columnSql .= this->getColumnSize(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_JSON:
                if empty columnSql {
                    let columnSql .= "JSON";
                }

                break;

            case Column::TYPE_LONGBLOB:
                if empty columnSql {
                    let columnSql .= "LONGBLOB";
                }

                break;

            case Column::TYPE_LONGTEXT:
                if empty columnSql {
                    let columnSql .= "LONGTEXT";
                }

                break;

            case Column::TYPE_MEDIUMBLOB:
                if empty columnSql {
                    let columnSql .= "MEDIUMBLOB";
                }

                break;

            case Column::TYPE_MEDIUMINTEGER:
                if empty columnSql {
                    let columnSql .= "MEDIUMINT";
                }

                let columnSql .= this->getColumnSize(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_MEDIUMTEXT:
                if empty columnSql {
                    let columnSql .= "MEDIUMTEXT";
                }

                break;

            case Column::TYPE_SMALLINTEGER:
                if empty columnSql {
                    let columnSql .= "SMALLINT";
                }

                let columnSql .= this->getColumnSize(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_TEXT:
                if empty columnSql {
                    let columnSql .= "TEXT";
                }

                break;

            case Column::TYPE_TIME:
                if empty columnSql {
                    let columnSql .= "TIME";
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

            case Column::TYPE_TINYINTEGER:
                if empty columnSql {
                    let columnSql .= "TINYINT";
                }

                let columnSql .= this->getColumnSize(column) . this->checkColumnUnsigned(column);

                break;

            case Column::TYPE_TINYTEXT:
                if empty columnSql {
                    let columnSql .= "TINYTEXT";
                }

                break;

            case Column::TYPE_VARCHAR:
                if empty columnSql {
                    let columnSql .= "VARCHAR";
                }

                let columnSql .= this->getColumnSize(column);

                break;

            default:
                if unlikely empty columnSql {
                    throw new Exception(
                        "Unrecognized MySQL data type at column " . column->getName()
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
     * Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.
     */
    public function getForeignKeyChecks() -> string
    {
        return "SELECT @@foreign_key_checks";
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
        if schemaName {
            return "SHOW TABLES FROM `" . schemaName . "`";
        }

        return "SHOW TABLES";
    }

    /**
     * Generates the SQL to list all views of a schema or user
     */
    public function listViews(string! schemaName = null) -> string
    {
        if schemaName {
            return "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '" . schemaName . "' ORDER BY view_name";
        }

        return "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name";
    }

    /**
     * Generates SQL to modify a column in a table
     */
    public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> string
    {
        var afterPosition, defaultValue, columnDefinition;
        string sql;

        let columnDefinition = this->getColumnDefinition(column),
            sql = "ALTER TABLE " . this->prepareTable(tableName, schemaName);

        if typeof currentColumn != "object" {
            let currentColumn = column;
        }

        if column->getName() !== currentColumn->getName() {
            let sql .= " CHANGE COLUMN `" . currentColumn->getName() . "` `" . column->getName() . "` " . columnDefinition;
        } else {
            let sql .= " MODIFY `" . column->getName() . "` " . columnDefinition;
        }

        if column->hasDefault() {
            let defaultValue = column->getDefault();

            if memstr(strtoupper(defaultValue), "CURRENT_TIMESTAMP") {
                let sql .= " DEFAULT " . defaultValue;
            } else {
                let sql .= " DEFAULT \"" . addcslashes(defaultValue, "\"") . "\"";
            }
        }

        if column->isNotNull() {
            let sql .= " NOT NULL";
        } else {
            let sql .= " NULL";
        }

        if column->isAutoIncrement() {
            let sql .= " AUTO_INCREMENT";
        }

        if column->isFirst() {
            let sql .= " FIRST";
        } else {
            let afterPosition = column->getAfterPosition();

            if afterPosition {
                let sql .=  " AFTER `" . afterPosition . "`";
            }
        }

        return sql;
    }

    /**
     * Returns a SQL modified with a LOCK IN SHARE MODE clause
     *
     *```php
     * $sql = $dialect->sharedLock("SELECT * FROM robots");
     *
     * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
     *```
     */
    public function sharedLock(string! sqlQuery) -> string
    {
        return sqlQuery . " LOCK IN SHARE MODE";
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
        if schemaName {
            return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '" . tableName . "' AND `TABLE_SCHEMA` = '" . schemaName . "'";
        }

        return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '" . tableName . "' AND `TABLE_SCHEMA` = DATABASE()";
    }

    /**
     * Generates the SQL to describe the table creation options
     */
    public function tableOptions(string! table, string schema = null) -> string
    {
        string sql;

        let sql = "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ";

        if schema {
            return sql . "TABLES.TABLE_SCHEMA = '" . schema . "' AND TABLES.TABLE_NAME = '" . table . "'";
        }

        return sql . "TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = '" . table . "'";
    }

    /**
     * Generates SQL to truncate a table
     */
    public function truncateTable(string! tableName, string! schemaName) -> string
    {
        string table;

        if schemaName {
            let table = "`" . schemaName . "`.`" . tableName . "`";
        } else {
            let table = "`" . tableName . "`";
        }

        return "TRUNCATE TABLE " . table;
    }

    /**
     * Generates SQL checking for the existence of a schema.view
     */
    public function viewExists(string! viewName, string schemaName = null) -> string
    {
        if schemaName {
            return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '" . viewName . "' AND `TABLE_SCHEMA`='" . schemaName . "'";
        }

        return "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='" . viewName . "' AND `TABLE_SCHEMA` = DATABASE()";
    }

    /**
     * Generates SQL to add the table creation options
     */
    protected function getTableOptions(array! definition) -> string
    {
        var options, engine, autoIncrement, tableCollation, collationParts;
        array tableOptions;

        if !fetch options, definition["options"] {
            return "";
        }

        let tableOptions = [];

        /**
         * Check if there is an ENGINE option
         */
        if fetch engine, options["ENGINE"] {
            if engine {
                let tableOptions[] = "ENGINE=" . engine;
            }
        }

        /**
         * Check if there is an AUTO_INCREMENT option
         */
        if fetch autoIncrement, options["AUTO_INCREMENT"] {
            if autoIncrement {
                let tableOptions[] = "AUTO_INCREMENT=" . autoIncrement;
            }
        }

        /**
         * Check if there is a TABLE_COLLATION option
         */
        if fetch tableCollation, options["TABLE_COLLATION"] {
            if tableCollation {
                let collationParts = explode("_", tableCollation),
                    tableOptions[] = "DEFAULT CHARSET=" . collationParts[0],
                    tableOptions[] = "COLLATE=" . tableCollation;
            }
        }

        return join(" ", tableOptions);
    }

    /**
     * Checks if the size and/or scale are present and encloses those values
     * in parentheses if need be
     */
    private function checkColumnSizeAndScale(<ColumnInterface> column) -> string
    {
        string columnSql;

        if column->getSize() {
            let columnSql .= "(" . column->getSize();

            if column->getScale() {
                let columnSql .= "," . column->getScale() . ")";
            } else {
                let columnSql .= ")";
            }
        }

        return columnSql;
    }

    /**
     * Checks if a column is unsigned or not and returns the relevant SQL syntax
     */
    private function checkColumnUnsigned(<ColumnInterface> column) -> string
    {
        if column->isUnsigned() {
            return " UNSIGNED";
        }

        return "";
    }
}
