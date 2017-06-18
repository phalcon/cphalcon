
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

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Adapter;
use Phalcon\Annotations\Reflection;

/**
 * Phalcon\Annotations\Adapter\Memory
 *
 * Stores the parsed annotations in memory. This adapter is the suitable development/testing
 */
class Memory extends Adapter
{
	/**
	 * Data
	 * @var mixed
	 */
	protected _data;

	/**
	 * Reads parsed annotations from memory
	 */
	public function read(string! key) -> <Reflection> | boolean
	{
		var data;

		if fetch data, this->_data[strtolower(key)] {
			return data;
		}

		return false;
	}

	/**
	 * Writes parsed annotations to memory
	 */
	public function write(string! key, <Reflection> data)
	{
		var lowercasedKey;

		let lowercasedKey = strtolower(key);
		let this->_data[lowercasedKey] = data;
	}
}
