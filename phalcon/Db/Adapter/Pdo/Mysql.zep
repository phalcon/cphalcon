
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db;
use Phalcon\Db\Adapter\Pdo as PdoAdapter;
use Phalcon\Db\Column;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\Exception;
use Phalcon\Db\Index;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\Reference;
use Phalcon\Db\ReferenceInterface;

/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 *
 *<code>
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *</code>
 */
class Mysql extends PdoAdapter
{
    protected dialectType = "mysql";

    protected type = "mysql";

    /**
     * Adds a foreign key to a table
     */
    public function addForeignKey(string! tableName, string! schemaName, <ReferenceInterface> reference) -> bool
    {
        var foreignKeyCheck;

        let foreignKeyCheck = this->{"prepare"}(
            this->dialect->getForeignKeyChecks()
        );

        if unlikely !foreignKeyCheck->execute() {
            throw new Exception(
                "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1"
            );
        }

        return this->{"execute"}(
            this->dialect->addForeignKey(
                tableName,
                schemaName,
                reference
            )
        );
    }

    /**
     * Returns an array of Phalcon\Db\Column objects describing a table
     *
     * <code>
     * print_r(
     *     $connection->describeColumns("posts")
     * );
     * </code>
     */
    public function describeColumns(string table, string schema = null) -> <ColumnInterface[]>
    {
        var columns, columnType, fields, field, oldColumn, sizePattern, matches,
            matchOne, matchTwo, columnName;
        array definition;

        let oldColumn = null,
            sizePattern = "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#";

        let columns = [];

        let fields = this->fetchAll(
            this->dialect->describeColumns(table, schema),
            Db::FETCH_NUM
        );

        /**
         * Get the SQL to describe a table
         * We're using FETCH_NUM to fetch the columns
         * Get the describe
         * Field Indexes: 0:name, 1:type, 2:not null, 3:key, 4:default, 5:extra
         */
        for field in fields {
            /**
             * By default the bind types is two
             */
            let definition = [
                "bindType": Column::BIND_PARAM_STR
            ];

            /**
             * By checking every column type we convert it to a
             * Phalcon\Db\Column
             */
            let columnType = field[1];

            /**
             * The order of these IF statements matters. Since we are using
             * memstr to figure out whether a particular string exists in the
             * columnType we will end up with false positives if the order
             * changes.
             *
             * For instance if we have a `varchar` column and we check for
             * `char` first, then that will match. Therefore we have firs the IF
             * statements that are "unique" and further down the ones that can
             * appear a substrings of the columnType above them.
             */

            switch true {
                /**
                 * BOOL
                 */
                 case memstr(columnType, "tinyint(1)"):
                    /**
                     * tinyint(1) is boolean
                     */
                    let definition["type"] = Column::TYPE_BOOLEAN,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_BOOL;

                    break;

                /**
                 * BIGINT
                 */
                case memstr(columnType, "bigint"):
                    let definition["type"] = Column::TYPE_BIGINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * MEDIUMINT
                 */
                case memstr(columnType, "mediumint"):
                    let definition["type"] = Column::TYPE_MEDIUMINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * SMALLINT
                 */
                case memstr(columnType, "smallint"):
                    let definition["type"] = Column::TYPE_SMALLINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * TINYINT
                 */
                case memstr(columnType, "tinyint"):
                    /**
                     * Smallint/Bigint/Integers/Int are int
                     */
                    let definition["type"] = Column::TYPE_TINYINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * INT
                 */
                case memstr(columnType, "int"):
                    let definition["type"] = Column::TYPE_INTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * BIT
                 */
                case memstr(columnType, "bit"):
                    let definition["type"] = Column::TYPE_BIT,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * ENUM
                 */
                case memstr(columnType, "enum"):
                    let definition["type"] = Column::TYPE_ENUM;

                    break;

                /**
                 * DATE
                 */
                case memstr(columnType, "datetime"):
                    let definition["type"] = Column::TYPE_DATETIME;

                    break;

                /**
                 * DATETIME
                 */
                case memstr(columnType, "date"):
                    let definition["type"] = Column::TYPE_DATE;

                    break;

                /**
                 * DECIMAL - This will need to be a string so as not to lose
                 * the decimals
                 */
                case memstr(columnType, "decimal"):
                    let definition["type"] = Column::TYPE_DECIMAL,
                        definition["isNumeric"] = true;

                    break;

                /**
                 * DOUBLE
                 */
                case memstr(columnType, "double"):
                    let definition["type"] = Column::TYPE_DOUBLE,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * FLOAT
                 */
                case memstr(columnType, "float"):
                    let definition["type"] = Column::TYPE_FLOAT,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * MEDIUMBLOB
                 */
                case memstr(columnType, "mediumblob"):
                    let definition["type"] = Column::TYPE_MEDIUMBLOB;

                    break;

                /**
                 * LONGBLOB
                 */
                case memstr(columnType, "longblob"):
                    let definition["type"] = Column::TYPE_LONGBLOB;

                    break;

                /**
                 * TINYBLOB
                 */
                case memstr(columnType, "tinyblob"):
                    let definition["type"] = Column::TYPE_TINYBLOB;

                    break;

                /**
                 * BLOB
                 */
                case memstr(columnType, "blob"):
                    let definition["type"] = Column::TYPE_BLOB;

                    break;

                /**
                 * TIMESTAMP
                 */
                case memstr(columnType, "timestamp"):
                    let definition["type"] = Column::TYPE_TIMESTAMP;

                    break;

                /**
                 * TIME
                 */
                case memstr(columnType, "time"):
                    let definition["type"] = Column::TYPE_TIME;

                    break;

                /**
                 * JSON
                 */
                case memstr(columnType, "json"):
                    let definition["type"] = Column::TYPE_JSON;

                    break;

                /**
                 * LONGTEXT
                 */
                case memstr(columnType, "longtext"):
                    let definition["type"] = Column::TYPE_LONGTEXT;

                    break;

                /**
                 * MEDIUMTEXT
                 */
                case memstr(columnType, "mediumtext"):
                    let definition["type"] = Column::TYPE_MEDIUMTEXT;

                    break;

                /**
                 * TINYTEXT
                 */
                case memstr(columnType, "tinytext"):
                    let definition["type"] = Column::TYPE_TINYTEXT;

                    break;

                /**
                 * TEXT
                 */
                case memstr(columnType, "text"):
                    let definition["type"] = Column::TYPE_TEXT;

                    break;

                /**
                 * VARCHAR
                 */
                case memstr(columnType, "varchar"):
                    let definition["type"] = Column::TYPE_VARCHAR;

                    break;

                /**
                 * CHAR
                 */
                case memstr(columnType, "char"):
                    let definition["type"] = Column::TYPE_CHAR;

                    break;

                /**
                 * Default
                 */
                default:
                    let definition["type"] = Column::TYPE_VARCHAR;

                    break;
            }

            /**
             * If the column type has a parentheses we try to get the column
             * size from it
             */
            if memstr(columnType, "(") {
                let matches = null;

                if definition["type"] == Column::TYPE_ENUM {
                    let definition["size"] = substr(columnType, 5, -1);
                } elseif preg_match(sizePattern, columnType, matches) {
                    if fetch matchOne, matches[1] {
                        let definition["size"] = (int) matchOne;
                    }

                    if fetch matchTwo, matches[2] {
                        let definition["scale"] = (int) matchTwo;
                    }
                }
            }

            /**
             * Check if the column is unsigned, only MySQL support this
             */
            if memstr(columnType, "unsigned") {
                let definition["unsigned"] = true;
            }

            /**
             * Positions
             */
            if oldColumn == null {
                let definition["first"] = true;
            } else {
                let definition["after"] = oldColumn;
            }

            /**
             * Check if the field is primary key
             */
            if field[3] == "PRI" {
                let definition["primary"] = true;
            }

            /**
             * Check if the column allows null values
             */
            if field[2] == "NO" {
                let definition["notNull"] = true;
            }

            /**
             * Check if the column is auto increment
             */
            if field[5] == "auto_increment" {
                let definition["autoIncrement"] = true;
            }

            /**
             * Check if the column is default values
             */
            if field[4] !== null {
                let definition["default"] = field[4];
            }

            /**
             * Every route is stored as a Phalcon\Db\Column
             */
            let columnName = field[0],
                columns[] = new Column(columnName, definition),
                oldColumn = columnName;
        }

        return columns;
    }

    /**
     * Lists table indexes
     *
     * <code>
     * print_r(
     *     $connection->describeIndexes("robots_parts")
     * );
     * </code>
     */
    public function describeIndexes(string! table, string! schema = null) -> <IndexInterface[]>
    {
        var indexes, index, keyName, indexType, indexObjects, columns, name;

        let indexes = [];

        for index in this->fetchAll(this->dialect->describeIndexes(table, schema), Db::FETCH_ASSOC) {
            let keyName = index["Key_name"];
            let indexType = index["Index_type"];

            if !isset indexes[keyName] {
                let indexes[keyName] = [];
            }

            if !isset indexes[keyName]["columns"] {
                let columns = [];
            } else {
                let columns = indexes[keyName]["columns"];
            }

            let columns[] = index["Column_name"];
            let indexes[keyName]["columns"] = columns;

            if keyName == "PRIMARY" {
                let indexes[keyName]["type"] = "PRIMARY";
            } elseif indexType == "FULLTEXT" {
                let indexes[keyName]["type"] = "FULLTEXT";
            } elseif index["Non_unique"] == 0 {
                let indexes[keyName]["type"] = "UNIQUE";
            } else {
                let indexes[keyName]["type"] = null;
            }
        }

        let indexObjects = [];

        for name, index in indexes {
            let indexObjects[name] = new Index(
                name,
                index["columns"],
                index["type"]
            );
        }

        return indexObjects;
    }

    /**
     * Lists table references
     *
     *<code>
     * print_r(
     *     $connection->describeReferences("robots_parts")
     * );
     *</code>
     */
    public function describeReferences(string! table, string! schema = null) -> <ReferenceInterface[]>
    {
        var references, reference, arrayReference, constraintName,
            referenceObjects, name, referencedSchema, referencedTable, columns,
            referencedColumns, referenceUpdate, referenceDelete;

        let references = [];

        for reference in this->fetchAll(this->dialect->describeReferences(table, schema), Db::FETCH_NUM) {

            let constraintName = reference[2];

            if !isset references[constraintName] {
                let referencedSchema  = reference[3];
                let referencedTable   = reference[4];
                let referenceUpdate   = reference[6];
                let referenceDelete   = reference[7];
                let columns           = [];
                let referencedColumns = [];
            } else {
                let referencedSchema  = references[constraintName]["referencedSchema"];
                let referencedTable   = references[constraintName]["referencedTable"];
                let columns           = references[constraintName]["columns"];
                let referencedColumns = references[constraintName]["referencedColumns"];
                let referenceUpdate   = references[constraintName]["onUpdate"];
                let referenceDelete   = references[constraintName]["onDelete"];
            }

            let columns[] = reference[1],
                referencedColumns[] = reference[5];

            let references[constraintName] = [
                "referencedSchema"  : referencedSchema,
                "referencedTable"   : referencedTable,
                "columns"           : columns,
                "referencedColumns" : referencedColumns,
                "onUpdate"          : referenceUpdate,
                "onDelete"          : referenceDelete
            ];
        }

        let referenceObjects = [];
        for name, arrayReference in references {
            let referenceObjects[name] = new Reference(
                name,
                [
                    "referencedSchema"  : arrayReference["referencedSchema"],
                    "referencedTable"   : arrayReference["referencedTable"],
                    "columns"           : arrayReference["columns"],
                    "referencedColumns" : arrayReference["referencedColumns"],
                    "onUpdate"          : arrayReference["onUpdate"],
                    "onDelete"          : arrayReference["onDelete"]
                ]
            );
        }

        return referenceObjects;
    }

    /**
     * Returns PDO adapter DSN defaults as a key-value map.
     */
    protected function getDsnDefaults() -> array
    {
        // In modern MySQL the "utf8mb4" charset is more ideal than just "uf8".
        return [
            "charset" : "utf8mb4"
        ];
    }
}
