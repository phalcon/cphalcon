
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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

namespace Phalcon\Translate;

/**
 * Phalcon\Translate\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
interface AdapterInterface
{

	/**
	 * Returns the translation string of the given key
	 *
	 * @param	string translateKey
	 * @param	array placeholders
	 * @return	string
	 */
	public function t(string! translateKey, placeholders = null) -> string;

	/**
	 * Returns the translation related to the given key
	 *
	 * @param	string index
	 * @param	array placeholders
	 * @return	string
	 */
	public function query(string! index, placeholders = null) -> string;

	/**
	 * Check whether is defined a translation key in the internal array
	 */
	public function exists(string! index) -> boolean;

}
