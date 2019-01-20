
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
 * Phalcon\Filter\Sanitize\Int
 *
 * Sanitizes a value to integer
 */
class Email
{
	/**
	 * @var mixed input The text to sanitize
	 */
	public function __invoke(var input)
	{
		return filter_var(input, constant("FILTER_SANITIZE_EMAIL"));
	}
}
