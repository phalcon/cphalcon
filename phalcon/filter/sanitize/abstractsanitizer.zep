
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
 * Phalcon\Filter\Sanitize\AbsInt
 *
 * Sanitizes a value to absolute integer
 */
abstract class AbstractSanitizer
{
	/**
	 * @var mixed input The text to sanitize
	 */
	protected function checkArguments(array arguments, int parameterCount) -> var
	{
		if parameterCount !== count(arguments) {
			throw new \InvalidArgumentException("Invalid passed arguments");
		}

		if 1 === parameterCount {
			return arguments[0];
		} else {
			return arguments;
		}
	}
}
