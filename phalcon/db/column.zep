
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Db\Exception;
use Phalcon\Db\ColumnInterface;

/**
 * Phalcon\Db\Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *<code>
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
 *</code>
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
	protected _after;

	/**
	 * Column is autoIncrement?
	 *
	 * @var bool
	 */
	protected _autoIncrement = false;

	/**
	 * Bind Type
	 */
	protected _bindType = 2;

	/**
	 * Default column value
	 */
	protected _default = null { get };

	/**
	 * Position is first
	 *
	 * @var bool
	 */
	protected _first = false;

	/**
	 * The column have some numeric type?
	 */
	protected _isNumeric = false;

	/**
	 * Column's name
	 *
	 * @var string
	 */
	protected _name { get };

	/**
	 * Column not nullable?
	 *
	 * @var bool
	 */
	protected _notNull = false;

	/**
	 * Column is part of the primary key?
	 */
	protected _primary = false;

	/**
	 * Integer column number scale
	 *
	 * @var int
	 */
	protected _scale = 0 { get };

	/**
	 * Schema which table related is
	 *
	 * @var string
	 */
	protected _schemaName { get };

	/**
	 * Integer column size
	 *
	 * @var int
	 */
	protected _size = 0 { get };

	/**
	 * Column data type
	 *
	 * @var int
	 */
	protected _type { get };

	/**
	 * Column data type reference
	 *
	 * @var int
	 */
	protected _typeReference = -1 { get };

	/**
	 * Column data type values
	 *
	 * @var array|string
	 */
	protected _typeValues { get };

	/**
	 * Integer column unsigned?
	 *
	 * @var bool
	 */
	protected _unsigned = false;

	/**
	 * Phalcon\Db\Column constructor
	 */
	public function __construct(string! name, array! definition)
	{
		var type, notNull, primary, size, scale, dunsigned, first,
			after, bindType, isNumeric, autoIncrement, defaultValue,
			typeReference, typeValues;

		let this->_name = name;

		/**
		 * Get the column type, one of the TYPE_* constants
		 */
		if fetch type, definition["type"] {
			let this->_type = type;
		} else {
			throw new Exception("Column type is required");
		}

		if fetch typeReference, definition["typeReference"] {
			let this->_typeReference = typeReference;
		}

		if fetch typeValues, definition["typeValues"] {
			let this->_typeValues = typeValues;
		}

		/**
		 * Check if the field is nullable
		 */
		if fetch notNull, definition["notNull"] {
			let this->_notNull = notNull;
		}

		/**
		 * Check if the field is primary key
		 */
		if fetch primary, definition["primary"] {
			let this->_primary = primary;
		}

		if fetch size, definition["size"] {
			let this->_size = size;
		}

		/**
		 * Check if the column has a decimal scale
		 */
		if fetch scale, definition["scale"] {
			switch type {

				case self::TYPE_INTEGER:
				case self::TYPE_FLOAT:
				case self::TYPE_DECIMAL:
				case self::TYPE_DOUBLE:
				case self::TYPE_BIGINTEGER:
					let this->_scale = scale;
					break;

				default:
					throw new Exception("Column type does not support scale parameter");
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
			let this->_unsigned = dunsigned;
		}

		/**
		 * Check if the field is numeric
		 */
		if fetch isNumeric, definition["isNumeric"] {
			let this->_isNumeric = isNumeric;
		}

		/**
		 * Check if the field is auto-increment/serial
		 */
		if fetch autoIncrement, definition["autoIncrement"] {
			if !autoIncrement {
				let this->_autoIncrement = false;
			} else {
				switch type {

					case self::TYPE_INTEGER:
					case self::TYPE_BIGINTEGER:
						let this->_autoIncrement = true;
						break;

					default:
						throw new Exception("Column type cannot be auto-increment");
				}
			}
		}

		/**
		 * Check if the field is placed at the first position of the table
		 */
		if fetch first, definition["first"] {
			let this->_first = first;
		}

		/**
		 * Name of the column which is placed before the current field
		 */
		if fetch after, definition["after"] {
			let this->_after = after;
		}

		/**
		 * The bind type to cast the field when passing it to PDO
		 */
		if fetch bindType, definition["bindType"] {
			let this->_bindType = bindType;
		}

	}

	/**
	 * Restores the internal state of a Phalcon\Db\Column object
	 */
	public static function __set_state(array! data) -> <ColumnInterface>
	{
		var definition, columnType, notNull, size, dunsigned, after,
			isNumeric, first, bindType, primary, columnName, scale,
			defaultValue, autoIncrement,
			columnTypeReference, columnTypeValues;

		if !fetch columnName, data["_columnName"] {
			if !fetch columnName, data["_name"] {
				throw new Exception("Column name is required");
			}
		}

		let definition = [];

		if fetch columnType,  data["_type"] {
			let definition["type"] = columnType;
		}

		if fetch columnTypeReference,  data["_typeReference"] {
			let definition["typeReference"] = columnTypeReference;
		} else {
			let definition["typeReference"] = -1;
		}

		if fetch columnTypeValues,  data["_typeValues"] {
			let definition["typeValues"] = columnTypeValues;
		}

		if fetch notNull, data["_notNull"] {
			let definition["notNull"] = notNull;
		}

		if fetch primary, data["_primary"] {
			let definition["primary"] = primary;
		}

		if fetch size, data["_size"] {
			let definition["size"] = size;
		}

		if fetch scale, data["_scale"] {

			switch definition["type"] {

				case self::TYPE_INTEGER:
				case self::TYPE_FLOAT:
				case self::TYPE_DECIMAL:
				case self::TYPE_DOUBLE:
				case self::TYPE_BIGINTEGER:
					let definition["scale"] = scale;
					break;
			}
		}

		if fetch defaultValue, data["_default"] {
			let definition["default"] = defaultValue;
		}

		if fetch dunsigned, data["_unsigned"] {
			let definition["unsigned"] = dunsigned;
		}

		if fetch autoIncrement, data["_autoIncrement"] {
			let definition["autoIncrement"] = autoIncrement;
		}

		if fetch isNumeric, data["_isNumeric"] {
			let definition["isNumeric"] = isNumeric;
		}

		if fetch first, data["_first"] {
			let definition["first"] = first;
		}

		if fetch after, data["_after"] {
			let definition["after"] = after;
		}

		if fetch bindType, data["_bindType"] {
			let definition["bindType"] = bindType;
		}

		return new self(columnName, definition);
	}

	/**
	 * Check whether field absolute to position in table
	 *
	 * @return string
	 */
	public function getAfterPosition() -> string
	{
		return this->_after;
	}

	/**
	 * Returns the type of bind handling
	 */
	public function getBindType() -> int
	{
		return this->_bindType;
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
		return this->_autoIncrement;
	}

	/**
	 * Check whether column have first position in table
	 */
	public function isFirst() -> bool
	{
		return this->_first;
	}

	/**
	 * Not null
	 */
	public function isNotNull() -> bool
	{
		return this->_notNull;
	}

	/**
	 * Check whether column have an numeric type
	 */
	public function isNumeric() -> bool
	{
		return this->_isNumeric;
	}

	/**
	 * Column is part of the primary key?
	 */
	public function isPrimary() -> bool
	{
		return this->_primary;
	}

	/**
	 * Returns true if number column is unsigned
	 */
	public function isUnsigned() -> bool
	{
		return this->_unsigned;
	}
}
