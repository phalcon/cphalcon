
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

namespace Phalcon\Db\Column;

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
abstract class Type
{
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


	protected dialect = [];
	/**
	 * Column is autoIncrement?
	 *
	 * @var boolean
	 */
	protected _autoIncrement = false;
	
	/**
	 * Column is autoIncrement?
	 *
	 * @var boolean
	 */
	protected _scale = false;
	
	/**
	 * The column have some numeric type?
	 */
	protected _isNumeric = false;
	
	protected _bindType = 2;

	public function getDialects() {
		return $this->dialect;
	}
	
	public function getName() {
		return get_class(this);
	}

	public function supportScale() {
		return this->_scale;
	}
	
	public function supportAutoIncrement() {
		return this->_autoIncrement;
	}
	
	public function hasDialectName(dialect,test) {
		var name;
		
		if fetch name, this->getNameForDialect(dialect) {
			if name == test {
				return true;
			}
		}
		
		return false;
	}
	
	public function getBindType() {
		return this->_bindType;
	}
	
	public function getNameForDialect(dialect) {
		var name;
		
		if !fetch name, this->dialect[dialect] {
			throw new Exception("Unsupported dialect \"" . dialect . "\""); 
		}
		let name = substr(name, 0, strpos(name, "("));
		return name;
	}
	
	public function getDialect(dialect) {
		return this->dialect[dialect];
	}
	
	
}
