
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

class AssociativeArray implements InterpolatorInterface
{

	/**
	 * Replaces placeholders by the values passed
	*/
	public function replacePlaceholders(string! translation, placeholders = null) -> string
	{
		var key, value;

		if typeof placeholders === "array" && count(placeholders) {
			for key, value in placeholders {
				let translation = str_replace("%" . key . "%", value, translation);
			}
		}

		return translation;
	}
}
