
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
 * Phalcon\Filter\Sanitize\Int
 *
 * Sanitizes a value to integer
 */
class Email extends AbstractSanitizer implements SanitizerInterface
{
	/**
	 * @var mixed input The text to sanitize
	 */
	public function __invoke()
	{
		var input;

		let input = this->checkArguments(func_get_args(), 1);

		return filter_var(input, constant("FILTER_SANITIZE_EMAIL"));
	}
}
