
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Phalcon\Filter\Sanitize\Regex
 *
 * Sanitizes a value performing preg_replace
 */
class Regex
{
	/**
	 * @var mixed input The text to sanitize
	 */
	public function __invoke(string! input, string! pattern, string! replace)
	{
		return preg_replace(pattern, replace, input);
	}
}
