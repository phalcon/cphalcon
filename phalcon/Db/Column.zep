
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Allows to define columns to be used on create or alter table operations
 *
 *```php
 * use Phalcon\Db\Column as Column;
 *
 * // Column definition
 * $column = new Column(
 *     "id",
 *     [
 *         "type"          => Column::TYPE_INTEGER,
 *         "size"          => 10,
 *         "unsigned"      => true,
 *         "notNull"       => true,
 *         "autoIncrement" => true,
 *         "first"         => true,
 *     ]
 * );
 *
 * // Add column to existing table
 * $connection->addColumn("robots", null, $column);
 *```
 */
class Column implements ColumnInterface
{
    /**
     * Bind Type Blob
     */
    const BIND_PARAM_BLOB = 3;

    /**
     * Bind Type Bool
     */
    const BIND_PARAM_BOOL = 5;

    /**
     * Bind Type Decimal
     */
    const BIND_PARAM_DECIMAL = 32;

    /**
     * Bind Type Integer
     */
    const BIND_PARAM_INT = 1;

    /**
     * Bind Type Null
     */
    const BIND_PARAM_NULL = 0;

    /**
     * Bind Type String
     */
    const BIND_PARAM_STR = 2;

    /**
     * Skip binding by type
     */
    const BIND_SKIP = 1024;

    /**
     * Big integer abstract data type
     */
    const TYPE_BIGINTEGER = 14;

    /**
     * Bit abstract data type
     */
    const TYPE_BIT = 19;

    /**
     * Blob abstract data type
     */
    const TYPE_BLOB = 11;

    /**
     * Bool abstract data type
     */
    const TYPE_BOOLEAN = 8;

    /**
     * Char abstract data type
     */
    const TYPE_CHAR = 5;

    /**
     * Date abstract data type
     */
    const TYPE_DATE = 1;

    /**
     * Datetime abstract data type
     */
    const TYPE_DATETIME = 4;

    /**
     * Decimal abstract data type
     */
    const TYPE_DECIMAL = 3;

    /**
     * Double abstract data type
     */
    const TYPE_DOUBLE = 9;

    /**
     * Enum abstract data type
     */
    const TYPE_ENUM = 18;

    /**
     * Float abstract data type
     */
    const TYPE_FLOAT = 7;

    /**
     * Int abstract data type
     */
    const TYPE_INTEGER = 0;

    /**
     * Json abstract data type
     */
    const TYPE_JSON = 15;

    /**
     * Jsonb abstract data type
     */
    const TYPE_JSONB = 16;

    /**
     * Longblob abstract data type
     */
    const TYPE_LONGBLOB = 13;

    /**
     * Longtext abstract data type
     */
    const TYPE_LONGTEXT = 24;

    /**
     * Mediumblob abstract data type
     */
    const TYPE_MEDIUMBLOB = 12;

    /**
     * Mediumintegerr abstract data type
     */
    const TYPE_MEDIUMINTEGER = 21;

    /**
     * Mediumtext abstract data type
     */
    const TYPE_MEDIUMTEXT = 23;

    /**
     * Smallint abstract data type
     */
    const TYPE_SMALLINTEGER = 22;

    /**
     * Text abstract data type
     */
    const TYPE_TEXT = 6;

    /**
     * Time abstract data type
     */
    const TYPE_TIME = 20;

    /**
     * Timestamp abstract data type
     */
    const TYPE_TIMESTAMP = 17;

    /**
     * Tinyblob abstract data type
     */
    const TYPE_TINYBLOB = 10;

    /**
     * Tinyint abstract data type
     */
    const TYPE_TINYINTEGER = 26;

    /**
     * Tinytext abstract data type
     */
    const TYPE_TINYTEXT = 25;

    /**
     * Varchar abstract data type
     */
    const TYPE_VARCHAR = 2;

    /**
     * Column Position
     *
     * @var string
     */
    protected after;

    /**
     * Column is autoIncrement?
     *
     * @var bool
     */
    protected autoIncrement = false;

    /**
     * Bind Type
     */
    protected bindType = 2;

    /**
     * Default column value
     */
    protected _default = null { get };

    /**
     * Position is first
     *
     * @var bool
     */
    protected first = false;

    /**
     * The column have some numeric type?
     */
    protected isNumeric = false;

    /**
     * Column's name
     *
     * @var string
     */
    protected name { get };

    /**
     * Column not nullable?
     *
     * Default SQL definition is NOT NULL.
     *
     * @var bool
     */
    protected notNull = true;

    /**
     * Column is part of the primary key?
     */
    protected primary = false;

    /**
     * Integer column number scale
     *
     * @var int
     */
    protected scale = 0 { get };

    /**
     * Integer column size
     *
     * @var int
     */
    protected size = 0 { get };

    /**
     * Column data type
     *
     * @var int
     */
    protected type { get };

    /**
     * Column data type reference
     *
     * @var int
     */
    protected typeReference = -1 { get };

    /**
     * Column data type values
     *
     * @var array|string
     */
    protected typeValues { get };

    /**
     * Integer column unsigned?
     *
     * @var bool
     */
    protected unsigned = false;

    /**
     * Phalcon\Db\Column constructor
     */
    public function __construct(string! name, array! definition)
    {
        var type, notNull, primary, size, scale, dunsigned, first, after,
            bindType, isNumeric, autoIncrement, defaultValue, typeReference,
            typeValues;

        let this->name = name;

        /**
         * Get the column type, one of the TYPE_* constants
         */
        if unlikely !fetch type, definition["type"] {
            throw new Exception("Column type is required");
        }

        let this->type = type;

        if fetch typeReference, definition["typeReference"] {
            let this->typeReference = typeReference;
        }

        if fetch typeValues, definition["typeValues"] {
            let this->typeValues = typeValues;
        }

        /**
         * Check if the field is nullable
         */
        if fetch notNull, definition["notNull"] {
            let this->notNull = notNull;
        }

        /**
         * Check if the field is primary key
         */
        if fetch primary, definition["primary"] {
            let this->primary = primary;
        }

        if fetch size, definition["size"] {
            let this->size = size;
        }

        /**
         * Check if the column has a decimal scale
         */
        if fetch scale, definition["scale"] {
            switch type {
                case self::TYPE_BIGINTEGER:
                case self::TYPE_DECIMAL:
                case self::TYPE_DOUBLE:
                case self::TYPE_FLOAT:
                case self::TYPE_INTEGER:
                case self::TYPE_MEDIUMINTEGER:
                case self::TYPE_SMALLINTEGER:
                case self::TYPE_TINYINTEGER:
                    let this->scale = scale;
                    break;

                default:
                    throw new Exception(
                        "Column type does not support scale parameter"
                    );
            }
        }

        /**
         * Check if the column is default value
         */
        if fetch defaultValue, definition["default"] {
            let this->_default = defaultValue;
        }

        /**
         * Check if the field is unsigned (only MySQL)
         */
        if fetch dunsigned, definition["unsigned"] {
            let this->unsigned = dunsigned;
        }

        /**
         * Check if the field is numeric
         */
        if fetch isNumeric, definition["isNumeric"] {
            let this->isNumeric = isNumeric;
        }

        /**
         * Check if the field is auto-increment/serial
         */
        if fetch autoIncrement, definition["autoIncrement"] {
            if !autoIncrement {
                let this->autoIncrement = false;
            } else {
                switch type {
                    case self::TYPE_BIGINTEGER:
                    case self::TYPE_INTEGER:
                    case self::TYPE_MEDIUMINTEGER:
                    case self::TYPE_SMALLINTEGER:
                    case self::TYPE_TINYINTEGER:
                        let this->autoIncrement = true;
                        break;

                    default:
                        throw new Exception(
                            "Column type cannot be auto-increment"
                        );
                }
            }
        }

        /**
         * Check if the field is placed at the first position of the table
         */
        if fetch first, definition["first"] {
            let this->first = first;
        }

        /**
         * Name of the column which is placed before the current field
         */
        if fetch after, definition["after"] {
            let this->after = after;
        }

        /**
         * The bind type to cast the field when passing it to PDO
         */
        if fetch bindType, definition["bindType"] {
            let this->bindType = bindType;
        }
    }

    /**
     * Check whether field absolute to position in table
     */
    public function getAfterPosition() -> string
    {
        return this->after;
    }

    /**
     * Returns the type of bind handling
     */
    public function getBindType() -> int
    {
        return this->bindType;
    }

    /**
     * Check whether column has default value
     */
    public function hasDefault() -> bool
    {
        if this->isAutoIncrement() {
            return false;
        }

        return this->_default !== null;
    }

    /**
     * Auto-Increment
     */
    public function isAutoIncrement() -> bool
    {
        return this->autoIncrement;
    }

    /**
     * Check whether column have first position in table
     */
    public function isFirst() -> bool
    {
        return this->first;
    }

    /**
     * Not null
     */
    public function isNotNull() -> bool
    {
        return this->notNull;
    }

    /**
     * Check whether column have an numeric type
     */
    public function isNumeric() -> bool
    {
        return this->isNumeric;
    }

    /**
     * Column is part of the primary key?
     */
    public function isPrimary() -> bool
    {
        return this->primary;
    }

    /**
     * Returns true if number column is unsigned
     */
    public function isUnsigned() -> bool
    {
        return this->unsigned;
    }
}
