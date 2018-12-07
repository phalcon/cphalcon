
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Filters;

use Phalcon\Assets\FilterInterface;

/**
 * Phalcon\Assets\Filters\None
 *
 * Returns the content without make any modification to the original source
 */
class None implements FilterInterface
{
	/**
	 * Returns the content without be touched
	 */
	public function filter(string! content) -> string
	{
		return content;
	}
}
