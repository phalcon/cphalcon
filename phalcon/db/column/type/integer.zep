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
use Phalcon\Db\Column;

class Integer extends ColumnType
{
	public function setup()
	{
		let this->dialects = [
				"mysql":"INT(#size#)",
				"sqlite":"INT",
				"postgresql":"INTEGER"
			];
		let this->_autoIncrement = true;
		let this->_scale = true;
		let this->_isNumeric = true;
		let this->_bindType = Column::BIND_PARAM_INT;
	}
	public function castValue(value) {
		return (int)value;
	}
}