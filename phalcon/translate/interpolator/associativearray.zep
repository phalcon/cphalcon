
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Translate\Interpolator;

use Phalcon\Translate\InterpolatorInterface;

class AssociativeArray implements InterpolatorInterface
{

	/**
	 * Replaces placeholders by the values passed
	*/
	public function replacePlaceholders(string! translation, placeholders = null) -> string
	{
		var key, value;

		if typeof placeholders === "array" && count(placeholders) {
			for key, value in placeholders {
				let translation = str_replace("%" . key . "%", value, translation);
			}
		}

		return translation;
	}
}
