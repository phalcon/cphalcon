
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
 * Phalcon\Db\Column\Type
 *
 * ColumnType 
 */
abstract class Type
{

	protected dialects = [];
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
	
	public function castValue(value) {
		return value;
	}
	
	public function getDialects() {
		return this->dialects;
	}
	
	public function getName() {
		var completeClassName;
		
		let completeClassName = get_class(this);
                		
		return strtolower(str_replace("Type","",substr(completeClassName, strrpos(completeClassName,"\\")+1)));
	}

	public function supportScale() {
		return this->_scale;
	}
	
	public function supportAutoIncrement() {
		return this->_autoIncrement;
	}
	
	public function getBindType() {
		return this->_bindType;
	}
	
	public function isNumeric() {
		return this->_isNumeric;
	}
	
}
