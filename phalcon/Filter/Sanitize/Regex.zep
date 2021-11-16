
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
 * Phalcon\Filter\Sanitize\Regex
 *
 * Sanitizes a value performing preg_replace
 */
class Regex
{
    /**
     * @param mixed $input
     * @param mixed $pattern
     * @param mixed $replace
     *
     * @return string|string[]|null
     */
    public function __invoke(var input, var pattern, var replace)
    {
        return preg_replace(pattern, replace, input);
    }
}
