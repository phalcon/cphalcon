
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate;

/**
 * Phalcon\Translate\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
interface InterpolatorInterface
{
	/**
	 * Replaces placeholders by the values passed
	*/
	public function replacePlaceholders(string! translation, placeholders = null) -> string;
}
