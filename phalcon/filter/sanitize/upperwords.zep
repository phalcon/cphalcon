
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
 * Phalcon\Filter\Sanitize\UpperWords
 *
 * Sanitizes a value to uppercase teh first character of each word
 */
class UpperWords extends AbstractSanitizer implements SanitizerInterface
{
	/**
	 * @var mixed input The text to sanitize
	 */
	public function __invoke()
	{
		var input;

		let input = this->checkArguments(func_get_args(), 1);

		if (true === function_exists("mb_convert_case")) {
			return mb_convert_case(input, MB_CASE_TITLE, "UTF-8");
		}

		return ucwords(utf8_decode(input));
	}
}
