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

namespace Phalcon\Db\Column\Type;

use Phalcon\Db\Column\Type as ColumnType;
use Phalcon\Db\Column as Column;

class CharType extends ColumnType
{
	public function setup()
	{
		let this->dialects = [
        		"mysql":"CHAR(#size#)",
        		"sqlite":["CHARACTER(#size#)","CHAR(#size#)"],
        		"postgresql":"CHARACTER(#size#)"
        	];
		let this->_autoIncrement = false;
		let this->_scale = false;
		let this->_isNumeric = false;
		let this->_bindType = Column::BIND_PARAM_STR;
	}
}