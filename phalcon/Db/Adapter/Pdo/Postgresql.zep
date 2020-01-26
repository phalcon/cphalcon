
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
use Phalcon\Db\RawValue;
use Phalcon\Db\Reference;
use Phalcon\Db\ReferenceInterface;
use Throwable;

/**
 * Specific functions for the Postgresql database system
 *
 * ```php
 * use Phalcon\Db\Adapter\Pdo\Postgresql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 5432,
 *     "username" => "postgres",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Postgresql($config);
 * ```
 */
class Postgresql extends PdoAdapter
{
    /**
     * @var string
     */
    protected dialectType = "postgresql";

    /**
     * @var string
     */
    protected type = "pgsql";

    /**
     * Constructor for Phalcon\Db\Adapter\Pdo\Postgresql
     */
    public function __construct(array! descriptor)
    {
        if isset descriptor["charset"] {
            trigger_error(
                "Postgres does not allow the charset to be changed in the DSN."
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
        var schema, sql, status;

        if empty descriptor {
            let descriptor = (array) this->descriptor;
        }

        if fetch schema, descriptor["schema"] {
            unset descriptor["schema"];
        } else {
            let schema = "";
        }

        if isset descriptor["password"] {
            if typeof descriptor["password"] == "string" && strlen(descriptor["password"]) == 0 {
                let descriptor["password"] = null;
            }
        }

        let status = parent::connect(descriptor);

        if !empty schema {
            let sql = "SET search_path TO '" . schema . "'";

            this->execute(sql);
        }

        return status;
    }

    /**
     * Creates a table
     */
    public function createTable(string! tableName, string! schemaName, array! definition) -> bool
    {
        var sql, queries, query, exception, columns;

        if unlikely !fetch columns, definition["columns"] {
            throw new Exception("The table must contain at least one column");
        }

        if unlikely !count(columns) {
            throw new Exception("The table must contain at least one column");
        }

        let sql = this->dialect->createTable(tableName, schemaName, definition);

        let queries = explode(";", sql);

        if count(queries) > 1 {
            try {
                this->{"begin"}();

                for query in queries {
                    if empty query {
                        continue;
                    }

                    this->{"query"}(query . ";");
                }

                return this->{"commit"}();
            } catch Throwable, exception {
                this->{"rollback"}();

                throw exception;
            }
        } else {
            return this->{"execute"}(queries[0] . ";");
        }

        return true;
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
        var columns, columnType, fields, field, definition, oldColumn,
            columnName, charSize, numericSize, numericScale;

        let oldColumn = null, columns = [];

        /**
         * We're using FETCH_NUM to fetch the columns
         * 0:name, 1:type, 2:size, 3:numericsize, 4: numericscale, 5: null,
         * 6: key, 7: extra, 8: position, 9 default
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
            let columnType = field[1],
                charSize = field[2],
                numericSize = field[3],
                numericScale = field[4];

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
                 case memstr(columnType, "boolean"):
                    /**
                     * tinyint(1) is boolean
                     */
                    let definition["type"] = Column::TYPE_BOOLEAN,
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
                        definition["size"] = numericSize;

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
                    let definition["type"] = Column::TYPE_DATETIME,
                        definition["size"] = 0;

                    break;

                /**
                 * DATETIME
                 */
                case memstr(columnType, "date"):
                    let definition["type"] = Column::TYPE_DATE,
                        definition["size"] = 0;

                    break;

                /**
                 * NUMERIC -> DECIMAL - This will need to be a string so as not
                 * to lose the decimals
                 */
                case memstr(columnType, "decimal"):
                case memstr(columnType, "numeric"):
                    let definition["type"] = Column::TYPE_DECIMAL,
                        definition["size"] = numericSize,
                        definition["isNumeric"] = true,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * DOUBLE
                 */
                case memstr(columnType, "double precision"):
                    let definition["type"] = Column::TYPE_DOUBLE,
                        definition["isNumeric"] = true,
                        definition["size"] = numericSize,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * FLOAT
                 */
                case memstr(columnType, "float"):
                case memstr(columnType, "real"):
                    let definition["type"] = Column::TYPE_FLOAT,
                        definition["isNumeric"] = true,
                        definition["size"] = numericSize,
                        definition["bindType"] = Column::BIND_PARAM_DECIMAL;

                    break;

                /**
                 * MEDIUMBLOB
                 */
                case memstr(columnType, "mediumblob"):
                    let definition["type"] = Column::TYPE_TEXT;

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
                 * JSONB
                 */
                case memstr(columnType, "jsonb"):
                    let definition["type"] = Column::TYPE_JSONB;

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
                case memstr(columnType, "varying"):
                case memstr(columnType, "varchar"):
                    let definition["type"] = Column::TYPE_VARCHAR,
                        definition["size"] = charSize;

                    break;

                /**
                 * CHAR
                 */
                case memstr(columnType, "char"):
                    let definition["type"] = Column::TYPE_CHAR,
                        definition["size"] = charSize;

                    break;

                /**
                 * UUID
                 */
                case memstr(columnType, "uuid"):
                    let definition["type"] = Column::TYPE_CHAR,
                        definition["size"] = 36;

                    break;

                /**
                 * Default
                 */
                default:
                    let definition["type"] = Column::TYPE_VARCHAR;

                    break;
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
            if field[6] == "PRI" {
                let definition["primary"] = true;
            }

            /**
             * Check if the column allows null values
             */
            if field[5] == "NO" {
                let definition["notNull"] = true;
            }

            /**
             * Check if the column is auto increment
             */
            if field[7] == "auto_increment" {
                let definition["autoIncrement"] = true;
            }

            /**
             * Check if the column has default values
             */
            if field[9] !== null {
                let definition["default"] = preg_replace(
                    "/^'|'?::[[:alnum:][:space:]]+$/",
                    "",
                    field[9]
                );

                if strcasecmp(definition["default"], "null") == 0 {
                    let definition["default"] = null;
                }
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
     * Returns the default identity value to be inserted in an identity column
     *
     *```php
     * // Inserting a new robot with a valid default value for the column 'id'
     * $success = $connection->insert(
     *     "robots",
     *     [
     *         $connection->getDefaultIdValue(),
     *         "Astro Boy",
     *         1952,
     *     ],
     *     [
     *         "id",
     *         "name",
     *         "year",
     *     ]
     * );
     *```
     */
    public function getDefaultIdValue() -> <RawValue>
    {
        return new RawValue("DEFAULT");
    }

    /**
     * Modifies a table column based on a definition
     */
    public function modifyColumn(string! tableName, string! schemaName, <ColumnInterface> column, <ColumnInterface> currentColumn = null) -> bool
    {
        var sql, queries, query, exception;

        let sql = this->dialect->modifyColumn(
            tableName,
            schemaName,
            column,
            currentColumn
        );

        let queries = explode(";", sql);

        if count(queries) > 1 {
            try {
                this->{"begin"}();

                for query in queries {
                    if empty query {
                        continue;
                    }

                    this->{"query"}(query . ";");
                }

                return this->{"commit"}();
            } catch Throwable, exception {
                this->{"rollback"}();

                throw exception;
            }
        } else {
            return !empty sql ? this->{"execute"}(queries[0] . ";") : true;
        }

        return true;
    }

    /**
     * Check whether the database system requires a sequence to produce
     * auto-numeric values
     */
    public function supportSequences() -> bool
    {
        return true;
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
