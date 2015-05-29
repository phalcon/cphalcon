
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
use Phalcon\Db\Column\Type as ColumnType;

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
 *   "type" => "integer",
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
	const TYPE_INTEGER = "integer";

	/**
	 * Date abstract type
	 */
	const TYPE_DATE = "date";

	/**
	 * Varchar abstract type
	 */
	const TYPE_VARCHAR = "varchar";

	/**
	 * Decimal abstract type
	 */
	const TYPE_DECIMAL = "decimal";

	/**
	 * Datetime abstract type
	 */
	const TYPE_DATETIME = "datetime";

	/**
	 * Char abstract type
	 */
	const TYPE_CHAR = "char";

	/**
	 * Text abstract data type
	 */
	const TYPE_TEXT = "text";

	/**
	 * Float abstract data type
	 */
	const TYPE_FLOAT = "float";

	/**
	 * Boolean abstract data type
	 */
	const TYPE_BOOLEAN = "boolean";

	/**
	 * Double abstract data type
	 *
	 */
	const TYPE_DOUBLE = "double";
	
	const TYPE_ENUM = "enum";

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
	protected _type;

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
	 * Default Bind Type
	 */
	protected _bindType = 2;
	
	/**
	 * List of column type
	 * @var array
	 */
	protected static _columnTypes;
	
	/**
	 * List of column type by dialect keyword
	 * @var array
	 */
	protected static _columnTypesDialectKeywords;
	
	
	/**
	 *
	 * Allows to add column type to be used on create or alter table operations
	 *
	 *<code>
	 *	use Phalcon\Db\Column as Column;
	 *
	 * //column definition
	 * Column::addType( (new \MyNamespace\MyColumnType()) );
	 *</code>
	 *
	 */
	public static function addType(<ColumnType> type)
	{
		let self::_columnTypes[type->getName()] = get_class(type);
		
		self::addDialectKeywords(type);
	}
	
	/**
	 * get all column types if type is null 
	 *
	 *
	 */
	public static function getColumnTypes( type = null ) {
		self::initialize();
		
		if name !== null {
			return isset self::_columnTypes[type] ? self::_columnTypes[type] : false;
		} else {
			return self::_columnTypes;
		}
	}
	
	private static function addDialectKeywords(<ColumnType> ColumnType) {
		
		var dialects,dialect,keyword,dialectKeywords,keywords;
		
		let dialects = ColumnType->getDialects();
        				
		for dialect, dialectKeywords in dialects {
			
			if typeof dialectKeywords == "string" {
				let keywords = [dialectKeywords];
			} else {
				let keywords = dialectKeywords;
			}
			
			for keyword in keywords {
				if preg_match("#\\(#",keyword) {
					let keyword = substr(keyword, 0, strpos(keyword, "("));
				}
				let keyword = strtoupper(keyword);
				
				let self::_columnTypesDialectKeywords[dialect][keyword] = ColumnType->getName();
			}
		}
	}
	
	protected static function initialize() {
		
		var className;
	
		if empty self::_columnTypes {
			let self::_columnTypes  = [
										"integer" : "\\Phalcon\\Db\\Column\\Type\\Integer",
										"date" : "\\Phalcon\\Db\\Column\\Type\\Date",
										"varchar" : "\\Phalcon\\Db\\Column\\Type\\Varchar",
										"decimal" : "\\Phalcon\\Db\\Column\\Type\\Decimal",
										"datetime" : "\\Phalcon\\Db\\Column\\Type\\Datetime",
										"char" : "\\Phalcon\\Db\\Column\\Type\\CharType",
										"text" : "\\Phalcon\\Db\\Column\\Type\\Text",
										"float" : "\\Phalcon\\Db\\Column\\Type\\FloatType",
										"bigint" : "\\Phalcon\\Db\\Column\\Type\\Bigint",
										"enum" : "\\Phalcon\\Db\\Column\\Type\\Enum"
									];
									
			let self::_columnTypesDialectKeywords = [];
			for className in self::_columnTypes {
				self::addDialectKeywords( (new {className}()) );
			}
		}
	}
	
	/**
	 * Get column type name by dialect and keyword
	 *
	 *<code>
	 *	use Phalcon\Db\Column as Column;
	 *
	 * //column definition
	 * $columnType = Column::getColumnTypeByDialectKeyword("mysql","INT");
	 *</code>
	 *
	 */
	public static function getColumnTypeByDialectKeyword(string dialect, string type) {
		
		var formattedType;
		
		self::initialize();
		
		if !isset self::_columnTypesDialectKeywords[dialect] {
			throw new Exception("Unknown dialect");
		}
		
		let formattedType = strtoupper(type);
		if isset self::_columnTypesDialectKeywords[dialect][formattedType] {
			return self::_columnTypesDialectKeywords[dialect][formattedType];
		}
		
		return "varchar";
	}
	
	/**
	 * Set column type for column
	 * 
	 *
	 *
	 *
	 */
	protected function setType(type) {
		
		var columnTypes,columnTypeClass;
		
		let columnTypes = self::getColumnTypes();
		
		if typeof type == "integer" {
        				
			if !fetch columnTypeClass,columnTypes[ array_keys(columnTypes)[type] ] {
				throw new Exception("Unknown column type \"" . type . "\"");
			}
			
		} else {
			
			if !fetch columnTypeClass,columnTypes[strtolower(type)] {
				throw new Exception("Unknown column type \"" . type . "\"");
			}
			
		}
		let this->_type = new {columnTypeClass}();
	}

	/**
	 * Phalcon\Db\Column constructor
	 */
	public function __construct(string! name, array! definition)
	{
	
		var type, notNull, primary, size, scale, dunsigned, first,
			after, autoIncrement, defaultValue,
			typeReference, typeValues;
			
		let this->_name = name;

		/**
		 * Get the column type, one of the TYPE_* constants
		 */
		if fetch type, definition["type"] {
		
			this->setType(type);
			
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
			if this->_type->supportScale() {
				let this->_scale = scale;
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
		let this->_isNumeric = this->_type->isNumeric();

		/**
		 * Check if the field is auto-increment/serial
		 */
		if fetch autoIncrement, definition["autoIncrement"] {
			if autoIncrement {
				if this->_type->supportAutoIncrement() {
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
		let this->_bindType = this->_type->getBindType();

	}
	
	/**
	 *
	 *
	 *
	 *
	 */
	public function getType(onlyName = true)
	{
		if onlyName === true {
			return this->_type->getName();
		}
		else {
			return this->_type;
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
		return this->_type->isNumeric();
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
			columnTypeReference, columnTypeValues,
			columnTypes,typeClass;

		if !fetch columnName, data["_columnName"] {
			if !fetch columnName, data["_name"] {
				throw new Exception("Column name is required");
			}
		}

		let definition = [];

		if fetch columnType,  data["_type"] {
		
			let columnTypes = self::getColumnTypes();
			
			if typeof columnType == "integer" {
							
				if !fetch typeClass,columnTypes[array_keys(columnTypes)[columnType]] {
					throw new Exception("Unknown column type \"" . columnType . "\"");
				}
				
			} else {
				
				if !fetch typeClass,columnTypes[strtolower(columnType)] {
					throw new Exception("Unknown column type \"" . columnType . "\"");
				}
				
			}
		
			let definition["type"] = (new {typeClass}())->getName();
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
			let definition["scale"] = scale;
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
