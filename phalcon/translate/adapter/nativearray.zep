
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\AdapterInterface;
use Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 */
class NativeArray extends Adapter implements AdapterInterface, \ArrayAccess
{

	protected _translate;

	/**
	 * Phalcon\Translate\Adapter\NativeArray constructor
	 *
	 * @param array options
	 */
	public function __construct(array! options)
	{
		var data;

		if !fetch data, options["content"] {
			throw new Exception("Translation content was not provided");
		}

		if typeof data !== "array" {
			throw new Exception("Translation data must be an array");
		}

		let this->_translate = data;
	}

	/**
	 * Returns the translation related to the given key
	 *
	 * @param string  index
	 * @param array   placeholders
	 * @return string
	 */
	public function query(string! index, placeholders = null) -> string
	{
		var translation, key, value;

		if fetch translation, this->_translate[index] {
			if typeof placeholders === "array" {
				if count(placeholders) {
					for key, value in placeholders {
						let translation = str_replace("%" . key . "%", value, translation);
					}
				}
			}
			return translation;
		}
		return index;
	}

	/**
	 * Check whether is defined a translation key in the internal array
	 *
	 * @param    string index
	 * @return   bool
	 */
	public function exists(string! index) -> boolean
	{
		return isset this->_translate[index];
	}
}
