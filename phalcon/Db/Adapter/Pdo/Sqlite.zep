
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
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
use Phalcon\Db\RawValue;
use Phalcon\Db\Reference;
use Phalcon\Db\ReferenceInterface;

/**
 * Specific functions for the SQLite database system
 *
 * ```php
 * use Phalcon\Db\Adapter\Pdo\Sqlite;
 *
 * $connection = new Sqlite(
 *     [
 *         "dbname" => "/tmp/test.sqlite",
 *     ]
 * );
 * ```
 */
class Sqlite extends PdoAdapter
{
    /**
     * @var string
     */
    protected dialectType = "sqlite";

    /**
     * @var string
     */
    protected type = "sqlite";

    /**
     * Constructor for Phalcon\Db\Adapter\Pdo\Sqlite
     */
    public function __construct(array! descriptor)
    {
        if isset descriptor["charset"] {
            trigger_error(
                "SQLite does not allow the charset to be changed in the DSN."
            );
        }

        parent::__construct(descriptor);
    }

    /**
     * This method is automatically called in Phalcon\Db\Adapter\Pdo
     * constructor. Call it when you need to restore a database connection.
     */
    public function connect(array descriptor = null) -> bool
    {
        var dbname;

        if empty descriptor {
            let descriptor = (array) this->descriptor;
        }

        if fetch dbname, descriptor["dbname"] {
            let descriptor["dsn"] = dbname;

            unset descriptor["dbname"];
        } elseif unlikely !isset descriptor["dsn"] {
            throw new Exception(
                "The database must be specified with either 'dbname' or 'dsn'."
            );
        }

        return parent::connect(descriptor);
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
    public function describeColumns(string! table, string! schema = null) -> <ColumnInterface[]>
    {
        var columns, columnType, fields, field, definition, oldColumn,
            sizePattern, matches, matchOne, matchTwo, columnName;

        let oldColumn = null,
            sizePattern = "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#";

        let columns = [];

        /**
         * We're using FETCH_NUM to fetch the columns
         */
        let fields = this->fetchAll(
            this->dialect->describeColumns(table, schema),
            Enum::FETCH_NUM
        );

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
            let columnType = field[2];

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
             *
             * BIGINT/INT
             */
            if memstr(columnType, "bigint") {
                /**
                 * Bigint are int
                 */
                let definition["type"] = Column::TYPE_BIGINTEGER,
                    definition["isNumeric"] = true,
                    definition["bindType"] = Column::BIND_PARAM_INT;
            } elseif memstr(columnType, "int") || memstr(columnType, "INT") {
                /**
                 * Smallint/Integers/Int are int
                 */
                let definition["type"] = Column::TYPE_INTEGER,
                    definition["isNumeric"] = true,
                    definition["bindType"] = Column::BIND_PARAM_INT;

                if field[5] {
                    let definition["autoIncrement"] = true;
                }
            } elseif memstr(columnType, "tinyint(1)") {
                /**
                 * Tinyint(1) is boolean
                 */
                let definition["type"] = Column::TYPE_BOOLEAN,
                    definition["bindType"] = Column::BIND_PARAM_BOOL,
                    columnType = "boolean"; // Change column type to skip size check

            /**
             * ENUM
             */
            } elseif memstr(columnType, "enum") {
                /**
                 * Enum are treated as char
                 */
                let definition["type"] = Column::TYPE_CHAR;

            /**
             * DATE/DATETIME
             */
            } elseif memstr(columnType, "datetime") {
                /**
                 * Special type for datetime
                 */
                let definition["type"] = Column::TYPE_DATETIME;
            } elseif memstr(columnType, "date") {
                /**
                 * Date/Datetime are varchars
                 */
                let definition["type"] = Column::TYPE_DATE;

            /**
             * FLOAT/DECIMAL/DOUBLE
             */
            } elseif memstr(columnType, "decimal") {
                /**
                 * Decimals are floats
                 */
                let definition["type"] = Column::TYPE_DECIMAL,
                    definition["isNumeric"] = true,
                    definition["bindType"] = Column::BIND_PARAM_DECIMAL;
            } elseif memstr(columnType, "float") {
                /**
                 * Float/Smallfloats/Decimals are float
                 */
                let definition["type"] = Column::TYPE_FLOAT,
                    definition["isNumeric"] = true,
                    definition["bindType"] = Column::TYPE_DECIMAL;

            /**
             * TIMESTAMP
             */
            } elseif memstr(columnType, "timestamp") {
                /**
                 * Timestamp as date
                 */
                let definition["type"] = Column::TYPE_TIMESTAMP;

            /**
             * TEXT/VARCHAR/CHAR
             */
            } elseif memstr(columnType, "varchar") {
                /**
                 * Varchar are varchars
                 */
                let definition["type"] = Column::TYPE_VARCHAR;
            } elseif memstr(columnType, "char") {
                /**
                 * Chars are chars
                 */
                let definition["type"] = Column::TYPE_CHAR;
            } elseif memstr(columnType, "text") {
                /**
                 * Text are varchars
                 */
                let definition["type"] = Column::TYPE_TEXT;

            } else {
                /**
                 * By default is string
                 */
                let definition["type"] = Column::TYPE_VARCHAR;
            }

            /**
             * If the column type has a parentheses we try to get the column
             * size from it
             */
            if memstr(columnType, "(") {
                let matches = null;

                if preg_match(sizePattern, columnType, matches) {
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
            if field[5] {
                let definition["primary"] = true;
            }

            /**
             * Check if the column allows null values
             */
            if field[3] == 0 {
                let definition["notNull"] = false;
            }

            /**
             * Check if the column is default values
             * When field is empty default value is null
             */
            if strcasecmp(field[4], "null") != 0 && field[4] != "" {
                let definition["default"] = preg_replace(
                    "/^'|'$/",
                    "",
                    field[4]
                );
            }

            /**
             * Every route is stored as a Phalcon\Db\Column
             */
            let columnName = field[1],
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
        var indexes, index, keyName, indexObjects, name, columns,
            describeIndexes, describeIndex, indexSql;

        let indexes = [];

        for index in this->fetchAll(this->dialect->describeIndexes(table, schema), Enum::FETCH_ASSOC) {
            let keyName = index["name"];

            if !isset indexes[keyName] {
                let indexes[keyName] = [];
            }

            if !isset indexes[keyName]["columns"] {
                let columns = [];
            } else {
                let columns = indexes[keyName]["columns"];
            }

            let describeIndexes = this->fetchAll(
                this->dialect->describeIndex(keyName),
                Enum::FETCH_ASSOC
            );

            for describeIndex in describeIndexes {
                let columns[] = describeIndex["name"];
            }

            let indexes[keyName]["columns"] = columns;

            let indexSql = this->fetchColumn(
                this->dialect->listIndexesSql(table, schema, keyName)
            );

            if index["unique"] {
                if preg_match("# UNIQUE #i", indexSql) {
                    let indexes[keyName]["type"] = "UNIQUE";
                } else {
                    let indexes[keyName]["type"] = "PRIMARY";
                }
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
     */
    public function describeReferences(string! table, string! schema = null) -> <ReferenceInterface[]>
    {
        var references, reference, arrayReference, constraintName,
            referenceObjects, name, referencedSchema, referencedTable, columns,
            referencedColumns, number;

        let references = [];

        for number, reference in this->fetchAll(this->dialect->describeReferences(table, schema), Enum::FETCH_NUM) {
            let constraintName = "foreign_key_" . number;

            if !isset references[constraintName] {
                let referencedSchema = null;
                let referencedTable = reference[2];
                let columns = [];
                let referencedColumns = [];
            } else {
                let referencedSchema = references[constraintName]["referencedSchema"];
                let referencedTable = references[constraintName]["referencedTable"];
                let columns = references[constraintName]["columns"];
                let referencedColumns = references[constraintName]["referencedColumns"];
            }

            let columns[] = reference[3],
                referencedColumns[] = reference[4];

            let references[constraintName] = [
                "referencedSchema"  : referencedSchema,
                "referencedTable"   : referencedTable,
                "columns"           : columns,
                "referencedColumns" : referencedColumns
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
                    "referencedColumns" : arrayReference["referencedColumns"]
                ]
            );
        }

        return referenceObjects;
    }

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
     *         $connection->getDefaultValue(),
     *     ],
     *     [
     *         "name",
     *         "year",
     *     ]
     * );
     *```
     */
    public function getDefaultValue() -> <RawValue>
    {
        return new RawValue("NULL");
    }

    /**
     * Check whether the database system requires an explicit value for identity
     * columns
     */
    public function useExplicitIdValue() -> bool
    {
        return true;
    }

    /**
     * Returns PDO adapter DSN defaults as a key-value map.
     */
    protected function getDsnDefaults() -> array
    {
        return [];
    }
}
