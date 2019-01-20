
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

use Phalcon\Filter\SanitizerInterface;

/**
 * Phalcon\Filter\Sanitize\FloatValCast
 *
 * Sanitizes a value to float casting it also
 */
class FloatValCast
{
	/**
	 * @var mixed input The text to sanitize
	 */
	public function __invoke(var input)
	{
		return doubleval(input);
	}
}
