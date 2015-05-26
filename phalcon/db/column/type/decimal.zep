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

class Decimal extends ColumnType
{
	
	public function setup()
	{
		let this->dialect = [
				"mysql":"DECIMAL(#size#,#scale#)",
				"postgresql":"NUMERIC(#size#,#scale#)"
			];
		let this->_autoIncrement = false;
		let this->_scale = true;
		let this->_isNumeric = true;
	}

	public function castValue(value) {
		return floatval(value);
	}
}