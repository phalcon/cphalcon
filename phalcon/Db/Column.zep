/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Db\Exceptions\ColumnTypeRejectsAutoIncrement;
use Phalcon\Db\Exceptions\ColumnTypeRejectsScale;
use Phalcon\Db\Exceptions\ColumnTypeRequired;
use Phalcon\Db\Exceptions\GeneratedAutoIncrementConflict;
use Phalcon\Db\Exceptions\GeneratedDefaultConflict;
use Phalcon\Db\Exceptions\InvalidGenerationExpression;

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
 *         "comment"       => "",
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
     *
     * @var int
     */
    const BIND_PARAM_BLOB = 3;

    /**
     * Bind Type Bool
     *
     * @var int
     */
    const BIND_PARAM_BOOL = 5;

    /**
     * Bind Type Decimal
     *
     * @var int
     */
    const BIND_PARAM_DECIMAL = 32;

    /**
     * Bind Type Integer
     *
     * @var int
     */
    const BIND_PARAM_INT = 1;

    /**
     * Bind Type Null
     *
     * @var int
     */
    const BIND_PARAM_NULL = 0;

    /**
     * Bind Type String
     *
     * @var int
     */
    const BIND_PARAM_STR = 2;

    /**
     * Skip binding by type
     *
     * @var int
     */
    const BIND_SKIP = 1024;

    /**
     * Big integer abstract data type
     *
     * @var int
     */
    const TYPE_BIGINTEGER = 14;

    /**
     * Bit abstract data type
     *
     * @var int
     */
    const TYPE_BIT = 19;

    /**
     * Binary abstract data type
     *
     * @var int
     */
    const TYPE_BINARY = 27;

    /**
     * Blob abstract data type
     *
     * @var int
     */
    const TYPE_BLOB = 11;

    /**
     * Bool abstract data type
     *
     * @var int
     */
    const TYPE_BOOLEAN = 8;

    /**
     * Char abstract data type
     *
     * @var int
     */
    const TYPE_CHAR = 5;

    /**
     * Date abstract data type
     *
     * @var int
     */
    const TYPE_DATE = 1;

    /**
     * Datetime abstract data type
     *
     * @var int
     */
    const TYPE_DATETIME = 4;

    /**
     * Decimal abstract data type
     *
     * @var int
     */
    const TYPE_DECIMAL = 3;

    /**
     * Double abstract data type
     *
     * @var int
     */
    const TYPE_DOUBLE = 9;

    /**
     * Enum abstract data type
     *
     * @var int
     */
    const TYPE_ENUM = 18;

    /**
     * Float abstract data type
     *
     * @var int
     */
    const TYPE_FLOAT = 7;

    /**
     * Int abstract data type
     *
     * @var int
     */
    const TYPE_INTEGER = 0;

    /**
     * Json abstract data type
     *
     * @var int
     */
    const TYPE_JSON = 15;

    /**
     * Jsonb abstract data type
     *
     * @var int
     */
    const TYPE_JSONB = 16;

    /**
     * Longblob abstract data type
     *
     * @var int
     */
    const TYPE_LONGBLOB = 13;

    /**
     * Longtext abstract data type
     *
     * @var int
     */
    const TYPE_LONGTEXT = 24;

    /**
     * Mediumblob abstract data type
     *
     * @var int
     */
    const TYPE_MEDIUMBLOB = 12;

    /**
     * Mediumintegerr abstract data type
     *
     * @var int
     */
    const TYPE_MEDIUMINTEGER = 21;

    /**
     * Mediumtext abstract data type
     *
     * @var int
     */
    const TYPE_MEDIUMTEXT = 23;

    /**
     * Smallint abstract data type
     *
     * @var int
     */
    const TYPE_SMALLINTEGER = 22;

    /**
     * Text abstract data type
     *
     * @var int
     */
    const TYPE_TEXT = 6;

    /**
     * Time abstract data type
     *
     * @var int
     */
    const TYPE_TIME = 20;

    /**
     * Timestamp abstract data type
     *
     * @var int
     */
    const TYPE_TIMESTAMP = 17;

    /**
     * Tinyblob abstract data type
     *
     * @var int
     */
    const TYPE_TINYBLOB = 10;

    /**
     * Tinyint abstract data type
     *
     * @var int
     */
    const TYPE_TINYINTEGER = 26;

    /**
     * Tinytext abstract data type
     *
     * @var int
     */
    const TYPE_TINYTEXT = 25;

    /**
     * UUID abstract data type
     *
     * @var int
     */
    const TYPE_UUID = 29;

    /**
     * Varbinary abstract data type
     *
     * @var int
     */
    const TYPE_VARBINARY = 28;

    /**
     * Varchar abstract data type
     *
     * @var int
     */
    const TYPE_VARCHAR = 2;

    /**
     * PostgreSQL `BYTEA` binary type
     *
     * @var int
     */
    const TYPE_BYTEA = 30;

    /**
     * PostgreSQL `INET` IPv4/IPv6 address type
     *
     * @var int
     */
    const TYPE_INET = 31;

    /**
     * PostgreSQL `CIDR` network-address type
     *
     * @var int
     */
    const TYPE_CIDR = 32;

    /**
     * PostgreSQL `MACADDR` MAC-address type
     *
     * @var int
     */
    const TYPE_MACADDR = 33;

    /**
     * PostgreSQL `INT4RANGE` range-of-integer type
     *
     * @var int
     */
    const TYPE_INT4RANGE = 34;

    /**
     * PostgreSQL `INT8RANGE` range-of-bigint type
     *
     * @var int
     */
    const TYPE_INT8RANGE = 35;

    /**
     * PostgreSQL `NUMRANGE` range-of-numeric type
     *
     * @var int
     */
    const TYPE_NUMRANGE = 36;

    /**
     * PostgreSQL `TSRANGE` range-of-timestamp (without time zone) type
     *
     * @var int
     */
    const TYPE_TSRANGE = 37;

    /**
     * PostgreSQL `TSTZRANGE` range-of-timestamp (with time zone) type
     *
     * @var int
     */
    const TYPE_TSTZRANGE = 38;

    /**
     * PostgreSQL `DATERANGE` range-of-date type
     *
     * @var int
     */
    const TYPE_DATERANGE = 39;

    /**
     * Spatial `GEOMETRY` base type (MySQL 5.7+; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_GEOMETRY = 40;

    /**
     * Spatial `POINT` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_POINT = 41;

    /**
     * Spatial `LINESTRING` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_LINESTRING = 42;

    /**
     * Spatial `POLYGON` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_POLYGON = 43;

    /**
     * Spatial `MULTIPOINT` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_MULTIPOINT = 44;

    /**
     * Spatial `MULTILINESTRING` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_MULTILINESTRING = 45;

    /**
     * Spatial `MULTIPOLYGON` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_MULTIPOLYGON = 46;

    /**
     * Spatial `GEOMETRYCOLLECTION` type (MySQL; PostgreSQL + PostGIS)
     *
     * @var int
     */
    const TYPE_GEOMETRYCOLLECTION = 47;

    /**
     * Column Position
     *
     * @var string|null
     */
    protected after = null;

    /**
     * Whether the column is an array of its base type. Recognized by the
     * PostgreSQL dialect (e.g. `INTEGER[]`, `TEXT[]`). MySQL and SQLite
     * ignore the flag.
     *
     * @var bool
     */
    protected isArray = false;

    /**
     * Column is autoIncrement?
     *
     * @var bool
     */
    protected autoIncrement = false;

    /**
     * Bind Type
     *
     * @var int
     */
    protected bindType = 2;

    /**
     * Column's comment
     *
     * @var string|null
     */
     protected comment = null;

    /**
     * Default column value
     *
     * @var mixed|null
     */
    protected defaultValue = null;

    /**
     * Position is first
     *
     * @var bool
     */
    protected first = false;

    /**
     * Generation expression for `GENERATED ALWAYS AS (...)`. Null when the
     * column is not a generated/computed column.
     *
     * @var string|null
     */
    protected generated = null;

    /**
     * Whether a generated column is `STORED` (true) or `VIRTUAL` (false).
     * Ignored when the column is not generated. PostgreSQL only supports
     * `STORED` and emits it regardless of this flag.
     *
     * @var bool
     */
    protected generationStored = false;

    /**
     * The column have some numeric type?
     *
     * @var bool
     */
    protected isNumeric = false;

    /**
     * Whether the column is `INVISIBLE` (MySQL 8.0.23+). Invisible columns
     * are excluded from `SELECT *` expansion but can still be referenced
     * explicitly.
     *
     * @var bool
     */
    protected invisible = false;

    /**
     * Column's name
     *
     * @var string
     */
    protected name;

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
     *
     * @var bool
     */
    protected primary = false;

    /**
     * Integer column number scale
     *
     * @var int
     */
    protected scale = 0;

    /**
     * Integer column size
     *
     * @var int|string
     */
    protected size = 0;

    /**
     * Column data type
     *
     * @var int
     */
    protected type;

    /**
     * Column data type reference
     *
     * @var int
     */
    protected typeReference = -1;

    /**
     * Column data type values
     *
     * @var array|string
     */
    protected typeValues = [];

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
            typeValues, comment, generated, generationStored, invisible,
            isArray;

        let this->name = name;

        /**
         * Get the column type, one of the TYPE_* constants
         */
        if unlikely !fetch type, definition["type"] {
            throw new ColumnTypeRequired();
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
                    throw new ColumnTypeRejectsScale();
            }
        }

        /**
         * Check if the column is default value
         */
        if fetch defaultValue, definition["default"] {
            let this->defaultValue = defaultValue;
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
                        throw new ColumnTypeRejectsAutoIncrement();
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

        /**
         * Get the column comment
         */
         if fetch comment, definition["comment"] {
            let this->comment = comment;
        }

        /**
         * Generated/computed column expression. When a non-empty string is
         * provided the column is marked as generated and DEFAULT /
         * AUTO_INCREMENT are no longer compatible at the dialect level.
         */
        if fetch generated, definition["generated"] {
            if generated !== null {
                if unlikely typeof generated != "string" {
                    throw new InvalidGenerationExpression();
                }

                if unlikely this->autoIncrement {
                    throw new GeneratedAutoIncrementConflict();
                }

                if unlikely this->defaultValue !== null {
                    throw new GeneratedDefaultConflict();
                }

                let this->generated = generated;
            }
        }

        /**
         * Storage flag for generated columns. true = STORED, false = VIRTUAL.
         */
        if fetch generationStored, definition["generationStored"] {
            let this->generationStored = (bool) generationStored;
        }

        /**
         * Whether the column is INVISIBLE (MySQL 8.0.23+).
         */
        if fetch invisible, definition["invisible"] {
            let this->invisible = (bool) invisible;
        }

        /**
         * Whether the column is an array of its base type (PostgreSQL).
         */
        if fetch isArray, definition["array"] {
            let this->isArray = (bool) isArray;
        }
    }

    /**
     * Check whether field absolute to position in table
     */
    public function getAfterPosition() -> string | null
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
     * Column's comment
     */
     public function getComment() -> string | null
     {
        return this->comment;
     }

    /**
     * Default column value
     */
    public function getDefault() -> var
    {
        return this->defaultValue;
    }

    /**
     * Returns the generation expression for a generated/computed column.
     * Returns `null` when the column is not generated.
     */
    public function getGenerationExpression() -> string | null
    {
        return this->generated;
    }

    /**
     * Column's name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Integer column number scale
     */
    public function getScale() -> int
    {
        return this->scale;
    }

    /**
     * Integer column size
     */
    public function getSize() -> int | string
    {
        return this->size;
    }

    /**
     * Column data type
     */
    public function getType() -> int | string
    {
        return this->type;
    }

    /**
     * Column data type reference
     */
    public function getTypeReference() -> int
    {
        return this->typeReference;
    }

    /**
     * Column data type values
     */
    public function getTypeValues() -> array | string
    {
        return this->typeValues;
    }

    /**
     * Check whether column has default value
     */
    public function hasDefault() -> bool
    {
        if this->isAutoIncrement() {
            return false;
        }

        return this->defaultValue !== null;
    }

    /**
     * Whether the column is an array of its base type. Recognized by the
     * PostgreSQL dialect (e.g. `INTEGER[]`, `TEXT[]`); MySQL and SQLite
     * ignore the flag.
     */
    public function isArray() -> bool
    {
        return this->isArray;
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
     * Whether the column is a generated/computed column.
     */
    public function isGenerated() -> bool
    {
        return this->generated !== null;
    }

    /**
     * Whether a generated column is `STORED`. `false` means `VIRTUAL`.
     * Always meaningful only when `isGenerated()` is `true`.
     */
    public function isGenerationStored() -> bool
    {
        return this->generationStored;
    }

    /**
     * Whether the column is declared `INVISIBLE` (MySQL 8.0.23+). Invisible
     * columns are excluded from `SELECT *` expansion but can still be
     * referenced explicitly. PostgreSQL and SQLite have no equivalent and
     * dialects targeting them ignore the flag.
     */
    public function isInvisible() -> bool
    {
        return this->invisible;
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
