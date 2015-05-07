
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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
 *	use Phalcon\Db\Column as Column;
 *
 * //column definition
 * $column = new Column("id", array(
 *   "type" => Column::TYPE_INTEGER,
 *   "size" => 10,
 *   "unsigned" => true,
 *   "notNull" => true,
 *   "autoIncrement" => true,
 *   "first" => true
 * ));
 *
 * //add column to existing table
 * $connection->addColumn("robots", null, $column);
 *</code>
 *
 */
class Column implements ColumnInterface
{

	/**
	 * Integer abstract type
	 */
	const TYPE_INTEGER = 0;

	/**
	 * Date abstract type
	 */
	const TYPE_DATE = 1;

	/**
	 * Varchar abstract type
	 */
	const TYPE_VARCHAR = 2;

	/**
	 * Decimal abstract type
	 */
	const TYPE_DECIMAL = 3;

	/**
	 * Datetime abstract type
	 */
	const TYPE_DATETIME = 4;

	/**
	 * Char abstract type
	 */
	const TYPE_CHAR = 5;

	/**
	 * Text abstract data type
	 */
	const TYPE_TEXT = 6;

	/**
	 * Float abstract data type
	 */
	const TYPE_FLOAT = 7;

	/**
	 * Boolean abstract data type
	 */
	const TYPE_BOOLEAN = 8;

	/**
	 * Double abstract data type
	 *
	 */
	const TYPE_DOUBLE = 9;
	
	
	/**
	 * Bind Type Null
	 */
	const BIND_PARAM_NULL = 0;

	/**
	 * Bind Type Integer
	 */
	const BIND_PARAM_INT = 1;

	/**
	 * Bind Type String
	 */
	const BIND_PARAM_STR = 2;

	/**
	 * Bind Type Bool
	 */
	const BIND_PARAM_BOOL = 5;

	/**
	 * Bind Type Decimal
	 */
	const BIND_PARAM_DECIMAL = 32;

	/**
	 * Skip binding by type
	 */
	const BIND_SKIP = 1024;

	/**
	 * Column's name
	 *
	 * @var string
	 */
	protected _name { get };

	/**
	 * Schema which table related is
	 *
	 * @var string
	 */
	protected _schemaName { get };

	/**
	 * Column data type
	 *
	 * @var int|string
	 */
	protected _type { get };

	/**
	 * Column data type reference
	 *
	 * @var int
	 */
	protected _typeReference { get };

	/**
	 * Column data type values
	 *
	 * @var array|string
	 */
	protected _typeValues { get };

	/**
	 * The column have some numeric type?
	 */
	protected _isNumeric = false;

	/**
	 * Integer column size
	 *
	 * @var int
	 */
	protected _size = 0 { get };

	/**
	 * Integer column number scale
	 *
	 * @var int
	 */
	protected _scale = 0 { get };

	/**
	 * Default column value
	 */
	protected _default = null { get };

	/**
	 * Integer column unsigned?
	 *
	 * @var boolean
	 */
	protected _unsigned = false;

	/**
	 * Column not nullable?
	 *
	 * @var boolean
	 */
	protected _notNull = false;

	/**
	 * Column is part of the primary key?
	 */
	protected _primary = false;

	/**
	 * Column is autoIncrement?
	 *
	 * @var boolean
	 */
	protected _autoIncrement = false;

	/**
	 * Position is first
	 *
	 * @var boolean
	 */
	protected _first = false;

	/**
	 * Column Position
	 *
	 * @var string
	 */
	protected _after;

	/**
	 * Bind Type
	 */
	protected _bindType = 2;

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
		} else {
			let this->_typeReference = -1;
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
			if type == self::TYPE_INTEGER || type == self::TYPE_FLOAT || type == self::TYPE_DECIMAL || type == self::TYPE_DOUBLE {
				let this->_scale = scale;
			} else {
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
			if autoIncrement {
				if type == self::TYPE_INTEGER {
					let this->_autoIncrement = true;
				} else {
					throw new Exception("Column type cannot be auto-increment");
				}
			} else {
				let this->_autoIncrement = false;
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
	 * Returns true if number column is unsigned
	 */
	public function isUnsigned() -> boolean
	{
		return this->_unsigned;
	}

	/**
	 * Not null
	 */
	public function isNotNull() -> boolean
	{
		return this->_notNull;
	}

	/**
	 * Column is part of the primary key?
	 */
	public function isPrimary() -> boolean
	{
		return this->_primary;
	}

	/**
	 * Auto-Increment
	 */
	public function isAutoIncrement() -> boolean
	{
		return this->_autoIncrement;
	}

	/**
	 * Check whether column have an numeric type
	 */
	public function isNumeric() -> boolean
	{
		return this->_isNumeric;
	}

	/**
	 * Check whether column have first position in table
	 */
	public function isFirst() -> boolean
	{
		return this->_first;
	}

	/**
	 * Check whether field absolute to position in table
	 *
	 * @return string
	 */
	public function getAfterPosition()
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
	 * Restores the internal state of a Phalcon\Db\Column object
	 */
	public static function __set_state(array! data) -> <Column>
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
			if definition["type"] == self::TYPE_INTEGER || definition["type"] == self::TYPE_FLOAT || definition["type"] == self::TYPE_DECIMAL {
				let definition["scale"] = scale;
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
}
