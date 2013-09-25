
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

namespace Phalcon\Flash;

/**
 * Phalcon\Flash\Direct
 *
 * This is a variant of the Phalcon\Flash that inmediately outputs any message passed to it
 */
class Direct extends Phalcon\Flash implements Phalcon\FlashInterface
{

	/**
	 * Outputs a message
	 *
	 * @param  string type
	 * @param  string message
	 * @return string
	 */
	public function message(string type, string message) -> string
	{
		return this->outputMessage(type, message);
	}

}
