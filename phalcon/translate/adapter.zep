
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

namespace Phalcon\Translate;

use Phalcon\Translate\Exception;

/**
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */
abstract class Adapter
{

	/**
	 * Returns the translation string of the given key
	 *
	 * @param string  translateKey
	 * @param array   placeholders
	 * @return string
	 */
	public function t(string! translateKey, placeholders = null) -> string
	{
		return this->{"query"}(translateKey, placeholders);
	}

	/**
	 * Returns the translation string of the given key (alias of method 't')
	 *
	 * @param string  translateKey
	 * @param array   placeholders
	 * @return string
	 */
	public function _(string! translateKey, placeholders = null) -> string
	{
		return this->{"query"}(translateKey, placeholders);
	}

	/**
	 * Sets a translation value
	 *
	 * @param string offset
	 * @param string value
	 */
	public function offsetSet(var offset, var value)
	{
		throw new Exception("Translate is an immutable ArrayAccess object");
	}

	/**
	 * Check whether a translation key exists
	 */
	public function offsetExists(string! translateKey) -> boolean
	{
		return this->{"exists"}(translateKey);
	}

	/**
	 * Unsets a translation from the dictionary
	 *
	 * @param string offset
	 */
	public function offsetUnset(var offset)
	{
		throw new Exception("Translate is an immutable ArrayAccess object");
	}

	/**
	 * Returns the translation related to the given key
	 *
	 * @param  string translateKey
	 * @return string
	 */
	public function offsetGet(string! translateKey)
	{
		return this->{"query"}(translateKey, null);
	}

	/**
	 * Replaces placeholders by the values passed	
	 */
	protected function replacePlaceholders(string! translation, placeholders = null) -> string
	{
		var key, value;

		if typeof placeholders === "array" {
			if count(placeholders) {
				for key, value in placeholders {
					let translation = str_replace("%" . key . "%", value, translation);
				}
			}
		}

		return translation;
	}
}
