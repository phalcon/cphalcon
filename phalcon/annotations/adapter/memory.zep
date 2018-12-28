
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	public function read(string! key) -> <Reflection> | bool
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
