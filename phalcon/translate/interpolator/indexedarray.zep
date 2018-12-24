
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Interpolator;

use Phalcon\Translate\InterpolatorInterface;

class IndexedArray implements InterpolatorInterface
{

	/**
	 * Replaces placeholders by the values passed
	*/
	public function replacePlaceholders(string! translation, placeholders = null) -> string
	{
		if typeof placeholders === "array" && count(placeholders) {
			array_unshift(placeholders, translation);
			return call_user_func_array("sprintf", placeholders);
		}
		return translation;
	}
}
