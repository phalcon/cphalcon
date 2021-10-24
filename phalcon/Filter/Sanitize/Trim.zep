
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Phalcon\Filter\Sanitize\Trim
 *
 * Sanitizes a value removing leading and trailing spaces
 */
class Trim
{
    /**
     * @param string $input The text to sanitize
     *
     * @return string
     */
    public function __invoke(string! input)
    {
        return trim(input);
    }
}
