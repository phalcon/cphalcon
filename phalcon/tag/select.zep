
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

namespace Phalcon\Tag;

/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT html tag using a static array of values or a Phalcon\Mvc\Model resultset
 */
abstract class Select
{

	/**
	 * Generates a SELECT tag
	 *
	 * @param array parameters
	 * @param array data
	 */
	public static function selectField(parameters, data=null) -> string
	{
	}

}
