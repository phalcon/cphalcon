
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Db\Adapter\Pdo\AbstractPdo as PdoAdapter;
use Phalcon\Db\Column;
use Phalcon\Db\ColumnInterface;
use Phalcon\Db\Enum;
use Phalcon\Db\Exception;
use Phalcon\Db\Index;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\Reference;
use Phalcon\Db\ReferenceInterface;

/**
 * Specific functions for the MySQL database system
 *
 *```php
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
 *```
 */
class Mysql extends PdoAdapter
{
    /**
     * @var string
     */
    protected dialectType = "mysql";

    /**
     * @var string
     */
    protected type = "mysql";

    /**
     * Constructor for Phalcon\Db\Adapter\Pdo
     *
     * @param array descriptor = [
     *     'host' => 'localhost',
     *     'port' => '3306',
     *     'dbname' => 'blog',
     *     'username' => 'sigma'
     *     'password' => 'secret'
     *     'dialectClass' => null,
     *     'options' => [],
     *     'dsn' => null,
     *     'charset' => 'utf8mb4'
     * ]
     */
    public function __construct(array! descriptor)
    {
        /**
         * Returning numbers as numbers and not strings. If the user already
         * set this option in the descriptor["options"], we do not have to set
         * anything
         */
        if (!isset(descriptor["options"][\PDO::ATTR_EMULATE_PREPARES])) {
            let descriptor["options"][\PDO::ATTR_EMULATE_PREPARES]  = false;
        }
        if (!isset(descriptor["options"][\PDO::ATTR_STRINGIFY_FETCHES])) {
            let descriptor["options"][\PDO::ATTR_STRINGIFY_FETCHES]  = false;
        }

        parent::__construct(descriptor);
    }

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
     * ```php
     * print_r(
     *     $connection->describeColumns("posts")
     * );
     * ```
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
            Enum::FETCH_NUM
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
                 * BIGINT
                 */
                case starts_with(columnType, "bigint", true):
                    let definition["type"] = Column::TYPE_BIGINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_STR;

                    break;

                /**
                 * MEDIUMINT
                 */
                case starts_with(columnType, "mediumint", true):
                    let definition["type"] = Column::TYPE_MEDIUMINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * SMALLINT
                 */
                case starts_with(columnType, "smallint", true):
                    let definition["type"] = Column::TYPE_SMALLINTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * TINYINT
                 */
                case starts_with(columnType, "tinyint", true):
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
                case starts_with(columnType, "int", true):
                    let definition["type"] = Column::TYPE_INTEGER,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * BIT
                 */
                case starts_with(columnType, "bit", true):
                    let definition["type"] = Column::TYPE_BIT,
                        definition["bindType"] = Column::BIND_PARAM_INT;

                    break;

                /**
                 * ENUM
                 */
                case starts_with(columnType, "enum", true):
                    let definition["type"] = Column::TYPE_ENUM;

                    break;

                /**
                 * DATE
                 */
                case starts_with(columnType, "datetime", true):
                    let definition["type"] = Column::TYPE_DATETIME;

                    break;

                /**
                 * DATETIME
                 */
                case starts_with(columnType, "date", true):
                    let definition["type"] = Column::TYPE_DATE;

                    break;

                /**
                 * DECIMAL - This will need to be a string so as not to lose
                 * the decimals
                 */
                case starts_with(columnType, "decimal", true):
                    let definition["type"] = Column::TYPE_DECIMAL,
                        definition["isNumeric"] = true;

                    break;

                /**
                 * DOUBLE
                 */
                case starts_with(columnType, "double", true):
                    let definition["type"] = Column::TYPE_DOUBLE,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * FLOAT
                 */
                case starts_with(columnType, "float", true):
                    let definition["type"] = Column::TYPE_FLOAT,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * MEDIUMBLOB
                 */
                case starts_with(columnType, "mediumblob", true):
                    let definition["type"] = Column::TYPE_MEDIUMBLOB;

                    break;

                /**
                 * LONGBLOB
                 */
                case starts_with(columnType, "longblob", true):
                    let definition["type"] = Column::TYPE_LONGBLOB;

                    break;

                /**
                 * TINYBLOB
                 */
                case starts_with(columnType, "tinyblob", true):
                    let definition["type"] = Column::TYPE_TINYBLOB;

                    break;

                /**
                 * BLOB
                 */
                case starts_with(columnType, "blob", true):
                    let definition["type"] = Column::TYPE_BLOB;

                    break;

                /**
                 * TIMESTAMP
                 */
                case starts_with(columnType, "timestamp", true):
                    let definition["type"] = Column::TYPE_TIMESTAMP;

                    break;

                /**
                 * TIME
                 */
                case starts_with(columnType, "time", true):
                    let definition["type"] = Column::TYPE_TIME;

                    break;

                /**
                 * JSON
                 */
                case starts_with(columnType, "json", true):
                    let definition["type"] = Column::TYPE_JSON;

                    break;

                /**
                 * LONGTEXT
                 */
                case starts_with(columnType, "longtext", true):
                    let definition["type"] = Column::TYPE_LONGTEXT;

                    break;

                /**
                 * MEDIUMTEXT
                 */
                case starts_with(columnType, "mediumtext", true):
                    let definition["type"] = Column::TYPE_MEDIUMTEXT;

                    break;

                /**
                 * TINYTEXT
                 */
                case starts_with(columnType, "tinytext", true):
                    let definition["type"] = Column::TYPE_TINYTEXT;

                    break;

                /**
                 * TEXT
                 */
                case starts_with(columnType, "text", true):
                    let definition["type"] = Column::TYPE_TEXT;

                    break;

                /**
                 * VARCHAR
                 */
                case starts_with(columnType, "varchar", true):
                    let definition["type"] = Column::TYPE_VARCHAR;

                    break;

                /**
                 * CHAR
                 */
                case starts_with(columnType, "char", true):
                    let definition["type"] = Column::TYPE_CHAR;

                    break;

                /**
                 * VARBINARY
                 */
                case starts_with(columnType, "varbinary", true):
                    let definition["type"] = Column::TYPE_BINARY;

                    break;

                /**
                 * BINARY
                 */
                case starts_with(columnType, "binary", true):
                    let definition["type"] = Column::TYPE_BINARY;

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
            if field[4] == "PRI" {
                let definition["primary"] = true;
            }

            /**
             * Check if the column allows null values
             */
            if field[3] == "YES" {
                let definition["notNull"] = false;
            }

            /**
             * Check if the column is auto increment
             */
            if field[6] == "auto_increment" {
                let definition["autoIncrement"] = true;
            }

            /**
             * Check if the column has default value
             */
            if field[5] !== null {
                if memstr(field[6], "on update") {
                    let definition["default"] = field[5] . " " . field[6];
                } else {
                    let definition["default"] = field[5];
                }
            } else {
                if memstr(field[6], "on update") {
                    let definition["default"] = "NULL " . field[6];
                }
            }

            /**
             * Check if the column has comment
             */
             if field[8] !== null {
                let definition["comment"] = field[8];
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
     * ```php
     * print_r(
     *     $connection->describeIndexes("robots_parts")
     * );
     * ```
     */
    public function describeIndexes(string! table, string! schema = null) -> <IndexInterface[]>
    {
        var indexes, index, keyName, indexType, indexObjects, columns, name;

        let indexes = [];

        for index in this->fetchAll(this->dialect->describeIndexes(table, schema), Enum::FETCH_ASSOC) {
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
                let indexes[keyName]["type"] = "";
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
     *```php
     * print_r(
     *     $connection->describeReferences("robots_parts")
     * );
     *```
     */
    public function describeReferences(string! table, string! schema = null) -> <ReferenceInterface[]>
    {
        var references, reference, arrayReference, constraintName,
            referenceObjects, name, referencedSchema, referencedTable, columns,
            referencedColumns, referenceUpdate, referenceDelete;

        let references = [];

        for reference in this->fetchAll(this->dialect->describeReferences(table, schema), Enum::FETCH_NUM) {

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
