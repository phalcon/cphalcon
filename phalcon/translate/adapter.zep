
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

namespace Phalcon\Translate;

/**
* Phalcon\Translate\Adapter
*
* Base class for Phalcon\Translate adapters
*/
class Adapter extends Phalcon\Translate\Adapter\NativeArray implements Phalcon\Translate\AdapterInterface
{

	/**
	 * Returns the translation string of the given key
	 *
	 * @param string  translateKey
	 * @param array   placeholders
	 * @return string
	 */
	public function  t(string! translateKey, placeholders=null)
	{
		return this->query(translateKey, placeholders);
	}

	/**
	 * Sets a translation value
	 *
	 * @param         string offset
	 * @param         string value
	 */
	public function offsetSet(offset, value)
	{
		throw new Phalcon\Translate\Exception("Translate is an immutable ArrayAccess object");
	}

	/**
	 * Check whether a translation key exists
	 *
	 * @param string  translateKey
	 * @return boolean
	 */
	public function offsetExists(string! translateKey) -> boolean
	{
		return this->exists(translateKey);
	}

	/**
	 * Unsets a translation from the dictionary
	 *
	 * @param string offset
	 */
	public function offsetUnset()
	{
		throw new Phalcon\Translate\Exception("Translate is an immutable ArrayAccess object");
	}

	/**
	 * Returns the translation related to the given key
	 *
	 * @param  string translateKey
	 * @return string
	 */
	public function offsetGet(string! translateKey)
	{
		return this->query(translateKey, null);
	}

}