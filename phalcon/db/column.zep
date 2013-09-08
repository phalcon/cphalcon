
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
class Column implements Phalcon\Db\ColumnInterface
{

	/**
	 * Integer abstract type
	 *
	 */
	const TYPE_INTEGER = 0;

	/**
	 * Date abstract type
	 *
	 */
	const TYPE_DATE = 1;

	/**
	 * Varchar abstract type
	 *
	 */
	const TYPE_VARCHAR = 2;

	/**
	 * Decimal abstract type
	 *
	 */
	const TYPE_DECIMAL = 3;

	/**
	 * Datetime abstract type
	 *
	 */
	const TYPE_DATETIME = 4;

	/**
	 * Char abstract type
	 *
	 */
	const TYPE_CHAR = 5;

	/**
	 * Text abstract data type
	 *
	 */
	const TYPE_TEXT = 6;

	/**
	 * Float abstract data type
	 *
	 */
	const TYPE_FLOAT = 7;

	/**
	 * Boolean abstract data type
	 *
	 */
	const TYPE_BOOLEAN = 8;

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
	protected _columnName;

	/**
	 * Schema which table related is
	 *
	 * @var string
	 */
	protected _schemaName;

	/**
	 * Column data type
	 *
	 * @var int
	 */
	protected _type;

	/**
	 * The column have some numeric type?
	 */
	protected _isNumeric = false;

	/**
	 * Integer column size
	 *
	 * @var int
	 */
	protected _size = 0;

	/**
	 * Integer column number scale
	 *
	 * @var int
	 */
	protected _scale = 0;

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

}
