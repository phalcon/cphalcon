
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

use Phalcon\Helper\Exception;

/**
 * Phalcon\Helper\Arr
 *
 * This class offers quick array functions throught the framework
 */
class Arr
{
    /**
     * Helper method to get an array element or a default
     */
    final public static function get(array! collection, var index, var defaultValue) -> var
    {
        var value;

        if likely fetch value, collection[index] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Helper method to get an array element or a default
     */
    final public static function has(array! collection, var index) -> bool
    {
        return isset(collection[index]);
    }

    /**
     * Helper method to set an array element
     */
    final public static function set(array! collection, var value, var index = null) -> array
    {
		if null === index {
			let collection[] = value;
		} else {
			let collection[index] = value;
		}

		return collection;
    }
}
