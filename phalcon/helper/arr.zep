
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

use Phalcon\Exception;

/**
 * Phalcon\Helper\Arr
 *
 * Array helper methods
 */
class Arr
{
	/**
	 * Helper method to check an array for an element. If it exists it returns it,
	 * if not, it returns the supplied default value
	 */
	public static function get(var key, array collection, var defaultValue = null) -> var
	{
		var value;

		if typeof !== "string" || true !== is_numeric(key) {
			throw new Exception("Key must be either string or numeric");
		}

		if likely fetch value, collection[name] {
			return value;
		}

		return defaultValue;
	}

	/**
	 * Helper method to add an element to an array with an optional key. Returns
	 * the final array
	 */
	public static function set(var value, array collection = [], var key = null) -> array
	{
		if null === key {
			let collection[] = value;
		} else {
			let collection[key] = value;
		}

		return collection;
	}
}
