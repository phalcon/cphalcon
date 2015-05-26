
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
use Phalcon\Db\Column;

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
	
	protected _bindType = Column::BIND_PARAM_STR;
	
	public function __construct()
	{
		this->setup();
	}
	
	abstract public function setup(){}
	
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
		
		let name = this->getNameForDialect(dialect);
		
		if name == test {
			return true;
		}
		
		return false;
	}
	
	public function getBindType() {
		return this->_bindType;
	}
	public function isNumeric() {
		return this->_isNumeric;
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
		var out;
		let out = isset this->dialect[dialect] ? this->dialect[dialect] : false ;
		return out;
	}
	
	public function castValue(value) {
		return value;
	}
	
}
