
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * Phalcon\Utility
 *
 * This class contains protected methods used throughout the framework
 */
class Utility
{
	/**
	 * Helper method to check an array for an element. If it exists it returns it,
	 * if not, it returns the supplied default value
	 *
	 * This is really necessary evil here since we do not have traits with Zephir.
	 * Once we do, this will definitely be removed from being a static.
	 */
	public static function arrayGetDefault(string name, array parameters, var defaultValue = null) -> var
	{
		var value;

		if likely fetch value, parameters[name] {
			return value;
		}

		return defaultValue;
	}
}
