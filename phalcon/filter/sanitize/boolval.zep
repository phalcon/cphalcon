
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
use Phalcon\Filter\Sanitize\AbstractSanitizer;

/**
 * Phalcon\Filter\Sanitize\BoolVal
 *
 * Sanitizes a value to boolean
 */
class BoolVal extends AbstractSanitizer implements SanitizerInterface
{
	/**
	 * @var mixed input The text to sanitize
	 */
	public function __invoke()
	{
		var falseArray, input, trueArray;

		let input = this->checkArguments(func_get_args(), 1),
			trueArray  = ["true", "on", "yes", "y", "1"],
			falseArray = ["false", "off", "no", "n", "0"];

		if true === in_array(input, trueArray) {
			return true;
		}

		if true === in_array(input, falseArray) {
			return false;
		}

		return (bool) input;
	}
}
